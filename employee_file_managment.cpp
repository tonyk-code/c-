/****************************************************************************************
Write a C++ program that permits users to enter the following information about your small company’s 10 employees, 
sorts the information in ascending ID number, and then writes the sorted information to a file:
    ID No. 	Sex(M/F) 	Hourly-Wage 	Years-with-the-Company
    After the records are stored successfully, 
write a program that reads the file created one record at a time, asks for the number of hours each employee worked each month, 
and calculates and displays each employee’s total pay for the month
Develop a program that reads the file created and changes the hourly wage or years for each employee, and creates a new updated file

****************************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

struct information {
    int id_number;
    char gender;
    int hourly_wage;
    int years_in_the_company;
};

void ascending_order(information info[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (info[j].id_number > info[j + 1].id_number) {
                swap(info[j], info[j + 1]);
                /* swap(info[j].id_number,info[j+1].id_number);
                swap(info[j].gender,info[j+1].gender);
                swap(info[j].Hourly_wage,info[j+1].Hourly_wage);
                swap(info[j].years_in_the_company,info[j+1].years_in_the_company); */
            }
        }
    }
}

void getrecords(information info[], int n) {
    ofstream file("employee.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            cout << "Enter the employee information: " << endl;
            cout << "ID: ";
            cin >> info[i].id_number;
            cout << "Gender (M/F): ";
            cin >> info[i].gender;
            cout << "Hourly Wage: ";
            cin >> info[i].hourly_wage;
            cout << "Years with the company: ";
            cin >> info[i].years_in_the_company;
        }
        ascending_order(info, n);
        for (int i = 0; i < n; i++) {
            file << info[i].id_number << " "
                 << info[i].gender << " "
                 << info[i].hourly_wage << " "
                 << info[i].years_in_the_company << endl;
        }
        file.close();
    } else {
        cout << "Employee file couldn't be opened!" << endl;
    }
}

void calculateMonthlyPay(int n) {
    ifstream file("employee.txt");
    if (!file.is_open()) {
        cout << "Unable to open employee file." << endl;
        return;
    }
    information info;
    int hours;
    cout << "\nMonthly Pay Report:\n";
    while (file >> info.id_number >> info.gender >> info.hourly_wage >> info.years_in_the_company) {
        cout << "Enter hours worked this month by employee " << info.id_number << ": ";
        cin >> hours;
        int total_pay = hours * info.hourly_wage;
        cout << "ID: " << info.id_number << " | Pay: $" << total_pay << endl;
    }
    file.close();
}

void updateRecord(int n) {
    ifstream infile("employee.txt");
    information info[10];
    int i = 0;
    while (i < n && infile >> info[i].id_number >> info[i].gender >> info[i].hourly_wage >> info[i].years_in_the_company) {
        i++;
    }
    infile.close();

    for (int j = 0; j < i; j++) {
        cout << "Update info for employee ID " << info[j].id_number << ":\n";
        cout << "Current Hourly Wage: " << info[j].hourly_wage << ", enter new (or -1 to keep): ";
        int new_wage;
        cin >> new_wage;
        if (new_wage != -1) info[j].hourly_wage = new_wage;

        cout << "Current Years: " << info[j].years_in_the_company << ", enter new (or -1 to keep): ";
        int new_years;
        cin >> new_years;
        if (new_years != -1) info[j].years_in_the_company = new_years;
    }

    ofstream outfile("employee_updated.txt");
    for (int j = 0; j < i; j++) {
        outfile << info[j].id_number << " "
                << info[j].gender << " "
                << info[j].hourly_wage << " "
                << info[j].years_in_the_company << endl;
    }
    outfile.close();
    cout << "Records updated and saved to 'employee_updated.txt'\n";
}

int main() {
    const int num_employees = 10;
    information info[num_employees];
    getrecords(info, num_employees);
    calculateMonthlyPay(num_employees);
    updateRecord(num_employees);
    return 0;
}
