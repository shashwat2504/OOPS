#include <iostream>
using namespace std;

// Base Class
class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing a shape" << endl;
    }
};

// Derived Class - Circle
class Circle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing a Circle" << endl;
    }
};

// Derived Class - Rectangle
class Rectangle : public Shape
{
public:
    void draw()
    {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main()
{
    Shape *s;   // Base class pointer
    int choice;

    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Draw Circle" << endl;
        cout << "2. Draw Rectangle" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                Circle c;
                s = &c;
                s->draw();   // Polymorphism
                break;
            }

            case 2:
            {
                Rectangle r;
                s = &r;
                s->draw();   // Polymorphism
                break;
            }

            case 3:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 3);

    return 0;
}