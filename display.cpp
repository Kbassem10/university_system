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
void Courses_menu(university_main &uni)
{
    cout << "\t\t\t\t Courses Menu \t\t\t\t" << endl;
    cout << "1 - Add a new course\n";
    cout << "2 - Display all courses\n";
    cout << "3 - Remove a course\n";
    cout << "4 - View Course Prerequisites \n";
    cout << "5 - view waiting list \n";
    cout << "6 - View Course \n";
    cout << "7 - Search for course with hashing \n";
    cout << "0 - Back to Main Menu\n";
    cout << "Enter your choice: ";

    int choice = int_checker();
    switch (choice)
    {
    case 1:
        clearScreen();
        cout << "Adding course...\n";
        uni.addcourse();
        break;
    case 2:
        clearScreen();
        cout << "Displaying all courses...\n";
        uni.displaycourses();
        break;
    case 3:
        clearScreen();
        cout << "Removing course...\n";
        uni.Removecourse();
        break;
    case 4:
        clearScreen();
        cout << "Viewing Course Prerequisites...\n";
        uni.viewpre();
        break;
    case 5:
        clearScreen();
        cout << "Displaying waiting list...\n";
        uni.waitlist();
        break;
    case 6:
        clearScreen();
        cout << "viewing Course...\n";
        uni.display_course();
        break;
    case 7:
        clearScreen();
        cout << "Searching for Course with hashing...\n";
        uni.searchWithHashing();
        break;

    case 0:
        clearScreen();
        cout << "Returning to Main Menu...\n";
        return;
    default:
        cout << "Invalid choice. Please try again.\n";
    }
    pause();
}
void Students_menu(university_main &uni)
{
    clearScreen();

    cout << "\t\t\t\t Students Menu \t\t\t\t\n";
    cout << "1 - Add Student\n";
    cout << "2 - Remove Student\n";
    cout << "3 - View Student\n";
    cout << "4 - Enroll in a Course\n";
    cout << "5 - Drop a Course\n";
    cout << "6 - Display enrollments\n";
    cout << "7 - Display students\n";
    cout << "8 - Sort Students\n";
    cout << "0 - Back to Main Menu\n";
    cout << "Enter your choice: ";
    int choice = int_checker();

    switch (choice)
    {
    case 1: // Passed
    {
        clearScreen();
        cout << "Adding a student...\n";
        uni.add_student();
        break;
    }
    case 2:
    {
        clearScreen();
        cout << "Removing a student...\n";
        uni.delete_student();
        break;
    }
    case 3: // Passed
    {
        clearScreen();
        cout << "Viewing a student...\n";
        uni.display_student_details();
        break;
    }
    case 4:
    {
        clearScreen();
        cout << "Enrolling in a course...\n";
        uni.enroll_course();
        break;
    }
    case 5:
    {
        clearScreen();
        cout << "Dropping a course...\n";
        uni.student_drop_course();
        break;
    }
    case 6:
    {
        clearScreen();
        cout << "Displaying enrollments...\n";
        uni.display_enrollments();
        break;
    }
    case 7:
    {
        clearScreen();
        cout << "Displaying students...\n";
        uni.display_students();
        break;
    }
    case 8:
    {
        clearScreen();
        cout << "Sorting Students...\n";
        uni.sort_linked_list_by_id();
        break;
    }
    case 0:
        clearScreen();
        cout << "Returning to Main Menu...\n";
        return;
    default:
        clearScreen();
        cout << "Invalid choice. Please try again.\n";
    }
    pause();
    
}
void Display_Menu(university_main &uni)
{
    int choice;
    do
    {
        clearScreen();
        cout << "\n\t\t\t\t----------------------\t\t\t\t\n";
        cout << " \t\t\t\tHellHound University\t\t\t\t\n";
        cout << "\t\t\t\t----------------------\t\t\t\t\n";
        cout << "1. Courses Menu\n";
        cout << "\t add,remove,display,view prerequisites\n";
        cout << "2. Students Menu\n";
        cout << "\t add,remove,display,enroll course,drop course,validate courses enrollment, view enrollments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        choice = int_checker();

        switch (choice)
        {
        case 1:
            clearScreen();
            Courses_menu(uni);
            break;
        case 2:
            clearScreen();
            Students_menu(uni);
            break;
        case 0:
            clearScreen();
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            clearScreen();
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
