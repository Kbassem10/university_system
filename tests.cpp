#include "main.cpp"
#include <iostream>
#include <cassert> // For simple test assertions

using namespace std;

// // Helper Functions for Output
// void print_separator()
// {
//     cout << "--------------------------" << endl;
// }

// // Test Functions
// void test_add_student()
// {
//     university_main uni;
//     cout << "Testing: add_student()" << endl;
//     uni.add_student(1, "Alice", "alice@example.com");
//     uni.add_student(1, "Alice", "alice@example.com"); // Should not add duplicate
//     uni.add_student(2, "Bob", "bob@example.com");
//     uni.display_student_details(1);
//     uni.display_student_details(2);
//     print_separator();
// }

// void test_delete_student()
// {
//     university_main uni;
//     cout << "Testing: delete_student()" << endl;
//     uni.add_student(1, "Alice", "alice@example.com");
//     uni.delete_student(1);
//     uni.display_student_details(1); // Should print "Not Found"
//     print_separator();
// }

// void test_courses_bst()
// {
//     university_main uni;
//     cout << "Testing: BST add/drop and display()" << endl;
//     uni.courses_bst_add(101, "Math 101", 3, "Dr. Smith");
//     uni.courses_bst_add(102, "Physics 101", 4, "Dr. Brown");
//     uni.courses_bst_drop(101); // Drop Math 101
//     uni.search_course(102);    // Should find Physics 101
//     uni.search_course(101);    // Should print "Course Not Found!"
//     print_separator();
// }

// void test_course_add_DLL()
// {
//     university_main uni;
//     cout << "Testing: Course Enrollment (DLL)" << endl;
//     uni.add_student(1, "Alice", "alice@example.com");
//     uni.courses_bst_add(101, "Math 101", 3, "Dr. Smith");
//     uni.enroll_course(101, 1); // Enroll Alice in Math 101
//     uni.display_enrollments(1); // Should display Math 101
//     print_separator();
// }

// void test_sort_students()
// {
//     university_main uni;
//     cout << "Testing: Sort Students (Linked List)" << endl;
//     uni.add_student(3, "Charlie", "charlie@example.com");
//     uni.add_student(1, "Alice", "alice@example.com");
//     uni.add_student(2, "Bob", "bob@example.com");
//     uni.sort_linked_list_by_id();   // Sort students by ID
//     uni.display_student_details(1); // First student should be Alice
//     print_separator();
// }

// void test_balance_courses()
// {
//     university_main uni;
//     cout << "Testing: Balance Courses (BST)" << endl;
//     uni.courses_bst_add(105, "English 101", 2, "Dr. White");
//     uni.courses_bst_add(110, "History 101", 3, "Dr. Green");
//     uni.courses_bst_add(120, "Chemistry 101", 4, "Dr. Blue");
//     uni.balance_courses_bts(); // Balance the BST
//     print_separator();
// }

void test_insert_hash() {
    hash_table ht;
    Course course1(1, "Course 1", 3, "Instructor 1", 30, 0);
    Course course2(2, "Course 2", 4, "Instructor 2", 25, 0);

    ht.insert_hash(&course1);
    ht.insert_hash(&course2);

    assert(ht.searchWithHashing(1) == &course1);
    assert(ht.searchWithHashing(2) == &course2);
    std::cout << "test_insert_hash passed!" << std::endl;
}

void test_searchWithHashing() {
    hash_table ht;
    Course course1(1, "Course 1", 3, "Instructor 1", 30, 0);
    Course course2(2, "Course 2", 4, "Instructor 2", 25, 0);

    ht.insert_hash(&course1);
    ht.insert_hash(&course2);

    assert(ht.searchWithHashing(1) == &course1);
    assert(ht.searchWithHashing(2) == &course2);
    assert(ht.searchWithHashing(3) == nullptr);
    std::cout << "test_searchWithHashing passed!" << std::endl;
}

void test_remove_from_hash() {
    hash_table ht;
    Course course1(1, "Course 1", 3, "Instructor 1", 30, 0);
    Course course2(2, "Course 2", 4, "Instructor 2", 25, 0);

    ht.insert_hash(&course1);
    ht.insert_hash(&course2);

    assert(ht.remove_from_hash(1) == 1);
    assert(ht.searchWithHashing(1) == nullptr);
    assert(ht.remove_from_hash(2) == 1);
    assert(ht.searchWithHashing(2) == nullptr);
    assert(ht.remove_from_hash(3) == 0);
    std::cout << "test_remove_from_hash passed!" << std::endl;
}

int main() {
    test_insert_hash();
    test_searchWithHashing();
    test_remove_from_hash();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

// void test_waitlist()
// {
//     cout << "Testing: Waitlist Operations" << endl;
//     Course course(301, "Waitlist Test", 3, "Dr. Test", 1, 1); // Limit is 1, already full
//     Student student(1, "Test Student", "test@student.com");

//     Course_Waitlist waitlist;
//     waitlist.enqueue_to_waitlist(&student, &course); // Add to waitlist
//     waitlist.displayWaitlist(&course);             // Should display the student
//     waitlist.dequeue_from_waitlist();       // Should remove the student
//     waitlist.displayWaitlist(&course);             // Should be empty
//     print_separator();
// }

// Main Function to Run All Tests
// int main()
// {
//     //test_add_student();
//     //test_delete_student();
//     //test_courses_bst();
//     //test_course_add_DLL();
//     //test_sort_students();
//     //test_balance_courses();
//     test_search_with_hashing();
//     //test_waitlist();

//     cout << "All tests completed!" << endl;
//     return 0;
// }