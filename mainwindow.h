#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    unsigned int nrofline = 1;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void inc();
    ~MainWindow() override;

private slots:
    void on_computeButton_clicked();
    void on_CI_Switch_clicked();
    void on_ClearAll_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
