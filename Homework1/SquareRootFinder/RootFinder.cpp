#include "RootFinder.h"
#include "ui_RootFinder.h"
#include <QtMath>
#include <QDebug>

RootFinder::RootFinder(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootFinder)
{
    ui->setupUi(this);

    LineEditArr[MultiplierA] = ui->lineEditMultiplierOne;
    LineEditArr[MultiplierB] = ui->lineEditMultiplierTwo;
    LineEditArr[MultiplierC] = ui->lineEditMultiplierThree;

    connect(ui->pushButtonCalculate,&QPushButton::clicked,this, &RootFinder::CalculateResult);
}



RootFinder::~RootFinder()
{
    delete ui;
}

bool RootFinder::CalculateResult()
{
    int MultiplierArr[3] = {0, 0, 0};
    int ValueOne;
    int ValueTwo;
    if(GetMultipliers(MultiplierArr) == false)
    {
        PrintResult(nullptr, nullptr, false);
        return false;
    }
    int Discriminant = (MultiplierArr[MultiplierB]*MultiplierArr[MultiplierB]) - 4 * MultiplierArr[MultiplierA] * MultiplierArr[MultiplierC];
    if(Discriminant < 0)
        PrintResult();
    else if(Discriminant == 0)
    {
        ValueOne = 0 - (MultiplierArr[MultiplierB] / (MultiplierArr[MultiplierA] * 2));
        PrintResult(&ValueOne);
    }
    else if(Discriminant > 0)
    {
        ValueOne =  (0 - MultiplierArr[MultiplierB] + static_cast<int>(qSqrt(Discriminant))) / 2 * MultiplierArr[MultiplierA];
        ValueTwo =  (0 - MultiplierArr[MultiplierB] - static_cast<int>(qSqrt(Discriminant))) / 2 * MultiplierArr[MultiplierA];
        PrintResult(&ValueOne, &ValueTwo);
    }
    return true;
}

bool RootFinder::GetMultipliers(int *_MultiplierArr)
{
    bool ReadResult = true;
    for(int i = 0; i < MultiplierNumber; i ++)
    {
        _MultiplierArr[i] = LineEditArr[i]->text().toInt(&ReadResult, 10);
        if(ReadResult == false)
            return false;
    }
    return true;
}

void RootFinder::PrintResult(int *_FirstRoot, int *_SecondRoot, bool _MultipliersFound)
{
    if(_MultipliersFound == false)
        ui->lineEdit_2->setText(ErrorMsg);
    else if(_FirstRoot != nullptr && _SecondRoot != nullptr)
        ui->lineEdit_2->setText(QString(ResultMsg).arg(*_FirstRoot).arg(*_SecondRoot));
    else if(_FirstRoot == nullptr && _SecondRoot == nullptr)
        ui->lineEdit_2->setText(QString(ResultMsg).arg(EmptyRootMsg).arg(EmptyRootMsg));
    else if(_FirstRoot != nullptr && _SecondRoot == nullptr)
        ui->lineEdit_2->setText(QString(ResultMsg).arg(*_FirstRoot).arg(EmptyRootMsg));
    else if(_FirstRoot == nullptr && _SecondRoot != nullptr)
        ui->lineEdit_2->setText(QString(ResultMsg).arg(EmptyRootMsg).arg(*_SecondRoot));
}
