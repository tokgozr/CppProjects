#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile(){
    string fileName;
    cout << "Please enter the name of file you want to create: ";
    cin >> fileName;
    ofstream file(fileName);

    if(file.is_open())
    {
        cout << fileName << "The file created successfully!" << endl;
        file.close();
    }
    else
        cout << "The file could not be created!" << endl;
}

void writeFile(){
    string fileName;
    cout << "Please enter the name of file you want to write: ";
    cin >> fileName;
    ofstream file(fileName, ios:: app); // add to end

    if (file.is_open())
    {
        string text;
        cout << "Enter your text. (To finish, press ':q'" << endl;
        cin.ignore();

        while (getline(cin, text)){
            if (text == ":q")
                break;
            file << text << endl;
        }
        file.close();
        cout << " Text successfully written to file" << fileName << "!" << endl;
    }
    else
        cout << "The file could not be opened!" << endl;
}

void readFile(){
    string fileName;
    cout << "Please enter the name of file you want to read: ";
    cin >> fileName;
    ifstream file(fileName);

    if (file.is_open()) {
        string line;
        cout << fileName << " content of file: " << endl;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else
        cout << "The file could not be opened!." << endl;
}

int main()
{
    int choice;

    do {
        cout << "\n1.Create File\n2.Write to File\n3.Read File\n4.Exit";
        cout << "Make your choice!: " << endl;
        cin >> choice;

        switch(choice)
        {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    }
    while (choice != 4);

    return 0;
}
