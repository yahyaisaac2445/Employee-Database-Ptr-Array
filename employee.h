#include <iostream>
//#define EMPLOYEE_ARR_SIZE 10
using namespace std;

class Employee
{
 private:
  string name;
  int ID;
   int* salary;
  // int salary;
  string address;
  //  employee ar[EMPLOYEE_ARR_SIZE];
 public:

  //constuctor
  Employee();
  Employee(string, int, int, string);

  //deconstructor
  ~Employee();

  Employee(const Employee&);
  string getName();
  int getID();
  //  int getSalary();
  string getAddress();
  int getSalary();

  void setName(string);
  void setID(int);
  void setSalary(int);//need star
  void setAddress(string);
  //void junk();

  void displayinfo();

  Employee& operator=(const Employee&);
 
  //  employee operator+(const employee);
};
