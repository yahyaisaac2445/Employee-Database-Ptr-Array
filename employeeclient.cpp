#include <iostream>
#include <fstream>
#include "employee.h"
#include <string>
#include <limits>
#include <sstream>
#include <vector>
#include <cstdlib>
using namespace std;

//Creator: Isaac Yahya
//Date: 2/23/2025
// the sky is blue
/*******************************************************************
This program is a database that is used to hold employee information. You can search for an employee, copy all the employee info onto a new file, you can add new employees and delete old ones. You can list all the employee's last names, calculate the average salary, as well as show the salaries higher than average and the ones lower than average. This program is meant to demonstrate my ability and knowledge with object oriented programming, data structures, pointers, as well as a solid understanding of c++ and basic coding practices. Employee data is stored within an array of pointers that point towards employee objects. Each employee is an object, that holds different variables such as strings for the name and address, and int for the salary and ID, 
 *****************************************************************/

//int SIZE = 9; old hard coded size

/********************************************************************
In order to have this program function like an actual database that a company can use, I had to make it so the program would update the size permanently, instead of having the size hard coded. To do this, the program takes the size from a seperate data file and updates that data file accordingly
**********************************************************************/
int loadSize()
{
  ifstream fin("sizefile");//open file
  if(!fin)
    {
      cerr << "Error file cannot open" << endl;
    }
  
  int SIZE = 0;//initialize size variable

  fin >> SIZE;

  fin.close();
    
  return SIZE;
}

int SIZE = loadSize();//load size into size variable

void checkSIZE()
{
  if(SIZE == 0)//ifstatement to set size to a default in case size is 0
  {
    SIZE = 10;
  }
}

void saveSize(int size)//call this function when the size has been updated, updates datafile
{
  ofstream fout("sizefile");//open foutput

  if(!fout)
    {
      cerr << "Error file cannot open" << endl;
    }
  fout << size << endl;//updates text in file

  fout.close();
}
void fillArray(Employee ar[])//fillarray if the array being used in main was a normal array and not a pointer array
{
  for(int i = 0; i < SIZE; i++)
    {
      string name;
      int ID;
      int salary;
      string address;
           Employee a;
      cout << "Enter the employee name: " << endl;
      cin >> name;
            a.setName(name);
      //      ar[i].setName(name);
      cout << "Enter the employee ID: " << endl;
      cin >> ID;
            a.setID(ID);
      //      ar[i].setID(ID);
      cout << "Enter the employee salary: " << endl;  
      cin >> salary;
      //      ar[i].setSalary(salary);
      //      cin >> salary;
      //      a.setSalary(&salary);
            a.setSalary(salary);
      cout << "Enter the address: " << endl;
      cin >> address;
      //      ar[i].setAddress(address);
           a.setAddress(address);
   
           ar[i] = a;
      
      cout << ar[i].getName() << endl;
      cout << ar[i].getID() << endl;
      cout << ar[i].getSalary() << endl;
      cout << ar[i].getAddress() << endl;
      
      /*
      cout << a.getName() << endl;
      cout << a.getID() << endl;
      cout << a.getSalary() << endl;
      cout << a.getAddress() << endl;
      */
      //                 delete salary;
    }
  //  delete salary;
}

