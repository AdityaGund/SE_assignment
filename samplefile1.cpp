#include <iostream>
using namespace std;

// Function to perform basic arithmetic operations
float calculator(float num1, float num2, char operation) {
    switch(operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if(num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return -1;  // Returning an error value
            }
        default:
            cout << "Invalid operator!" << endl;
            return -1;  // Returning an error value
    }
}

// Function to run tests and compare with expected results
void run_test(float num1, float num2, char operation, float expected) {
    float result = calculator(num1, num2, operation);

    if(result == expected) {
        cout << "Test passed: " << num1 << " " << operation << " " << num2 
             << " = " << expected << endl;
    } else {
        cout << "Test failed: " << num1 << " " << operation << " " << num2 
             << " (Expected: " << expected << ", Got: " << result << ")" << endl;
    }
}

int main() {
    // Basic user interaction
    float num1, num2;
    char operation;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;

    float result = calculator(num1, num2, operation);
    if(result != -1) {
        cout << "Result: " << result << endl;
    }

    // Running conformance tests
    cout << "\nRunning conformance tests...\n";
    run_test(10, 5, '+', 15);   // Test addition
    run_test(10, 5, '-', 5);    // Test subtraction
    run_test(10, 5, '*', 50);   // Test multiplication
    run_test(10, 5, '/', 2);    // Test division
    run_test(10, 0, '/', -1);   // Test division by zero
    run_test(10, 5, '%', -1);   // Test invalid operator
    cout << "Conformance tests completed.\n";

    return 0;
}
