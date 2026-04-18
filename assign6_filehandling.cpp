#include<iostream>
#include<fstream>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    int marks;
};

int main()
{
    Student s[10];   // array of objects
    int i = 0;

    ifstream fin("input.txt");   // open file for reading
    ofstream fout("output.txt"); // open file for writing

    // Check if file opened
    if (!fin)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    // Read data from file
    while (fin >> s[i].roll >> s[i].name >> s[i].marks)
    {
        i++;
    }

    fin.close();

    // Display data
    cout << "Student Data:\n";
    for (int j = 0; j < i; j++)
    {
        cout << s[j].roll << " "
             << s[j].name << " "
             << s[j].marks << endl;
    }

    // Write data to output file
    for (int j = 0; j < i; j++)
    {
        fout << s[j].roll << " "
             << s[j].name << " "
             << s[j].marks << endl;
    }

    fout.close();

    cout << "\nData written to output.txt";

    return 0;
}