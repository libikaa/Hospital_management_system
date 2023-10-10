#pragma once

#include "drug.h"
#include<string>

class Patient
{
private:
    string pname;
    int id;
    int phonenumber;
    string address;
    int age;
    string sex;
    string drug;
    string symp;
    int dose;
    Drug k;
public:
    explicit Patient(int i=0);
    int getpat_id() const
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
