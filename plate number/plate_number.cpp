/*
===========================================================
Team Project: Ethiopian License Plate Generator
Contributors: GitHub: @tonk-code, GitHub: @isaacydk
Description:
This C++ program simulates the process of generating Ethiopian license plates
based on various criteria such as:
- Type of vehicle (Private, Government, Diplomatic, Commercial, Specialized)
- Travel history (domestic/international)
- Region selection
- Custom plate number and alphabet combinations

Features:
- Displays all possible plate number and prefix combinations
- Supports custom input to generate a specific license plate design
- Handles formatting and display with regions and plate types

Note: The `possible_combination` function shows all prefix/number combinations.
The final plate is then chosen by the user.

Purpose:
This project is part of a team effort for software engineering studies and practice.

===========================================================
*/

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// Predefined license plate types and regional codes
string stateTypes[5] = {"Private", "Government", "Diplomatic", "Commercial", "Specializedlicenceplate"};
string regions[13] = {"AA", "AF", "AM", "BE", "DD", "GA", "HA", "OR", "SN", "SW", "SO", "SI","TI" };

// Function declarations
void display(int licence_type,string plate_number,string region,string character);
void OOOOOformat(int number,int range);

// Displays all possible combinations of license numbers and letter prefixes
void possible_combination(int range,int licencetype,string region){
    long long int count=0;
    string prefix,plate_number;

    for(int i=1;i<=range;i++){
        cout<<++count<<". ";
        OOOOOformat(i,range);
        cout<<endl;
    }

    for (char j='A';j<='Z';j++){
        for(int i=1;i<=range;i++){
            cout<<++count<<". "<<j<<" ";
            OOOOOformat(i,range);
            cout<<endl;
        }
    }
    for (char k='A';k<='Z';k++){
        for (char j='A';j<='Z';j++){
            for(int i=1;i<=range;i++){
                cout<<++count<<". "<<k<<j<<" ";
                OOOOOformat(i,range);
                cout<<endl;
            }
        }
    }
    for (char l='A';l<='Z';l++){
        for (char k='A';k<='Z';k++){
            for (char j='A';j<='Z';j++){
                for(int i=1;i<=range;i++){
                    cout<<++count<<". "<<l<<k<<j<<" ";
                    OOOOOformat(i,range);
                    cout<<endl;
                }
            }
        }
    }  
    // User selects one of the combinations displayed
    cout<<"Enter the plate number you want(000001-00009): ";
    cin>>plate_number;
    cout<<"Enter the aplhabet(A-Z or AA-ZZ or AAA-ZZZ): ";
    cin>>prefix;
    display(licencetype,plate_number,region,prefix);
}

// Region selection helper function
void region_asking(){
    cout<<"please , choose a region: \n";
    cout<<"0 - for Addis Ababa.\n";
    cout<<"1 - for afar.\n";
    cout<<"2 - for amhara.\n";
    cout<<"3 - for benishangul-gumuz.\n";
    cout<<"4 - for Dire Dawa.\n";
    cout<<"5 - for gambela.\n";
    cout<<"6 - for harari.\n"; 
    cout<<"7 - for oromia.\n";
    cout<<"8 - for southern nations,nationalities and peoples(SNNPR).\n";
    cout<<"9 - for southwest ethiopia peoples.\n";
    cout<<"10  - for somali.\n";
    cout<<"11 - for sidama.\n";
    cout<<"12 - for Tigray.\n";
}