/****************************************************************
This function loads the array with pointers that point to objects. It gets all this data from a seperate data file
*****************************************************************/
void fillArrayPtr(Employee *ar[])//call array pointer
{
  ifstream fin("datafile");//open datafile

  if(!fin)
    {
      cerr << "Error, cannot open file" << endl;
      return;
      
    }

  for(int i = 0; i < SIZE; i++)//for loop to enter all the data from the file into an array index
    {
      string name;
      int ID;
      int salary;
      string address;

      ar[i] = new Employee; //allocate new memory for each index
      
      getline(fin, name, ',');
      ar[i]->setName(name);// use setters from the class Employee to add data to the variables within the object
      //                 cout << "name:" << name << "check" <<  endl;
      fin.ignore(1);//fin.ignore to make sure the input stream is valid and clear to fully enter all required data
      fin >> ID;
      ar[i]->setID(ID);
      //                cout << "ID:" << ID << "check for space" <<  endl;
      fin.ignore(2);
      fin >> salary;
      ar[i]->setSalary(salary);
      //           cout << "Salary:" << salary << "check" << endl;
      fin.ignore(2);

      getline(fin, address);
      ar[i]->setAddress(address);
      
      /*
      cout << "fillarray" << endl;
      cout << ar[i]->getName() << endl;
      cout << ar[i]->getID() << endl;
      cout << ar[i]->getSalary() << endl;
      cout << ar[i]->getAddress() << endl << endl;
      */
    }
    
  fin.close();

}

/*****************************************************************
This function is called at the end of main. Since we are dealing with pointers, we must make sure to delete the allocated memory so there are no crashes or dangling pointers of any kind
********************************************************/
void delArrayPtr(Employee *ar[])
{
  for(int i = 0; i < SIZE; i++)//for loop to delete each index of the array
    {
      if(ar[i] != nullptr)
	{
	  delete ar[i];
	  ar[i] = nullptr;//set the pointers to nullptr
	  //	  cout << "Deleting index " << i << endl;
	}
    }

}

