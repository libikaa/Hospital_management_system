#pragma once

#include<string>


class Drug
{
private:
    string drug_name;
    int cost;
    std::array<int, 10> quantity;
    std::array<int, 10> level;
    string symptoms;
public:
    friend class Patient;
    char* getsymp();
    explicit Drug (int i=0);
    void getdata();
    void disp_file();
    void add_drug();
};
