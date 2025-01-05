#include "main.cpp"

void test_sort_student()
{
    // Helper function to print the student list
    auto print_students = [](Student *head)
    {
        Student *temp = head;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    };

    // Edge Case 1: Sorting an empty list
    Student *empty_list = nullptr;
    cout << "Sorting an empty list:" << endl;
    Student *sorted_empty_list = sort_student(empty_list);
    print_students(sorted_empty_list);

    // Edge Case 2: Sorting a list with one student
    Student *single_student = new Student{1, "Alice Johnson", "alice@example.com"};
    cout << "Sorting a list with one student:" << endl;
    Student *sorted_single_student = sort_student(single_student);
    print_students(sorted_single_student);

    // Edge Case 3: Sorting a list with multiple students in random order
    Student *student_list_random = new Student{3, "John Doe", "john@example.com"};
    student_list_random->next = new Student{1, "Alice Johnson", "alice@example.com"};
    student_list_random->next->next = new Student{2, "Bob Smith", "bob@example.com"};
    cout << "Sorting a list with multiple students in random order:" << endl;
    Student *sorted_student_list_random = sort_student(student_list_random);
    print_students(sorted_student_list_random);

    // Edge Case 4: Sorting a list with multiple students already in sorted order
    Student *student_list_sorted = new Student{1, "Alice Johnson", "alice@example.com"};
    student_list_sorted->next = new Student{2, "Bob Smith", "bob@example.com"};
    student_list_sorted->next->next = new Student{3, "John Doe", "john@example.com"};
    cout << "Sorting a list with multiple students already in sorted order:" << endl;
    Student *sorted_student_list_sorted = sort_student(student_list_sorted);
    print_students(sorted_student_list_sorted);

    // Edge Case 5: Sorting a list with multiple students in reverse order
    Student *student_list_reverse = new Student{3, "John Doe", "john@example.com"};
    student_list_reverse->next = new Student{2, "Bob Smith", "bob@example.com"};
    student_list_reverse->next->next = new Student{1, "Alice Johnson", "alice@example.com"};
    cout << "Sorting a list with multiple students in reverse order:" << endl;
    Student *sorted_student_list_reverse = sort_student(student_list_reverse);
    print_students(sorted_student_list_reverse);

    // Edge Case 6: Sorting a list with duplicate student IDs
    Student *student_list_duplicates = new Student{2, "John Doe", "john@example.com"};
    student_list_duplicates->next = new Student{1, "Alice Johnson", "alice@example.com"};
    student_list_duplicates->next->next = new Student{2, "Bob Smith", "bob@example.com"};
    cout << "Sorting a list with duplicate student IDs:" << endl;
    Student *sorted_student_list_duplicates = sort_student(student_list_duplicates);
    print_students(sorted_student_list_duplicates);

    // Clean up dynamically allocated memory
    auto delete_list = [](Student *head)
    {
        while (head != nullptr)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    };

    delete_list(sorted_single_student);
    delete_list(sorted_student_list_random);
    delete_list(sorted_student_list_sorted);
    delete_list(sorted_student_list_reverse);
    delete_list(sorted_student_list_duplicates);
}

void hash_table_test()
{
    // Hash Table Test
    hash_table courseHashTable;

    // Edge Case 1: Inserting a course into an empty hash table
    Course *course1 = new Course(1, "Mathematics", 3, "Dr. Smith");
    courseHashTable.insert_hash(course1);
    cout << "Inserted course: " << course1->name << endl;

    // Edge Case 2: Inserting multiple courses with unique keys
    Course *course2 = new Course(2, "Physics", 4, "Dr. Brown");
    Course *course3 = new Course(3, "Chemistry", 3, "Dr. Green");
    courseHashTable.insert_hash(course2);
    courseHashTable.insert_hash(course3);
    cout << "Inserted courses: " << course2->name << ", " << course3->name << endl;

    // Edge Case 3: Inserting multiple courses with colliding keys (same hash index)
    Course *course4 = new Course(12, "Biology", 3, "Dr. White"); // 12 % 10 == 2
    courseHashTable.insert_hash(course4);
    cout << "Inserted course with collision: " << course4->name << endl;

    // Edge Case 4: Searching for a course that exists
    Course *searchResult = courseHashTable.searchWithHashing(12);
    if (searchResult)
    {
        cout << "Found course: " << searchResult->name << endl;
    }
    else
    {
        cout << "Course not found." << endl;
    }

    // Edge Case 5: Searching for a course that does not exist
    searchResult = courseHashTable.searchWithHashing(10);
    if (searchResult)
    {
        cout << "Found course: " << searchResult->name << endl;
    }
    else
    {
        cout << "Course not found." << endl;
    }

    // Edge Case 6: Inserting a course with a duplicate key
    Course *course5 = new Course(2, "Advanced Physics", 5, "Dr. Einstein");
    courseHashTable.insert_hash(course5);
    cout << "Inserted course with duplicate key: " << course5->name << endl;
    searchResult = courseHashTable.searchWithHashing(2);
    if (searchResult)
    {
        cout << "Found course after duplicate insert: " << searchResult->name << endl;
    }
    else
    {
        cout << "Course not found after duplicate insert." << endl;
    }

    // Edge Case 7: Handling a large number of insertions to test performance and collisions
    for (int i = 100; i < 110; ++i)
    {
        Course *course = new Course(i, "Course " + to_string(i), 3, "Instructor " + to_string(i));
        courseHashTable.insert_hash(course);
    }
    for (int i = 100; i < 110; ++i)
    {
        searchResult = courseHashTable.searchWithHashing(i);
        if (searchResult)
        {
            cout << "Found course: " << searchResult->name << endl;
        }
        else
        {
            cout << "Course not found: " << i << endl;
        }
    }

    // Clean up dynamically allocated memory
    delete course1;
    delete course2;
    delete course3;
    delete course4;
    delete course5;
    for (int i = 100; i < 110; ++i)
    {
        Course *course = courseHashTable.searchWithHashing(i);
        delete course;
    }
}

