#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class publication{
    private:
        string title;
        float price;
    public:
        void add(){
            cout<<"Enter the Publication details: "<<endl;
            cout<<"Enter the title:  ";
            cin.ignore();
            getline(cin,title);
            
            cout<<"Enter the Price:  ";
            cin>>price;
        }
        void Display(){
            cout<<"The Publication details are: "<<endl;
            cout<<"The Title is:  "<<title<<endl;
            cout<<"The Price is: "<<price<<endl;
        }
};
class book:public publication{
    private:
        int pages;
    public:
        void add_book(){
            try{
                add();
                cout<<"Enter the Page Count: ";
                cin>>pages;
                if (pages<=0){
                    throw pages;
                }
            }
            catch(int n){
                cout<<"Invalid Pagecount! "<<endl;
                pages=0;
            }
        }
        void display_book(){
            Display();
                cout<<"The page count is: "<<pages;
                cout<<endl;
        }
};
class tape:public publication{
    private:    
        int mins;
    public: 
        void add_tape(){
            try{
                add();
                cout<<"Enter the Play Duration of the tape: ";
                cin>>mins;
                if(mins<=0){
                    throw mins;
                }
            }
            catch(int m){
                cout<<"Invalid Play time!! "<<endl;
                mins=0;
            }
        }
        void display_tape(){
            Display();
            cout<<"The Play count is "<<mins<<" mins"<<endl;
            cout<<endl;
        }
};
int main(){
    book b1[10];
    tape t1[10];
    int ch,bookCount=0,tapeCount=0;
    do{
        cout<<"\nMenu \n";
        cout<<"\nPublication DataBase System";
        cout<<"\n1.Add info to books";
        cout<<"\n2.Add info to tape ";
        cout<<"\n3.Display info of books: ";
        cout<<"\n4.Display info of Tape: ";
        cout<<"\n5.Exit";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        switch(ch){
        case 1:
            b1[bookCount].add_book();
            bookCount++;
            break;
        case 2:
            t1[tapeCount].add_tape();
            tapeCount++;
            break;
        case 3:
            cout<<"\nThe Book publication Status: \n";
            for(int i=0;i<bookCount;i++){
                b1[i].display_book();
            }
            break;
        case 4:
            cout<<"\nThe Tape Publication Status : \n";
            for (int i=0;i<tapeCount;i++){
                t1[i].display_tape();
            }
            break;
        case 5:
            exit(0);
        } 
    }
    while(ch!=5);
    
    return 0;  
}