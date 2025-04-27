#include <iostream>
#include <string>
using namespace std;

int main(){
    int age;
    string name;
    
    cout<<"Enter your age: ";
    cin>>age; //without cin.ignore()

    cout<<"Enter your full name: ";
    getline(cin, name);

    cout<<"Age: "<<age<<", Name: "<<name<<endl;

}