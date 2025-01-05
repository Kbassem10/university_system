#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

struct Course_enrollment_Node
{
    string course_name;
    Course_enrollment_Node *next;
    Course_enrollment_Node *prev;

    Course_enrollment_Node(string courseName)
        : course_name(courseName), next(nullptr), prev(nullptr) {}
};

class Course_enrollment_History
{
public:
    Course_enrollment_Node *head;
    Course_enrollment_Node *tail;
    Course_enrollment_History() : head(nullptr), tail(nullptr) {}

    void add_course(string course_name)
    {
        Course_enrollment_Node *new_Course = new Course_enrollment_Node(course_name);
        if (!head)
        {
            head = tail = new_Course;
        }
        else
        {
            tail->next = new_Course;
            new_Course->prev = tail;
            tail = new_Course;
        }
    }
    bool check_course_enrollment(string course)
    {
        bool flag = false;
        if (!head)
        {
            return flag;
        }
        else
        {
            Course_enrollment_Node *current = head;
            while (current != nullptr)
            {
                if (current->course_name == course)
                {
                    flag = true;
                }
                current = current->next;
            }
        }
        return flag;
    }
    void view_enrollment_History()
    {
        if (!head)
        {
            cout << "No courses enrolled." << endl;
            return;
        }

        Course_enrollment_Node *current = head;
        cout << "Enrollment History:" << endl;
        while (current)
        {
            cout << "- " << current->course_name << endl;
            current = current->next;
        }
    }
};

struct Student
{
    int id;
    string name;
    string email;
    Student *next;
    Course_enrollment_History *enrollmentHistory;
    Student(int studentId, const string &studentName, const string &studentEmail) : id(studentId), name(studentName), email(studentEmail), next(nullptr)
    {
        enrollmentHistory = new Course_enrollment_History();
    }
};
class StudentRecords // shalaby ysheel w yktbha Raqam 1
{
private:
    Student *head;

public:
    Student *get_head()
    {
        return head;
    }

    StudentRecords() : head(nullptr) {}

