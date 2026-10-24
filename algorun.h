#ifndef ALGORUN_H
#define ALGORUN_H

class Algorun
{
    // Isentropic exponents
    static constexpr double KAPPA_AIR      = 1.4;

    // Constants (J/kg.K)
    static constexpr double RA             = 287.2; // Specific gas constant for dry air
    static constexpr double RV             = 461.5; // Specific gas constant for water vapor

    // Types of pressure tappings
    static constexpr unsigned int NO_TAPPINGS      = 0;
    static constexpr unsigned int CORNER_TAPPINGS  = 1;
    static constexpr unsigned int RADIUS_TAPPINGS  = 2;
    static constexpr unsigned int FLANGE_TAPPINGS  = 3;

    // Maximum number of iterations for the calculation of the flow coefficient
    static constexpr unsigned int NMAX_ITER        = 1000;

    // Max allowable relative difference between the flow coefficient at the
    // current iteration and that at the previous iteration.
    static constexpr double TOL            = 1e-8;
    static constexpr double PI             = 3.141592653589793238462643383279502884L;

    double D;
    double beta;
    unsigned int tappings;
    double T;
    double p;
    double phi;
    double Dp;

    double q_m, q_V, v, pvs, W, rho, nu, eps, C, Re_D, alpha, alphaprev;
    int iters;


public:
    Algorun(double D, double beta, unsigned int tappings, double T, double p, double phi, double Dp);
    double get_q_m();
    double get_q_V();
    double get_v();
    double get_pvs();
    double get_W();
    double get_rho();
    double get_nu();
    double get_eps();
    double get_C();
    double get_Re_D();
    double get_alpha();
    bool check_limits_of_use();
    bool check_expansibility_validity(bool ISO = true);
    int get_iters();
    void set_D(double D);
    void set_beta(double beta);
    void set_tappings(unsigned int tappings);
    void set_T(double T);
    void set_p(double p);
    void set_phi(double phi);
    void set_Dp(double Dp);
    ~Algorun();
    int run();
    void afterrun();
    double uncertainty();

private:
    double discharge_coefficient(double D, double beta, unsigned int tappings, double Re_D); // Checks the tables
    double flow_coefficient(double discharge_coefficient, double beta);
    double expansibility_factor(double p1, double Dp, double beta, double kappa, bool ISO = true); // only ISO=true checks table A12
    double mass_flow_rate(double alpha, double eps, double beta, double D, double Dp, double rho); // q_m
    double saturated_vapor_pressure(double T, unsigned int algorithm = 0); // pvs
    double density_upstream(double W, double p1, double T); // rho
    double Reynold_number(double v, double D, double nu); // Re_D
    double kinematic_viscosity(double T); // nu
    double humidity_ratio(double phi, double pvs, double p1); // W [X]
    double avg_flow_velocity(double q_m, double rho, double D); // v
    double Uprime_C(double D, double beta, double Re_D);
    double Uprime_eps(double p1, double Dp, double kappa, bool ISO = true);
};

#endif // ALGORUN_H
