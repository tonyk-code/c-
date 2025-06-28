#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>
#include <fstream>

using  namespace std;

const int MAX_CARS=40;
typedef long long int BigInt;  

int selectedIndexGlobal;

struct carModelsCompanyHave{
    string plateNumber;
    string carName;
    string model;
    int rentPerDay;
    string availability1;
    int seats;
    bool availability2;
};

struct customerInfo{
    string name;
    int age;
    string ID_number;
    string phone;
    string gender;
    string email;
    string address; 
    BigInt rentedDays;
    BigInt totalPayment;
};

void recordCars(carModelsCompanyHave cars[]){
    ifstream file("cars.txt" , ios::in);
    if(file.is_open()){
        for(int i=0;i<MAX_CARS;i++){
            file>>cars[i].plateNumber>>cars[i].carName>>cars[i].model>>cars[i].rentPerDay>>cars[i].availability1>>cars[i].seats;
            if(cars[i].availability1=="available"){
                cars[i].availability2=true;
            }
            else if(cars[i].availability1=="notavailable"){
                cars[i].availability2=false;
            }
            else {
                cerr << "Error: Invalid availability status in cars.txt for car " << i+1 << endl;
                exit(1);  
            }
        }

        file.close();
    }
    else{
        cout<<"File not opened.";
    }
}

bool displayCars( carModelsCompanyHave cars[]){
    recordCars(cars);
    
    while(true){
        int seats;
        string inputs;
        cout << "\nEnter the number of seats(4 , 5 , 6 , 7): ";
        getline(cin,inputs);

        while (inputs.length() != 1 || (inputs[0] != '4' && inputs[0] != '5' && inputs[0] != '6' && inputs[0] != '7')) {
            cout << "\nPlease enter a valid input (4 , 5 , 6 or 7): ";
            getline(cin,inputs);
        }

        seats = stoi(inputs);
        

        int indexMap[MAX_CARS]; 
        int j = 1;
        bool found = false;

        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].seats == seats && cars[i].availability2 == true) {
                found = true;
                indexMap[j] = i;
                cout << j++ << "." << endl;
                cout << "*****************************************************\n\n";
                cout << "Car Name and Model: " << cars[i].carName << " " << cars[i].model << endl;
                cout << "Rent per day: $" << cars[i].rentPerDay << endl;
                cout << "Plate number: " << cars[i].plateNumber << endl;
                cout << "Availability: " << cars[i].availability1 << endl;
                cout << "Number of seats: " << cars[i].seats << endl << endl;
                cout << "*****************************************************\n";
            }
        }

        if (!found) {
            cout << "No available cars found with " << seats << " seats.\n";
            cin.ignore();

            string input;
            int tryagain;
            cout<<"Do you want to try with a different total seat numbers\n"
                <<"1. YES\n"
                <<"2. NO\n"
                <<"Choice: ";
            getline(cin,input);

            while (input.length() != 1 || (input[0] != '1' && input[0] != '2')) {
                cout << "\nPlease enter a valid input (1 or 2): ";
                getline(cin,input);
            }

            tryagain=stoi(input);

            if(tryagain==1){
                continue;
            }
            else{
                cout << "\n-----------------------------------------\n";
                cout << "   Thank you for choosing YNY Car Rental!\n";
                cout << "   We hope to see you again. Goodbye!\n";
                cout << "-----------------------------------------\n";
                return false;
            }
        }
        
        string input;
        int choice;
        cout << "\nEnter the number of the car you want to rent (1 to " << j - 1 << "): ";
        getline(cin,input);

        while (input.empty() || !all_of(input.begin(), input.end(), ::isdigit) || stoi(input) < 1 || stoi(input) > (j-1)) {
            cout << "\nPlease enter a valid number (1 to " << j-1 << "): ";
            getline(cin, input);
        }

        choice = stoi(input);
 
        int selectedIndex = indexMap[choice];
        selectedIndexGlobal=selectedIndex;

        cout << "=====================================================\n";
        cout << "|              You have selected:                   |\n";
        cout << "=====================================================\n";
        cout << "| Car Name & Model : " << cars[selectedIndex].carName 
            << " " << cars[selectedIndex].model << "\n";
        cout << "| Rent per Day     : $" << cars[selectedIndex].rentPerDay << "\n";
        cout << "| Plate Number     : " << cars[selectedIndex].plateNumber << "\n";
        cout << "| Number of Seats  : " << cars[selectedIndex].seats << "\n";
        cout << "=====================================================\n";

    
        string input1;
        int proceed;
        cout<< "\nDo you want to proceed with the rental?\n"
            << "1. Yes\n"
            << "2. No (Exit)\n"
            << "3. Go Back to Seat Selection\n"
            << "Choice: ";
        getline(cin,input1);

        while (input1.length() != 1 || (input1[0] != '1' && input1[0] != '2' && input1[0] != '3')) {
            cout << "\nPlease enter a valid input (1, 2 or 3): ";
            getline(cin,input1);
        } 
        proceed=stoi(input1);
        
        if(proceed==1){
            return true;
        }

        else if(proceed==2){
            cout << "\n-----------------------------------------\n";
            cout << "   Thank you for choosing YNY Car Rental!\n";
            cout << "   We hope to see you again. Goodbye!\n";
            cout << "-----------------------------------------\n";
            return false;
        }

        else {
            continue;
        }
    }
}

