#ifndef ROOTFINDER_H
#define ROOTFINDER_H

#include <QMainWindow>
#include <QLineEdit>
namespace Ui {
class RootFinder;
}

class RootFinder : public QMainWindow
{
    Q_OBJECT

public:
    explicit RootFinder(QWidget *parent = nullptr);
    ~RootFinder();
    bool    CalculateResult();
    bool    GetMultipliers(int *_MultiplierArr);
    void    PrintResult(int *_FirstRoot = nullptr, int *_SecondRoot = nullptr, bool _MultipliersFound = true);
private:
    Ui::RootFinder *ui;
    const int     MultiplierNumber = 3;
    const QString ErrorMsg  = "Multipliers Incorrect";
    const QString ResultMsg = "X1 = %1 , X2 = %2";
    const QString EmptyRootMsg = " no value ";
    const int     MultiplierA = 0;
    const int     MultiplierB = 1;
    const int     MultiplierC = 2;
    QLineEdit *LineEditArr[3];
};

#endif // ROOTFINDER_H