void searchEmployee(Employee *ar[])
{
  bool backSearchMenu = true;
  bool exit = false;
  
  while(backSearchMenu == true)
    {
      int info = 0;
  //  string find;
  //  string name;
  //int destination = SIZE + 1;
  //  int destination = SIZE;
      while(info != 1 && info != 2 && info != 3 && info != 4 && info != 5)//while loop so it can go back if user does not enter an adequate answer
	{
	  cout << "What type of information are you using to find the employee?" << endl;// menu
	  cout << "1. Employee name" << endl;
	  cout << "2. Employee ID" << endl;
	  cout << "3. Employee salary" << endl;
	  cout << "4. Employee Address" << endl;
	  cout << "5. Back to Main Menu" << endl;
	  cout << "Enter here: ";
	  cin >> info;
	//	cout << info << endl << endl;
	  if(cin.fail())// if enter invalid input
	    {
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	      cout << "Invalid input, try again " << endl;
	      continue;
	    }
	  if(info == 5)
	    {
	      cout << endl;
	    }
	  if(info <= 0 || info > 5)
	    {
	      //	    cout << info << endl << endl;
	      cout << "Out of range, try again" << endl << endl;
	      //  return;
	    }
	  
	}
      switch(info)
	{
	//	bool exit = false;
	case 1:
	  {
	    int found = 0;
	    bool employeeNotFound = false;
	    string name;
	    cout << "Enter the name of the employee: ";
	    cin.ignore();
	    getline(cin, name);
	    int i;
	    for(i = 0; i < SIZE; i++)
	      {
		if(ar[i]->getName() == name)//output of employees info
		  {
		    cout << ar[i]->getName() << "'s employee information: " << endl;
		    cout << "ID: " << ar[i]->getID() << endl;
		    cout << "Salary: " << "$" << ar[i]->getSalary() << endl;
		    cout << "Address: " << ar[i]->getAddress() << endl;
		    cout << endl;
		    found++;
		//return;
		//		break;
		  }
	    //	    cout << "This is where the return is" << endl;
	      }
	    if(found != 0)
	      {
		return;
	      }
	    employeeNotFound = true;
	    if(employeeNotFound == true)
	      {
		cout << "No employee with that name" << endl << endl;
		break;
	      }
	    break;
	  }
	case 2:
	  {
	    //	  bool exit = false;
	    int ID;
	    int found = 0;
	    bool employeeNotFound = false;
	    while(true)
	      {
		cout << "Enter the ID of the employee: ";
		//	  cin.ignore();
		cin >> ID;
		
		if(cin.fail())
		  {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Invalid input" << endl << endl;
		    //		  continue;
		    exit = true;
		    break;
		  }
		else
		  {
		    break;
		  }
	      }
	    if(exit == true)
	      {
		//	      cout << "in if" << endl;
		break;
	      }
	
	    int i;
	    for(i = 0; i < SIZE; i++)
	      {
		if(ar[i]->getID() == ID)
		  {
		    cout << ar[i]->getName() << "'s employee information: " << endl;
		    cout << "ID: " << ar[i]->getID() << endl;
		    cout << "Salary: " << "$" << ar[i]->getSalary() << endl;
		    cout << "Address: " << ar[i]->getAddress() << endl;
		    cout << endl;
		    found++;
		//       break;
		//		return;
		  }
	      }
	    if(found != 0)
	      {
		return;
	      }
	    employeeNotFound = true;
	    if(employeeNotFound == true)
	      {
		cout << "No employee with that ID" << endl << endl;
		break;
	      }
	    break;
	  }
	case 3:
	  {
	    int salary;
	    int found = 0;
	    bool employeeNotFound = false;
	    while(true)
	      {
		cout << "Enter the salary of the employee: ";
		//	  cin.ignore();
		cin >> salary;
		
		if(cin.fail())
		  {
		    cin.clear();
		    cin.ignore(numeric_limits<streamsize>::max(), '\n');
		    cout << "Invalid input" << endl << endl;
		    exit = true;
		    break;
	    //            continue;
		  }
		else
		  {
		    break;
		  }
	      }
	    if(exit == true)
	      {
		break;
	      }
	    int i;
	    for(i = 0; i < SIZE; i++)
	      {
		if(ar[i]->getSalary() == salary)
		  {
		    cout << ar[i]->getName() << "'s employee information: " << endl;
		    cout << "ID: " << ar[i]->getID() << endl;
		    cout << "Salary: " << "$" << ar[i]->getSalary() << endl;
		    cout << "Address: " << ar[i]->getAddress() << endl;
		    cout << endl;
		    found++;
		//		return;
		//              break;
		  }
	      }
	    if(found != 0)
	      {
		return;
	      }
	    employeeNotFound = true;
	    if(employeeNotFound == true)
	      {
		cout << "No employee with that salary" << endl << endl;
		break;
	      }
	    break;
	  }
	case 4:
	  {
	    string address;
	    int found = 0;
	    bool employeeNotFound = false;
	    cout << "Enter the address of the employee: ";
	    cin.ignore();
	    getline(cin, address);
	    int i;
	    for(i = 0; i < SIZE; i++)
	      {
		if(ar[i]->getAddress() == address)
		  {
		    cout << ar[i]->getName() << "'s employee information: " << endl;
		    cout << "ID: " << ar[i]->getID() << endl;
		    cout << "Salary: " << "$" << ar[i]->getSalary() << endl;
		    cout << "Address: " << ar[i]->getAddress() << endl;
		    cout << endl;
		    found++;
		    //		  return;
		    //		  break;
		  }
	      }
	    if(found != 0)
	      {
		return;
	      }
	    employeeNotFound = true;
	    if(employeeNotFound == true)
	      {
		cout << "No employee with that address" << endl << endl;
		break;
	      }
	    break;
	  }
	case 5:
	  {
	    return;
	  }
	}
    }
}

/*****************************************************************
This function simply displays all of the employee info that is in the array. It uses getters from the Employee class to access said variables
****************************************************************/
void displayAll(Employee *ar[])
{
  cout << "Displaying all employee's info:" << endl;

  for(int i = 0; i < SIZE; i++)
    {
      cout << ar[i]->getName() << endl;
      cout << ar[i]->getID() << endl;
      cout << ar[i]->getSalary() << endl;
      cout << ar[i]->getAddress() << endl << endl;
    }


}

/**************************************************************
This function creates a data file that user names and outputs all of the data from the array on to it
 **************************************************************/
