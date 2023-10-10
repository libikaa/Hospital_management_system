#include <iostream>
#include <string.h>
#include "choice.h"
#include<stdio.h>
#include<fstream>
#include<string.h>

using namespace std;
void Choice::doc_menu()
{
	int option;
	char temp;
	do
	{
        cout<<"please pick an option"<<endl;
        cout<<"(1)\tAdd new doctor record\n"<<endl;
        cout<<"(2)\tCheck patient record\n"<<endl;
        cout<<"(3)\tProvide Prescription\n"<<endl;
        cout<<"(4)\tDisplay doctor record\n"<<endl;
        cout<<"(5)\tDisplay all doctor records\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>option;
        doc_opt(option);
        cout<<"Do you want to continue[y or n]\n"<<endl;
        cin>>temp;
    	}while(temp=='y');
}
void Choice::pat_menu()
{
	int option;
	char temp;
	do
	{
        cout<<"please pick an option"<<endl;
        cout<<"(1)\tAdd new patient record\n"<<endl;
        cout<<"(2)\tView your medical report\n"<<endl;
        cout<<"(3)\tTake a general check up\n"<<endl;
        cout<<"(4)\tBook doctor appointment\n"<<endl;
        cout<<"(5)\tDisplay Patient record\n"<<endl;
        cout<<"(6)\tDisplay all Patient records\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>option;
        pat_opt(option);
        cout<<"Do you want to continue[y or n]\n"<<endl;
        cin>>temp;
    	}while(temp=='y');
}
void Choice::admin_menu()
{
    int option;
    char temp;
    do
    {
        cout<<"please pick an option"<<endl;
        cout<<"(1)\tAdd Staff details\n"<<endl;
        cout<<"(2) \tDisplay Staff record\n"<<endl;
        cout<<"(3) \tDisplay all Staff records\n"<<endl;
        cout<<"(4)\tDelete Doctor record\n"<<endl;
        cout<<"(5)\tDelete Staff record\n"<<endl;
        cout<<"(6)\tEdit Doctor record\n"<<endl;
        cout<<"(7)\tEdit Staff record\n"<<endl;
        cout<<"(8)\tAdd drug data into file\n"<<endl;
        cout<<"(9)\tDisplay drug file\n"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>option;
        admin_opt(option);
        cout<<"Do you want to continue[y or n]\n"<<endl;
        cin>>temp;
    }while(temp=='y');
}
void Choice::doc_opt(int choice)
{
    Doctor d(1);
    switch(choice)
    {
        case 1: d.add_doctor(); break;
        case 2:{int p;
                cout<<"Enter the patient ID to view record: "<<endl;
                cin>>p;
                d.checkPatients(p);} break;
        case 3: {int p;
                cout<<"Enter the Patient ID to be examined: "<<endl;
                cin>>p;
                d.prescribeDrugs(p);} break;
        case 4:	{int p;
                cout<<"Enter the Doctor ID to view record: "<<endl;
                cin>>p;
                d.Disp_doc(p);} break;
        case 5:	d.Disp_alld(); break;
        default:cout<<"Invalid choice"<<endl;
    }
}
void Choice::pat_opt(int choice)
{
    Patient p(1);
    switch(choice)
    {
        case 1: p.add_patient();break;
        case 2:{int d;
                cout<<"Enter the Patient ID to view your report: "<<endl;
                cin>>d;
                p.receiveDrugs(d);} break;
        case 3: {int d;
                cout<<"Enter the Patient ID: "<<endl;
                cin>>d;
                p.checkup(d);}break;
        case 4: p.bookAppointment();break;
        case 5: {int d;
                cout<<"Enter the Patient ID to view record: "<<endl;
                cin>>d;
                p.Disp_pat(d);}break;
        case 6: p.Disp_allp();break;
        default:cout<<"Invalid choice"<<endl;
    }
}
void Choice::admin_opt(int choice)
{
    Staff s(1);
    Administration a(1);
    Drug d(1);
    switch(choice)
    {
        case 1: s.add_staff();break;
        case 2: {int di;
                cout<<"Enter the Staff ID to view record: "<<endl;
                cin>>di;
                s.disp_stf(di);}break;
        case 3: s.disp_alls();break;
        case 4:{string doc;
                cout<<"Enter the Doctor name whose record is to be deleted: "<<endl;
                cin>>doc;
                a.deleteDoctor(doc);} break;
        case 5:{string sp;
                cout<<"Enter the Staff name whose record is to be deleted: "<<endl;
                cin>>sp;
                a.deleteStaff(sp);} break;
        case 6: a.edit_doctor();break;
        case 7: a.edit_staff();break;
        case 8: d.add_drug();break;
        case 9: d.disp_file();break;
        default:cout<<"Invalid choice"<<endl;
    }
}
