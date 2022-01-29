#pragma once

#include "doctor.h"
#include "staff.h"

class Administration
{
public:
    Administration(int i=0);
    Staff s;
    Doctor d;
    void deleteDoctor(char del_name[50]);
    void edit_doctor();
    void deleteStaff(char del_name[50]);
    void edit_staff();
};
