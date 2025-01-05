#include <iostream>
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

void Display_Menu()
{
    int choice;
    cout << "\t\t\t\t Welcome to Hellhound University\t\t\t\t" << endl;
    pause();
    do
    {
        clearScreen();
        cout << "\nMenu: \n";
        // print menu
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
        // switch
    } while (choice != 0);
}
