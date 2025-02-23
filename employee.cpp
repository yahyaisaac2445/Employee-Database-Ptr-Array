#include "employee.h"
#include <iostream>
#include <string>
using namespace std;

Employee::Employee()
{
  name = " ";
  ID = 0;
  salary = new int(0);
  address = " ";
}

Employee::Employee(string n, int I, int s, string addy)
{
  name = n;
  ID = I;
  // salary = s;
  address = addy;
  // salary = new int;// this is an inefficient way of assigning a value to what the salary pointer is point too
  // *salary = s;
  //more efficient way to assign a value to what salary is pointing too while allocating new memory
  salary = new int(s);
}

Employee::~Employee()
{
   delete salary;
  cout << "Calling deconstructor" << endl;
}

Employee::Employee(const Employee &obj)
{
  name = obj.name;
  ID = obj.ID;
  //  salary = new int;//???
  //  salary = obj.salary;//???
  //  salary = new int(*obj.salary);//takes the value of pointer variable salary and allocats new memory and puts the pointer variables value in to the other objects salary, since salary is a pointer variable you need to star it(dereference) so that it can put the actual value and not the address
   salary = new int(*(obj.salary));
  address = obj.address;


}

string Employee::getName()
{
  return name;
}

int Employee::getID()
{
  return ID;
}
/*
int employee::getSalary()
{
  return salary;
}
*/

int Employee::getSalary()
{
  return *salary;
}

string Employee::getAddress()
{
  return address;
}

void Employee::displayinfo()
{
  cout << "Info for employee: " << endl;
  cout << "Name: " << name << endl;
  cout << "ID: " << ID << endl;
  cout <<  "Salary value: " << *salary << endl;
  cout <<  "Salary pointer: " << salary << endl;
  cout << "Address: " << address << endl;
}

void Employee::setName(string newname)
{
  name = newname;
}

void Employee::setID(int newID)
{
  ID = newID;
}
void Employee::setSalary(int newsalary)
{
  *salary = newsalary;
}
void Employee::setAddress(string newadd)
{
  address = newadd;
}

Employee& Employee::operator=(const Employee& rhs)
{
  if(this == &rhs)
    {
      return *this;
    }
  else
    {
      delete salary;
      this->salary = new int(*(rhs.salary));
      this->name = rhs.name;
      this->ID = rhs.ID;
      this->address = rhs.address;
      return *this;
    }
}
/*
employee employee::operator+(const employee rhs)
{
  string newname = name;

  string str1 = to_string(ID);
  string str2 = to_string(rhs.ID);
  string newID = str1 + "and " + str2;

  int newsalary = salary + rhs.salary;

  string newaddress = address + "and " + rhs.address;

  return employee(newname,stoi(newID), newsalary, newaddress);
}
*/
