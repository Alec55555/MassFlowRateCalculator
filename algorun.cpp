#include "algorun.h"
#include <cmath>

#ifdef _MSC_VER
#define pown(base, exp) pow((base), (exp))
#endif


#define pown(base, exp) pow((base), (exp))

Algorun::Algorun(double D, double beta, unsigned int tappings, double T, double p, double phi, double Dp)
{
    this->D = D;
    this->beta = beta;
    this->tappings = tappings;
    this->T = T;
    this->p = p;
    this->phi = phi;
    this->Dp = Dp;
}

bool Algorun::check_limits_of_use()
{
    bool check;
    double D = this->D*1000;
    double d = D * this->beta;
    check = 50 <= D && D <= 1000 && 0.1 <= beta && beta <= 0.75 && d >= 12.5;
    switch (tappings) {
    case FLANGE_TAPPINGS:
        check *= Re_D >= 5000;
        check *= Re_D >= 170 * pown(beta, 2) * D;
        break;

    default:
        if (beta <= 0.56)
            check *= Re_D >= 5000;
        else
            check *= Re_D >= 16000 * pown(beta, 2);
    }

    return(check);
}

bool Algorun::check_expansibility_validity(bool ISO)
{
    if (ISO == true)
        return ((p - Dp) / p >= 0.75);
    else
        return true;
}

double Algorun::discharge_coefficient(double D, double beta, unsigned int tappings, double Re_D) // Checks the tables
{
    /*
     * Calculates the discharge coefficient of the orifice plate.
     *
     * Arguments:
     * ~~~~~~~~~~~
     * D: double
     *  Inner diameter of the pipe (m).
     * beta: double
     *  Diameter ratio of the orifice plate.
     * tappings: unsigned int
     *  Type of pressure tappings (0, 1, 2, 3).
     * Re_D: double
     *  Reynolds number in pipe.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  Discharge coefficient of the orifice plate.
     */

    double L1, Lprime2;

    // Convert the inner diameter to mm:
    D *= 1e3;

    switch (tappings)
    {
    case RADIUS_TAPPINGS: // D and D/2 tappings
        L1      = 1.0;
        Lprime2 = .47;  // 0.5 D /pm 0.02D for \beta \leq 0.6 and 0.5D \pm 0.01D for \beta > 0.6
        break;

    case FLANGE_TAPPINGS:
        L1      = 25.4/D;
        Lprime2 = 25.4/D;
        break;

    default: // CORNER_TAPPINGS
        L1      = 0.0;
        Lprime2 = 0.0;
    }

    double A        = pow(19e3*beta/Re_D, 0.8);
    double Mprime2  = 2.0*Lprime2/(1.0 - beta);
    double betato4  = pown(beta, 4);
    double C        =  0.5961
               + 0.0261 * pown(beta, 2)
               - 0.216 * pown(beta, 8)
               + 0.000521 * pow(1e6*beta/Re_D, 0.7)
               + (0.0188 + 0.0063 * A) * pow(beta, 3.5) * pow(1e6/Re_D, 0.3)
               + (0.043 + 0.080 * exp(-10.0*L1) - 0.123 * exp(-7.0*L1)) * (1.0 - 0.11 * A) * betato4/(1.0-betato4)
               - 0.031 * (Mprime2 - 0.8 * pow(Mprime2, 1.1)) * pow(beta, 1.3);


    if (D < 71.12)
        C += 0.011 * (0.75 - beta) * (2.8 - D/25.4);

    return(C);
}

