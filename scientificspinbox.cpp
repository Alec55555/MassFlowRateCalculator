#include "scientificspinbox.h"

#include <QDoubleValidator>
#include <QLocale>

ScientificSpinBox::ScientificSpinBox(QWidget *parent) : QDoubleSpinBox(parent)
{
    setDecimals(6);
    setRange(-1e100, 1e100);
    m_validator = new QDoubleValidator(this);
    m_validator->setNotation(QDoubleValidator::ScientificNotation);
}

QValidator::State ScientificSpinBox::validate(QString &input, int &pos) const
{
    QString cleanText = input;
    if (!prefix().isEmpty() && cleanText.startsWith(prefix())) {
        cleanText.remove(0, prefix().length());
    }
    if (!suffix().isEmpty() && cleanText.endsWith(suffix())) {
        cleanText.chop(suffix().length());
    }
    cleanText = cleanText.trimmed();

    return m_validator->validate(input, pos);
}

double ScientificSpinBox::valueFromText(const QString &text) const
{
    QString cleanText = text;
    if (!prefix().isEmpty() && cleanText.startsWith(prefix())) {
        cleanText.remove(0, prefix().length());
    }
    if (!suffix().isEmpty() && cleanText.endsWith(suffix())) {
        cleanText.chop(suffix().length());
    }
    cleanText = cleanText.trimmed();

    bool ok;
    double val = locale().toDouble(cleanText, &ok);
    return ok ? val : QDoubleSpinBox::valueFromText(text);
}

QString ScientificSpinBox::textFromValue(double value) const
{
    return locale().toString(value, 'e', decimals());
}