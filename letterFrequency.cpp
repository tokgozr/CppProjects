#include <iostream>
#include <string>
#include <map> // map
#include <cctype> // tolower
using namespace std;

int main()
{
    string text;
    map<char, int> frequency;

    cout << "Enter a sentence or paragraph: ";
    getline(cin, text);

    for (char ch : text)
    {
        ch = tolower(ch);

        if (isalpha(ch))
        {
            frequency[ch]++;
        }
    }
    cout << "Letter frequency:\n";
    for (auto pair : frequency)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
   return 0;
}
