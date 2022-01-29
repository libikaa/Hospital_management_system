#pragma once

#include "doctor.h"
class Appointment
{
private:
    char slot;
    char Doctorname[50];
    Doctor d;
public:
    friend class Patient;
    Appointment(int i=0);
    void get_data();
    void checkAvailability(char Doc_name[50],char sl);
    void Disp_allap();
};