void test_case()
{
    // Student Records Test
    StudentRecords studentRecords;
    studentRecords.add(7, "Alice Johnson", "alice@example.com");
    studentRecords.add(5, "Bob Smith", "bob@example.com");
    studentRecords.add(6, "John doe", "Jon@example.com");
    studentRecords.add(1, "Sherlock Holmes", "Sherlock@example.com");
    studentRecords.add(10, "Lionel Messi", "Messi@example.com");
    studentRecords.add(3, "Shalaby Festek", "Shalaby@example.com");
    studentRecords.display();
    studentRecords.remove(10);
    studentRecords.display();

    // Course Records Test
    bst courseRecords;
    courseRecords.addcourse(5, "Data Structures", 3, "Dr. Smith");
    courseRecords.addcourse(4, "Algorithms", 4, "Dr. Brown");
    courseRecords.addcourse(8, "Operating Systems", 3, "Dr. Green");
    // courseRecords.displayCourses(); // Uncomment this line if displayCourses method is implemented

    // Search Test
    Student *student = linear_search_student(studentRecords.get_head(), 3);
    Course *course = binary_search_course(courseRecords.root, 4);

    if (student == NULL)
    {
        cout << "Student Not Found!" << endl;
    }
    else
    {
        cout << "Student: " << student->name << endl;
    }
    if (course == NULL)
    {
        cout << "Course: " << course->name << endl;
    }
    else
    {
        cout << "Course Not Found!" << endl;
    }

    // sort linked list by id
    Student *student_sort = sort_student(studentRecords.get_head());
    studentRecords.display();

    // Course enrollment test
    student->enrollmentHistory->add_course("Calc 3");
    student->enrollmentHistory->add_course("Data structures");
    student->enrollmentHistory->add_course("Python");
    student->enrollmentHistory->add_course("Proba");
    student->enrollmentHistory->view_enrollment_History();
    cout << student->enrollmentHistory->check_course_enrollment("Python") << endl;
    cout << student->enrollmentHistory->check_course_enrollment("C++") << endl;

    // Course waitlist test
    cout << "\nCourse Waitlist Test:\n";
    Course *testCourse = new Course(10, "Artificial Intelligence", 4, "Dr. Watson");
    testCourse->waitlist.enqueue("John Doe");
    testCourse->waitlist.enqueue("Lionel Messi");
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    delete testCourse;
}

void test_bst()
{
    bst courseTree;

    // Test Case 1: Inserting nodes into the BST
    courseTree.addcourse(5, "Data Structures", 3, "Dr. Smith");
    courseTree.addcourse(3, "Algorithms", 4, "Dr. Johnson");
    courseTree.addcourse(8, "Operating Systems", 3, "Dr. Lee");
    courseTree.addcourse(1, "Discrete Mathematics", 3, "Dr. Brown");
    courseTree.addcourse(4, "Computer Networks", 3, "Dr. White");
    courseTree.addcourse(7, "Database Systems", 3, "Dr. Green");
    courseTree.addcourse(10, "Artificial Intelligence", 3, "Dr. Black");
    cout << "Inserted courses:" << endl;
    courseTree.display(courseTree.root);

    // Test Case 2: Searching for nodes in the BST
    Course *searchResult = courseTree.root;
    while (searchResult != nullptr && searchResult->id != 4)
    {
        if (4 < searchResult->id)
        {
            searchResult = searchResult->left;
        }
        else
        {
            searchResult = searchResult->right;
        }
    }
    if (searchResult)
    {
        cout << "Found course: " << searchResult->name << endl;
    }
    else
    {
        cout << "Course not found." << endl;
    }

    searchResult = courseTree.root;
    while (searchResult != nullptr && searchResult->id != 6)
    {
        if (6 < searchResult->id)
        {
            searchResult = searchResult->left;
        }
        else
        {
            searchResult = searchResult->right;
        }
    }
    if (searchResult)
    {
        cout << "Found course: " << searchResult->name << endl;
    }
    else
    {
        cout << "Course not found." << endl;
    }

    // Test Case 3: Removing nodes from the BST
    courseTree.dropCourse(3);
    cout << "Removed course with ID 3:" << endl;
    courseTree.display(courseTree.root);

    courseTree.dropCourse(8);
    cout << "Removed course with ID 8:" << endl;
    courseTree.display(courseTree.root);

    courseTree.dropCourse(5);
    cout << "Removed course with ID 5:" << endl;
    courseTree.display(courseTree.root);

    // Additional Test Case: Removing the root node
    courseTree.dropCourse(1);
    cout << "Removed course with ID 1 (root):" << endl;
    courseTree.display(courseTree.root);

    // Additional Test Case: Removing a non-existent node
    courseTree.dropCourse(999);
    cout << "Attempted to remove non-existent course with ID 999:" << endl;
    courseTree.display(courseTree.root);
}

