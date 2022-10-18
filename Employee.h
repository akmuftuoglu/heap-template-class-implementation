


//  HW2 PIC10C
//
//  Created by Aral Muftuoglu on 10/16/22.
//



#ifndef __EMPLOYEE__
#define __EMPLOYEE__


#include<string>
#include<iostream>


using std::string;
using std::ostream;


class Employee
{
    public:
        /**
          Constructs an employee with empty name and no salary.
          */
        Employee();
        /**
          Constructs an employee with a given name and salary.
          @param employee_name the employee name
          @param initial_salary the initial salary
          */
        Employee(string employee_name, double initial_salary);
        /**
          Sets the salary of this employee.
          @param new_salary the new salary value
          */
        void set_salary(double new_salary);
        /**
          Gets the salary of this employee.
          @return the current salary
          */
        double get_salary() const;
        /**
          Gets the name of this employee.
          @return the employee name
          */
        string get_name() const;
    private:
        string name;
        double salary;
};

class CompareBySalary
{
    public:
        bool operator()(const Employee& a, const Employee& b) const;
};

class CompareByName
{
    public:
        bool operator()(const Employee& a, const Employee& b) const;
};

ostream& operator<<(ostream& out, const Employee& e);
#endif
