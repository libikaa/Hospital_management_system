#include "Patient.h"
#include "appointment.h"
#include<iostream>
#include <string.h>
#include<fstream>
using namespace std;

Patient::Patient(int i):k(1)
{
    if(i==0)
    {
    char ch='y';
    while(ch=='y')
    {
    cout<<"Enter the name of the patient: "<<endl;
    cin>>pname;
    cout<<"Enter the patient id: "<<endl;
    cin>>id;
    cout<<"Enter the phone number of the patient: "<<endl;
    cin>>phonenumber;
    cout<<"Enter the address of the patient: "<<endl;
    cin>>address;
    cout<<"Enter the age of the patient: "<<endl;
    cin>>age;
    cout<<"Enter the sex of the patient: F for Female or M for Male"<<endl;
    cin>>sex;
    cout<<"Enter the symptoms"<<endl;
    cin>>symp;
    ofstream file1;
    file1.open("Patient.txt",ios::app);
    if(!file1)
    {
        cout<<"Error opening file"<<endl;
    }
    file1.write((char*)this,sizeof(Patient));
    cout<<"want to add more patient record?[yes or no]"<<endl;
    cin>>ch;
    file1.close();
    }
    }
}
void Patient::add_patient()
{
    Patient p;
}
void Patient::getPatientdetails()
{
    cout<<"THE DETAILS OF THE PATIENT IS : "<<endl;
    cout<<"NAME : "<<pname<<endl;
    cout<<"ID : "<<id<<endl;
    cout<<"PHONE NUMBER : "<<phonenumber<<endl;
    cout<<"ADDRESS : "<<address<<endl;
    cout<<"AGE : "<<age<<endl;
    cout<<"SEX : "<<sex<<endl;
    cout<<"SYMPTOMS : "<<symp<<endl;
}
void Patient::Disp_allp()
{
    ifstream kr;
    Patient d(1);
    cout<<"Displaying all Patient details..."<<endl;
    kr.open("Patient.txt",ios::in);
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!kr.eof())
    {
        d.getPatientdetails();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
}
void Patient::check()
{
    ifstream dr;
    dr.open("Drug_symp.txt",ios::in);
    dr.read((char *)&k,sizeof(k));
    if(!dr)
    {
        cout<<"Error in opening file"<<endl;
    }
    int lev;char found='n';
    while(!dr.eof())
    {
        if(strcmp(k.getsymp(),this->symp)==0)
        {
            found='f';
            strcpy(drug,k.drug_name);
            cout<<"Enter the dosage level (0/1/2): "<<endl;
            cin>>lev;
            switch(lev)
            {
                case 0: dose=k.quantity[0];break;
                case 1: dose=k.quantity[1];break;
                case 2: dose=k.quantity[2];break;
                default: cout<<"INVALID OPTION"<<endl;
            }
            break;
        }
        dr.read((char *)&k,sizeof(k));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
}
void Patient::Disp_pat(int p_id)
{
    ifstream pat;
    Patient p(1);
    pat.open("Patient.txt",ios::in);
    pat.read((char *)&p,sizeof(p));
    char found='n';
    if(!pat)
    {
        cout<<"Error in opening file"<<endl;
    }
    while(!pat.eof())
    {
        if(p.id==p_id)
        {
            cout<<"Displaying Patient details..."<<endl;
            found='f';
            p.getPatientdetails();
        }
        pat.read((char *)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
    pat.close();
}
void Patient::makePayment(int p_id)
{
    string dru;
    int q;
    int c;
    float pay;
    ifstream ke;
    
    ke.open("pat_det.txt",ios::in);
    ke.read((char *)&p,sizeof(p));
    if(!ke)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!ke.eof())
    {
        if(p.id==p_id)
        {
            strcpy(dru,p.drug);
            q=p.dose;
        }
    }
    ke.close();
    ifstream l;
    Drug d(1);
    l.open("Drug_symp.txt",ios::in);
    l.read((char *)&d,sizeof(d));
    if(!l)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!l.eof())
    {
        if(strcmp(dru,d.drug_name)==0)
        {
                c=d.cost;
        }
        l.read((char *)&d,sizeof(d));
    }
    l.close();
    pay=c*q;
    cout<<"Drug prescribed: "<<endl;
    cout<<c;
    cout<<"Quantity of the Drug: "<<endl;
    cout<<q;
    cout<<"Amount to be paid: "<<endl;
    cout<<pay;
}
void Patient::getDrugdet()
{
    cout<<"DRUG NAME: "<<drug<<endl;
    cout<<"DRUG DOSE: "<<dose<<endl;
}
void Patient::receiveDrugs(int p_id)
{
    ifstream m;
    Patient p(1);
    m.open("Pat_det.txt",ios::in);
    m.read((char *)&p,sizeof(p));
    if(!m)
    {
        cout<<"Error opening file"<<endl;
    }
    char found='n';
    while(!m.eof())
    {
        if(p.id==p_id)
        {
            found='f';
            p.getPatientdetails();
            p.getDrugdet();
            break;
        }
        m.read((char *)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
    m.close();
}
void Patient::checkup(int p_id)
{
    cout<<"\n\nGeneral health checkup\n\n"<<endl;
    ifstream r;
    Patient p(1);
    r.open("Patient.txt");
    r.read((char *)&p,sizeof(p));
    (!r) ? cout<<"Error opening file"<<endl: cout<<" ";
    char found='n';
    float w;
    float h;
    float bmi;
    float s_l;
    float p_l;
    while(!r.eof())
    {
        if(p_id==p.id)
        {
            found='f';
            cout<<"Enter weight in kg :"<<endl;
            cin>>w;
            cout<<"Enter the height in m: "<<endl;
            cin>>h;
            bmi=w/(h*h);
            cout<<"Enter the blood sugar level(before eating) in mg/dL: "<<endl;
            cin>>s_l;
            cout<<"Enter the blood pressure level(systolic) in mm Hg: "<<endl;
            cin>>p_l;
            cout<<"\nYour body mass index is "<<bmi<<endl;
            switch (true) {
                case (bmi < 18.5):
                    cout << "\tUNDERWEIGHT";
                    break;
                case (bmi < 24.9):
                    cout << "\tHEALTHY";
                    break;
                case (bmi < 30):
                    cout << "\tOVERWEIGHT";
                    break;
                case (bmi >= 30):
                    cout << "\tSUFFERING FROM OBESITY";
                    break;
                default:
                    cout << "INVALID CHOICE" << endl;
                    break;
            }

            cout<<"\nYour blood sugar level is: "<<s_l<<endl;
            if (s_l < 100) {
                cout << "\tNORMAL";
            } else if (s_l <= 125) {
                cout << "\tAT HIGH RISK";
            } else if (s_l >= 126) {
                cout << "\tDIABETIC";
            } else {
                cout << "\tINVALID CHOICE" << endl;
            }

            cout<<"\nYour blood pressure is "<<p_l<<endl;
           if (p_l < 120) {
                cout << "\tNORMAL";
            } else if (p_l < 129) {
                cout << "\tELEVATED";
            } else if (p_l < 139) {
                cout << "\tPRE HIGH BLOOD PRESSURE";
            } else if (p_l < 179) {
                cout << "\tHIGH BLOOD PRESSURE";
            } else if (p_l >= 180) {
                cout << "\tHYPERTENSION";
            } else {
                cout << "\tINVALID CHOICE" << endl;
            }

            cout<<"\n\n\n";
            break;
        }
        r.read((char *)&p,sizeof(p));
    }
    (found=='n') ? cout<<"File record not found"<<endl: cout<<"";
    r.close();
}
void Patient::bookAppointment()
{
    int count=0;
    if (count==0)
    {
    Appointment a(0);
    cout<<"BOOKED"<<endl;
    count++;
    }
    else if(count==1)
    {
    string dn;
    string slt;
    Appointment b(1);
    cout<<"\n\nBOOK YOUR APPOINTMENT..."<<endl;
    cout<<"Enter the Doctor name: "<<endl;
    cin>>dn;
    cout<<"Enter the appointment Slot: "<<endl;
    cout<<"Slot A: 9:00-10:00\nSlot B: 10:00-11:00\nSlot C: 11:00-12:00\nSlot D: 3:00-4:00\nSlot E: 4:00-5:00\nSlot F: 5:00-6:00\n"<<endl;
    cin>>slt;
    b.checkAvailability(dn,slt);
    }
}
