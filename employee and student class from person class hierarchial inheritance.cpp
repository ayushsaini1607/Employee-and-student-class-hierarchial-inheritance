#include<iostream>
#include<stdio.h>
#include<string.h>

#define marksloop for(int i=0;i<5;i++)

using namespace std;

class Person
{
    protected:
      char fname[30];
      char lname[30];
      int age;
      char gender;
      bool validateGender() const;
    public:
       Person()
        {
            fname[0]=0;
            lname[0]=0;
            age=0;
        }
       void getPerson();
       void displayPerson() const;
       ~Person(){}
};

class Employee: protected Person
{
    int empId;
    char dept[30];
    float month_salary;
    float annual_salary;
    float calc_annual_salary();

    public:
      Employee()
       {
           empId=0;
           dept[0]=0;
           month_salary=0;
           annual_salary=0;
       }
      void getEmployee();
      void displayEmployee() const;
      ~Employee(){}
};

class Student: protected Person
{
    char PRN[12];
    char dept[30];
    unsigned int marks[5];
    float perc;
    bool validatePRN() const;
    bool validateMarks() const;
    void calcPerc();
    public:
       Student()
        {
            PRN[0]=0;
            dept[0]=0;
            int i;
            marksloop
              marks[i]=0;
        }
       void getStudent();
       void displayStudent() const;   
};

bool Person::validateGender() const
{
   return gender=='M'|| gender=='F' ? true : false;
}

void Person::getPerson()
{
    cout<<"\nEnter first name : ";
    fflush(stdin);
    gets(fname);
    cout<<"\nEnter last name : ";
    fflush(stdin);
    gets(lname);
    cout<<"\nEnter age : ";
    do{
       cin>>age;
       if(age<0)
          cout<<"\nInvalid age!Enter again: ";
    }while(age<0);
    cout<<"\nEnter gender : ";
    cin>>gender;
    while(!validateGender())
      {
          cout<<"\nInvalid gender entered!\nEnter again!";
          cin>>gender;
      }   
}

void Person::displayPerson() const
{
    cout<<"\nFirst name : "<<fname;
    cout<<"\nLast name : "<<lname;
    cout<<"\nAge : "<<age;
    cout<<"\nGender : "<<gender;
}

void Employee::getEmployee()
{
    getPerson();
    cout<<"\nEnter employeeID : ";
    cin>>empId;
    cout<<"\nEnter Department : ";
    fflush(stdin);
    gets(dept);
    cout<<"\nEnter monthly salary : ";
    do{
       cin>>month_salary;
       if(month_salary<0)
          cout<<"\nInvalid Salary!Enter again: ";
    }while(month_salary<0);
    annual_salary=calc_annual_salary();
}

void Employee::displayEmployee() const
{
    displayPerson();
    cout<<"\nEmployeeID : "<<empId;
    cout<<"\nDepartment : "<<dept;
    cout<<"\nMonthly Salary : "<<month_salary;
    cout<<"\nAnnual Salary : "<<annual_salary;
}

float Employee::calc_annual_salary()
{
    return month_salary*12;
}

bool Student::validatePRN() const
{
    int len=strlen(PRN);
    if(len!=11)
      {
          cout<<"\nInvalid PRN!\nEnter PRN again: ";
          return false;
      }
    marksloop
      {
          if(PRN[i]<48 || PRN[i]>57)             //ascii value for digits
            {
                cout<<"\nInvalid PRN!\nEnter PRN again: ";
                return false;
            }
      }
    return true;
}

bool Student::validateMarks() const
{
    int i;
    marksloop
       if(marks[i]>100)
         {
           cout<<"\nInvalid Marks entered! Enter marks again!";
           return false;
         }
    return true;
}

void Student::getStudent()
{
   getPerson();
   cout<<"\nEnter PRN : ";
   fflush(stdin);
   gets(PRN);
   while(!validatePRN())
    {
      fflush(stdin);
      gets(PRN);
    }
   cout<<"\nEnter marks in five subjects(out of 100) : ";
   marksloop
       cin>>marks[i];
   while(!validateMarks())            //if both are true then only calculate percentage else take input again
       {
           marksloop
              cin>>marks[i];
       } 
   cout<<"\nEnter department : ";
   fflush(stdin);
   gets(dept); 
   calcPerc(); 
}

void Student::displayStudent() const
{
    displayPerson();
    cout<<"\nPRN : "<<PRN;
    cout<<"\nDepartment : "<<dept;
    cout<<"\nMarks in five subjects : ";
    marksloop
    {
        cout<<marks[i]<<"\t";
    }
    cout<<"\nPercentage : "<<perc;
}

void Student::calcPerc()
{
   int total=0;
   marksloop
       total+=marks[i];
   perc=(total*100.0)/500; 
}

int main()
{
    Employee E;
    Student S;
    cout<<"\nEnter Employee Details : ";
    E.getEmployee();
    cout<<"\nEnter Student Details : ";
    S.getStudent();
    cout<<"\n\nDisplaying Details...\n\n";
    cout<<"\n\nEmployee Details : ";
    E.displayEmployee();
    cout<<"\n\nStudent Details : ";
    S.displayStudent();
    return 0;
}
