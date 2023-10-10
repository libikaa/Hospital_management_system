#pragma once
#include <string>
class Staff
{
private:
    string sname;
    int id_sal;
    int ssalary;
    string department;
public:
    friend class Administration;
    explicit Staff(int i=0);
    void getstaffdetails();
    void add_staff();
    void disp_alls();
    void disp_stf(int s_id);
};