int main(){
    string state_type;
    int state_no;
    
    // Ask the user for the type of license plate
    cout<<"Select the type of license plate based on its purpose: "<<endl;
    cout<<"0 - for private"<<endl;
    cout<<"1 - for Government"<<endl;
    cout<<"2 - for Diplomatic"<<endl;
    cout<<"3 - for Commercial"<<endl;
    cout<<"4 - for Specialized licence plate"<<endl;
    cin>>state_no;
    state_type=stateTypes[state_no] ;

    // Declare control variables
    char decision;
    int range;

    // Handle different state types
    if (state_type == "Private"){
        cout<<"Did you travel outside the country? (y for yes, n for no):";
        cin>>decision;

        if (decision == 'y' || decision == 'Y'){   
            range = 10000;
            possible_combination(range,2,"ET");
        }
        else if (decision == 'n' || decision == 'N'){
            string region;
            int region_no;
            region_asking();
            cin>>region_no;

            region = regions[region_no];

            int licence_types;
            cout<<"Enter the licence type"<<endl;
            cout<<"1 - for taxi"<<endl;
            cout<<"2 - for private car"<<endl;
            cin>>licence_types;
            if(licence_types ==1 || licence_types == 2 ) {
                 range = 10000;
                possible_combination(range,licence_types,region);
            }
            else {
                cout<<"Error!"<<endl;
            }
        }
    }
    else if (state_type == "Government")
    {
        cout<<"Do you want for Government institution(G), police(P) or Federal defence(F)?";
        cin>>decision;
        if( decision == 'G' || decision == 'g' ){
            int range=10000;
            possible_combination(range,4,"ET");
        }
        else if( decision == 'p' || decision == 'P' ){
            int range=10000;
            string region;
            int region_no;
            region_asking();
            cin>>region_no;
            region = regions[region_no];
            possible_combination(range,4,region);
        }
        else if( decision == 'F' || decision == 'f' ){
            int range=10000;
            possible_combination(range,4,"DF");
        }
        else{
            cout<<"Invalid input!!!";
        }
    }
    else if (state_type == "Diplomatic")
    {
        int country_code;
        cout<<"Ente a country code "<<endl;
        cout<<"001 - for Italy"<<endl;
        cout<<"002 - for France"<<endl;
        cout<<"003 - for United Kingdom"<<endl;
        cout<<"004 - for United States of America"<<endl;
        cout<<"005 - for Belgium"<<endl;
        cout<<"006 - for Turkey"<<endl;
        cout<<"007 - for Egypt"<<endl;
        cout<<"008 - for Greece"<<endl;
        cout<<"009 - for Czech Republic"<<endl;
        cout<<"010 - for Russia"<<endl;
    
        cin>>country_code;
        range = 1000;
        cout<<"Here is the possible combination for your licence plate"<<endl;
        possible_combination(range,4,"CD");
    }
    else if (state_type == "Commercial")
    {
        cout<<"Did you travel out side the country (y- for yes n-for no)";
        cin>>decision;
        if (decision == 'y' || decision == 'Y'){   
            range = 10000 ;
            possible_combination(range,3,"ET");
        }
        else if (decision == 'n' || decision == 'N'){
            string region;
            int region_no;
            region_asking();
            cin>>region_no;

            region = regions[region_no];
            cout<<"Your licence plate is type 3"<<endl;
            int licence_types = 3;
            range = 10000;
            possible_combination(range,licence_types,region);
        }
    }
    else if (state_type == "Specializedlicenceplate"){
        int special_type;
        cout<<"Its for UN or AU(1 for UN , 2 - AU )"<<endl;
        cin>>special_type;
    
        if (special_type == 1){
            range = 100;
            possible_combination(range,4,"UN");
        }
        else if (special_type == 2){
            range = 10000;
            possible_combination(range,4,"AU");
        }
        else{
            cout<<"Error!"<<endl;
        }
    }
    
    return 0;
}

// Function to display the final formatted license plate
void display(int licence_type,string plate_number,string region,string character){
    char a=region[0];
    char b=region[1];

    cout<<setw(22)<<"----------------------"<<endl;
    cout<<setw(8)<<"|       "<<setw(1)<<a<<setw(13)<<"|"<<endl;
    cout<<setw(5) <<"|   ("<<setw(1)<<licence_type<<setw(5)<<")    "<<setw(3)<<character<<setw(5)<<plate_number<<setw(3)<<"  |"<<endl;
    cout<<setw(8)<<"|       "<<setw(1)<<b<<setw(13)<<"|"<<endl;
    cout<<setw(22)<<"----------------------"<<endl;
}

// Formats the numeric part of the plate based on the range
void OOOOOformat(int number,int range){
    int remainder,x;
    if(range==100){
        x=100;
        for(int j=1; j<=3;j++){
            remainder=number%x;
            number=number/x;
            cout<<number<<" ";
            x=x/10;
            number=remainder;
        }
    }
    else if(range==1000){
        x=1000;
        for(int j=1; j<=4;j++){
            remainder=number%x;
            number=number/x;
            cout<<number<<" ";
            x=x/10;
            number=remainder;
        }
    }
    else{
        x=10000;
        for(int j=1; j<=5;j++){
            remainder=number%x;
            number=number/x;
            cout<<number<<" ";
            x=x/10;
            number=remainder;
        }
    }
}
