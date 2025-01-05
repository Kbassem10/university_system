// FILE: test_main.cpp

#include "main.cpp"
#include <cassert>
#include <iostream>

class university_main_test {
public:
    void run_tests() {
        test_add_student();
        test_delete_student();
        test_display_student_details();
        test_courses_bst_add();
        test_courses_bst_drop();
        test_course_add_DLL();
        test_view_enrollment_History_DLL();
        test_search_student();
        test_search_course();
        test_sort_linked_list_by_id();
        test_balance_courses_bts();
        test_searchWithHashing();
    }

private:
    void test_add_student() {
        university_main uni;
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        // Assuming display_student_details prints student details
        uni.display_student_details(1);
    }

    void test_delete_student() {
        university_main uni;
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        uni.delete_student(1);
        uni.display_student_details(1); // Should indicate student not found
    }

    void test_display_student_details() {
        university_main uni;
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        uni.display_student_details(1); // Should display student details
    }

    void test_courses_bst_add() {
        university_main uni;
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.search_course(101); // Should display course details
    }

    void test_courses_bst_drop() {
        university_main uni;
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.courses_bst_drop(101);
        uni.search_course(101); // Should indicate course not found
    }

    void test_course_add_DLL() {
        university_main uni;
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.course_add_DLL(101, 1); // Should add course to student's enrollment history
    }

    void test_view_enrollment_History_DLL() {
        university_main uni;
        uni.view_enrollment_History_DLL(); // Should display enrollment history
    }

    void test_search_student() {
        university_main uni;
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        uni.search_student(1); // Should indicate student found
        uni.search_student(2); // Should indicate student not found
    }

    void test_search_course() {
        university_main uni;
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.search_course(101); // Should indicate course found
        uni.search_course(102); // Should indicate course not found
    }

    void test_sort_linked_list_by_id() {
        university_main uni;
        uni.add_student(2, "Jane Doe", "jane@example.com", "0987654321", "456 Main St", "password");
        uni.add_student(1, "John Doe", "john@example.com", "1234567890", "123 Main St", "password");
        uni.sort_linked_list_by_id(); // Should sort students by ID and display sorted list
    }

    void test_balance_courses_bts() {
        university_main uni;
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.courses_bst_add(102, "Science", 4, "Prof. Johnson");
        uni.balance_courses_bts(); // Should balance BST and display courses
    }

    void test_searchWithHashing() {
        university_main uni;
        uni.courses_bst_add(101, "Math", 3, "Prof. Smith");
        uni.searchWithHashing(101); // Should indicate course found
        uni.searchWithHashing(102); // Should indicate course not found
    }
};

int main() {
    university_main_test tester;
    tester.run_tests();
    return 0;
}