void createEmployeeFile(Employee *ar[])
{
  ofstream fout;
  string fileName;

  cout << "Enter the name of the file you want to create: ";
  cin >> fileName;

  //fileName += ".out";
  fout.open(fileName);//create file with new name

  if(!fout)
    {
      cerr << "Error, cannot create file" << endl;
      return;
    }
   
  for(int i = 0; i < SIZE; i++)//add info into file
     {
       fout << ar[i]->getName() << ", " << ar[i]->getID() << ", " << ar[i]->getSalary() << ", " << ar[i]->getAddress() << endl;
     }
  cout << "File named " << fileName << " has been created in current directory";
  cout << endl << endl;
  fout.close();
}

void addNewEmployee(Employee* ar[])
{
  int newhire;
  ofstream fout("datafile", ios::app);//append mode, add to file without overwriting

  if(!fout)
    {
      cerr << "Error, cannot create file" << endl;
      return;
    }
  
  string name;
  int ID;
  int salary;
  string address;

  while(true)//while loop keeps running unless told otherwise
    {
      cout << "How many new employees do you want to add to the database?: ";
      cin >> newhire;
      if(cin.fail())//if they put anything but an int into newhire variable
	{
	  cin.clear();//reset input stream error
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear input sream
	  cout << "Invalid input, try again " << endl;
	  continue;
	}
      
      if(newhire < 0)
	{
	  cout << "Cannot accept negative numbers, try again" << endl;
	  continue;
	}
      
      if(!cin.fail())
	{
	  break;
	}
    }
  cin.ignore();
  int counter = SIZE;
  //  int counter = ogsize - 1;
  SIZE += newhire;
  int num = 1;
  for(counter; counter < SIZE; counter++)
    {
      ar[counter] = new Employee;//allocate new memory
      
      cout << "New employee " << num << ": " << endl;
      
      cout << "Enter the name of the new employee: ";
      getline(cin, name);
      ar[counter]->setName(name);
      fout << name << ", ";

      srand(static_cast<unsigned>(time(0))); //these two lines make a random ID
      int ID = rand() % 9000 + 1000;
      for(int i= 0; i < SIZE - newhire; i++)//for loop to make sure no duplicates
	{
	  if(ar[i]->getID() == ID)//if duplicate add 1 to current ID and reset loop to make sure its all good
	    {
	      ID += 1;
	      i = -1;
	    }
	}
      ar[counter]->setID(ID);
      cout << "The ID for " << name << " is " << ID << endl;
      fout << ID << ", ";
      //      cin.ignore();
      /*
      cout << "Enter the ID of the new employee: "; // if you want the user to enter ID
      cin >> ID;
      ar[counter]->setID(ID);
      fout << ID << ", ";

      cin.ignore();
      */
      
      cout << "Enter the salary of the new employee: ";
      cin >> salary;
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear input stream
      ar[counter]->setSalary(salary);
      fout << salary << ", ";

      
      cout << "Enter the address of the new employee: ";
      getline(cin, address);
      ar[counter]->setAddress(address);
      fout << address << endl;
      
      cout << endl;

      num++;
    }
  fout.close();
 
}

