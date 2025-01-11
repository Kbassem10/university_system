#include "main.cpp"
#include <iostream>
#include <cassert> // For simple test assertions
#include <sstream>

using namespace std;

// Helper Functions for Output
void print_separator()
{
    cout << "--------------------------" << endl;
}

// Test Functions
void test_add_student()
{
    university_main uni;
    cout << "Testing: add_student()" << endl;
    uni.add_student();
    uni.add_student(); // Should not add duplicate
    uni.display_student_details();
    print_separator();
}

void test_delete_student()
{
    university_main uni;
    cout << "Testing: delete_student()" << endl;
    uni.add_student();
    uni.delete_student();
    uni.display_student_details(); // Should print "Not Found"
    print_separator();
}

void test_courses_bst()
{
    university_main uni;
    cout << "Testing: BST add/drop and display()" << endl;
    uni.addcourse();
    uni.addcourse();
    uni.Removecourse(); // Drop Math 101
    uni.search_course(102);    // Should find Physics 101
    uni.search_course(101);    // Should print "Course Not Found!"
    print_separator();
}

void test_course_add_DLL()
{
    university_main uni;
    cout << "Testing: Course Enrollment (DLL)" << endl;
    uni.add_student();
    uni.addcourse();
    uni.enroll_course(); // Enroll Alice in Math 101
    uni.display_enrollments(); // Should display Math 101
    print_separator();
}

void test_sort_students()
{
    university_main uni;
    cout << "Testing: Sort Students (Linked List)" << endl;
    uni.add_student();
    uni.add_student();
    uni.add_student();
    uni.sort_linked_list_by_id();   // Sort students by ID
    uni.display_student_details(); // First student should be Alice
    print_separator();
}

void test_balance_courses()
{
    university_main uni;
    cout << "Testing: Balance Courses (BST)" << endl;
    uni.addcourse();
    uni.addcourse();
    uni.addcourse();
    uni.balance_courses_bts(); // Balance the BST
    print_separator();
}

void test_search_with_hashing()
{
    university_main uni;
    cout << "Testing: Hash Search" << endl;
    uni.addcourse();
    uni.searchWithHashing(); // Should find the course
    uni.searchWithHashing(); // Should print "Not Found"
    print_separator();
}

void test_waitlist()
{
    cout << "Testing: Waitlist Operations" << endl;
    Course course(301, "Waitlist Test", 3, "Dr. Test", 1, 1); // Limit is 1, already full
    Student student(1, "Test Student", "test@student.com");

    Course_Waitlist waitlist;
    waitlist.enqueue_to_waitlist(&student); // Add to waitlist
    waitlist.displayWaitlist();             // Should display the student
    waitlist.dequeue_from_waitlist();       // Should remove the student
    waitlist.displayWaitlist();             // Should be empty
    print_separator();
}

void test_view_enrollment_History()
{
    // Create a student and enroll in courses
    Student student(1, "Test Student", "test@student.com");

    Course course1(1, "Course 1", 3, "Instructor 1", 30, 0);
    Course course2(2, "Course 2", 3, "Instructor 2", 30, 0);

    Course_enrollment_Node node1(&course1);
    Course_enrollment_Node node2(&course2);

    student.enrollmentHistory->head = &node1;
    node1.next = &node2;
    node2.prev = &node1;

    // Redirect cout to a stringstream to capture the output
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Call the function
    student.enrollmentHistory->view_enrollment_History();

    // Restore cout
    cout.rdbuf(old);

    // Check the output
    string expected_output = "Enrollment History:\n- Course 1\n- Course 2\n";
    string actual_output = buffer.str();

    if (actual_output == expected_output)
    {
        cout << "Test passed!" << endl;
    }
    else
    {
        cout << "Test failed!" << endl;
        cout << "Expected output:\n" << expected_output;
        cout << "Actual output:\n" << actual_output;
    }
}

int main()
{
    // test_add_student();
    // test_delete_student();
    // test_courses_bst();
    // test_course_add_DLL();
    // test_sort_students();
    // test_balance_courses();
    // test_search_with_hashing();
    // test_waitlist();
    //test_view_enrollment_History();



    //test_validatePrerequisites();
    //test_enroll_course()
    return 0;
}