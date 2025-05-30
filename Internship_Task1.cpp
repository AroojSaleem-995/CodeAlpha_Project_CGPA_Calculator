#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
double getGradePoint(const string& grade){
    if(grade == "A+" || grade == "A" )
    return 4.0;
    else if (grade == "A-")
    return 3.7;
    else if (grade == "B+")
    return 3.3;
    else if (grade == "B")
    return 3.0;
    else if (grade == "B-")
    return 2.7;
    else if (grade == "C+")
    return 2.3;
    else if (grade == "C")
    return 2.0;
    else if (grade == "C-")
    return 1.7;
    else if (grade == "D+")
    return 1.3;
    else if (grade == "D")
    return 1.0;
    else if (grade == "F")
    return 0.0;
    else
    return -1.0; //Invalid Grade
}
int main() {
    int numCourses;
    double totalCreditHours=0;
    double totalGradePoints = 0;
    cout << "------------CGPA CALCULATOR------------" << endl;
    cout <<"Enter the number of Courses: ";
    cin>>numCourses;
    for(int i=0; i<numCourses; i++){
        string courseName, grade;
        double creditHours;
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin.ignore();
        getline(cin, courseName);
        cout << "Enter credit hours for " << courseName << ": ";
        cin >> creditHours;
        cout << "Enter grade (A+, A, A-, ..., F) for " << courseName << ": ";
        cin >> grade;
        double gradePoint = getGradePoint(grade);
        if (gradePoint == -1.0) {
            cout << "Invalid grade entered. Please try again.\n";
            --i; // redo this course
            continue;
        }
        totalCreditHours += creditHours;
        totalGradePoints += gradePoint * creditHours;
        cout << fixed << setprecision(2);
        cout << "Grade Point for " << courseName << ": " << gradePoint << "\n";
    }
    double GPA = totalGradePoints / totalCreditHours;
    cout << "\n----- RESULTS -----\n";
    cout << "Total Credit Hours: " << totalCreditHours << "\n";
    cout << "Total Grade Points: " << totalGradePoints << "\n";
    cout << "GPA for this semester: " << fixed << setprecision(2) << GPA << "\n";
    // Optional: Ask if user wants to calculate CGPA
    char choice;
    cout << "\nDo you want to calculate cumulative CGPA? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        double prevCGPA, prevCredits;
        cout << "Enter your previous CGPA: ";
        cin >> prevCGPA;
        cout << "Enter total previous credit hours: ";
        cin >> prevCredits;
        double cumulativeCGPA = ((prevCGPA * prevCredits) + totalGradePoints) / (prevCredits + totalCreditHours);
        cout << "Your cumulative CGPA is: " << fixed << setprecision(2) << cumulativeCGPA << "\n";
    }
    cout << "\nThank you for using the CGPA Calculator!\n";
    return 0;
}
