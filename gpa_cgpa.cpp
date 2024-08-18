#include <iostream>
#include <iomanip> // For setting width and formatting
using namespace std;

int main() 
{
    int numSemesters;
    float totalCredits = 0.0;
    float totalWeightedPoints = 0.0;
    float cgpa;

    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    if (numSemesters <= 0) 
    {
        cout << "Number of semesters must be greater than zero." << endl;
        return 1;
    }

    char choice;
    cout << "Do you know the previous semesters' averages and total credits? (y/n): ";
    cin >> choice;

    cout << endl;
    cout << setw(15) << left << "Semester"
         << setw(20) << left << "GPA"
         << setw(25) << left << "Total Credits"
         << setw(25) << left << "Weighted Points" << endl;
    cout << string(75, '-') << endl;

    if (choice == 'y' || choice == 'Y') 
    {

        for (int i = 1; i <= numSemesters; ++i) 
        {
            float gpa, credits;
            cout << "Enter the GPA for semester " << i << ": ";
            cin >> gpa;
            cout << "Enter the total credits for semester " << i << ": ";
            cin >> credits;

            if (credits <= 0) 
            {
                cout << "Total credits must be greater than zero for semester " << i << "." << endl;
                return 1;
            }

            totalWeightedPoints += gpa * credits;
            totalCredits += credits;

            cout << setw(15) << left << "Semester " + to_string(i)
                 << setw(20) << left << fixed << setprecision(2) << gpa
                 << setw(25) << left << fixed << setprecision(2) << credits
                 << setw(25) << left << fixed << setprecision(2) << gpa * credits << endl;
        }
    } 
    else 
    {
        for (int i = 1; i <= numSemesters; ++i) 
        {
            int numSubjects;
            float semesterCredits = 0.0;
            float semesterWeightedPoints = 0.0;
            float gpa;

            cout << "Enter the number of subjects for semester " << i << ": ";
            cin >> numSubjects;

            if (numSubjects <= 0) 
            {
                cout << "Number of subjects must be greater than zero for semester " << i << "." << endl;
                return 1;
            }
            for (int j = 1; j <= numSubjects; ++j) 
            {
                float grade, credits;
                cout << "Enter the grade for subject " << j << ": ";
                cin >> grade;
                cout << "Enter the credits for subject " << j << ": ";
                cin >> credits;

                if (credits <= 0) 
                {
                    cout << "Credits must be greater than zero for subject " << j << "." << endl;
                    return 1;
                }
                semesterWeightedPoints += grade * credits;
                semesterCredits += credits;
            }
            if (semesterCredits == 0) 
            {
                cout << "Total credits cannot be zero for semester " << i << "." << endl;
                return 1;
            }
            gpa = semesterWeightedPoints / semesterCredits;

            totalWeightedPoints += gpa * semesterCredits;
            totalCredits += semesterCredits;

            cout << setw(15) << left << "Semester " + to_string(i)
                 << setw(20) << left << fixed << setprecision(2) << gpa
                 << setw(25) << left << fixed << setprecision(2) << semesterCredits
                 << setw(25) << left << fixed << setprecision(2) << semesterWeightedPoints << endl;
        }
    }
    if (totalCredits == 0) 
    {
        cout << "Total credits cannot be zero." << endl;
        return 1;
    }
    cgpa = totalWeightedPoints / totalCredits;

    cout << endl << string(75, '-') << endl;
    cout << setw(15) << left << "Total"
         << setw(20) << left << fixed << setprecision(2) << cgpa
         << setw(25) << left << fixed << setprecision(2) << totalCredits
         << setw(25) << left << fixed << setprecision(2) << totalWeightedPoints << endl;

    return 0;
}
