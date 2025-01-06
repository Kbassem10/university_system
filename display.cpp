#include <iostream>
#include <string>
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
void Courses_menu()
{
}
void Students_menu()
{
}
void Display_Menu()
{
    int choice;
    cout << "\t\t\t\t Welcome to Hellhound University\t\t\t\t" << endl;
    pause();
    do
    {
        clearScreen();
        cout << "\n----------------------\n";
        cout << " Hellhound University\n";
        cout << "----------------------\n";
        cout << "1. Courses menu\n";
        cout << "*containts:"<<endl;
        cout << "\t ADD,Remove,View Courses\n";
        cout << "----------------------\n";
        cout << "2. Students menu\n";
        cout << "\t ADD,Remove,View students\n";
        cout << "\t Enroll,Drop,Validate courses enrollment\n";
        cout << "----------------------\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();
        while (true)
        {
            string input;
            getline(cin, input);
            try
            {
                choice = stoi(input);
                break;
            }
            catch (...)
            {
                cout << "Invalid input! Please enter a valid number: ";
            }
        }
        switch (choice)
        {
        case 1:
        {
            Courses_menu;
            break;
        }
        case 2:
        {
            Students_menu;
            break;
        }
        case 0:
        {
            cout << "Exiting program. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}
int main()
{
    Display_Menu();
}