void deleteEmployee(Employee* ar[])
{
  string name;
  string nametrial;
  bool found = false;
  struct Remove{
    string empName;
    int indx;
  };
  
  vector<Remove> removeVec;

  cin.ignore();
  while(true)
    {
      cout << "What is the name of the employee you would like to delete? If you want to go back to the main menu type capital B: ";
      getline(cin, name);

      for(int i = 0; i < SIZE; i++)
	{
	  if(name == ar[i]->getName())
	    {
	      found = true;
	      break;
	    }
	}
      if(name == "B")
	{
	  break;
	}
      if(!cin.fail())
	{
	  if(found == true)
	    {
	      break;
	    }
	    if(found == false)
	      {
		cout << "No employee with that name, try again" << endl;
		continue;
	      }
        }
    }
  
  if(name == "B")
    {
      return;
    }
  //  cin >> name;

  for(int i = 0; i < SIZE; i++)
    {
      //      cout << "in first for loop " << " " << i << endl;
      Remove temp;
      if(ar[i]->getName() == name)
	{
	  //	  cout << "in if statement" << endl;
	  temp.empName = ar[i]->getName();
	  temp.indx = i;
	  removeVec.push_back(temp);
	}
      //      cout << removeVec[0].empName << " " << removeVec[0].indx << endl;
    }
  if(removeVec.size() > 1)
    {
      string choice;
      while(choice != "yes" && choice != "no")
	{
	  cout << "Multiple employees have the name: " << name << ". Would you like to delete all of them, yes or no?: ";
	  cin >> choice;

	  if(choice != "yes" && choice != "no")
	    {
	      cout << "Invalid input, either enter yes or no, try again" << endl;
	      //continue
	    }
	}
      if(choice == "yes")
	{
	  ifstream fin("datafile");

	  if(!fin)
	    {
	      cerr << "Error cannot open file" << endl;
	    }
	  stringstream addpound;
	  string line;
	  int lineNum = 0;
	  int vec_count = 0;
	  while(getline(fin, line))
	    {
	      if(lineNum == removeVec[vec_count].indx)
		{
		  line += '#';
		  vec_count++;
		}
	      addpound << line << endl;
	      lineNum++;
	    }
	  fin.close();

	  ofstream fout("datafile");

	  if(!fout)
	    {
	      cerr << "Error cannot open file" << endl;
	    }
	  fout << addpound.str();

	  fout.close();
	  //	  cout << "Not yet";
	  for(int i = 0; i < removeVec.size(); i++)
	    {
	      cout << removeVec.size() << endl;
	      cout << "going through first for loop" << endl;
	      int deleteIndx = removeVec[i].indx;

	       for(int j = deleteIndx; j < SIZE - 1; j++)
		 {
		   ar[j] = ar[j + 1];
		 }
	       SIZE--;
	       for(int countarray = 0; countarray < SIZE; countarray++)
		 {
		   cout << ar[countarray]->getName() << endl;
		   cout << ar[countarray]->getID() << endl;
		   cout << ar[countarray]->getSalary() << endl;
		   cout << ar[countarray]->getAddress() << endl;
		 }

	       for(int z = i + 1; z < removeVec.size(); z++)
		 {
		   cout << "This is i" << i << endl;
		   removeVec[z].indx -= 1;
		 }
	    }

	  //load new array to make sure all employees removed get excluded
	  
	  stringstream ss;
	  int linecounter = -1;
	  string line2;

	  ifstream finput("datafile");

	  if(!finput)
	    {
	      cerr << "Error cannot open file" << endl;
	    }
	  while(getline(finput, line2))
	    {	
		if(!line2.empty() && line2[line2.size() - 1] != '#')
		  {
		    ss << line2 << endl;
		  }
	    }

	  finput.close();
	  
	  ofstream foutput("datafile");

	  if(!foutput)
	    {
	      cerr << "Error cannot open file" << endl;
	    }
	  foutput << ss.str();

	  foutput.close();
	  
	}
      if(choice == "no")
	{
	  int choice;
	  string deleteEmp;
	  while(choice < 1 || choice > removeVec.size())
	    {
	      cout << "Which " << name << " would you like to delete? Enter the number not the name" << endl;

	      for(int i = 0; i < removeVec.size(); i++)
		{
		  cout << i + 1 << ". " << removeVec[i].empName << endl;
		}
	      cout << "Choose here: ";
	      cin >> choice;

	      if(cin.fail())
		{
		  cin.clear();
		  cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  cout << "Invalid input, try again " << endl;
		  continue;
		}

	      if(choice < 1 || choice > removeVec.size())
		{
		  cout << "Choice is out of range" << endl;
		}
	    }
	  int deleteIndx = removeVec[choice - 1].indx;

	  for(int i = deleteIndx; i < SIZE - 1; i++)
	    {
	      ar[i] = ar[i + 1];
	    }
	  SIZE--;

	  ifstream fin("datafile");

	  if(!fin)
	    {
	      cerr << "Error, input file cannot open" << endl;
	      return;
	    }

	  stringstream ss;
	  int linecounter = -1;
	  string line;
	  while(getline(fin, line))
	    {
	      linecounter++;
	      if(linecounter != deleteIndx)//figure out how to exclude employee that needs to be deleted
		{
		  ss << line << endl;
		}
	    }

	  fin.close();

	  ofstream fout("datafile");

	  if(!fout)
	    {
	      cerr << "Error, output file cannot open" << endl;
	    }

	  fout << ss.str();

	  fout.close();
	}
    }
  if(removeVec.size() == 1)
    {
      int deleteIndx = removeVec[0].indx;

      for(int i = deleteIndx; i < SIZE - 1; i++)
	{
	  ar[i] = ar[i + 1];
	}
      
      ifstream fin("datafile");

	if(!fin)
	  {
	    cerr << "Error, input file cannot open" << endl;
	    return;
	  }
      
      stringstream ss;
      int linecounter = -1;
      string line;
       while(getline(fin, line))
            {
              linecounter++;
              if(linecounter != deleteIndx)//figure out how to exclude employee that needs to be deleted
                {
                  ss << line << endl;
                }
            }

          fin.close();

          ofstream fout("datafile");

          if(!fout)
            {
              cerr << "Error, output file cannot open" << endl;
            }

          fout << ss.str();

          fout.close();
	  
	  SIZE--;
    }



}
/****************************************************************
This function calculates the average salary of all the employee's. It does this by using a for loop that goes to each index in the array and uses the getter function from the Employee class, getSalary(). getSalary() returns an integer variable which we simply plug said variables value into a sum variable that we created and initialized within this function
 ****************************************************************/