    void add(int id, const string &name, const string &email)
    {
        Student *newStudent = new Student{id, name, email};
        if (!head)
        {
            head = newStudent;
        }
        else
        {
            Student *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student added: " << name << endl;
    }

    void remove(int id)
    {
        if (!head)
        {
            cout << "Student not found.\n";
            return;
        }

        if (head->id == id)
        {
            Student *toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Student removed.\n";
            return;
        }

        Student *temp = head;
        while (temp->next && temp->next->id != id)
        {
            temp = temp->next;
        }

        if (!temp->next)
        {
            cout << "Student not found.\n";
            return;
        }

        Student *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Student removed.\n";
    }

    void display() const
    {
        Student *temp = head;
        cout << "Student Records:\n";
        while (temp)
        {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    Student *getHead() const
    {
        return head;
    }
};

struct WaitlistNode
{
    string studentName;
    WaitlistNode *next;

    WaitlistNode(const string &name) : studentName(name), next(nullptr) {}
};
class Course_Waitlist
{
public:
    WaitlistNode *front;
    WaitlistNode *rear;

    Course_Waitlist() : front(nullptr), rear(nullptr) {}

    void enqueue(const string &studentName)
    {
        WaitlistNode *new_student = new WaitlistNode(studentName);
        if (!rear)
        {
            front = rear = new_student;
        }
        else
        {
            rear->next = new_student;
            rear = new_student;
        }
        cout << "Added to waitlist: " << studentName << endl;
    };

    void dequeue()
    {
        if (!front)
        {
            cout << "Waitlist is empty." << endl;
            return;
        }
        WaitlistNode *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        cout << "Enrolled from waitlist: " << temp->studentName << endl;
        delete temp;
    }

    void displayWaitlist() const
    {
        if (front == nullptr)
        {
            cout << "Waitlist is empty." << endl;
            return;
        }

        cout << "Current Waitlist:" << endl;
        WaitlistNode *current = front;
        while (current != nullptr)
        {
            cout << "- " << current->studentName << endl;
            current = current->next;
        }
    }
};

struct Course
{
    int id;
    string name;
    int credits;
    Course *left;
    Course *right;
    Course_Waitlist waitlist;
    string CourseInstructor;

    Course(int id, const string &name, int credits, const string &CourseInstructor)
        : id(id), name(name), credits(credits), left(nullptr), right(nullptr), CourseInstructor(CourseInstructor) {}
};

class bst // Fahmy yeshel w yktbha Raqam 2
{
public:
    Course *root;
    bst() { root = nullptr; }
    void addcourse(int idcourse, string namecourse, int creditscourse, string teachers)
    {
        Course *newcourse = new Course(idcourse, namecourse, creditscourse, teachers);
        if (root == nullptr)
        {
            root = newcourse;
            return;
        }
        Course *temp = root;
        Course *parent = nullptr; //-------------> parent variable 3ashan lma temp yeb2a b null (5alas position is found) the parent variable bya5od reference elly kan a5r 7aga 3ndha
        while (temp != nullptr)
        {
            parent = temp;
            if (idcourse < temp->id)
            {
                temp = temp->left;
            }
            else if (idcourse > temp->id)
            {
                temp = temp->right;
            }
            else
            {
                cout << " this course is already exist";
                delete newcourse;
                return;
            }
        }
        if (idcourse < parent->id)
        {
            parent->left = newcourse;
        }
        else
        {
            parent->right = newcourse;
        }
    }
    void dropCourse(int id)
    {
        Course *temp = root;
        Course *parent = nullptr;

        // With one or no children
        while (temp != nullptr && temp->id != id)
        {
            parent = temp;
            if (id < temp->id)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (temp == nullptr)
        {
            cout << "course does not exist";
            return;
        }
        if (temp->left == nullptr || temp->right == nullptr)
        {
            Course *sorryNadeem;
            if (temp->left != nullptr)
            {
                sorryNadeem = temp->left;
            }
            else
            {
                sorryNadeem = temp->right;
            }
            if (parent == nullptr)
            {
                root = sorryNadeem;
            }
            else
            {
                if (temp == parent->left)
                {
                    parent->left = sorryNadeem;
                }
                else
                {
                    parent->right = sorryNadeem;
                }
            }
            delete temp;
        }
        else
        { // with 2 children
            Course *next = temp->right;
            Course *nextparent = temp;
            while (next->left != nullptr)
            {
                nextparent = next;
                next = next->left;
            }
            temp->id = next->id;
            temp->name = next->name;
            temp->credits = next->credits;
            temp->CourseInstructor = next->CourseInstructor;

            if (nextparent->left == next)
            {
                nextparent->left = next->right;
            }
            else
            {
                nextparent->right = next->right;
            }
            delete next;
        }
    }
    void display(Course *node)
    {
        if (node == nullptr)
            return;
        display(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Credits: " << node->credits << ", Instructor: " << node->CourseInstructor << endl;
        display(node->right);
    }
};
Student *linear_search_student(Student *head, int student_id)
{
    if (head == NULL)
    {
        return NULL;
    }
    Student *current = head;
    while (current != NULL)
    {
        if (current->id == student_id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Course *binary_search_course(Course *root, int course_id)
{
    Course *current = root;
    while (current != NULL)
    {
        if (current->id == course_id)
        {
            return current;
        }

        if (course_id > current->id)
        {
            current = current->right;
        }

        if (course_id < current->id)
        {
            current = current->left;
        }
    }

    return current;
}

void linked_list_swap(Student *node1, Student *node2)
{
    if (!node1 || !node2)
    {
        return;
    }

    int temp_id = node1->id;
    node1->id = node2->id;
    node2->id = temp_id;

    string temp_name = node1->name;
    node1->name = node2->name;
    node2->name = temp_name;

    string temp_email = node1->email;
    node1->email = node2->email;
    node2->email = temp_email;
}

Student* sort_student(Student *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Student *current = head;
    while (current != NULL)
    {
        Student *min = current;
        Student *next = current->next;
        while (next != NULL)
        {
            if (next->id < min->id)
            {
                min = next;
            }
            next = next->next;
        }
        if (min != current)
        {
            linked_list_swap(min, current);
        }
        current = current->next;
    }
    return head;
}

void in_order_bts_to_array(Course* root, vector<Course*>& nodes){
    if(root == NULL){
        return;
    }
    in_order_bts_to_array(root->left, nodes);
    nodes.push_back(root);
    in_order_bts_to_array(root->right, nodes);
}

Course* array_to_bts(vector<Course*>& nodes,int start, int end){
    if(nodes.size() == 0){
        return NULL;
    }
    if(start > end){
        return NULL;
    }

    int mid = (start + end) / 2;
    Course* new_root = nodes[mid];
    
    new_root->left = array_to_bts(nodes, start, mid -1);
    new_root->right = array_to_bts(nodes, mid+1, end);

    return new_root;
}

Course* sort_courses_bts(Course* root){
    vector<Course*> bts_nodes;
    in_order_bts_to_array(root, bts_nodes);
    Course* new_root = array_to_bts(bts_nodes, 0, bts_nodes.size() - 1);
    return new_root;
}

class hash_table
{
private:
    struct hash_node
    {
        int key;
        Course *value;
        hash_node *next_node;
    };
    hash_node **table;
    int table_size;
    int num_elements;

    void rehash()
    {
        int old_table_size = table_size;
        table_size *= 2;
        hash_node **new_table = new hash_node *[table_size];
        for (int i = 0; i < table_size; ++i)
        {
            new_table[i] = NULL;
        }

        for (int i = 0; i < old_table_size; ++i)
        {
            hash_node *current = table[i];
            while (current != NULL)
            {
                hash_node *next = current->next_node;
                int new_index = hashFunction(current->key);
                current->next_node = new_table[new_index];
                new_table[new_index] = current;
                current = next;
            }
        }

        delete[] table;
        table = new_table;
    }

public:
    hash_table()
    {
        table_size = 10;
        num_elements = 0;
        table = new hash_node *[table_size];
        for (int i = 0; i < table_size; ++i)
        {
            table[i] = NULL;
        }
    }

    // hashing function
    int hashFunction(int key)
    {
        return key % table_size;
    }

    void insert_hash(Course *value)
    {
        int key = value->id;

        if (num_elements > table_size)
        {
            rehash();
        }

        int index = hashFunction(key);
        hash_node *new_node = new hash_node;
        new_node->next_node = NULL;
        new_node->key = key;
        new_node->value = value;
        if (table[index])
        {
            hash_node *current = table[index];
            while (current->next_node != NULL)
            {
                current = current->next_node;
            }
            current->next_node = new_node;
        }
        else
        {
            table[index] = new_node;
        }
        num_elements++;
    }

    Course *searchWithHashing(int key)
    {
        int index = hashFunction(key);
        hash_node *current = table[index];
        while (current != NULL)
        {
            if (current->value->id == key)
            {
                return current->value;
            }
            current = current->next_node;
        }
        return NULL;
    }

    int remove_from_hash(int key)
    {
        int index = hashFunction(key);
        hash_node *current = table[index];
        hash_node *prev = NULL;

        while (current != NULL)
        {
            if (current->value->id == key)
            {
                break;
            }
            prev = current;
            current = current->next_node;
        }

        if (current == NULL)
        {
            return 0;
        }

        if (prev == NULL)
        {
            table[index] = current->next_node;
        }
        else
        {
            prev->next_node = current->next_node;
        }

        delete current;
        num_elements--;
        return 1;
    }
};
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

int main()
{
    // hash_table_test();
    // test_sort_student();
    // test_case();
    // test_bst();
    Display_Menu();
    return 0;
}
