# Data Structures Course Project - Fall 2024

## University Management System

This project involves designing a university management system that efficiently handles student records, course information, enrollment histories, and course registrations using a variety of data structures. It integrates components such as linked lists, stacks, queues, binary search trees, and hash tables to ensure optimal performance for diverse operations.

### Features

1. **Student Records Management**: 
   - Uses a Single Linked List (SLL) to store and manage student details.
   - Functionalities include adding, removing, and displaying student records.

2. **Course Records Management**: 
   - Implements a Binary Search Tree (BST) to organize and search course information.
   - Supports adding and dropping courses.

3. **Course Enrollment History**: 
   - Employs a Double Linked List (DLL) to track each student's course history.
   - Allows adding and viewing enrollment records.

4. **Course Registration**: 
   - Validates course prerequisites using a Stack.
   - Ensures students meet prerequisites before registration.

5. **Course Waitlist Management**: 
   - Manages waitlists using a Queue.
   - Supports adding students to waitlists and enrolling them when spots become available.

6. **Search and Sort Operations**: 
   - Implements search functionalities for students and courses.
   - Provides sorting capabilities for student records.

7. **Hash Table for Fast Access**: 
   - Enhances lookup efficiency with a Hash Table.
   - Includes collision handling and efficient search operations.

### Usage Instructions

1. **Compilation**: 
   - Use a C++ compiler to compile the source files located in the `src` directory.

2. **Running the Application**: 
   - Execute the compiled binary to start the university management system.

3. **Testing**: 
   - Test cases are provided in the `tests` directory. Compile and run `tests/tests.cpp` to validate functionalities.

### Future Enhancements

- Implement a graphical user interface (GUI) for better user interaction.
- Extend the system to include more features such as course grading and student performance tracking.

### Acknowledgments

- This project is developed as part of the Data Structures course for Fall 2024 at the University.