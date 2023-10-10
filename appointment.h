#pragma once

#include "doctor.h"
#include <string>
class Appointment
{
private:
    char slot;
    string Doctorname;
    Doctor d;
public:
    friend class Patient;
    explicit Appointment(int i=0);
    void get_data();
    void checkAvailability(string Doc_name,char sl);
    void Disp_allap();
};
