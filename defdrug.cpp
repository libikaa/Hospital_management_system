#include<iostream>
#include "drug.h"
#include <string.h>
#include <fstream>
using namespace std;

Drug::Drug(int i)
{
    char ch='y';
    if(i==0)
    {
    while(ch=='y')
    {
    cout<<"Enter the drug name: "<<endl;
    cin>>drug_name;
    cout<<"Enter the symptoms: "<<endl;
    cin>>symptoms;
    cout<<"Enter the cost of the drug: "<<endl;
    cin>>cost;
    for(i=0; i<=2; i++){
    cout<<"Enter the level of the drug(0 / 1 / 2): "<<endl;
    cin>>level[i];
    cout<<"Enter the quantity of the drug: "<<endl;
    cin>>quantity[i];}
    ofstream file1;
    file1.open("Drug_symp.txt",ios::app);
    if(!file1)
    {
        cout<<"Error opening file"<<endl;
    }
    file1.write((char*)this,sizeof(Drug));
    cout<<"want to add more record?[yes or no]"<<endl;
    cin>>ch;
    file1.close();
    }
    }
}
char* Drug::getsymp()
{
    return symptoms;
}
void Drug::getdata() const
{
    cout<<"SYMPTOMS:    \n"<<symptoms<<endl;
    cout<<"DRUG NAME:   \n"<<drug_name<<endl;
    cout<<"COST:        \n"<<cost;
    for(int i=0; i<=2; i++){
    cout<<"LEVEL:       \n"<<level[i];
    cout<<"QUANTITY:    \n"<<quantity[i];}
}

void Drug::disp_file() const
{
    ifstream kr;
    Drug d(1);
    cout<<"Displaying the symptoms-drug data file..."<<endl;
    kr.open("Drug_symp.txt");
    kr.read((char *)&d,sizeof(d));
    if(!kr)
    {
        cout<<"Error opening file"<<endl;
    }
    while(!kr.eof())
    {
        d.getdata();
        kr.read((char *)&d,sizeof(d));
    }
    kr.close();
}
void Drug::add_drug() const
{
    Drug d;
}
