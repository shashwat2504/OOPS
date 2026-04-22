#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Person{
public:
    string name;
    string address;

    Person(string name, string address){
        this->name = name;
        this->address = address;
    }

    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Directory : public Person{
public:
    string phone;

    Directory(string name, string address, string phone)
        : Person(name, address)
    {
        this->phone = phone;
    }

   
    string getPhone(){
        return phone;
    }

    string getPhone(string countryCode){
        return countryCode + "-" + phone;
    }

    void display() override {
        Person::display();
        cout << "Phone: " << phone << endl;
    }

    // 🔥 File Handling
    void saveFile(){
        ofstream File("directory.txt", ios::app);
        File << name << "," << address << "," << phone << endl;
        File.close();
    }
};

int main(){
    vector<Directory> contacts;
    int choice;

    try {
        do{
            cout << "\n===== DIRECTORY MENU =====\n";
            cout << "1. Add Contact\n";
            cout << "2. Display All Contacts\n";
            cout << "3. Search by Phone\n";
            cout << "4. Show Phone with Country Code\n";
            cout << "5. Save All to File\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice){

                case 1: {
                    string name, address, phone;

                    cout << "Enter Name: ";
                    cin >> name;

                    cout << "Enter Address: ";
                    cin >> address;

                    cout << "Enter Phone: ";
                    cin >> phone;

                    if(phone.length() < 5){
                        throw "Invalid phone number!";
                    }

                    contacts.push_back(Directory(name, address, phone));
                    cout << "Contact added!\n";
                    break;
                }

                case 2: {
                    if(contacts.empty()){
                        throw "No contacts available!";
                    }

                    for(auto &c : contacts){
                        c.display();
                        cout << "-------------------\n";
                    }
                    break;
                }

                case 3: {
                    if(contacts.empty()){
                        throw "No contacts available!";
                    }

                    string searchPhone;
                    cout << "Enter phone number to search: ";
                    cin >> searchPhone;

                    bool found = false;

                    for(auto &c : contacts){
                        if(c.getPhone() == searchPhone){
                            cout << "Contact found:\n";
                            c.display();
                            found = true;
                            break;
                        }
                    }

                    if(!found){
                        throw "Contact not found!";
                    }

                    break;
                }

                case 4: {
                    if(contacts.empty()){
                        throw "No contacts available!";
                    }

                    string code;
                    cout << "Enter country code (e.g., +91): ";
                    cin >> code;

                    for(auto &c : contacts){
                        cout << c.name << ": "
                             << c.getPhone(code) << endl;
                    }
                    break;
                }

                case 5: {
                    if(contacts.empty()){
                        throw "No contacts to save!";
                    }

                    for(auto &c : contacts){
                        c.saveFile();
                    }

                    cout << "All contacts saved to file!\n";
                    break;
                }

                case 6:
                    cout << "Exiting...\n";
                    break;

                default:
                    cout << "Invalid choice!\n";
            }

        } while(choice != 6);
    }

    catch(const char* msg){
        cout << "Error: " << msg << endl;
    }

    return 0;
}