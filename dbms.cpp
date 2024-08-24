#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Record {
    int id;
    string name;
    int age;
};

void addRecord() {
    Record record;
    ofstream file("database.txt", ios::app); //open file in append mode

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    cout << "Enter ID: ";
    cin >> record.id;
    cout << "Enter Name: ";
    cin.ignore(); //clear input buffer
    getline(cin, record.name);
    cout << "Enter Age: ";
    cin >> record.age;

    file << record.id << " " << record.name << " " << record.age << endl;

    file.close();
}

void deleteRecord() {
    int id;
    cout << "Enter ID of the record to delete: ";
    cin >> id;

    ifstream file("database.txt");
    ofstream temp("temp.txt");

    if (!file || !temp) {
        cout << "Error opening file!" << endl;
        return ;
    }

    Record record;
    bool found = false;
    string line;

     while (getline(file, line)) {
        istringstream iss(line);
        iss >> record.id >> ws;
        getline(iss, record.name, ' ');
        iss >> record.age;

        if (record.id == id) {
            found = true;
            continue; // Skip this record
        }

        temp << record.id << " " << record.name << " " << record.age << endl;
    }

    file.close();
    temp.close();

    remove("database.txt");
    rename("temp.txt", "database.txt");

    if (found) {
        cout << "Record deleted successfully!" << endl;
    } else {
        cout << "Record with ID " << id << " not found." << endl;
    }
}

void displayRecords() {
    ifstream file("database.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Record record;
    string line;

    cout << "ID\tName\tAge" << endl;
    cout << "----------------------" << endl;

     while (getline(file, line)) {
        istringstream iss(line);
        iss >> record.id >> ws;
        getline(iss, record.name, ' ');
        iss >> record.age;

        cout << record.id << "\t" << record.name << "\t" << record.age << endl;
    }
    file.close();
}

int main()
{
    int choice;
    do {
        cout << "Mini Database Management System" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Display Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addRecord();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            displayRecords();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    }
    while (choice!= 4);

    return 0;
}
