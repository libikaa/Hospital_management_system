#pragma once

#include "doctor.h"
#include "Staff.h"
#include <string>

class Administration
{
public:
    explicit Administration(int i=0);
    Staff s;
    Doctor d;
    void deleteDoctor(string del_name);
    void edit_doctor();
    void deleteStaff(string del_name);
    void edit_staff();
};
