#include <iostream>
#include <string>
#include "main.cpp"
using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}
void pause()
{
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}
void Courses_menu(university_main uni)
{
}
void Students_menu(university_main &uni)
{
    clearScreen();
    int choice;
    cout << "\t\t\t\t Students Menu \t\t\t\t\n";
    cout << "1 - Add Student\n";
    cout << "2 - Remove Student\n";
    cout << "3 - View Student\n";
    cout << "4 - Enroll in a Course\n";
    cout << "5 - Drop a Course\n";
    cout << "6 - Validate Courses Enrollment\n";
    cout << "0 - Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "Adding a student...\n";
        int id;
        string name;
        string email;
        cout << "Enter student id\n";
        cin >> id;
        cout << "Enter student name\n";
        cin >> name;
        cout << "Enter student email";
        cin >> email;
        uni.add_student(id, name, email);
        break;
    }
    case 2:
        cout << "Removing a student...\n";
        break;
    case 3:
        cout << "Viewing a student...\n";
        break;
    case 4:
        cout << "Enrolling in a course...\n";
        break;
    case 5:
        cout << "Dropping a course...\n";
        break;
    case 6:
        cout << "Validating courses enrollment...\n";
        break;

    default:
        cout << "Invalid choice. Please try again.\n";
    }
    pause();
}
void Display_Menu(university_main& uni)
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n----------------------\n";
        cout << " HellHound University\n";
        cout << "----------------------\n";
        cout << "1. Courses Menu\n";
        cout << "\t add,remove,display,view prerequisites\n";
        cout << "2. Students Menu\n";
        cout << "\t add,remove,display,enroll course,drop course,validate courses enrollment, view enrollments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Courses_menu(uni);
            break;
        case 2:
            Students_menu(uni);
            break;
        case 0:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            pause();
        }
    } while (choice != 0);
}
int main()
{
    university_main uni;
    Display_Menu(uni);
}
