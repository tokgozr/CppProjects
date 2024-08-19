#include <iostream>
#include <string>
#include <sstream> //stringstream
using namespace std;

int main()
{
    string text;
    int wordCount = 0;

    cout << "Enter a sentence or paragraph: ";
    getline(cin, text);

    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        wordCount++;
    }
    cout << "The total number of words is: " << wordCount << endl;
    return 0;
}