void test_university_main() {
    university_main uni;

    // Testing courses_bst_add
    cout << "Testing courses_bst_add...\n";
    uni.courses_bst_add(101, "Math 101", 3, "Dr. Smith"); // Valid case
    uni.courses_bst_add(102, "Physics 101", 4, "Dr. Brown"); // Valid case
    uni.courses_bst_add(101, "Math 101 Duplicate", 3, "Dr. Smith"); // Duplicate ID
    uni.courses_bst_add(103, "", 4, "Dr. Johnson"); // Empty course name
    uni.courses_bst_add(104, "Chemistry 101", -1, "Dr. Lee"); // Negative credit hours
    uni.courses_bst_add(105, "Biology 101", 3, ""); // Empty instructor name

    // Testing courses_bst_drop
    cout << "Testing courses_bst_drop...\n";
    uni.courses_bst_drop(101); // Valid case
    uni.courses_bst_drop(999); // Non-existing ID
    uni.courses_bst_drop(-1);  // Invalid ID

    // Testing course_enrollment_DLL
    cout << "Testing course_enrollment_DLL...\n";
    uni.course_add_DLL("Math 101"); // Valid case
    uni.course_add_DLL(""); // Empty course name
    uni.course_add_DLL("Physics 101"); // Another valid case

    // Testing view_enrollment_History_DLL
    cout << "Testing view_enrollment_History_DLL...\n";
    uni.view_enrollment_History_DLL();

    // Testing Course_Waitlist
    cout << "Testing Course_Waitlist...\n";
    uni.Course_Waitlist_enqueue("John Doe"); // Valid case
    uni.Course_Waitlist_enqueue("Jane Smith"); // Valid case
    uni.Course_Waitlist_enqueue(""); // Empty student name
    uni.Course_Waitlist_dequeue(); // Dequeue John Doe
    uni.Course_Waitlist_dequeue(); // Dequeue Jane Smith
    uni.Course_Waitlist_dequeue(); // Attempt to dequeue from empty waitlist

    // Testing search_student
    cout << "Testing search_student...\n";
    uni.search_student(12345); // Non-existing student
    uni.search_student(-1); // Invalid student ID

    // Testing search_course
    cout << "Testing search_course...\n";
    uni.search_course(102); // Existing course
    uni.search_course(999); // Non-existing course
    uni.search_course(-1);  // Invalid course ID

    // Testing sort_linked_list_by_id
    cout << "Testing sort_linked_list_by_id...\n";
    uni.sort_linked_list_by_id();

    // Testing balance_courses_bts
    cout << "Testing balance_courses_bts...\n";
    uni.balance_courses_bts();

// Hash Table Validation: Test Edge Cases

    // Case 1: Test collisions (Assuming hash table uses a simple modulus-based hash function)
    // We will add two courses with the same hash value (e.g., same ID % size of the hash table)
    // Let's assume a simple size for the hash table, e.g., 10.
    cout << "\nTesting Hash Table Collision...\n";
    uni.courses_bst_add(10, "Course 10", 3, "Instructor A"); // Assuming ID 10 gives hash value 0
    uni.courses_bst_add(20, "Course 20", 3, "Instructor B"); // Assuming ID 20 also gives hash value 0 (collision)
    cout << "Added Course 10 and Course 20, checking collision handling.\n";
    uni.searchWithHashing(10); // Should find Course 10
    uni.searchWithHashing(20); // Should find Course 20

    // Case 2: Test very large IDs
    cout << "\nTesting Hash Table with Very Large IDs...\n";
    int large_id = 1000000000;
    uni.courses_bst_add(large_id, "Big Course", 3, "Instructor C");
    cout << "Added course with large ID: " << large_id << endl;
    uni.searchWithHashing(large_id); // Should find the course with the large ID

    // Case 3: Test searching for very large ID
    int invalid_large_id = 1000000001;
    cout << "Searching for non-existent course with ID: " << invalid_large_id << endl;
    uni.searchWithHashing(invalid_large_id); // Should return "Not Found"
}

//!!!!!!! TO RUN THE TEST YOU HAVE TO COMMENT THE MAIN IN THE main.cpp !!!!!!!!!!!!!
int main()
{
    //hash_table_test();
    // test_sort_student();
    // test_case();
    // test_bst();
    //Display_Menu();
    test_university_main();
    return 0;
}