#pragma once

#include "Patient.h"
#include<string>

class Doctor
{
private:
    Patient p;
    string name;
    string speciality;
    string qualification;
    int id_doc;
    int salary;
public:
    friend class Administration;
    explicit Doctor(int i=0);
    void add_doctor();
    void getDoctordetails();
    void getHospitaldetails();
    void checkPatients(int p_id);
    void prescribeDrugs(int p_id);
    void Disp_alld();
    void Disp_doc(int d_id);
};
