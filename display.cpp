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
    int choice;
    do{
        cout<<"\t\t\t\t Courses Menu \t\t\t\t"<<endl;
        cout << "1. Add a new course\n";
        cout << "2. Display all courses\n";
        cout << "3. Remove a course\n";
        cout << "4. View Course Prerequisites \n";
        cout<< "5. view waiting list \n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
        case 1:
            uni.addcourse();
            break;
        case 2:
            uni.displaycourses();
            break;
        case 3:
            uni.removecourse();
            break;
        case 4:
            uni.viewpre();
            break;
        case 5:
            uni.waitlist();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        }
        while (choice != 0){
            return 0;
        }
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
    cout << "6 - Display enrollments\n";
    cout << "7 - Display students\n";
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
        cout << "Enter student id: \n";
        cin >> id;
        cout << "Enter student name: \n";
        cin >> name;
        cout << "Enter student email: \n";
        cin >> email;
        uni.add_student(id, name, email);
        break;
    }
    case 2:
    {
        cout << "Removing a student...\n";
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        uni.delete_student(id);
        break;
    }
    case 3:
    {
        cout << "Viewing a student...\n";
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        uni.display_student_details(id);
        break;
    }
    case 4:
    {
        cout << "Enrolling in a course...\n";
        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        int course_id;
        cout << "Enter course ID: ";
        cin >> course_id;
        uni.enroll_course(course_id, student_id);
        break;
    }
    case 5:
    {
        cout << "Dropping a course...\n";
        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        int course_id;
        cout << "Enter course ID: ";
        cin >> course_id;
        uni.student_drop_course(course_id, student_id);
        break;
    }
    case 6:
    {
        cout << "Displaying enrollments\n";
        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        uni.display_enrollments(student_id);
        break;
    }
    case 7:
    {
        cout << "Displaying students\n";
    }
    default:
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
