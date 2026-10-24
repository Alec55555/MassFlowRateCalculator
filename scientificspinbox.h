#ifndef SCIENTIFICSPINBOX_H
#define SCIENTIFICSPINBOX_H

#include <QDoubleSpinBox>

class ScientificSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit ScientificSpinBox(QWidget *parent = nullptr);
    ~ScientificSpinBox() override = default;

protected:
    QValidator::State validate(QString &input, int &pos) const override;
    double valueFromText(const QString &text) const override;
    QString textFromValue(double value) const override;

private:
    QDoubleValidator *m_validator;
};

#endif // SCIENTIFICSPINBOX_H
