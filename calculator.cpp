/******************************************************************************** 
 * his C++ program functions as a simple calculator that evaluates a sequence of numbers and operations entered by the user. 
 * The calculator supports five operators: +, -, *, /, and %, and handles operator precedence (i.e., multiplication, division, and modulus are evaluated before addition and subtraction). 
 * The user is prompted to enter numbers and operators in sequence and ends input with the = sign. 
 * If division or modulus by zero occurs, the program detects it and displays an appropriate error message. 
 * The program uses arrays to store the numbers and operations, and performs two passes: one to handle high-precedence operations and one to finish the rest.
 
*********************************************************************************/

#include <iostream>

using namespace std;

int x = 0;  // Global flag variable to indicate division/modulus by zero

// Function to perform the required calculation based on operator
double calculate(double num1, double num2, char oper){
    switch (oper){
        case '+': 
            return num1 + num2;
        case '-': 
            return num1 - num2;
        case '*': 
            return num1 * num2;
        case '/': 
            if(num2 == 0){
                x++;  // Set error flag
                return 0;
            }
            return num1 / num2;
        case '%': 
            if(num2 == 0){
                x++;  // Set error flag
                return 0;
            }
            // Cast to int for modulus operation
            return static_cast<int>(num1) % static_cast<int>(num2);
        default:
            cout << "Unknown operator";
            return 0;
    }
}

int main(){
    int indexO = 0, indexN = 0;         // Index counters for operators and numbers
    char opp[100] = {0};                // Array to store operators
    double num[100] = {0}, number;      // Array to store numbers

    cout << "Enter the number and the operations when you finish hit the = sign\n";

    // Input loop: accepts number followed by operator until '=' is entered
    while(true){
        cin >> number;
        num[indexN] = number;
        cin >> opp[indexO];
        if (opp[indexO] == '='){
            break;
        }
        indexN++;
        indexO++;
    }

    // First pass: handle *, /, and % with proper precedence
    for(int i = 0; i < indexO; i++){
        if (opp[i] == '*' || opp[i] == '/' || opp[i] == '%'){
            double result = calculate(num[i], num[i+1], opp[i]);
            num[i] = result;  // Store result in current position

            // Shift numbers left to fill the gap
            for (int j = i+1; j < indexN; j++) {
                num[j] = num[j+1]; 
            }

            // Shift operators left to remove used operator
            for (int j = i; j < indexO-1; j++) {
                opp[j] = opp[j+1];
            }

            indexN--;  // One less number
            indexO--;  // One less operator
            i--;       // Reevaluate at current position
        }
    }

    // Second pass: handle remaining + and - from left to right
    double finalResult = num[0];
    for (int i = 0; i < indexO; i++) {
        finalResult = calculate(finalResult, num[i+1], opp[i]);
    }

    // Display result or error if division/modulus by zero occurred
    if(x != 0){
        cout << "Error division by zero!!";
    }
    else{
        cout << finalResult << endl;
    }

    return 0;
}
