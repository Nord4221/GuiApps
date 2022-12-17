#ifndef SIDECALCULATOR_H
#define SIDECALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class SideCalculator;
}

class SideCalculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit SideCalculator(QWidget *parent = nullptr);
    ~SideCalculator();
    bool    CalculateResult();
    bool    GetSizes(qreal *_MultiplierArr);
    void    PrintResult(qreal *_SideLength = nullptr, bool _CorrectValuesFound = true);
private:
    QLineEdit *LineEditArr[3];
    Ui::SideCalculator *ui;
    void            SwitchMode();
    bool            IsDegreeMode = true;
    const int       SizeParameterAmount = 3;
    const QString   ErrorMsg  = "Size parameters Incorrect";
    const QString   ResultMsg = "Third side length = %1";
    const QString   EmptyRootMsg = " no value ";
    const int       SideSizeFrst = 0;
    const int       SideSizeScnd = 1;
    const int        AngleSize    = 2;
};

#endif // SIDECALCULATOR_H
