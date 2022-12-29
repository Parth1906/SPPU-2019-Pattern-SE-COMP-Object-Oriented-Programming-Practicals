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
#include<cstring>
#include<iomanip>
using namespace std;

class db
{   
    int roll;
    char name[20];
    char dob[20];
    char bg[10];
    char Class[10];
    char div[10];
    char addr[20];
    char phone[12];
    char license[20];
    public:
        static int Count;
        static int count(){Count=0;cout<<"Number of objects created: "<<Count<<endl;}
        void fin(){cout<<"This is a INLINE Function"<<endl;}
        db(){
            roll=12;
            strcpy(name,"Akshay");
            strcpy(dob,"11-12-03");
            strcpy(bg,"O+");
            strcpy(Class,"SE");
            strcpy(div,"C");
            strcpy(addr,"Pune");
            strcpy(phone,"2384330995");
            strcpy(license,"abc102030abc");
        }
        db(db *d){
            strcpy(name,d->name);
            strcpy(dob,d->dob);
            strcpy(bg,d->bg);
            strcpy(Class,d->Class);
            strcpy(div,d->div);
            strcpy(addr,d->addr);
            strcpy(phone,d->phone);
            strcpy(license,d->license);
            ++Count;
        }
        void getData();
        friend void Display(db d);
        ~db(){
            cout<<"\n"<<this->Count<<" - "<<this->name<<" (object) is destroyed! "<<endl;
        }
}; 
int db::Count;
void db::getData(){
    cout<<"Enter Name:\nDate of Birth:\nBlood group:\nClass:\nDivision:\nAddress:\nPhone number:\nlicense: "<<endl;
    cin>>name>>dob>>bg>>Class>>div>>addr>>phone>>license;
}
void Display(db d){
    cout<<"Name:  "<<d.name<<endl<<"Date of Birth: "<<d.dob<<endl<<"Blood group: "<<d.bg<<endl<<"Class:  "<<d.Class<<endl<<"Division: "<<d.div<<endl<<"Address: "<<d.addr<<endl<<
    "Phone no: "<<d.phone<<endl<<"License: "<<d.license<<endl;
}
int main(){
    db d1,*ptr[5];
    cout<<"Default values: "<<endl;
    Display(d1);
    d1.getData();
    cout<<endl;
    Display(d1);
    db d2(&d1);
    cout<<"Useof the copy constructor"<<endl;
    cout<<"How many objects you want to create? ";
    int n;
    cin>>n;
    cout<<"Enter the Data: "<<endl;
    for(int i=0;i<n;i++){
        ptr[i]=new db;
        ptr[i]->getData();
    }
    for(int i=0;i<n;i++){
        Display(*ptr[i]);
    }
    db::count();
    for(int i=0;i<n;i++){
        delete(ptr[i]);
    }
    cout<<"Objects Deleted "<<endl;


    return 0;
}