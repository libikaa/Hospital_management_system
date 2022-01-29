#pragma once


class Drug
{
private:
    char drug_name[50];
    int cost;
    int quantity[10];
    int level[10];
    char symptoms[50];
public:
    friend class Patient;
    char* getsymp();
    Drug (int i=0);
    void getdata();
    void disp_file();
    void add_drug();
};
