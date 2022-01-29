#include "Staff.h"
#include<iostream>
#include<string.h>
#include <fstream>
using namespace std;

Staff::Staff(int i)
{
    char ch='y';
    if(i==0)
    {
    while(ch=='y')
    {
    cout<<"Enter the name of the staff: "<<endl;
    cin>>sname;
    cout<<"Enter the id of the staff: "<<endl;
    cin>>id_sal;
    cout<<"Enter the salary of the staff: "<<endl;
    cin>>ssalary;
    cout<<"Enter the department of the staff: "<<endl;
    cin>>department;
    ofstream file1;
    file1.open("Staff.txt",ios::out| ios::app);
    if(!file1)
    {
        cout<<"Error opening file"<<endl;
    }
    file1.write((char*)this,sizeof(Staff));
    cout<<"want to add more Staff record?[yes or no]"<<endl;
    cin>>ch;
    file1.close();
    }
    }
}
void Staff::getstaffdetails()
{
    cout<<"NAME : "<<sname<<endl;
    cout<<"ID : "<<id_sal<<endl;
    cout<<"SALARY : "<<ssalary<<endl;
    cout<<"DEPARTMENT : "<<department<<endl;
}
void Staff::disp_stf(int s_id)
{
    ifstream pat;
    Staff p(1);
    pat.open("Staff.txt",ios::in);
    pat.read((char *)&p,sizeof(p));
    char found='n';
    if(!pat)
    {
        cout<<"Error in opening file"<<endl;
    }
    while(!pat.eof())
    {
        if(p.id_sal==s_id)
        {
            cout<<"Displaying Staff details..."<<endl;
            found='f';
            p.getstaffdetails();
            break;
        }
        pat.read((char *)&p,sizeof(p));
    }
    if(found=='n')
    {
        cout<<"File record not found"<<endl;
    }
    pat.close();
}
void Staff::disp_alls()
{
    ifstream kr;
    Staff d(1);
    cout<<"Displaying all Staff details..."<<endl;
    kr.open("Staff.txt",ios::in);
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!kr.eof())
    {
        d.getstaffdetails();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
}
void Staff::add_staff()
{
    Staff s;
}
