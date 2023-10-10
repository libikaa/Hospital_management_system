#include<iostream>
#include "appointment.h"
#include <string.h>
#include<fstream>
using namespace std;

Appointment::Appointment(int i)
{
    if(i==0)
    {
    ifstream kr;
    
    cout<<"Displaying all Doctor details..."<<endl;
    kr.open("Doctor.txt",ios::in);
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!kr.eof())
    {
        d.getDoctordetails();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
    cout<<"\n\nBOOK YOUR APPOINTMENT..."<<endl;
    cout<<"Enter the Doctor name: "<<endl;
    cin>>Doctorname;
    cout<<"Enter the appointment Slot: "<<endl;
    cout<<"Slot A: 9:00-10:00\nSlot B: 10:00-11:00\nSlot C: 11:00-12:00\nSlot D: 3:00-4:00\nSlot E: 4:00-5:00\nSlot F: 5:00-6:00\n"<<endl;
    cin>>slot;
    ofstream file1;
    file1.open("App.txt",ios::out);
    if(!file1)
    {
        cout<<"Error opening file"<<endl;
    }
    file1.write((char*)this,sizeof(Appointment));
    file1.close();
    }
    cout<<"Appointment status: \n"<<endl;
}
void Appointment::checkAvailability(string doc_name,char sl)
{
    fstream kr;
    Appointment a(1);
    kr.open("App.txt",ios::in | ios::out);
    kr.read((char *)&a,sizeof(a));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(kr.eof())
    {
        if(strcmp(doc_name,a.Doctorname)==0 && sl==a.slot)
        {
            cout<<"Sorry..Appointment unavailable\n"<<endl;
            
        }
        else
        {
            strcpy(a.Doctorname,doc_name);
            a.slot=sl;
            kr.write((char *)&a,sizeof(a));
            cout<<"BOOKED\n"<<endl;
        }
        break;
    }
    kr.close();
}
void Appointment::get_data()
{
    cout<<"DOCTOR NAME: "<<endl;
    cout<<Doctorname;
    cout<<"APPOINTMENT SLOT: "<<endl;
    cout<<slot;
}

void Appointment::Disp_allap()
{
    ifstream kr;
    
    cout<<"Displaying all Appointment details..."<<endl;
    kr.open("Appointment.txt",ios::in);
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!kr.eof())
    {
        d.get_data();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
}
