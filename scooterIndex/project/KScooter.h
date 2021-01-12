#pragma once
#include "Scooter.h"
class KScooter :
    public Scooter
{
public:
    KScooter();
    KScooter(const string& a_manufacturer, const string& a_model, const string& a_serialnumber, int a_year, double a_maxLoad, bool a_forProfessionals);
    KScooter(const KScooter& a_kscooter) = delete;
    ~KScooter();

    void setForProfessionals(bool a_forProfessionals);

    bool getForProfessionals() const;

    void askInfo() override;
    void printScooter() const override;

private:
    bool m_forProfessionals;
};

