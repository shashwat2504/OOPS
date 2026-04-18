#include <iostream>
using namespace std;

// ----------- Circle Class -----------
class Circle {
private:
    float radius;

public:
    Circle() {
        radius = 1;
        cout << "Circle Default Constructor called\n";
    }

    Circle(float r) {
        radius = r;
        cout << "Circle Parameterized Constructor called\n";
    }

    Circle(Circle &c) {
        radius = c.radius;
        cout << "Circle Copy Constructor called\n";
    }

    float area() {
        return 3.14 * radius * radius;
    }

    float perimeter() {
        return 2 * 3.14 * radius;
    }

    ~Circle() {
        cout << "Circle Destructor called\n";
    }
};

// ----------- Rectangle Class -----------
class Rectangle {
private:
    float length, width;

public:
    Rectangle() {
        length = 1;
        width = 1;
        cout << "Rectangle Default Constructor called\n";
    }

    Rectangle(float l, float w) {
        length = l;
        width = w;
        cout << "Rectangle Parameterized Constructor called\n";
    }

    Rectangle(Rectangle &r) {
        length = r.length;
        width = r.width;
        cout << "Rectangle Copy Constructor called\n";
    }

    float area() {
        return length * width;
    }

    float perimeter() {
        return 2 * (length + width);
    }

    ~Rectangle() {
        cout << "Rectangle Destructor called\n";
    }
};

// ----------- Main Function -----------
int main() {
    int choice;

    cout << "\n===== MENU =====\n";
    cout << "1. Circle Default Constructor\n";
    cout << "2. Circle Parameterized Constructor\n";
    cout << "3. Circle Copy Constructor\n";
    cout << "4. Rectangle Default Constructor\n";
    cout << "5. Rectangle Parameterized Constructor\n";
    cout << "6. Rectangle Copy Constructor\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {

        case 1: {
            Circle c;
            cout << "Area: " << c.area() << endl;
            cout << "Perimeter: " << c.perimeter() << endl;
            break;
        }

        case 2: {
            float r;
            cout << "Enter radius: ";
            cin >> r;
            Circle c(r);
            cout << "Area: " << c.area() << endl;
            cout << "Perimeter: " << c.perimeter() << endl;
            break;
        }

        case 3: {
            Circle c1(5);
            Circle c2 = c1;
            cout << "Area (Copied): " << c2.area() << endl;
            cout << "Perimeter (Copied): " << c2.perimeter() << endl;
            break;
        }

        case 4: {
            Rectangle r;
            cout << "Area: " << r.area() << endl;
            cout << "Perimeter: " << r.perimeter() << endl;
            break;
        }

        case 5: {
            float l, w;
            cout << "Enter length and width: ";
            cin >> l >> w;
            Rectangle r(l, w);
            cout << "Area: " << r.area() << endl;
            cout << "Perimeter: " << r.perimeter() << endl;
            break;
        }

        case 6: {
            Rectangle r1(4, 6);
            Rectangle r2 = r1;
            cout << "Area (Copied): " << r2.area() << endl;
            cout << "Perimeter (Copied): " << r2.perimeter() << endl;
            break;
        }

        default:
            cout << "Invalid choice!";
    }

    return 0;
}