void averageSalary(Employee* ar[])
{
  int sum = 0;//initialize and create sum variable
  
  cout << "The average salary of all " << SIZE << " employees is: ";

  for(int i = 0; i < SIZE; i++)
    {
      sum += ar[i]->getSalary();//add all salaries
    }
  double salary = (double)sum / SIZE;//calculate avg

  cout << sum << endl;
  cout << salary << endl << endl;
}

/**********************************************************
This function literally does the same thing as the above function but it returns the value
 ********************************************************/
double averageSalaryReturn(Employee* ar[])//this func is for returning the average salary to be used in different functions
{
  int sum = 0;

  // cout << "The average salary of all " << SIZE << " employees is: ";

  for(int i = 0; i < SIZE; i++)
    {
      sum += ar[i]->getSalary();//add all salaries
    }
  double avgSalary = (double)sum / SIZE;//calculate avg

  //  cout << sum << endl;
  //   cout << avgSalary << endl << endl;

  return avgSalary;
}
/***************************************************************
This function, using getline and its delimiter ability, takes each employee's name from each index in the array and seperates the first and last name. Since there is a space between the first and last name in the string, I used the space as the delimiter to seperate the first and last name. Then I output only the last name
 **************************************************************/
void showLastNames(Employee* ar[])
{
  string firstName;
  string lastName;

  ifstream fin("datafile");
  
  cout << "Last names of all " << SIZE << " employees: " << endl;

  for(int i = 0; i < SIZE; i++)
    {
      getline(fin, firstName, ' ');//take in first name
      getline(fin, lastName, ',');//get last name b/c you already cleared firstname
      cout << lastName << endl;
      fin.ignore(numeric_limits<streamsize>::max(), '\n');//this line lets you skip to the next like in the file
    }

  fin.close();
}

/*****************************************************************
This function passes in the average salary as a parameter and displays each employee's salary that is bigger than the average salary
 ****************************************************************/
void upperBracketSalary(Employee* ar[], double avgSalary)
{
  cout << "These are the employees who have a bigger than average salary in the company" << endl;
  
  for(int i = 0; i < SIZE; i++)
    {
      if(ar[i]->getSalary() >= avgSalary)//ifstatement to check if the employee's salary is bigger then the average
	{
	  cout << ar[i]->getName() << "'s salary is " << ar[i]->getSalary() << endl;
	}
    }
  
  cout << endl;
}			
/********************************************************
This function has the same logic as the above function but it displays the employee salary's that are less than the average salary
 ******************************************************/
