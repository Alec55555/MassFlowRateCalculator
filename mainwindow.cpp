#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "algorun.h"
// #include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // auto *validator = new QDoubleValidator(this);
    // validator->setNotation(QDoubleValidator::ScientificNotation);
    // ui->lineEdit->setValidator(validator);
}

void MainWindow::inc(){this->nrofline+=1;}

void MainWindow::on_computeButton_clicked()
{
    ui->computeButton->setDisabled(true);
    ui->computeButton->setText("Please wait.");
    ui->computeButton->repaint();
    // QCoreApplication::processEvents();

    int runreturn;
    Algorun algorithm(ui->I_D->value(),
                      ui->I_beta->value(),
                      ui->I_tappings->currentIndex() + 1,
                      ui->I_T->value(),
                      ui->I_p->value(),
                      ui->I_phi->value()/100,
                      ui->I_Dp->value());
    runreturn = algorithm.run();
    algorithm.afterrun();

    if (runreturn == 0)
        ui->ConsoleOutput->appendPlainText(QString::number(nrofline) + QString(".\tThe program finised in ") + QString::number(algorithm.get_iters()) + QString(" iterations.") );
    else
        ui->ConsoleOutput->appendPlainText(QString::number(nrofline) + QString(".\tThe program ran out of iterations."));
    this->inc();

    ui->O_Qm->setValue(algorithm.get_q_m());
    ui->O_Qv->setValue(algorithm.get_q_V());
    ui->O_C->setValue(algorithm.get_C());
    ui->O_ReD->setValue(algorithm.get_Re_D());
    ui->O_W->setValue(algorithm.get_W());
    ui->O_alpha->setValue(algorithm.get_alpha());
    ui->O_eps->setValue(algorithm.get_eps());
    ui->O_nu->setValue(algorithm.get_nu());
    ui->O_pvs->setValue(algorithm.get_pvs());
    ui->O_v->setValue(algorithm.get_v());
    ui->O_rho->setValue(algorithm.get_rho());


    if (ui->CI_Switch->isChecked())
    {
        ui->O_QmCI->setValue(algorithm.uncertainty());
    }
    else
        ui->O_QmCI->setValue(0);

    if (!algorithm.check_limits_of_use()){
        if (ui->Warning_disable->isChecked())
            ui->Warning_Screen->appendPlainText(QString::number(nrofline - 1) + QString(". suppressed.") );
        else
            ui->ConsoleOutput->appendPlainText(QString("\t\tWarning!\n\t\tThe input values are outside of the limits of use of ISO5167-2 2022"));
        ui->O_QmCI->setDisabled(true);
        ui->CI_Switch->setChecked(false);
    }
    if (!algorithm.check_expansibility_validity()){
        if (ui->Warning_disable->isChecked())
            ui->Warning_Screen->appendPlainText(QString::number(nrofline - 1) + QString(". suppressed.") );
        else
            ui->ConsoleOutput->appendPlainText(QString("\t\tWarning. \n\t\tThe formula for expansibility factor is not aplicable, as per ISO5167-2 2022"));
        ui->O_QmCI->setDisabled(true);
        ui->CI_Switch->setChecked(false);
    }

    ui->computeButton->setDisabled(false);
    ui->computeButton->setText("Compute");
    ui->computeButton->repaint();
}

void MainWindow::on_CI_Switch_clicked()
{
    ui->O_QmCI->setDisabled(!(ui->CI_Switch->isChecked()));
}

void MainWindow::on_ClearAll_clicked()
{
    ui->ConsoleOutput->clear();
    ui->Warning_Screen->clear();
    ui->O_Qm->setValue(0);
    ui->O_Qv->setValue(0);
    ui->O_C->setValue(0);
    ui->O_ReD->setValue(0);
    ui->O_W->setValue(0);
    ui->O_alpha->setValue(0);
    ui->O_eps->setValue(0);
    ui->O_nu->setValue(0);
    ui->O_pvs->setValue(0);
    ui->O_v->setValue(0);
    ui->O_rho->setValue(0);
    ui->O_QmCI->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
