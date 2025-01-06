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




void Students_menu()
{
}
void Display_Menu(university_main uni) {
    int choice;
    do {
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

        switch (choice) {
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
