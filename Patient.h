#pragma once

#include "drug.h"

class Patient
{
private:
    char pname[50];
    int id;
    int phonenumber;
    char address[50];
    int age;
    char sex[50];
    char drug[50];
    char symp[50];
    int dose;
    Drug k;
public:
    Patient(int i=0);
    int getpat_id()
    {
        return id;
    }
    void getPatientdetails();
    void add_patient();
    void makePayment(int p_id);
    void receiveDrugs(int p_id);
    void checkup(int p_id);
    void bookAppointment();
    void check();
    void getDrugdet();
    void Disp_allp();
    void Disp_pat(int p_id);
};
