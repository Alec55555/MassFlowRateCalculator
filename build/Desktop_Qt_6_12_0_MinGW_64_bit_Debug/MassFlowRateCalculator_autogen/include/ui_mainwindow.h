/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *labelO_nu;
    QDoubleSpinBox *I_beta;
    QLabel *labelO_v;
    QLabel *labelO_pvs;
    QDoubleSpinBox *I_T;
    QLabel *label_Dp;
    QSpacerItem *verticalSpacer_4;
    QDoubleSpinBox *O_rho;
    QLabel *labelO_alpha;
    QLabel *label_T;
    QPushButton *computeButton;
    QDoubleSpinBox *O_W;
    QDoubleSpinBox *I_D;
    QDoubleSpinBox *O_Qm;
    QLabel *label_beta;
    QDoubleSpinBox *O_alpha;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *O_ReD;
    QDoubleSpinBox *O_v;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelO_rho;
    QLabel *label_D;
    QDoubleSpinBox *I_p;
    QRadioButton *Warning_disable;
    QLabel *label_phi;
    QCheckBox *CI_Switch;
    QLabel *labelO_ReD;
    QLabel *label_tappings;
    QLabel *labelO_Qv;
    QDoubleSpinBox *O_pvs;
    QLabel *labelO_eps;
    QLabel *labelO_Qm;
    QDoubleSpinBox *O_C;
    QPlainTextEdit *Warning_Screen;
    QSpacerItem *horizontalSpacer_6;
    QDoubleSpinBox *I_Dp;
    QComboBox *I_tappings;
    QDoubleSpinBox *O_eps;
    QLabel *label_p;
    QPushButton *ClearAll;
    QDoubleSpinBox *I_phi;
    QDoubleSpinBox *O_QmCI;
    QDoubleSpinBox *O_nu;
    QLabel *labelO_W;
    QDoubleSpinBox *O_Qv;
    QPlainTextEdit *ConsoleOutput;
    QLabel *labelO_C;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1385, 576);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        labelO_nu = new QLabel(centralwidget);
        labelO_nu->setObjectName("labelO_nu");
        labelO_nu->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_nu, 18, 4, 1, 1);

        I_beta = new QDoubleSpinBox(centralwidget);
        I_beta->setObjectName("I_beta");
        I_beta->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_beta->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        I_beta->setDecimals(5);
        I_beta->setMinimum(0.100000000000000);
        I_beta->setMaximum(0.750000000000000);
        I_beta->setSingleStep(0.500000000000000);
        I_beta->setValue(0.271400000000000);

        gridLayout->addWidget(I_beta, 2, 2, 1, 1);

        labelO_v = new QLabel(centralwidget);
        labelO_v->setObjectName("labelO_v");
        labelO_v->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_v, 19, 1, 1, 1);

        labelO_pvs = new QLabel(centralwidget);
        labelO_pvs->setObjectName("labelO_pvs");
        labelO_pvs->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_pvs, 20, 1, 1, 1);

        I_T = new QDoubleSpinBox(centralwidget);
        I_T->setObjectName("I_T");
        I_T->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_T->setDecimals(2);
        I_T->setMaximum(10273.149999999999636);
        I_T->setValue(293.149999999999977);

        gridLayout->addWidget(I_T, 0, 5, 1, 1);

        label_Dp = new QLabel(centralwidget);
        label_Dp->setObjectName("label_Dp");
        label_Dp->setAutoFillBackground(true);

        gridLayout->addWidget(label_Dp, 2, 7, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 0, 3, 4, 1);

        O_rho = new QDoubleSpinBox(centralwidget);
        O_rho->setObjectName("O_rho");
        O_rho->setEnabled(true);
        O_rho->setAcceptDrops(false);
        O_rho->setAutoFillBackground(false);
        O_rho->setWrapping(false);
        O_rho->setFrame(false);
        O_rho->setReadOnly(true);
        O_rho->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_rho->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_rho->setKeyboardTracking(false);
        O_rho->setProperty("showGroupSeparator", QVariant(false));
        O_rho->setSuffix(QString::fromUtf8(" kg/m3"));
        O_rho->setDecimals(8);
        O_rho->setMaximum(100000000000000000000.000000000000000);
        O_rho->setSingleStep(0.500000000000000);
        O_rho->setValue(0.000000000000000);

        gridLayout->addWidget(O_rho, 22, 2, 1, 1);

        labelO_alpha = new QLabel(centralwidget);
        labelO_alpha->setObjectName("labelO_alpha");
        labelO_alpha->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_alpha, 19, 4, 1, 1);

        label_T = new QLabel(centralwidget);
        label_T->setObjectName("label_T");

        gridLayout->addWidget(label_T, 0, 4, 1, 1);

        computeButton = new QPushButton(centralwidget);
        computeButton->setObjectName("computeButton");
        computeButton->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(computeButton->sizePolicy().hasHeightForWidth());
        computeButton->setSizePolicy(sizePolicy);
        computeButton->setMinimumSize(QSize(120, 120));
        computeButton->setMaximumSize(QSize(140, 120));
        QFont font;
        font.setPointSize(14);
        font.setUnderline(false);
        computeButton->setFont(font);
        computeButton->setCheckable(false);
        computeButton->setChecked(false);

        gridLayout->addWidget(computeButton, 5, 7, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        O_W = new QDoubleSpinBox(centralwidget);
        O_W->setObjectName("O_W");
        O_W->setEnabled(true);
        O_W->setAcceptDrops(false);
        O_W->setAutoFillBackground(false);
        O_W->setWrapping(false);
        O_W->setFrame(false);
        O_W->setReadOnly(true);
        O_W->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_W->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_W->setKeyboardTracking(false);
        O_W->setProperty("showGroupSeparator", QVariant(false));
        O_W->setSuffix(QString::fromUtf8(" kg/kg"));
        O_W->setDecimals(8);
        O_W->setMaximum(100000000000000000000.000000000000000);
        O_W->setSingleStep(0.500000000000000);
        O_W->setValue(0.000000000000000);

        gridLayout->addWidget(O_W, 21, 2, 1, 1);

        I_D = new QDoubleSpinBox(centralwidget);
        I_D->setObjectName("I_D");
        I_D->setAutoFillBackground(true);
        I_D->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_D->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        I_D->setSuffix(QString::fromUtf8(" m"));
        I_D->setDecimals(5);
        I_D->setMaximum(100000000000000000000.000000000000000);
        I_D->setSingleStep(0.500000000000000);
        I_D->setStepType(QAbstractSpinBox::StepType::DefaultStepType);
        I_D->setValue(0.049000000000000);

        gridLayout->addWidget(I_D, 0, 2, 1, 1);

        O_Qm = new QDoubleSpinBox(centralwidget);
        O_Qm->setObjectName("O_Qm");
        O_Qm->setEnabled(true);
        O_Qm->setAcceptDrops(false);
        O_Qm->setAutoFillBackground(false);
        O_Qm->setWrapping(false);
        O_Qm->setFrame(false);
        O_Qm->setReadOnly(true);
        O_Qm->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_Qm->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_Qm->setKeyboardTracking(false);
        O_Qm->setProperty("showGroupSeparator", QVariant(false));
        O_Qm->setSuffix(QString::fromUtf8(" kg/s"));
        O_Qm->setDecimals(8);
        O_Qm->setMaximum(100000000000000000000.000000000000000);
        O_Qm->setSingleStep(0.500000000000000);
        O_Qm->setValue(0.000000000000000);

        gridLayout->addWidget(O_Qm, 17, 2, 1, 1);

        label_beta = new QLabel(centralwidget);
        label_beta->setObjectName("label_beta");
        label_beta->setAutoFillBackground(false);

        gridLayout->addWidget(label_beta, 2, 1, 1, 1);

        O_alpha = new QDoubleSpinBox(centralwidget);
        O_alpha->setObjectName("O_alpha");
        O_alpha->setEnabled(true);
        O_alpha->setAcceptDrops(false);
        O_alpha->setAutoFillBackground(false);
        O_alpha->setWrapping(false);
        O_alpha->setFrame(false);
        O_alpha->setReadOnly(true);
        O_alpha->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_alpha->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_alpha->setKeyboardTracking(false);
        O_alpha->setProperty("showGroupSeparator", QVariant(false));
        O_alpha->setSuffix(QString::fromUtf8(""));
        O_alpha->setDecimals(8);
        O_alpha->setMaximum(100000000000000000000.000000000000000);
        O_alpha->setSingleStep(0.500000000000000);
        O_alpha->setValue(0.000000000000000);

        gridLayout->addWidget(O_alpha, 19, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 16, 0, 1, 1);

        O_ReD = new QDoubleSpinBox(centralwidget);
        O_ReD->setObjectName("O_ReD");
        O_ReD->setEnabled(true);
        O_ReD->setAcceptDrops(false);
        O_ReD->setAutoFillBackground(false);
        O_ReD->setWrapping(false);
        O_ReD->setFrame(false);
        O_ReD->setReadOnly(true);
        O_ReD->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_ReD->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_ReD->setKeyboardTracking(false);
        O_ReD->setProperty("showGroupSeparator", QVariant(false));
        O_ReD->setSuffix(QString::fromUtf8(""));
        O_ReD->setDecimals(8);
        O_ReD->setMaximum(100000000000000000000.000000000000000);
        O_ReD->setSingleStep(0.500000000000000);
        O_ReD->setValue(0.000000000000000);

        gridLayout->addWidget(O_ReD, 22, 5, 1, 1);

        O_v = new QDoubleSpinBox(centralwidget);
        O_v->setObjectName("O_v");
        O_v->setEnabled(true);
        O_v->setAcceptDrops(false);
        O_v->setAutoFillBackground(false);
        O_v->setWrapping(false);
        O_v->setFrame(false);
        O_v->setReadOnly(true);
        O_v->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_v->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_v->setKeyboardTracking(false);
        O_v->setProperty("showGroupSeparator", QVariant(false));
        O_v->setSuffix(QString::fromUtf8(" m/s"));
        O_v->setDecimals(8);
        O_v->setMaximum(100000000000000000000.000000000000000);
        O_v->setSingleStep(0.500000000000000);
        O_v->setValue(0.000000000000000);

        gridLayout->addWidget(O_v, 19, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 6, 4, 1);

        labelO_rho = new QLabel(centralwidget);
        labelO_rho->setObjectName("labelO_rho");
        labelO_rho->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_rho, 22, 0, 1, 2);

        label_D = new QLabel(centralwidget);
        label_D->setObjectName("label_D");
        label_D->setAutoFillBackground(false);

        gridLayout->addWidget(label_D, 0, 1, 1, 1);

        I_p = new QDoubleSpinBox(centralwidget);
        I_p->setObjectName("I_p");
        I_p->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_p->setDecimals(2);
        I_p->setMaximum(9999999999.149999618530273);
        I_p->setValue(102700.000000000000000);

        gridLayout->addWidget(I_p, 2, 5, 1, 1);

        Warning_disable = new QRadioButton(centralwidget);
        Warning_disable->setObjectName("Warning_disable");
        Warning_disable->setChecked(true);

        gridLayout->addWidget(Warning_disable, 5, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        label_phi = new QLabel(centralwidget);
        label_phi->setObjectName("label_phi");
        label_phi->setAutoFillBackground(true);

        gridLayout->addWidget(label_phi, 3, 4, 1, 1);

        CI_Switch = new QCheckBox(centralwidget);
        CI_Switch->setObjectName("CI_Switch");

        gridLayout->addWidget(CI_Switch, 17, 5, 1, 1);

        labelO_ReD = new QLabel(centralwidget);
        labelO_ReD->setObjectName("labelO_ReD");
        labelO_ReD->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_ReD, 22, 4, 1, 1);

        label_tappings = new QLabel(centralwidget);
        label_tappings->setObjectName("label_tappings");

        gridLayout->addWidget(label_tappings, 3, 1, 1, 1);

        labelO_Qv = new QLabel(centralwidget);
        labelO_Qv->setObjectName("labelO_Qv");
        labelO_Qv->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_Qv, 18, 1, 1, 1);

        O_pvs = new QDoubleSpinBox(centralwidget);
        O_pvs->setObjectName("O_pvs");
        O_pvs->setEnabled(true);
        O_pvs->setAcceptDrops(false);
        O_pvs->setAutoFillBackground(false);
        O_pvs->setWrapping(false);
        O_pvs->setFrame(false);
        O_pvs->setReadOnly(true);
        O_pvs->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_pvs->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_pvs->setKeyboardTracking(false);
        O_pvs->setProperty("showGroupSeparator", QVariant(false));
        O_pvs->setSuffix(QString::fromUtf8(" Pa"));
        O_pvs->setDecimals(8);
        O_pvs->setMaximum(100000000000000000000.000000000000000);
        O_pvs->setSingleStep(0.500000000000000);
        O_pvs->setValue(0.000000000000000);

        gridLayout->addWidget(O_pvs, 20, 2, 1, 1);

        labelO_eps = new QLabel(centralwidget);
        labelO_eps->setObjectName("labelO_eps");
        labelO_eps->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_eps, 20, 4, 1, 1);

        labelO_Qm = new QLabel(centralwidget);
        labelO_Qm->setObjectName("labelO_Qm");
        labelO_Qm->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_Qm, 17, 1, 1, 1);

        O_C = new QDoubleSpinBox(centralwidget);
        O_C->setObjectName("O_C");
        O_C->setEnabled(true);
        O_C->setAcceptDrops(false);
        O_C->setAutoFillBackground(false);
        O_C->setWrapping(false);
        O_C->setFrame(false);
        O_C->setReadOnly(true);
        O_C->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_C->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_C->setKeyboardTracking(false);
        O_C->setProperty("showGroupSeparator", QVariant(false));
        O_C->setSuffix(QString::fromUtf8(""));
        O_C->setDecimals(8);
        O_C->setMaximum(100000000000000000000.000000000000000);
        O_C->setSingleStep(0.500000000000000);
        O_C->setValue(0.000000000000000);

        gridLayout->addWidget(O_C, 21, 5, 1, 1);

        Warning_Screen = new QPlainTextEdit(centralwidget);
        Warning_Screen->setObjectName("Warning_Screen");
        Warning_Screen->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(5);
        Warning_Screen->setFont(font1);
        Warning_Screen->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        Warning_Screen->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        Warning_Screen->setLineWrapMode(QPlainTextEdit::LineWrapMode::WidgetWidth);
        Warning_Screen->setReadOnly(true);

        gridLayout->addWidget(Warning_Screen, 12, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 0, 1, 1);

        I_Dp = new QDoubleSpinBox(centralwidget);
        I_Dp->setObjectName("I_Dp");
        I_Dp->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_Dp->setDecimals(4);
        I_Dp->setMaximum(151325.000000000000000);
        I_Dp->setValue(235.360000000000014);

        gridLayout->addWidget(I_Dp, 2, 9, 1, 1);

        I_tappings = new QComboBox(centralwidget);
        I_tappings->addItem(QString());
        I_tappings->addItem(QString());
        I_tappings->addItem(QString());
        I_tappings->setObjectName("I_tappings");

        gridLayout->addWidget(I_tappings, 3, 2, 1, 1);

        O_eps = new QDoubleSpinBox(centralwidget);
        O_eps->setObjectName("O_eps");
        O_eps->setEnabled(true);
        O_eps->setAcceptDrops(false);
        O_eps->setAutoFillBackground(false);
        O_eps->setWrapping(false);
        O_eps->setFrame(false);
        O_eps->setReadOnly(true);
        O_eps->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_eps->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_eps->setKeyboardTracking(false);
        O_eps->setProperty("showGroupSeparator", QVariant(false));
        O_eps->setSuffix(QString::fromUtf8(""));
        O_eps->setDecimals(8);
        O_eps->setMaximum(100000000000000000000.000000000000000);
        O_eps->setSingleStep(0.500000000000000);
        O_eps->setValue(0.000000000000000);

        gridLayout->addWidget(O_eps, 20, 5, 1, 1);

        label_p = new QLabel(centralwidget);
        label_p->setObjectName("label_p");

        gridLayout->addWidget(label_p, 2, 4, 1, 1);

        ClearAll = new QPushButton(centralwidget);
        ClearAll->setObjectName("ClearAll");
        QFont font2;
        font2.setPointSize(8);
        ClearAll->setFont(font2);

        gridLayout->addWidget(ClearAll, 12, 7, 1, 1, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        I_phi = new QDoubleSpinBox(centralwidget);
        I_phi->setObjectName("I_phi");
        I_phi->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        I_phi->setSuffix(QString::fromUtf8(" %"));
        I_phi->setDecimals(1);
        I_phi->setMaximum(100.000000000000000);
        I_phi->setValue(77.000000000000000);

        gridLayout->addWidget(I_phi, 3, 5, 1, 1);

        O_QmCI = new QDoubleSpinBox(centralwidget);
        O_QmCI->setObjectName("O_QmCI");
        O_QmCI->setEnabled(false);
        O_QmCI->setAcceptDrops(false);
        O_QmCI->setAutoFillBackground(false);
        O_QmCI->setWrapping(false);
        O_QmCI->setFrame(false);
        O_QmCI->setReadOnly(true);
        O_QmCI->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_QmCI->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_QmCI->setKeyboardTracking(false);
        O_QmCI->setProperty("showGroupSeparator", QVariant(false));
        O_QmCI->setSuffix(QString::fromUtf8(" kg/s"));
        O_QmCI->setDecimals(8);
        O_QmCI->setMaximum(100000000000000000000.000000000000000);
        O_QmCI->setSingleStep(0.500000000000000);
        O_QmCI->setValue(0.000000000000000);

        gridLayout->addWidget(O_QmCI, 17, 3, 1, 2);

        O_nu = new QDoubleSpinBox(centralwidget);
        O_nu->setObjectName("O_nu");
        O_nu->setEnabled(true);
        O_nu->setAcceptDrops(false);
        O_nu->setAutoFillBackground(false);
        O_nu->setWrapping(false);
        O_nu->setFrame(false);
        O_nu->setReadOnly(true);
        O_nu->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_nu->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_nu->setKeyboardTracking(false);
        O_nu->setProperty("showGroupSeparator", QVariant(false));
        O_nu->setSuffix(QString::fromUtf8(" m2/s"));
        O_nu->setDecimals(8);
        O_nu->setMaximum(100000000000000000000.000000000000000);
        O_nu->setSingleStep(0.500000000000000);
        O_nu->setValue(0.000000000000000);

        gridLayout->addWidget(O_nu, 18, 5, 1, 1);

        labelO_W = new QLabel(centralwidget);
        labelO_W->setObjectName("labelO_W");
        labelO_W->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_W, 21, 0, 1, 2);

        O_Qv = new QDoubleSpinBox(centralwidget);
        O_Qv->setObjectName("O_Qv");
        O_Qv->setEnabled(true);
        O_Qv->setAcceptDrops(false);
        O_Qv->setAutoFillBackground(false);
        O_Qv->setWrapping(false);
        O_Qv->setFrame(false);
        O_Qv->setReadOnly(true);
        O_Qv->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        O_Qv->setCorrectionMode(QAbstractSpinBox::CorrectionMode::CorrectToNearestValue);
        O_Qv->setKeyboardTracking(false);
        O_Qv->setProperty("showGroupSeparator", QVariant(false));
        O_Qv->setSuffix(QString::fromUtf8(" m3/s"));
        O_Qv->setDecimals(8);
        O_Qv->setMaximum(100000000000000000000.000000000000000);
        O_Qv->setSingleStep(0.500000000000000);
        O_Qv->setValue(0.000000000000000);

        gridLayout->addWidget(O_Qv, 18, 2, 1, 1);

        ConsoleOutput = new QPlainTextEdit(centralwidget);
        ConsoleOutput->setObjectName("ConsoleOutput");
        ConsoleOutput->setAutoFillBackground(true);
        ConsoleOutput->setFrameShape(QFrame::Shape::StyledPanel);
        ConsoleOutput->setFrameShadow(QFrame::Shadow::Sunken);
        ConsoleOutput->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        ConsoleOutput->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        ConsoleOutput->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        ConsoleOutput->setUndoRedoEnabled(false);
        ConsoleOutput->setLineWrapMode(QPlainTextEdit::LineWrapMode::WidgetWidth);
        ConsoleOutput->setReadOnly(true);
        ConsoleOutput->setCenterOnScroll(false);

        gridLayout->addWidget(ConsoleOutput, 5, 1, 8, 5);

        labelO_C = new QLabel(centralwidget);
        labelO_C->setObjectName("labelO_C");
        labelO_C->setAutoFillBackground(true);

        gridLayout->addWidget(labelO_C, 21, 3, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 11, 7, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelO_nu->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Kinematic viscosity of air upstream of the orifice plate:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        I_beta->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>The diameter ratio of the orifice plate.</p><p>It corresponds to beta.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelO_v->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Average flow velocity in pipe:</p></body></html>", nullptr));
        labelO_pvs->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Saturation vapor pressure:</p></body></html>", nullptr));
        I_T->setSuffix(QCoreApplication::translate("MainWindow", " K", nullptr));
        label_Dp->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Pressure drop across the orifice plate in Pascals:</p></body></html>", nullptr));
        labelO_alpha->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Flow coefficient:</p></body></html>", nullptr));
        label_T->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Absolute temperature upstream of the orifice plate in Kelvin:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        computeButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>On press computes everything. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        computeButton->setText(QCoreApplication::translate("MainWindow", "Compute", nullptr));
#if QT_CONFIG(tooltip)
        I_D->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>The inner diameter of the pipe in meters.</p><p>This corresponds to D.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        I_D->setSpecialValueText(QString());
        label_beta->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Diameter ratio of orifice plate:</p></body></html>", nullptr));
        labelO_rho->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Density of (humid) air upstream of the orifice plate:</p></body></html>", nullptr));
        label_D->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Inner diameter of the pipe in meters:</p></body></html>", nullptr));
        I_p->setSuffix(QCoreApplication::translate("MainWindow", " Pa", nullptr));
#if QT_CONFIG(tooltip)
        Warning_disable->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Disables the ISO warnings for a cleaner console output.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Warning_disable->setText(QCoreApplication::translate("MainWindow", "Disable\n"
"Warnings", nullptr));
        label_phi->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Relative humidity of air upstream of the orifice plate:</p></body></html>", nullptr));
        CI_Switch->setText(QCoreApplication::translate("MainWindow", "Compute confidence interval", nullptr));
        labelO_ReD->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Reynolds number in pipe:</p></body></html>", nullptr));
        label_tappings->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Type of pressure tappings:</p></body></html>", nullptr));
        labelO_Qv->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Volume flow rate:</p></body></html>", nullptr));
        labelO_eps->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Expansibility factor:</p></body></html>", nullptr));
        labelO_Qm->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Mass flow rate:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        O_C->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        Warning_Screen->setPlaceholderText(QCoreApplication::translate("MainWindow", "Notifies on error suppressed.", nullptr));
        I_Dp->setSuffix(QCoreApplication::translate("MainWindow", " Pa", nullptr));
        I_tappings->setItemText(0, QCoreApplication::translate("MainWindow", "Corner", nullptr));
        I_tappings->setItemText(1, QCoreApplication::translate("MainWindow", "Radius (D and D/2)", nullptr));
        I_tappings->setItemText(2, QCoreApplication::translate("MainWindow", "Flange", nullptr));

        label_p->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Absolute pressure upstream of the orifice plate in Pascals:</p></body></html>", nullptr));
        ClearAll->setText(QCoreApplication::translate("MainWindow", "Clear console\n"
"and output values", nullptr));
#if QT_CONFIG(tooltip)
        O_QmCI->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        O_QmCI->setPrefix(QCoreApplication::translate("MainWindow", "\302\261 ", nullptr));
        labelO_W->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Humidity ratio of air upstream of the orifice plate:</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        ConsoleOutput->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>A place where relevant information can be found.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ConsoleOutput->setDocumentTitle(QCoreApplication::translate("MainWindow", "ConsoleOutput", nullptr));
        ConsoleOutput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Console output", nullptr));
        labelO_C->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"right\">Discharge coefficient:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
