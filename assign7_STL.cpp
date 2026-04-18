#include <iostream>
#include <vector>
using namespace std;

// Function to calculate average
double calculateAverage(vector<int> &grades) {
    int sum = 0;

    // using auto iterator
    for (auto it = grades.begin(); it != grades.end(); it++) {
        sum += *it;
    }

    return (double)sum / grades.size();
}

// Function to find minimum
int findMinimum(vector<int> &grades) {
    int min = *grades.begin();

    for (auto it = grades.begin(); it != grades.end(); it++) {
        if (*it < min) {
            min = *it;
        }
    }

    return min;
}

// Function to find maximum
int findMaximum(vector<int> &grades) {
    int max = *grades.begin();

    for (auto it = grades.begin(); it != grades.end(); it++) {
        if (*it > max) {
            max = *it;
        }
    }

    return max;
}

int main() {
    vector<int> grades;
    int n, value;

    cout << "Enter number of students: ";
    cin >> n;

    // Input grades
    for (int i = 0; i < n; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> value;
        grades.push_back(value);
    }

    cout << "\nAverage = " << calculateAverage(grades);
    cout << "\nMinimum = " << findMinimum(grades);
    cout << "\nMaximum = " << findMaximum(grades);

    return 0;
}





//     // Switch case
//     cout << "\n1. Average\n2. Minimum\n3. Maximum\nEnter choice: ";
//     cin >> choice;

//     switch (choice) {
//         case 1:
//             cout << "Average = " << calculateAverage(grades);
//             break;

//         case 2:
//             cout << "Minimum = " << findMinimum(grades);
//             break;

//         case 3:
//             cout << "Maximum = " << findMaximum(grades);
//             break;

//         default:
//             cout << "Invalid choice!";
//     }

//     return 0;
// }