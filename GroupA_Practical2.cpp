/*
Experiment Number 2 : Develop a program in C++ to create a database of
student’s information system
containing the following information: Name, Roll number, Class, Division,
Date of Birth, Blood group,
Contactaddress, Telephone number, Driving license no. and other. Construct
the database with
suitable member functions. Make use of constructor, default constructor,
copy constructor,
destructor, static member functions, friend class, this pointer, inline
code and dynamic
memory allocation operators-new and delete as well as exception handling.
*/



#include<iostream>
#include<string.h>
using namespace std;
class Data
{
 string address;
 long int *telephone;
 long int *dl_no;

 public:
 Data();
 ~Data();
 void input_student_data();
 void display_student_data();
 friend class Student;
};
class Student
{
 string Name;
 int Roll;
 string Class;
 char *Div;
 string dob;
 char *bg;
 static int count;

 public:
 Student();
 ~Student();
 static int get_count()
 {
 return count;
 }
 void input_data(Data *);
 void display_data(Data *);
};
Data::Data()
{
 address = " ";
 telephone = new long;
 dl_no = new long;
}
Data::~Data()
{
 delete telephone;
 delete dl_no;
}
void Data::input_student_data()
{
 cout<<"Contact Address : ";
 cin.ignore();
 getline(cin,address);
 cout<<"Telephone Number : ";
 cin>>*telephone;
 cout<<"Driving License Number : ";
 cin>>*dl_no;
}
void Data::display_student_data()
{
 cout<<"Contact Address : "<<address<<endl;
 cout<<"Telephone Number : "<<*telephone<<endl;
 cout<<"Driving License Number : "<<*dl_no<<endl;
}
Student::Student()
{

 Name = " ";
 Roll = 0;
 Class = " ";
 Div = new char;
 dob = "dd/mm/yyyy";
 bg = new char[5];
}
Student::~Student()
{
 delete Div;
 delete[] bg;
}
inline void Student::input_data(Data *stud1)
{
 cout<<"Name : ";
 cin.ignore();
 getline(cin,Name);
 cout<<"Roll Number : ";
 cin>>Roll;
 cout<<"Class : ";
 cin.ignore();
 getline(cin,Class);
 cout<<"Division : ";
 cin>>Div;
 cout<<"Date of Birth : ";
 cin.ignore();
 getline(cin,dob);
 cout<<"Blood Group : ";
 cin>>bg;
 stud1->input_student_data();
 count++;
}
inline void Student::display_data(Data *stud2)
{
 cout<<"Name : "<<Name<<endl;
 cout<<"Roll Number : "<<Roll<<endl;
 cout<<"Class : "<<Class<<endl;
 cout<<"Division : "<<Div<<endl;
 cout<<"Date of Birth : "<<dob<<endl;
 cout<<"Blood Group : "<<bg<<endl;
 stud2->display_student_data();
 cout<<"----------------------------------------------------------------------\n";
}
int Student::count;
int main()
{

 Student *st1[100];
 Data *st2[100];
 int a;
 int s=0;
 char ch;
 cout<<"--------------------MENU--------------------\n";
 cout<<"1. New Student\n";
 cout<<"2. View Database\n";
 cout<<"Enter your choice : "<<endl;
 cin>>a;

 if(a==1)
 {

 do
 {
 st1[s] = new Student;
 st2[s] = new Data;
 cout<<"Enter the details of student "<<s+1<<" : "<<endl;
 st1[s]->input_data(st2[s]);
 s++;
 cout<<"Do you want to create a new student (y/n): ";
 cin>>ch;
 }while(ch=='y' || ch=='Y');
 }

 else if(a==2)
 {

 cout<<"**************************StudentDatabase****************************"<<endl;

 for(int i=0;i<s;i++)
 {
 st1[i]->display_data(st2[i]);
 }
}
 else
 cout<<"WRONG CHOICE\n";

 cout<<"Total Number of Students : "<<Student::get_count()<<endl;
 return 0;
}
