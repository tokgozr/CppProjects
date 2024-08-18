#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int lowerBound = 1, upperBound = 100;
    int secretNumber, guess;
    int numberOfTries = 0;

    srand(time(0));
    secretNumber = lowerBound + rand() % (upperBound - lowerBound + 1);
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between " << lowerBound << " and " << upperBound << "." << endl;
    cout << "Try to guess it!" << endl;

    do{
        cout << "Enter your guess: ";
        cin >> guess;
        numberOfTries++;
        if (guess < lowerBound || guess > upperBound){
            cout << "Please enter a number between " << lowerBound << " and " <<upperBound << "." << endl;
        }
        else if (guess < secretNumber){
            cout << "Too low! Try Again." << endl;
        }
        else if (guess < secretNumber){
            cout << "Too high! Try Again." << endl;
        }
        else{
            cout << "Congratulations! You have guessed the number in " << numberOfTries << " tries." << endl;
        }
    }
    while (guess != secretNumber);
    return 0;
}