double Algorun::Uprime_C(double D, double beta, double Re_D)
{
    /*
     * Calculates the uncertainty of discharge coefficient C at k=2 (95% confidence level).
     *
     * Arguments:
     * ~~~~~~~~~~~
     * D: double
     *  Inner diameter of the pipe (m).
     * beta: double
     *  Diameter ratio of the orifice plate.
     * Re_D: double
     *  Reynolds number in pipe.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The relative expanded uncertainty of discharge coefficient C (as percentage)
     *   at k=2 (95% confidence level).
     */

    double Uprime_C;
    if      (0.1 <= beta && beta < 0.2)
        Uprime_C = 0.7 - beta;
    else if (0.2 <= beta && beta <= 0.6)
        Uprime_C = 0.5;
    else if (0.6 < beta && beta <= 0.75)
        Uprime_C = 1.667 * beta - 0.5;
    else
        return(0);

    if (D < 71.12)
        Uprime_C += 0.9 * (0.75 - beta) * (2.8 - D/25.4);

    if (beta > 0.5 && Re_D < 10000)
        Uprime_C += 0.5;

    return(Uprime_C/100);
}

double Algorun::flow_coefficient(double discharge_coefficient, double beta)
{
    /*
     * Calculates the flow coefficient of the orifice plate.
     *
     * Arguments:
     * ~~~~~~~~~~~
     * discharge_coefficient: double
     *  The discharge coefficient of the orifice plate.
     * beta: double
     *  Diameter ratio of the orifice plate.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  Flow coefficient of the orifice plate.
     */
    // product between the discharge coefficient and the velocity of approach factor
    return (double)(discharge_coefficient / sqrt(1.0 - pown(beta, 4)));
}

double Algorun::expansibility_factor(double p1, double Dp, double beta, double kappa, bool ISO) // only ISO=true checks table A12
{
    /*
     * Calculates the expansibility [expansion] factor eps.
     *
     * Arguments:
     * ~~~~~~~~~~~
     * p1: double
     *  The absolute air pressure upstream of the orifice plate (Pa).
     * Dp: double
     *  The pressure drop across the orifice plate (Pa).
     * beta: double
     *  Diameter ratio of the orifice plate.
     * kappa: double
     *  The isentropic exponent. (1.4 for air.)
     * ISO: bool
     *  A parameter that, if false, uses a different formula, supposedly better.
     *  It can be changed to false only in the case of flange pressure tappings.
     *  It is advised not to modify it from true, to respect the ISO-5167 norms.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The expansibility [expansion] factor eps of the orifice plate.
     */
    double p2   = p1 - Dp;
    double eps;
    if (ISO)
        eps  = 1.0 - (0.351 + 0.256 * pown(beta, 4) + 0.93 * pown(beta, 8)) * (1.0 - pow(p2/p1, 1.0/kappa));
    else // ONLY for flange pressure tappings (as in https://science.lpnu.ua/sites/default/files/journal-paper/2017/jul/5449/jeecs-02-02-2016-paper-01.pdf)
        eps  = 0.993023 - (0.3507 + 0.0849 * pown(beta, 4) + 1.8195 * pown(beta, 8)) * (1.0 - pow(p2/p1, 1.0/kappa));

    return(eps);
}

double Algorun::Uprime_eps(double p1, double Dp, double kappa, bool ISO)
{
    /*
     * Calculates the uncertainty of expansibility [expansion] factor eps at k=2 (95% confidence level).
     *
     * Arguments:
     * ~~~~~~~~~~~
     * p1: double
     *  The absolute air pressure upstream of the orifice plate (Pa).
     * Dp: double
     *  The pressure drop across the orifice plate (Pa).
     * kappa: double
     *  The isentropic exponent. (1.4 for air.)
     * ISO: bool
     *  A parameter that, if false, uses a different formula.
     *  It can be changed to false only in the case of flange pressure tappings.
     *  It is advised not to modify it from true, to respect the ISO-5167 norms.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The relative expanded uncertainty of expansibility [expansion] factor eps (as percentage)
     *   at k=2 (95% confidence level).
     */
    if (ISO)
        return (double)((3.5*Dp/p1)/kappa/100);
    else
        return (double)((2.88*Dp/p1)/kappa/100);
}