void rentCars( carModelsCompanyHave cars[] ){
    customerInfo customer;
    cin.ignore();
    string strdays; 
    int days;
    do {
        cout << "For how many days do you want to rent: ";
        getline(cin, strdays);
    } while (strdays.find_first_not_of("0123456789") != string::npos || strdays.empty() || (days = stoi(strdays)) <= 0);


    cout<<"Please Enter the following information:\n";
    cin.ignore();
    cout<<"Full Name: ";
    getline(cin,customer.name);

    string strage; 
    int age;
    do {
        cout << "Age: "; 
        getline(cin, strage);
    } while (strage.find_first_not_of("0123456789") != string::npos || strage.empty() || (age = stoi(strage)) < 18);
    
    customer.age=age;

    cout<<"ID Number: ";
    getline(cin,customer.ID_number);

    cout<<"Phone: ";
    getline(cin,customer.phone);

    cout<<"Gender: ";
    getline(cin,customer.gender);

    cout<<"Email: ";
    getline(cin,customer.email);

    cout<<"Address: ";
    getline(cin,customer.address);

    customer.rentedDays=days;
    customer.totalPayment=cars[selectedIndexGlobal].rentPerDay*days; 
    
    cout << "\n\n";
    cout << "==============================================\n";
    cout << "          CONGRATULATIONS ON YOUR RENTAL!         \n";
    cout << "==============================================\n";
    cout << " Here is your car key information:\n\n";
    cout << "  Car Model      : " << cars[selectedIndexGlobal].carName << " " << cars[selectedIndexGlobal].model << "\n";
    cout << "  Plate Number   : " << cars[selectedIndexGlobal].plateNumber << "\n";
    cout << "  Seats          : " << cars[selectedIndexGlobal].seats << "\n";
    cout << "  Rent/Day       : $" << cars[selectedIndexGlobal].rentPerDay << "\n";
    cout << "  Days Rented    : " << customer.rentedDays << "\n";
    cout << "  Total Payment  : $" << customer.totalPayment << "\n";
    cout << "==============================================\n";
    cout << " Please drive safely and enjoy your ride!  \n";
    cout << "==============================================\n\n";

    
    ofstream file("RentalHistory.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << "=====================================================\n";
        file << "            🚗   YNY Car Rental - Receipt\n";
        file << "=====================================================\n\n";

        file << "👤 Customer Information:\n";
        file << "---------------------------------------------\n";
        file << "Full Name     : " << customer.name << '\n';
        file << "Age           : " << customer.age << '\n';
        file << "ID Number     : " << customer.ID_number << '\n';
        file << "Phone         : " << customer.phone << '\n';
        file << "Gender        : " << customer.gender << '\n';
        file << "Email         : " << customer.email << '\n';
        file << "Address       : " << customer.address <<endl<<endl;

        file << "🚘 Car Information:\n";
        file << "---------------------------------------------\n";
        file << "Car Name/Model: " << cars[selectedIndexGlobal].carName << " " << cars[selectedIndexGlobal].model << '\n';
        file << "Plate Number  : " << cars[selectedIndexGlobal].plateNumber << '\n';
        file << "Seats         : " << cars[selectedIndexGlobal].seats << '\n';
        file << "Rent per Day  : $" << cars[selectedIndexGlobal].rentPerDay << '\n';
        file << "Rented Days   : " << customer.rentedDays << '\n';
        file << "Total Payment : $" << customer.totalPayment << '\n';

        file << "\n=====================================================\n\n";

        file.close();
    }
    else {
        cout << "Error: Could not open RentalHistory.txt.\n";
    }
}

