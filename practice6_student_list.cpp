#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Student{
protected:
    string name;
    int roll;

public:
    Student(string name, int roll){
        this->name = name;
        this->roll = roll;
    }

    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Roll: " << roll << endl;
    }
};

class Result : public Student{
    float marks;
    vector<float> v;

public:
    Result(string name, int roll, int n) : Student(name, roll){
        if(n <= 0){
            throw "Invalid number of subjects!";
        }

        float m, sum = 0;

        for(int i = 0; i < n; i++){
            cout << "Enter marks for subject " << i+1 << ": ";
            cin >> m;
            v.push_back(m);
            sum += m;
        }

        marks = sum / n;
    }


    float getAverage(){
        return marks;
    }

    float getAverage(float bonus){
        return marks + bonus;
    }

    float getHighestMarks(){
        float maxMarks = v[0];
        for(float m : v){
            if(m > maxMarks){
                maxMarks = m;
            }
        }
        return maxMarks;
    }

    void display() override {
        Student::display();
        cout << "Average Marks: " << marks << endl;
        cout << "Highest Marks: " << getHighestMarks() << endl;
    }

    void saveFile1(){
        ofstream File("student.txt", ios::app);
        File << roll << "," << name << "," 
             << marks << "," << getHighestMarks() << endl;
        File.close();
        cout << "Data saved successfully!\n";
    }
};

int main(){
    int roll, choice, n;
    string name;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter roll number: ";
    cin >> roll;

    cout << "How many subjects? ";
    cin >> n;

    try {
        Result res(name, roll, n);

       
        Student* ptr = &res;

        do{
            cout << "\n===== MENU =====\n";
            cout << "1. Display Details\n";
            cout << "2. Show Average Marks\n";
            cout << "3. Show Average with Bonus\n";
            cout << "4. Show Highest Marks\n";
            cout << "5. Save to File\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch(choice){
                case 1:
                    ptr->display();   
                    break;

                case 2:
                    cout << "Average Marks: " 
                         << res.getAverage() << endl;
                    break;

                case 3:
                    cout << "Average with Bonus (+5): "
                         << res.getAverage(5) << endl;
                    break;

                case 4:
                    cout << "Highest Marks: "
                         << res.getHighestMarks() << endl;
                    break;

                case 5:
                    res.saveFile1();
                    break;

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
}