#include <iostream>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

string generatePassword(int length)
{
    const string characters = "abcdefghijklmnopqrstuvwxyz"
                              "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                              "0123456789"
                              "!@#$%^&*()_+-=[]{}|;:,.<>?";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, characters.size() - 1);

    string password;
    password.resize(length);

    generate(password.begin(), password.end(), [&]() { return characters[dis(gen)];});
    return password;
}
int main()
{
    int length;
    cout << "Enter the wanted length for the password: ";
    cin >> length;

    if (length <= 0)
    {cout << "Password length must be greater than 0.\n";
        return 1;
    }
   string password = generatePassword(length);
   cout << "Generated password: " << password << endl;

   return 0;
}
