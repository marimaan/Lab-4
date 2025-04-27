#include <iostream>
#include <string>

using namespace std;

//Define the car class
class Car{
    //Protected class names
    protected:
    string model;
    int year;
    float price;

    //Default constructor
    public:
    Car() : model(""), year(0), price(0.0){}

    //Destructor 
    virtual ~Car(){}

    //Inputs for the user
    void inputBasic(){
        cout<<"Enter model: ";
        getline(cin, model);
        cout<<"Enter year: ";
        cin>>year;
        cout<<"Enter price: ";
        cin>>price;
    }

    //Basic display
    void displayBasic() const{
        cout<<"Model: "<<model<<", Year: "<<year<<", Price: $"<<price;
    }
};

//Derived ElectricCar class
class ElectricCar : public Car{
    //Specific name for ElectricCar
    private:
    float batterySize;

    public:
    //Constructor to initialize the ElectricCar object, setting the battery size to 0.0 initially
    ElectricCar() : batterySize(0.0){}

    void input(){
        inputBasic();  //Call the inputBasic() function to input the basic details
        cout << "Enter battery size (kWh): ";  
        cin >> batterySize; 
    }

    //Member function to display basic details along with the battery size
    void display() const{
        displayBasic();  
        cout << ", Battery: " << batterySize << " kWh" << endl; 
    }

    //Destructor for ElectricCar
    ~ElectricCar(){
        cout<<"Destroying Electric Car "<<model<<endl;
    }
};

//Derived GasCar class
class GasCar : public Car{
    //Specific member for GasCar
    private:
    float fuelCapacity;

    //Public members - default constructor, and input and display functions
    public:
    GasCar() : fuelCapacity(0.0){}

    void input(){
        inputBasic();
        cout<<"Enter fuel capacity (L): ";
        cin>>fuelCapacity;
    }

    void display() const{
        displayBasic();
        cout<<", Fuel: "<<fuelCapacity<<" L"<<endl;
    }

    //Destructor
    ~GasCar(){
        cout<<"Destroying Gas Car "<<model<<endl;
    }
};

//Derived HybridCar class
class HybridCar : public Car{
    //Specific members for HybridCar
    private:
    float batterySize, fuelCapacity;

    //Public members - default constructor, and input and display functions
    public:
    HybridCar() : batterySize(0.0), fuelCapacity(0.0){}

    void input(){
        inputBasic();
        cout<<"Enter battery size (kWh): ";
        cin>>batterySize;
        cout<<"Enter fuel capacity (L): ";
        cin>>fuelCapacity;
    }

    void display() const{
        displayBasic();
        cout<<", Battery: "<<batterySize<<" kWh, Fuel: "<<fuelCapacity<<" L"<<endl;
    }

    //Destructor
    ~HybridCar(){
        cout<<"Destroying Hybrid Car "<<model<<endl;
    }
};

int main(){
    int n;

    //User input fir starting the program
    cout<<"Enter total number of cars: ";
    cin>>n;

    //Create dynamic array of Car* and array to store the type codes
    Car** fleet = new Car*[n];
    int* type = new int[n];

    //User is asked to choose the type of car
    for(int i=0; i<n; i++){
        cout<<"\nCar "<<i+1<<" type: \n";
        cout<<"[1] Electric\n[2] Gasoline\n[3] Hybrid"<<endl;
        cout<<"Enter choice: ";
        cin>>type[i]; 
        cin.ignore();

        //Based on the car choice, a new object is created and the appropriate input function is called using static_cast to select the correct car type
        if(type[i]==1){
            fleet[i] = new ElectricCar();
            static_cast<ElectricCar*>(fleet[i])->input();
        }
        else if(type[i]==2){
            fleet[i] = new GasCar();
            static_cast<GasCar*>(fleet[i])->input();
        }
        else if(type[i]==3){
            fleet[i] = new HybridCar();
            static_cast<HybridCar*>(fleet[i])->input();
        }
    }

    cout<<"\n--- Fleet Information ---"<<endl;

    //Display all cars
    for(int i=0; i<n; i++){
        if(type[i]==1){
            static_cast<ElectricCar*>(fleet[i])->display();
        }
        else if(type[i]==2){
            static_cast<GasCar*>(fleet[i])->display();
        }
        else if(type[i]==3){
            static_cast<HybridCar*>(fleet[i])->display();
        }
    }

    cout<<"\n--- Cleaning up fleet ---"<<endl;
    
    //Cleanup
    for(int i=0; i<n; i++){
        delete fleet[i];
    }

    delete[] fleet;
    delete[] type;
    
    return 0;
}