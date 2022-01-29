#pragma once

class Staff
{
private:
    char sname[50];
    int id_sal;
    int ssalary;
    char department[50];
public:
    friend class Administration;
    Staff(int i=0);
    void getstaffdetails();
    void add_staff();
    void disp_alls();
    void disp_stf(int s_id);
};