double Algorun::mass_flow_rate(double alpha, double eps, double beta, double D, double Dp, double rho) // q_m
{
    /*
     * Calculates the mass flow rate. (kg/s)
     *
     * Arguments:
     * ~~~~~~~~~~~
     * alpha: double
     *  The flow coefficient of the orifice plate.
     * eps: double
     *  The expansibility [expansion] factor eps of the orifice plate.
     * beta: double
     *  The diameter ratio of the orifice plate.
     * D: double
     *  The inner diameter of the pipe (m).
     * Dp: double
     *  The pressure drop across the orifice plate (Pa).
     * rho: double
     *  The fluid density of (humid) air upstream of the orifice plate (kg/m3).
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The mass flow rate. (kg/s)
     */
    return (double) alpha*eps*pown(beta,2)*PI*pown(D,2)/4*sqrt(2*rho*Dp);
}

double Algorun::saturated_vapor_pressure(double T, unsigned int algorithm) // pvs
{
    /*
     * Calculates the saturated vapor pressure.
     *
     * Arguments:
     * ~~~~~~~~~~~
     * T: double
     *  Absolute temperature upstream of the orifice plate (K).
     * algorithm: unsigned int
     *  Specifies which equation to use. Defaults to Tetens equation.
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The saturated vapor pressure.
     */
    double val;
    switch (algorithm) {
    case 1: // Buck Equation
        val = 611.21*exp((19.84281876 - T/234.5) * (T - 273.15)/(T - 16.01));
        break;
    // case 2: // https://www.academia.edu/16642632/F06_SI_PSYCHROMETRICS
    //     val = exp(-5.8002206e3/T + 1.3914993e0 - 4.8640239e-2 * T + 4.1764768e-5 * pown(T, 2) - 1.4452093e-8 * pown(T, 3) + 6.5459673e0 * log(T));
    default: // Tetens equation
        val = 610.78*exp(17.2694*(T - 273.15)/(T - 35.85)); // why 17.2694 instead of 17.27?
    }

    return val;
}

double Algorun::humidity_ratio(double phi, double pvs, double p1) // W [X]
{
    /*
     * Calculates the humidity ratio of air (kg/kg/).
     *
     * Arguments:
     * ~~~~~~~~~~~
     * phi: double
     *  The relative humidity of air upstream of the orifice plate.
     * pvs: unsigned int
     *  The saturated vapor pressure.
     * p1: double
     *  The absolute air pressure upstream of the orifice plate (Pa).
     *
     * Returns:
     * ~~~~~~~~~~~
     * double:
     *  The humidity ratio of air.
     */
    double tmp = phi*pvs;
    return (double) 0.62198*tmp/(p1-tmp); // instead of 0.6223, as per https://www.academia.edu/16642632/F06_SI_PSYCHROMETRICS
}

double Algorun::density_upstream(double W, double p1, double T) // rho
{
    /*
    * Calculates the density of (humid) air upstream of the orifice plate (kg/m3).
    *
    * Arguments:
    * ~~~~~~~~~~~
    * W: double
    *  The relative humidity of air upstream of the orifice plate.
    * p1: double
    *  The absolute air pressure upstream of the orifice plate (Pa).
    * T: double
    *  Absolute temperature upstream of the orifice plate (K).
    *
    * Returns:
    * ~~~~~~~~~~~
    * double:
    *  The density of (humid) air upstream of the orifice plate (kg/m3).
    */
    return (double) (1.0 + W)/(RA + W*RV)*p1/T;
}

double Algorun::Reynold_number(double v, double D, double nu) // Re_D
{
    /*
    * Calculates the Raynolds number in the pipe.
    *
    * Arguments:
    * ~~~~~~~~~~~
    * v: double
    *  The average flow velocity in pipe (m/s).
    * D: double
    *  The inner diameter of the pipe (m).
    * nu: double
    *  The kinematic viscosity of air (m2/s).
    *
    * Returns:
    * ~~~~~~~~~~~
    * double:
    *  The Raynolds number in the pipe.
    */
    return (double) v * D / nu;
}

