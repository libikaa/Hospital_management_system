#pragma once

#include "patient.h"

class Doctor
{
private:
    Patient p;
    char name[50];
    char speciality[50];
    char qualification[50];
    int id_doc;
    int salary;
public:
    friend class Administration;
    Doctor(int i=0);
    void add_doctor();
    void getDoctordetails();
    void getHospitaldetails();
    void checkPatients(int p_id);
    void prescribeDrugs(int p_id);
    void Disp_alld();
    void Disp_doc(int d_id);
};
