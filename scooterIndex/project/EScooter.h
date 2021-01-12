#pragma once
#include "Scooter.h"
class EScooter :
    public Scooter
{
public:
    EScooter();
    EScooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad, double a_maxSpeed, double a_generalRange);
    EScooter(const EScooter& a_escooter) = delete;
    ~EScooter();
    

    void setMaxSpeed(int a_maxSpeed);
    void setGeneralRange(int a_generalRange);

    double getMaxSpeed() const;
    double getGeneralRange() const;

    void askInfo() override;
    void printScooter() const override;

private:
    double m_maxSpeed;
    double m_generalRange;

    
};