double Algorun::kinematic_viscosity(double T) // nu
{
    /*
    * Calculates the kinematic viscosity of air (m2/s).
    *
    * Arguments:
    * ~~~~~~~~~~~
    * T: double
    *  Absolute temperature upstream of the orifice plate (K).
    *
    * Returns:
    * ~~~~~~~~~~~
    * double:
    *  The kinematic viscosity of air (m2/s).
    */
    return (double) 9.95182e-11*pown(T, 2) + 3.55322e-8*T - 3.60844e-6; // why this instead of Sutherland's Law for Dynamic Viscosity divided by the density? how was it computed?
}

double Algorun::avg_flow_velocity(double q_m, double rho, double D) // v
{
    /*
    * Calculates the average flow velocity in pipe (m/s).
    *
    * Arguments:
    * ~~~~~~~~~~~
    * qm: double
    *  The mass flow rate. (kg/s)
    * rho: double
    *  The fluid density of (humid) air upstream of the orifice plate (kg/m3).
    * D: double
    *  The inner diameter of the pipe (m).
    *
    * Returns:
    * ~~~~~~~~~~~
    * double:
    *  The average flow velocity in pipe (m/s).
    */
    return (double) 4 * q_m / PI / rho / pown(D, 2);
}

double Algorun::get_q_m(){return this->q_m;}
double Algorun::get_q_V(){return this->q_V;}
double Algorun::get_v(){return this->v;}
double Algorun::get_pvs(){return this->pvs;}
double Algorun::get_W(){return this->W;}
double Algorun::get_rho(){return this->rho;}
double Algorun::get_nu(){return this->nu;}
double Algorun::get_eps(){return this->eps;}
double Algorun::get_C(){return this->C;}
double Algorun::get_Re_D(){return this->Re_D;}
double Algorun::get_alpha(){return this->alpha;}
int Algorun::get_iters(){return this->iters;}
void Algorun::set_D(double D){this->D = D;}
void Algorun::set_beta(double beta){this->beta = beta;}
void Algorun::set_tappings(unsigned int tappings){this->tappings = tappings;}
void Algorun::set_T(double T){this->T = T;}
void Algorun::set_p(double p){this->p = p;}
void Algorun::set_phi(double phi){this->phi = phi;}
void Algorun::set_Dp(double Dp){this->Dp = Dp;}

int Algorun::run()
{
    this->pvs   = saturated_vapor_pressure(T);
    this->W     = humidity_ratio(phi, pvs, p);
    this->rho   = density_upstream(W, p, T);
    this->nu    = kinematic_viscosity(T);
    this->eps   = expansibility_factor(p, Dp, beta, KAPPA_AIR);
    this->alpha = flow_coefficient(0.61, beta);
    this->q_m   = mass_flow_rate(alpha, eps, beta, D, Dp, rho);
    this->v     = avg_flow_velocity(q_m, rho, D);
    this->Re_D  = Reynold_number(v, D, nu);

    double dif = 1.0;
    for (this->iters = 1; this->iters <= NMAX_ITER; this->iters++)
    {
        this->alphaprev = alpha;
        this->C         = discharge_coefficient(D, beta, tappings, Re_D);
        this->alpha     = flow_coefficient(C, beta);
        this->q_m       = mass_flow_rate(alpha, eps, beta, D, Dp, rho);
        this->v         = avg_flow_velocity(q_m, rho, D);
        this->Re_D      = Reynold_number(v, D, nu);
        dif = fabs(alpha - alphaprev)/alpha;
        if (!(dif > TOL))
            return 0;
    }
    return 1;
}

void Algorun::afterrun()
{
    this->q_V = q_m / rho;
}

double Algorun::uncertainty()
{
    return sqrt(pown(Uprime_eps(p, Dp, KAPPA_AIR), 2) +
                pown(Uprime_C(D, beta, Re_D), 2) +
                pown(2 * pown(beta, 4) / (1 - pown(beta, 4)), 2) * pown(0.02, 2) +
                pown(2 / (1 - pown(beta, 4)), 2) * pown(0.022, 2) +
                pown(0.011, 2)/4 + pown(0.001, 2)/4
                ) * q_m;
}

Algorun::~Algorun(){}
