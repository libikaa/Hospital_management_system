#include <iostream>
#include "choice.h"
#include "doctor.h"
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    int opt;
    int k=1;
    Choice c;
    Doctor d(1);
    cout<<"\t\t\t\t\t\t _________________________________________________________________ \n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|WELCOME TO HOSPITAL MANAGEMENT  SYSTEM \t|\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|_________________________________________________________________|\n\n";
    system("pause");
    system("cls");
    while(k==1)
    {
    cout<<"\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
    cout<<"\t\t\t\t\t\t ____________________________________________________________________________________\n";
    cout<<"\t\t\t\t\t\t|\t|\n";
    cout<<"\t\t\t\t\t\t|             1  >> Press 1 if u are a DOCTOR                                        |\n";
    cout<<"\t\t\t\t\t\t|             2  >> Press 2 if u are a PATIENT                                       |\n";
    cout<<"\t\t\t\t\t\t|             3  >> Press 3 if u are an ADMIN STAFF                                  |\n";
    cout<<"\t\t\t\t\t\t|             4  >> Information About the Hospital                                   |\n";
    cout<<"\t\t\t\t\t\t|             5  >> Exit the Program                                                 |\n";
    cout<<"\t\t\t\t\t\t|____________________________________________________________________________________|\n\n";
    cout<<"\t\t\t\t\t\tEnter your choice: ";
    cin>>opt;
    switch(opt)
    {
        case 1:
            c.doc_menu();break;
        case 2:
            c.pat_menu();break;
        case 3:
            c.admin_menu(); break;
        case 4:
            d.getHospitaldetails();break;
        case 5:
            exit(0);
        default:cout<<"INAVLID CHOICE"<<endl;
    }
    cout<<"Do you want to continue(1/0)"<<endl;
    cin>>k;
    }
}