void lowerBracketSalary(Employee* ar[], double avgSalary)
{
 cout << "These are the employees who have a lower than average salary in the company" << endl;

  for(int i = 0; i < SIZE; i++)
    {
      if(ar[i]->getSalary() <= avgSalary)//if statement to check the salaries
        {
          cout << ar[i]->getName() << "'s salary is " << ar[i]->getSalary() << endl;
        }
    }

  cout << endl;
}
int main()
{

  //    employee empAr[SIZE];
  double avg;
  checkSIZE();//checks size, makes sure its not 0
  Employee *empAr[SIZE];//declare ptr array with size
  //    fillArray(empAr);
  fillArrayPtr(empAr);//fill the ptr array
    
  int choice;
  while(choice != 10)//main menu of the program, while loop lets you exit program if user enters 10
    {
      cout << "Choose an option: " << endl;
      cout << "1. Search for an employee" << endl;
      cout << "2. View all employees" << endl;
      cout << "3. Copy employee info onto a file" << endl;
      cout << "4. Add new employees" << endl;
      cout << "5. Delete employee(s)" << endl;
      cout << "6. Calculate average salary" << endl;
      cout << "7. Show all employee last names" << endl;
      cout << "8. Show higher than average employee salaries" << endl;
      cout << "9. Show lower than average employee salaries" << endl;
      cout << "10. Exit" << endl;
      cout << "Enter choice: ";
      cin >> choice;
    
      if(cin.fail())//if user enters a non integer then it makes you input again
	{
	  cin.clear();
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  cout << "Invalid input, try again " << endl;
	  continue;
	}

      if(0 >= choice || choice > 10)//if statement to make sure choice isnt out of range
	{
	  cout << "Error, choice is out of range, try again" << endl;
	  continue;
	}
      else
	{
	  switch(choice)//switch statement, from the main menu
	    {
	    case 1:
	      cout << endl;
	      searchEmployee(empAr);
	      break;
	    case 2:
	      cout << endl;
	      displayAll(empAr);
	      break;
	    case 3:
	      //	    cout << endl;
	      createEmployeeFile(empAr);
	      break;
	    case 4:
	      addNewEmployee(empAr);
	      saveSize(SIZE);
	      break;
	    case 5:
	      deleteEmployee(empAr);
	      saveSize(SIZE);
	      break;
	    case 6:
	      averageSalary(empAr);
	      break;
	    case 7:
	      cout << endl;
	      showLastNames(empAr);
	      cout << endl;
	      break;
	    case 8:
	      avg = averageSalaryReturn(empAr);
	      upperBracketSalary(empAr, avg);
	      break;
	    case 9:
	      double avgsalary2 = averageSalaryReturn(empAr);
	      lowerBracketSalary(empAr, avgsalary2);
	      break;
	    }
	}
    }

  //  delArrayPtr(empAr);
  //employee a("Isaac", 8184, 100000, "South Mammoth Place");
  /*
  cout << a.getName() << endl;
  cout << a.getID() << endl;
  cout << a.getSalary() << endl;
  cout << a.getAddress() << endl;
  */
  //    a.displayinfo();
  //    employee b("Chicken", 8232, 100, "Seaworld");
  //    b.displayinfo();


    //    employee b(a);
    //  b = a;

    //    b.displayinfo();
  // employee c(a);

   // cout << a.getSalary();
    //  cout << endl;
  //  a.displayinfo();
  //  b.displayinfo();

  // employee* d = new employee("Joe", 9232, 200000, "The White House");

  //  cout << d->getName();
  
  //  d->displayinfo();
  //  delete d;

  delArrayPtr(empAr);//deletes ptr array memory at the end of the program

}
