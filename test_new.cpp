#include <iostream>
#include <string>
#include "NewCode.cpp"
using namespace std;
void runTests()
{
    StudentRecords students;
    CourseRecords courses;

    // Test 1: Adding Students
    cout << "--- Test 1: Adding Students ---\n";
    try
    {
        students.addStudent(1, "John Doe", "john@example.com", "123456789", "123 Street", "password1");
        students.addStudent(2, "Jane Smith", "jane@example.com", "987654321", "456 Avenue", "password2");
        students.addStudent(1, "Duplicate", "dup@example.com", "555555555", "789 Road", "password3");
        students.addStudent(3, "Karim", "KIMO@TOP.com", "01010101010", "789 Road", "password");
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
    students.display();

    // Test 2: Adding Courses
    cout << "--- Test 2: Adding Courses ---\n";
    try
    {
        courses.addCourse(101, "Mathematics", 3, "Dr. Euler", 2);
        courses.addCourse(102, "Physics", 4, "Dr. Newton", 3);
        courses.addCourse(101, "Duplicate Course", 4, "Dr. Dup", 1);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Test 3: Adding Prerequisites
    cout << "--- Test 3: Adding Prerequisites ---\n";
    try
    {
        courses.addPrerequisite(102, 101); // Physics requires Mathematics
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Test 4: Enrolling Students
    cout << "--- Test 4: Enrolling Students ---\n";
    try
    {
        courses.enrollStudent(101, 1, students);
        courses.enrollStudent(101, 2, students);
        courses.enrollStudent(101, 3, students); // Should go to waitlist
        courses.enrollStudent(102, 1, students); // Should fail (prerequisite not met)
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Test 5: Dropping a Course
    cout << "--- Test 5: Dropping a Course ---\n";
    try
    {
        courses.dropCourse(101, 1, students); // Should enroll next from waitlist
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Test 6: Completing a Course
    cout << "--- Test 6: Completing a Course ---\n";
    try
    {
        courses.completeCourse(101, 2, "A", students);
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    // Test 7: Display All Data
    cout << "--- Test 7: Display All Data ---\n";
    cout << "Students:\n";
    students.display();
    cout << "Courses:\n";
    courses.enrollStudent(101, 3, students); // Attempt re-enroll
}

int main()
{
    runTests();
    return 0;
}
