#include <iostream>
using namespace std;

class Complex{
    float real, img;
    public:
    Complex(){
        real=0;
        img=0;
    }
    
    Complex operator +(Complex &c)
    {
        Complex t;
        t.real= real + c.real;
        t.img= img + c.img;
        return t;
    }
    Complex operator *(Complex &c)
    {
        Complex t;
        t.real= (real*c.real) - (img*c.img);
        t.img= (img*c.img) + (real* c.real);
        return t;
    }
    
    friend istream & operator >>(istream & , Complex&c);
    friend ostream & operator <<(ostream & , Complex&c);
    
    
};
istream & operator >>(istream &, Complex & c){
    cout<<"Enter the real and imaginary part"<<endl;
    cin>>c.real>>c.img;
    return cin;
}
ostream & operator <<(ostream &, Complex & c){
    cout<<c.real<<"+"<<c.img<<"j";
    return cout;
} 

int main() {
    Complex C1,C2,C3,C4;
    cin >> C1 >> C2;
    C3 = C1 + C2;
    C4 = C1 * C2;
    cout <<"Addition is "<< C3<<endl;
    cout << "Multiplication is "<<C4;
    return 0;
}