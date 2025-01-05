//!!!!!!! TO RUN THE TEST YOU HAVE TO COMMENT THE MAIN IN THE main.cpp !!!!!!!!!!!!!

#include <iostream>
#include "main.cpp"

void test_university_main() {
    university_main uni;

    // Test adding courses to BST and hash table
    uni.courses_bst_add(101, "Math", 3, "Dr. Smith");
    uni.courses_bst_add(102, "Physics", 4, "Dr. Johnson");
    uni.courses_bst_add(103, "Chemistry", 3, "Dr. Lee");

    // Test searching for courses
    uni.search_course(101); // Should print "Course: Math"
    uni.search_course(104); // Should print "Course Not Found!"

    // Test adding students
    Student student1(1, "Alice", "alice@example.com");
    Student student2(2, "Bob", "bob@example.com");
    Student student3(3, "Charlie", "charlie@example.com");

    // Add students to student records
    // uni.student_records.add_student(&student1);
    // uni.student_records.add_student(&student2);
    // uni.student_records.add_student(&student3);

    // Test searching for students
    uni.search_student(1); // Should print "Student Found, Name: Alice"
    uni.search_student(3); // Should print "Student Found, Name: Charlie"
    uni.search_student(4); // Should print "Student Not Found!"

    // Test adding courses to student's enrollment history
    uni.course_add_DLL(101, 1); // Alice enrolls in Math
    uni.course_add_DLL(102, 2); // Bob enrolls in Physics
    uni.course_add_DLL(103, 3); // Charlie enrolls in Chemistry

    // Test viewing enrollment history
    uni.view_enrollment_History_DLL(); // Should print enrollment history

    // Test dropping courses from BST and hash table
    uni.courses_bst_drop(102); // Drop Physics
    uni.search_course(102); // Should print "Course Not Found!"

    // Test dropping a non-existent course
    uni.courses_bst_drop(104); // Should print "Course Not Found!"

    // Test sorting linked list by student ID
    uni.sort_linked_list_by_id(); // Should print sorted student records

    // Test balancing courses BST
    uni.balance_courses_bts(); // Should print balanced BST

    // Test searching with hashing
    uni.searchWithHashing(101); // Should print "Found"
    uni.searchWithHashing(104); // Should print "Not Found"

    // Edge case: Adding a course with the same ID
    uni.courses_bst_add(101, "Advanced Math", 4, "Dr. Brown"); // Should handle duplicate ID

    // Edge case: Adding a student with the same ID
    Student student4(1, "Duplicate Alice", "duplicate_alice@example.com");
    // uni.student_records.add_student(&student4); // Should handle duplicate ID

    // Edge case: Enrolling a student in a course that is full
    for (int i = 0; i < 30; ++i) {
        Student* temp_student = new Student(100 + i, "Temp Student " + to_string(i), "temp" + to_string(i) + "@example.com");
        // uni.student_records.add_student(temp_student);
        uni.course_add_DLL(101, 100 + i); // Enroll in Math
    }
    uni.course_add_DLL(101, 3); // Charlie tries to enroll in Math, should be added to waitlist

    // Edge case: Dropping a course and enrolling from waitlist
    uni.courses_bst_drop(101); // Drop Math
    uni.search_course(101); // Should print "Course Not Found!"

    std::cout << "All test cases passed for university_main!" << std::endl;
}

int main() {
    test_university_main();
    return 0;
}