#include <iostream> //Including necessary libraries
using namespace std;


//Create a complex class
class Complex{
    
    private: //Private class names
    double real;
    double imag;


    public: //Public class name and
    //Constructor and destructor
    Complex(double r=0, double i=0) : real(r), imag(i){}

    ~Complex(){}


    //Overloading construction. Plus create a tool to sum two complex numbers
    Complex operator +(const Complex& other) const{
        return Complex(real + other.real, imag + other.imag);
    }


    //Overloading construction to create a tool to subtract two complex numbers
    Complex operator -(const Complex& other) const{
        return Complex(real - other.real, imag - other.imag);
    }


    //Overloading construction to create a tool to divide two complex numbers
    Complex operator /(const Complex& other) const{
        Complex result;
        double den = other.real*other.real+other.imag*other.imag;
        result.real = (real*other.real+imag*other.imag)/den;
        result.imag = (imag*other.real-real*other.imag)/den;
        return result;
    }

    friend ostream& operator<<(ostream& out, const Complex& obj);
};


ostream& operator<<(ostream& out, const Complex& obj){
    out<<obj.real;
    if(obj.imag<0){out<<" - "<<-obj.imag<<"i";}
    else{out<<" + "<<obj.imag<<"i";}
    return out;
}

int main(){
    Complex c1(4,5), c2(2,-3); //Defining the two complex numbers

    cout<<"c1 = "<<c1<<endl; //Value of c1
    cout<<"c2 = "<<c2<<endl; //Value of c2
    cout<<"Sum = "<<c1+c2<<endl; //Sum
    cout<<"Difference = "<<c1-c2<<endl; //Difference
    cout<<"Quotient = "<<c1/c2<<endl; //Quotient

    return 0;
}