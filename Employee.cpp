

//  HW2 PIC10C
//
//  Created by Aral Muftuoglu
//

#include "Employee.h"


bool CompareBySalary::operator()(const Employee& a,const Employee& b) const
{
    return a.get_salary() < b.get_salary();
}
bool CompareByName::operator()(const Employee& a,const Employee& b) const
{
    return a.get_name() < b.get_name();
}
Employee::Employee()
{
    salary = 0;
}
Employee::Employee(string employee_name, double initial_salary)
{
    name = employee_name;
    salary = initial_salary;
}
void Employee::set_salary(double new_salary)
{
    salary = new_salary;
}
double Employee::get_salary() const
{
    return salary;
}
string Employee::get_name() const
{
    return name;
}
ostream& operator<<(ostream& out, const Employee& ele)
{
    out << ele.get_name();
    return out;
}
