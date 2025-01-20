# University System

This project is a simple university management system that allows users to manage courses and students. It provides functionalities to add, remove, and display courses and students, as well as enroll students in courses and manage course prerequisites.

## Features

- Add, remove, and display courses
- Add, remove, and display students
- Enroll students in courses
- Drop courses for students
- View course prerequisites
- View waiting list for courses
- Sort and search students

## Requirements

- C++ compiler (e.g., g++)
- Standard C++ libraries

## Setup

1. Clone the repository:
    ```sh
    git clone https://github.com/Kbassem10/university_system/
    ```
2. Navigate to the project directory:
    ```sh
    cd university_system
    ```
3. Compile the project:
    ```sh
    g++ -o university_system main.cpp display.cpp
    ```

## Usage

1. Run the compiled program:
    ```sh
    ./university_system
    ```
2. Follow the on-screen instructions to navigate through the menus and manage courses and students.

## File Structure

- `main.cpp`: Contains the main logic and data structures for the university system.
- `display.cpp`: Contains functions for displaying menus and handling user input.

## Functions

### main.cpp

- `class university_main`: Main class containing methods for managing courses and students.
- `void addcourse()`: Adds a new course.
- `void displaycourses()`: Displays all courses.
- `void Removecourse()`: Removes a course.
- `void viewpre()`: Views course prerequisites.
- `void waitlist()`: Views the waiting list for a course.
- `void add_student()`: Adds a new student.
- `void delete_student()`: Removes a student.
- `void display_student_details()`: Displays details of a student.
- `void enroll_course()`: Enrolls a student in a course.
- `void student_drop_course()`: Drops a course for a student.
- `void display_enrollments()`: Displays all enrollments.
- `void display_students()`: Displays all students.
- `void sort_linked_list_by_id()`: Sorts students by ID.
- `void search_student()`: Searches for a student by ID.

### display.cpp

- `void clearScreen()`: Clears the console screen.
- `void pause()`: Pauses the console and waits for user input.
- `void Courses_menu(university_main &uni)`: Displays the courses menu and handles user input.
- `void Students_menu(university_main &uni)`: Displays the students menu and handles user input.
- `void Display_Menu(university_main &uni)`: Displays the main menu and handles user input.

## License

This project is licensed under the MIT License.
