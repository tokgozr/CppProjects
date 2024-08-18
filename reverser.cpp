#include <iostream>
#include <string>

using namespace std;
int main()
{
    string input;
    cout << "Bir kelime veya cumle giriniz: \n";
    getline(cin,input);

    string reversed;
    for(int i = input.length()-1; i>=0;i--)
    {
        reversed += input[i];
    }
    cout << "Tersine cevrilmis hali: " << reversed << endl;
    return 0;
}
