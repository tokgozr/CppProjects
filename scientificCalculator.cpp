#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
void showMenu()
{
    cout << "\nScientific Calculator Menu:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Square Root" << endl;
    cout << "6. Power (Exponentiation)" << endl;
    cout << "7. Logarithm (Base 10)" << endl;
    cout << "8. Natural Logarithm (Base e)" << endl;
    cout << "9. Sine" << endl;
    cout << "10. Cosine" << endl;
    cout << "11. Tangent" << endl;
    cout << "12. Factorial" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}
double factorial(int num) {
    if (num < 0) return -1;  // Error case
    if (num == 0 || num == 1) return 1;
    double result = 1;
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}
void performOperation(int choice) {
    vector<double> numbers;
    double num;

    cout << "Enter numbers (separated by space). Type 'x' to stop: ";

    // Read multiple numbers from the user
    while (cin >> num) {
        numbers.push_back(num);
    }
    cin.clear(); // Clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input

    switch (choice) {
        case 1: { // Addition
            double sum = 0;
            for (double n : numbers) {
                sum += n;
            }
            cout << "Result: " << fixed << setprecision(2) << sum << endl;
            break;
        }
        case 2: { // Subtraction
            if (numbers.size() < 2) {
                cout << "Error: At least two numbers are required for subtraction." << endl;
                break;
            }
            double result = numbers[0];
            for (size_t i = 1; i < numbers.size(); ++i) {
                result -= numbers[i];
            }
            cout << "Result: " << fixed << setprecision(2) << result << endl;
            break;
        }
        case 3: { // Multiplication
            double product = 1;
            for (double n : numbers) {
                product *= n;
            }
            cout << "Result: " << fixed << setprecision(2) << product << endl;
            break;
        }
        case 4: { // Division
            if (numbers.size() < 2) {
                cout << "Error: At least two numbers are required for division." << endl;
                break;
            }
            double result = numbers[0];
            for (size_t i = 1; i < numbers.size(); ++i) {
                if (numbers[i] != 0) {
                    result /= numbers[i];
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return;
                }
            }
            cout << "Result: " << fixed << setprecision(2) << result << endl;
            break;
        }
        case 5: { // Square Root
            if (numbers.size() != 1) {
                cout << "Error: Square root requires exactly one number." << endl;
                break;
            }
            if (numbers[0] >= 0) {
                cout << "Result: " << fixed << setprecision(2) << sqrt(numbers[0]) << endl;
            } else {
                cout << "Error: Cannot compute the square root of a negative number." << endl;
            }
            break;
        }
        case 6: { // Power
            if (numbers.size() != 2) {
                cout << "Error: Power operation requires exactly two numbers (base and exponent)." << endl;
                break;
            }
            cout << "Result: " << fixed << setprecision(2) << pow(numbers[0], numbers[1]) << endl;
            break;
        }
        case 7: { // Logarithm (Base 10)
            if (numbers.size() != 1) {
                cout << "Error: Logarithm requires exactly one number." << endl;
                break;
            }
            if (numbers[0] > 0) {
                cout << "Result: " << fixed << setprecision(2) << log10(numbers[0]) << endl;
            } else {
                cout << "Error: Logarithm of zero or negative number is undefined." << endl;
            }
            break;
        }
        case 8: { // Natural Logarithm (Base e)
            if (numbers.size() != 1) {
                cout << "Error: Natural logarithm requires exactly one number." << endl;
                break;
            }
            if (numbers[0] > 0) {
                cout << "Result: " << fixed << setprecision(2) << log(numbers[0]) << endl;
            } else {
                cout << "Error: Natural logarithm of zero or negative number is undefined." << endl;
            }
            break;
        }
        case 9: { // Sine
            if (numbers.size() != 1) {
                cout << "Error: Sine function requires exactly one angle in degrees." << endl;
                break;
            }
            double angle = numbers[0] * (M_PI / 180.0); // Convert degrees to radians
            cout << "Result: " << fixed << setprecision(2) << sin(angle) << endl;
            break;
        }
        case 10: { // Cosine
            if (numbers.size() != 1) {
                cout << "Error: Cosine function requires exactly one angle in degrees." << endl;
                break;
            }
            double angle = numbers[0] * (M_PI / 180.0); // Convert degrees to radians
            cout << "Result: " << fixed << setprecision(2) << cos(angle) << endl;
            break;
        }
        case 11: { // Tangent
            if (numbers.size() != 1) {
                cout << "Error: Tangent function requires exactly one angle in degrees." << endl;
                break;
            }
            double angle = numbers[0] * (M_PI / 180.0); // Convert degrees to radians
            cout << "Result: " << fixed << setprecision(2) << tan(angle) << endl;
            break;
        }
        case 12: { // Factorial
            if (numbers.size() != 1) {
                cout << "Error: Factorial function requires exactly one non-negative integer." << endl;
                break;
            }
            int intNum = static_cast<int>(numbers[0]);
            double factResult = factorial(intNum);
            if (factResult < 0) {
                cout << "Error: Factorial is not defined for negative numbers." << endl;
            } else {
                cout << "Result: " << fixed << setprecision(2) << factResult << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice. Please enter a number from the menu." << endl;
            break;
    }
}
int main()
{
    int choice;

    while(true){
        showMenu();
        cin >> choice;

        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from the menu." << endl;
            continue;
        }

        if (choice == 0)
        {
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        }

        performOperation(choice);
    }
    return 0;
}
