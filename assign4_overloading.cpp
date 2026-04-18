#include<iostream>
using namespace std;

class point
{
public:
    int x, y;

    point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
};

// -------- ADD --------
int add(int a, int b)
{
    return a + b;
}

point add(point p1, point p2)
{
    return point(p1.x + p2.x, p1.y + p2.y);
}

point operator+(const point& p1, const point& p2)
{
    return point(p1.x + p2.x, p1.y + p2.y);
}

// -------- SUB --------
int sub(int a, int b)
{
    return a - b;
}

point sub(point p1, point p2)
{
    return point(p1.x - p2.x, p1.y - p2.y);
}

point operator-(const point& p1, const point& p2)
{
    return point(p1.x - p2.x, p1.y - p2.y);
}

// -------- MUL --------
int mul(int a, int b)
{
    return a * b;
}

point mul(point p1, point p2)
{
    return point(p1.x * p2.x, p1.y * p2.y);
}

point operator*(const point& p1, const point& p2)
{
    return point(p1.x * p2.x, p1.y * p2.y);
}

// -------- DISPLAY --------
void display(point p)
{
    cout << "(" << p.x << "," << p.y << ")" << endl;
}

// -------- MAIN --------
int main()
{
    int choice;

    do
    {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "\n--- ADDITION ---" << endl;

                // Integer
                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                cout << "Integer Result = " << add(a,b) << endl;

                // Point
                int x1,y1,x2,y2;
                cout << "Enter Point1 (x y): ";
                cin >> x1 >> y1;
                cout << "Enter Point2 (x y): ";
                cin >> x2 >> y2;

                point p1(x1,y1), p2(x2,y2);

                cout << "Function Overloading: ";
                display(add(p1,p2));

                cout << "Operator Overloading: ";
                display(p1 + p2);

                break;
            }

            case 2:
            {
                cout << "\n--- SUBTRACTION ---" << endl;

                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                cout << "Integer Result = " << sub(a,b) << endl;

                int x1,y1,x2,y2;
                cout << "Enter Point1 (x y): ";
                cin >> x1 >> y1;
                cout << "Enter Point2 (x y): ";
                cin >> x2 >> y2;

                point p1(x1,y1), p2(x2,y2);

                cout << "Function Overloading: ";
                display(sub(p1,p2));

                cout << "Operator Overloading: ";
                display(p1 - p2);

                break;
            }

            case 3:
            {
                cout << "\n--- MULTIPLICATION ---" << endl;

                int a, b;
                cout << "Enter two integers: ";
                cin >> a >> b;
                cout << "Integer Result = " << mul(a,b) << endl;

                int x1,y1,x2,y2;
                cout << "Enter Point1 (x y): ";
                cin >> x1 >> y1;
                cout << "Enter Point2 (x y): ";
                cin >> x2 >> y2;

                point p1(x1,y1), p2(x2,y2);

                cout << "Function Overloading: ";
                display(mul(p1,p2));

                cout << "Operator Overloading: ";
                display(p1 * p2);

                break;
            }

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
}