void updateCarstxt(carModelsCompanyHave cars[]){
    cars[selectedIndexGlobal].availability1="notavailable";
    cars[selectedIndexGlobal].availability2=false;

    ofstream file("cars.txt" , ios::out );

    if(file.is_open()){
        for(int i = 0 ; i < MAX_CARS ; i++){
            file<<cars[i].plateNumber<<" "<<cars[i].carName<<" "<<cars[i].model<<" "<<cars[i].rentPerDay<<" "<<cars[i].availability1<<" "<<cars[i].seats<<"\n";
        }
        file.close();
    }

    else{
        cout<<"Cars.txt couldn't be opened!!!";
    }
}

void returnCar(carModelsCompanyHave cars[]) {
    string returnPlateNumber;
    bool isFound = false;
    cin.ignore();
    while (!isFound) {
        cout << "\nPlease enter the plate number of the car (or type 0 to cancel): ";
        getline(cin, returnPlateNumber);

        if (returnPlateNumber == "0" || returnPlateNumber == "exit") {
            cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "            Return process cancelled by user.          \n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            return;
        }

        for (int i = 0; i < MAX_CARS; i++) {
            if (cars[i].plateNumber == returnPlateNumber) {
                cars[i].availability1 = "available";
                cars[i].availability2 = true;
                isFound = true;
                break;
            }
        }

        if (!isFound) {
            cout << "\n-----------------------------------------------------\n";
            cout << "  Plate number not found. Please try again.\n";
            cout << "-----------------------------------------------------\n";
        }
    }

    ofstream file("cars.txt");

    if (file.is_open()) {
        for (int i = 0; i < MAX_CARS; i++ ) {
            file << cars[i].plateNumber << " "<< cars[i].carName << " "<< cars[i].model << " "<< cars[i].rentPerDay << " "<< cars[i].availability1 << " "<< cars[i].seats << "\n";
        }
        file.close();

        cout << "\n=====================================================\n";
        cout << "|             Car returned successfully!            |\n";
        cout << "|             Record has been updated.              |\n";
        cout << "=====================================================\n";
    } else {
        cout << "\nError: Unable to open cars.txt for writing.\n";
    }
}




int main(){
    carModelsCompanyHave cars[MAX_CARS];

    while (true) {
        string input;
        int option;
        cout << "\n";
        cout << "==============================================\n";
        cout << "     Welcome to YNY Car Rental Service!       \n";
        cout << "==============================================\n";
        cout << " What can we help you with today?\n\n";
        cout << " 1  Rent a Car\n";
        cout << " 2  Return a Car\n";
        cout << " 0  Exit\n";
        cout << "----------------------------------------------\n";
        cout << " Please enter your choice (1, 2 or 0): ";
        getline(cin,input);

        
        while (input.length() != 1 || (input[0] != '0' && input[0] != '1' && input[0] != '2')) {
            cout << "\nPlease enter a valid input (1, 2 or 0): ";
            getline(cin,input);
        }

        
        option=stoi(input);

        if (option == 1) {
            if (displayCars(cars)) {
                rentCars(cars);
                updateCarstxt(cars);
            }
        } else if (option == 2) {
            recordCars(cars);
            returnCar(cars);
        } else if (option == 0) {
            cout << "\n-----------------------------------------\n";
            cout << "   Thank you for choosing YNY Car Rental!\n";
            cout << "   We hope to see you again. Goodbye!\n";
            cout << "-----------------------------------------\n";
            break;  
        }

        cout << "\nPress Enter to return to the main menu...";
        cin.ignore();
        cin.get();  
    }
    return 0;
}