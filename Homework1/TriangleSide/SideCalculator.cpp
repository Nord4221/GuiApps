#include "SideCalculator.h"
#include "ui_SideCalculator.h"
#include "QtMath"

SideCalculator::SideCalculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SideCalculator)
{
    ui->setupUi(this);

    LineEditArr[SideSizeFrst] = ui->lineEditSideOne;
    LineEditArr[SideSizeScnd] = ui->lineEditSideTwo;
    LineEditArr[AngleSize   ] = ui->lineEditAngleSize;

    connect(ui->pushButtonCaluclate,&QPushButton::clicked,this, &SideCalculator::CalculateResult);

    connect(ui->radioButtonDegrees,&QRadioButton::clicked,this, &SideCalculator::SwitchMode);
    connect(ui->radioButtonRadians,&QRadioButton::clicked,this, &SideCalculator::SwitchMode);
}

SideCalculator::~SideCalculator()
{
    delete ui;
}

bool SideCalculator::CalculateResult()
{
    qreal SizeParameters[3] = {0.0, 0.0, 0.0};
    qreal ThirdSideLen;
    if(GetSizes(SizeParameters) == false)
    {
        PrintResult(nullptr, false);
        return false;
    }
    if(IsDegreeMode == true)
        SizeParameters[AngleSize] = qDegreesToRadians(SizeParameters[AngleSize]);
    ThirdSideLen = qSqrt(
                            qPow(SizeParameters[SideSizeFrst], 2) + qPow(SizeParameters[SideSizeScnd], 2) -
                            2*SizeParameters[SideSizeFrst]*SizeParameters[SideSizeScnd]*qCos(SizeParameters[AngleSize])
                        );
    PrintResult(&ThirdSideLen);
    return true;
}

bool SideCalculator::GetSizes(qreal *_MultiplierArr)
{
    bool ReadResult = true;
    for(int i = 0; i < SizeParameterAmount; i ++)
    {
        _MultiplierArr[i] = LineEditArr[i]->text().toDouble(&ReadResult);
        if(ReadResult == false)
            return false;
    }
    return true;
}

void SideCalculator::PrintResult(qreal *_SideLength, bool _CorrectValuesFound)
{
    if(_CorrectValuesFound == false)
        ui->lineEditResult->setText(ErrorMsg);
    else if(_SideLength != nullptr)
        ui->lineEditResult->setText(QString(ResultMsg).arg(*_SideLength));
    else if(_SideLength == nullptr )
        ui->lineEditResult->setText(QString(EmptyRootMsg));
}

void SideCalculator::SwitchMode()
{
    IsDegreeMode == true ? IsDegreeMode = false : IsDegreeMode = true;
}
