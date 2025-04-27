#include <iostream>
#include <string>
using namespace std;

// Define the Car class
class Car{
    //Private class names
    private:
    string model; // Car model name
    int year;     // Year of manufacture
    double price; // Price of the car

    //Public class name
    public:
    //Default constructor
    Car() : model(""), year(0), price(0.0){}

    //Parameterized constructor
    Car(string m, int y, float p) : model(m), year(y), price(p){
        cout<<"Car Constructor: "<<model<<" ("<<year<<") - $"<<price<<endl;
    }

    //Display function
    void display() const{
        cout<<"Model: "<<model<<", Year: "<<year<<", Price: $"<<price<<endl;
    }

    //Destructor
    ~Car(){
        cout<<"Car Destructor: "<<model<<" destroyed"<<endl;
    }
};

//CarCollection class
class CarCollection{
    //Private members
    private:
    Car* cars; //Pointer to Car class
    int size;

    public:
    CarCollection(){
    //Constructor
    //Ask the user how many cars they want to input
    cout << "How many cars do you want to enter? ";
    cin >> size;
    cin.ignore(); //Clear the newline 

    //Dynamically allocate temporary arrays to store user input for each car's details
    string* models = new string[size]; // Array to store car model names
    int* years = new int[size];         // Array to store car manufacturing years
    float* prices = new float[size];    // Array to store car prices

    //Loop to input data for each car
    for (int i = 0; i < size; i++) {
    cout << "\nEnter model for car " << i + 1 << ": ";
    getline(cin, models[i]); //Read full model name 
    
    cout << "Enter year: ";
    cin >> years[i]; //Read the year of manufacture

    cout << "Enter price: ";
    cin >> prices[i];  //Read the price of the car

    cin.ignore(); //Clear the newline
}

        //Cars array created with 'size' elements
        cars = new Car[size];

        cout<<"\n";

        for(int i=0; i<size; i++){

            new (&cars[i]) Car(models[i], years[i], prices[i]);
        }

        cout<<"CarCollection initialized with "<<size<<" cars\n"<<endl;

        //The three arrays above are deleted
        delete[] models;
        delete[] years;
        delete[] prices;
    }

    //Display function
    void displayCollection() const{
        cout<<"--- Car Collection ---"<<endl;

        for(int i=0; i<size; i++){
           cars[i].display();
        }
        cout<<"\n";
    }

    //Destructor
    ~CarCollection(){ 
        for(int i=0; i<size; i++){
        cars[i].~Car();
        }

       cout<<"CarCollection destroyed"<<endl;
    }

};

int main() {
    //Dynamically create a CarCollection object
    //The CarCollection constructor will ask the user for number of cars and input their details
    CarCollection* collections = new CarCollection();

    //Ask the display function to show all cars in the collection
    collections->displayCollection();

    //Delete the CarCollection object
    delete collections;

    return 0; 
}
