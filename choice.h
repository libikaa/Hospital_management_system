#pragma once

#include "Staff.h"
#include "choice.h"
#include "doctor.h"
#include "Patient.h"
#include "Administration.h"
#include "appointment.h"
#include "drug.h"
class Choice
{
public:
    void doc_menu();
    void pat_menu();
    void admin_menu();
    void doc_opt(int choice);
    void pat_opt(int choice);
    void admin_opt(int choice);
};
