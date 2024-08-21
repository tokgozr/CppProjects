#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Contact 
{
    string name;
    string phone;
    string email;
};

void addContact(vector<Contact>& addressBook) 
{
    Contact newContact;
    cout << "Isim: ";
    cin.ignore(); // Bu, önceki girişten kalan newline karakterini temizlemek için kullanılır.
    getline(cin, newContact.name);
    cout << "Telefon: ";
    getline(cin, newContact.phone);
    cout << "E-posta: ";
    getline(cin, newContact.email);
    addressBook.push_back(newContact);
    cout << "Yeni kisi eklendi!" << endl;
}

void deleteContact(vector<Contact>& addressBook) 
{
    string name;
    cout << "Silmek istediginiz kisinin adini girin: ";
    cin.ignore();
    getline(cin, name);

    for (auto it = addressBook.begin(); it != addressBook.end(); ++it) 
    {
        if (it->name == name) 
        {
            addressBook.erase(it);
            cout << name << " basariyla silindi!" << endl;
            return;
        }
    }
    cout << "Kisi bulunamadi!" << endl;
}

void listContacts(const vector<Contact>& addressBook) 
{
    if (addressBook.empty()) 
        cout << "Adres defteri bos!" << endl;
    else {
        for (const auto& contact : addressBook) 
        {
            cout << "Isim: " << contact.name << ", Telefon: " << contact.phone << ", E-posta: " << contact.email << endl;
        }
    }
}

int main() {
    vector<Contact> addressBook;
    int choice;

    do {
        cout << "\nAdres Defteri Menu" << endl;
        cout << "1. Yeni kisi ekle" << endl;
        cout << "2. Kisi sil" << endl;
        cout << "3. Tum kisileri listele" << endl;
        cout << "4. Cikis" << endl;
        cout << "Secim yapin: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addContact(addressBook);
                break;
            case 2:
                deleteContact(addressBook);
                break;
            case 3:
                listContacts(addressBook);
                break;
            case 4:
                cout << "Cikis yapiliyor..." << endl;
                break;
            default:
                cout << "Gecersiz secim!" << endl;
        }
    } while (choice != 4);

    return 0;
}
