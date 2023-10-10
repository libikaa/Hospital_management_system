#include "Administration.h"
#include<iostream>
#include<fstream>
#include <string.h>
#include <cstdio>
using namespace std;

Administration::Administration()
{

}
void Administration::deleteDoctor(string del_name)
{
    char option='y';
    while(option=='y')
    {
    ifstream res;
    ofstream file;
    Doctor k(1);
    res.open("Doctor.txt",ios::in);
    file.open("temp.txt",ios::out);
    res.read((char*)&k,sizeof(k));
    char found='n';
    if(!res)
        cout<<"FILE NOT FOUND"<<endl;
    while(!res.eof())
    {
            if(strcmp(k.name,del_name)==0)
            {
                found='f';
                cout<<"your record has been deleted"<<endl;
            }
            else
            {
                file.write((char*)&k,sizeof(k));
            }
            res.read((char*)&k,sizeof(k));
        }
        if(found=='n')
            cout<<"Doctor record not found"<<endl;
        file.close();
        res.close();
        remove("Doctor.txt");
        rename("temp.txt","Doctor.txt");
        cout<<"Do you want to delete any other Doctor record[if yes enter y]"<<endl;
        cin>>option;
    }
}
void Administration::deleteStaff(string del_name)
{
    char option='y';
    while(option=='y');
    {
    ifstream res;
    ofstream file;
    Staff k(1);
    res.open("Staff.txt",ios::in);
    file.open("temp.txt",ios::out);
    res.read((char*)&k,sizeof(k));
    char found='n';
    if(!res)
        cout<<"FILE NOT FOUND"<<endl;
    while(!res.eof())
    {
            if(strcmp(k.sname,del_name)==0)
            {
                found='f';
                cout<<"your record has been deleted"<<endl;
            }
            else
            {
                file.write((char*)&k,sizeof(k));
            }
            res.read((char*)&k,sizeof(k));
        }
        if(found=='n')
            cout<<"Staff record not found"<<endl;
        file.close();
        res.close();
        remove("Staff.txt");
        rename("temp.txt","Staff.txt");
        cout<<"Do you want to delete any other staff record[if yes enter y]"<<endl;
        cin>>option;
    }
}
void Administration::edit_doctor()
{
    Doctor p(1);
    fstream an;
    an.open("Doctor.txt",ios::in|ios::out);
    an.read((char*)&p,sizeof(p));
    string na;
    char found='n';
    int count=0;
    cout<<"Enter doctor name: "<<endl;
    cin>>na;
    while(!an.eof())
    {
        if(strcmp(p.name,na)==0)
        {
            int n;
            found='f';
            cout<<"which data of the doctor is to be altered???"<<endl;
            cout<<"1] Name\n 2] Speciality\n 3] Salary\n 4] ID number\n 5] Qualification\n"<<endl;
            cin>>n;
            switch(n){
                case 1:{char dn[50];
                        cout<<"Enter the new name of the doctor['.' to retain the old name]"<<endl;
                        cin.ignore();
                        cin>>dn;
                        (strcmp(dn, ".") == 0) ? (cout << "old name retained" << endl) : (strcpy(p.name, dn));

                        };break;
                case 2:{char dn[50];
                        cout<<"Enter the new Speciality['.' to retain the old Speciality]"<<endl;
                        cin.ignore();
                        cin>>dn;
                        (strcmp(dn, ".") == 0) ? (cout << "old Speciality retained" << endl) : (strcpy(p.speciality, dn));

                        };break;
                case 3:{int d;
                        cout<<"Enter the new salary[-1 to retain old salary]"<<endl;
                        cin.ignore();
                        cin>>d;
                        (d == -1) ? (cout << "old salary retained" << endl) : (p.salary = d);

                        };break;
                case 4:{int d;
                        cout<<"Enter the new ID number[-1 to retain old ID number]"<<endl;
                        cin>>d;
                        (d == -1) ? (cout << "old ID number retained" << endl) : (p.id_doc = d);

                        };break;
                case 5:{char dn[50];
                        cout<<"Enter the new Qualification['.' to retain old qualification]"<<endl;
                        cin.ignore();
                        cin>>dn;
                        (strcmp(dn, ".") == 0) ? (cout << "old Qualification retained" << endl) : (strcpy(p.qualification, dn));

                        };break;
                default:cout<<"Invalid option"<<endl;
            }
            break;
        }
        count++;
        an.read((char*)&p,sizeof(p));
    }
    if(found =='n')
    {
        cout<<"RECORD NOT FOUND"<<endl;
    }
    if(found =='f')
    {
        fstream kr;
        kr.open("Doctor.txt",ios::out | ios::in);
        kr.seekp(count*sizeof(p),ios::beg);
        kr.write((char *)&p,sizeof(p));
        kr.close();
    }
    an.close();
}
void Administration::edit_staff()
{
    Staff p(1);
    fstream an;
    an.open("Staff.txt",ios::in|ios::out);
    an.read((char*)&p,sizeof(p));
    char na[50];
    int count=0;
    char found='n';
    cout<<"Enter Staff name: "<<endl;
    cin>>na;
    while(!an.eof())
    {
        if(strcmp(p.sname,na)==0)
        {
            int n;
            found = 'f';
            cout<<"which data of the Staff is to be altered???"<<endl;
            cout<<"1] Name\n 2] Department\n 3] Salary\n 4] ID number\n"<<endl;
            cin>>n;
            switch(n){
                case 1:{char ani[50];
                        cout<<"Enter the new name of the staff['.' to retain the old name]"<<endl;
                        cin.ignore();
                        cin>>ani;
                        if(strcmp(ani,".")==0)
                            cout<<"old name retained"<<endl;
                        else
                            strcpy(p.sname,ani);
                        };break;
                case 2:{char ct[50];
                        cout<<"Enter the new Department['.' to retain the old Department]"<<endl;
                        cin.ignore();
                        cin>>ct;
                        if(strcmp(ct,".")==0)
                            cout<<"old Department retained"<<endl;
                        else
                            strcpy(p.department,ct);
                        };break;
                case 3:{int wt;
                        cout<<"Enter the new salary[-1 to retain old salary]"<<endl;
                        cin.ignore();
                        cin>>wt;
                        if(wt==-1)
                            cout<<"old salary retained"<<endl;
                        else
                            p.ssalary=wt;
                        };break;
                case 4:{int nu;
                        cout<<"Enter the new ID number[-1 to retain old ID number]"<<endl;
                        cin>>nu;
                        if(nu==-1)
                            cout<<"old ID number retained"<<endl;
                        else
                            p.id_sal=nu;
                        };break;
                default: cout<<"Invalid option"<<endl;
            }
            break;
        }
        count++;
        an.read((char*)&p,sizeof(p));
    }
    if(found =='n')
    {
        cout<<"RECORD NOT FOUND"<<endl;
    }
    if(found =='f')
    {
        fstream kr;
        kr.open("Staff.txt",ios::out | ios::in);
        kr.seekp(count*sizeof(p),ios::beg);
        kr.write((char *)&p,sizeof(p));
        kr.close();
    }
    an.close();
}
