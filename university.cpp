#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Forward Declaration because we need to use them before they were written
struct Course;
class Course_enrollment_History;
Course *binary_search_course(Course *root, int course_id);

// a struct of the stack to save on it the course that are prequists of another course and when validate it we pop and if empty then the student can resgiter on this course
struct stackCourseRegistration
{
    int CourseID;                                                                // the id of every course we add
    stackCourseRegistration *next;                                               // pointer to the next item on the stack
    stackCourseRegistration(int Courseid) : CourseID(Courseid), next(nullptr) {} // initialize the course id with what the function gets and the next is with NULL on the initialization
};

// the stack it self
class stackcourses
{
public:
    stackCourseRegistration *top; // poiter to the top of the stack
    stackcourses()
    {
        top = nullptr; // make the top = null on the cionstructor "means that the stack is empty"
    }
    ~stackcourses() // destructor to save memory while the program is runnning
    {
        while (top != nullptr) // loops on all of the elements on the stack till it's empty
        {
            pop(); // pop every item from the stack to reduce memory usage
        }
    }
    void push(int CourseID) // a function to push a new course to the stack
    {
        stackCourseRegistration *newnode = new stackCourseRegistration(CourseID); // ini the new node of the new course added
        newnode->next = top;                                                      // make the new node next to be the old top
        top = newnode;                                                            // make the top to be now to the next node
    }
    int pop() // a function to pop form the stack and remove the last added item
    {
        if (isEmpty()) // checks if the stack is empty
        {
            return -1; // if it's empty return -1
        }

        stackCourseRegistration *temp = top; // a temp pointer to the top
        int poped_course_id = top->CourseID; // a temp to the course id so the function can return after deleting it
        top = top->next;
        delete temp;
        return poped_course_id; // to return the value of the course id
    }
    bool isEmpty() // checks if the stack is empty
    {
        return top == nullptr;
    }
};

struct Student
{
    int id;
    string name;
    string email;
    Student *next;
    Course_enrollment_History *enrollmentHistory; // 3ashan 5ater yesayev el enrollment History
    Student(int studentId, const string &studentName, const string &studentEmail);
    ~Student()
    {
        delete next;
    }
};

struct WaitlistNode
{
    Student *student; // save the student pointer on the queue for easy access
    WaitlistNode *next;

    WaitlistNode(Student *this_student) : student(this_student), next(nullptr) {}
    ~WaitlistNode()
    {
        delete next;
    }
};

// student struct

// QUEUE
class Course_Waitlist
{
public:
    WaitlistNode *front; // front of the queue
    WaitlistNode *rear;  // rear of the queue

    Course_Waitlist() : front(nullptr), rear(nullptr) {}
    ~Course_Waitlist()
    {
        delete front;
        delete rear;
    }

    void enqueue_to_waitlist(Student *student)
    {
        WaitlistNode *new_student = new WaitlistNode(student);
        if (!rear)
        {
            front = rear = new_student;
        }
        else
        {
            rear->next = new_student;
            rear = new_student;
        }
    };

    WaitlistNode *dequeue_from_waitlist()
    {
        if (!front)
        {
            return NULL;
        }
        WaitlistNode *temp = front;
        front = front->next;
        if (queue_is_empty()) // if there was only one person on the queue
        {
            rear = nullptr;
        }
        temp->next = NULL;
        return temp;
    }

    void displayWaitlist() const // to display the waiting list O(n)
    {
        if (front == nullptr)
        {
            return;
        }

        cout << "Current Waitlist:" << endl;
        WaitlistNode *current = front;
        while (current != nullptr)
        {
            cout << "- " << current->student->name << endl;
            current = current->next;
        }
    }

    bool queue_is_empty()
    {
        return front == nullptr;
    }

    Student *seach_in_waitlist(int student_id)
    { // to search if a student found on the waiting list O(n)
        WaitlistNode *current = front;
        while (current != NULL)
        {
            if (current->student->id == student_id)
            {
                return current->student;
            }
            current = current->next;
        }
        return NULL;
    }
};

// COURSE struct of a bst
struct Course
{
    int id;
    string name;
    int credits;
    Course *left;
    Course *right;
    string CourseInstructor;
    int course_limit;                  // the course limit that detemins whether to add to the dll or the waitlist
    int current_number_of_enrollments; // to check the number of enrolled students
    stackcourses stack;
    Course_Waitlist waitlist;

    Course(int id, const string &name, int credits, const string &CourseInstructor, int course_limit, int current_number_of_enrollments)
        : id(id), name(name), credits(credits), left(nullptr), right(nullptr), CourseInstructor(CourseInstructor), course_limit(course_limit), current_number_of_enrollments(current_number_of_enrollments) {}
    ~Course()
    {
        delete left;
        delete right;
    }
};

// DLL Node
struct Course_enrollment_Node
{
    Course *course;
    Course_enrollment_Node *next;
    Course_enrollment_Node *prev;

    Course_enrollment_Node(Course *course)
        : course(course), next(nullptr), prev(nullptr) {}
    ~Course_enrollment_Node()
    {
        delete next;
        delete prev;
    }
};

// DLL
class Course_enrollment_History
{
public:
    Course_enrollment_Node *head;
    Course_enrollment_Node *tail;
    Course_enrollment_History() : head(nullptr), tail(nullptr) {}
    ~Course_enrollment_History()
    {
        delete head;
        delete tail;
    }

    int enroll_course(Course *course, Student *student)
    {
        Student *student_in_queue = course->waitlist.seach_in_waitlist(student->id); // to check if the student with that id exists on the waiting list
        if (student_in_queue)
        {
            cout << "You can't enroll now because it's full and you are already IN THE WAITING LIST!! WHEN SOMEONE DROP YOU WILL BE ADDED" << endl;
            return 0;
        }

        Course_enrollment_Node *new_Course = new Course_enrollment_Node(course);
        course->current_number_of_enrollments++; // to increment the number of enrolled students
        if (!head)
        {
            head = tail = new_Course;
            return 1;
        }
        else
        {
            tail->next = new_Course;
            new_Course->prev = tail;
            tail = new_Course;
            return 1;
        }
    }

    bool check_course_enrollment(int id) // checks if the course exists on the enrollments
    {
        if (!head) // checks if the list is empty
        {
            return false;
        }
        else
        {
            Course_enrollment_Node *current = head;
            while (current != nullptr)
            {
                if (current->course->id == id)
                {
                    return true;
                }
                current = current->next;
            }
        }
        return false;
    }

    void view_enrollment_History() // display all of the courses that this students is enrolled on it
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
            cout << "- " << current->course->name << endl;
            current = current->next;
        }
    }

    void student_drop_course(int id)
    {
        if (head == NULL)
        {
            cout << "No courses enrolled." << endl;
            return;
        }
        Course_enrollment_Node *current = head;

        while (current != NULL && current->course->id != id)
        {
            current = current->next;
        }

        if (current == NULL) // you reached the end and no course found
        {
            cout << "No course found with this id." << endl;
            return;
        }

        if (current == head) // you wants to delete the head
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
        }

        else // tail or on the middle
        {
            current->prev->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
        }
        current->course->current_number_of_enrollments--;
        delete current;
    }
};

// inheritance from the Student but not with the student struct because it needs the Course_enrollment_History to be decalred before it
Student::Student(int studentId, const string &studentName, const string &studentEmail)
    : id(studentId), name(studentName), email(studentEmail), next(nullptr), enrollmentHistory(nullptr)
{
    enrollmentHistory = new Course_enrollment_History();
}

// SLL from the student struct
class StudentRecords
{
public:
    Student *head;
    Student *tail;

    StudentRecords() : head(nullptr), tail(nullptr) {}
    ~StudentRecords()
    {
        delete head;
        delete tail;
    }

    void add(int id, string name, string email)
    {
        Student *newStudent = new Student{id, name, email};
        if (!head)
        {
            head = tail = newStudent;
        }
        else
        {
            tail->next = newStudent;
            tail = newStudent;
        }
    }

    void remove(int id)
    {
        if (!head)
        {
            return;
        }

        if (head->id == id) // if the node that we wants to delete is the head
        {
            Student *toDelete = head;
            head = head->next;
            toDelete->next = NULL;
            delete toDelete;
            return;
        }

        Student *current = head;
        while (current->next && current->next->id != id) // loop till you find the id or a NULL
        {
            current = current->next;
        }

        if (current->next == NULL) // if it's NULL "Not found" return
        {
            return;
        }

        Student *toDelete = current->next;
        current->next = current->next->next;
        toDelete->next = NULL;
        delete toDelete;
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

    void display_details(int id)
    {
        Student *temp = head;
        cout << "Student's Record:\n";
        while (temp)
        {
            if (temp->id == id)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Not Found.\n";
            return;
        }
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
        temp = temp->next;
    }
};

// BST to the courses
class bst
{
private:
    // Karim balance binary search tree

    // a helper function to convert the BST to an array
    void in_order_bts_to_array(Course *root, vector<Course *> &nodes)
    {
        if (root == NULL)
        {
            return;
        }
        in_order_bts_to_array(root->left, nodes);
        nodes.push_back(root);
        in_order_bts_to_array(root->right, nodes);
    }

    // helper function to convert the array to a bst
    Course *array_to_bts(vector<Course *> &nodes, int start, int end)
    {
        if (nodes.size() == 0)
        {
            return NULL;
        }
        if (start > end)
        {
            return NULL;
        }

        int mid = (start + end) / 2;
        Course *new_root = nodes[mid];

        new_root->left = array_to_bts(nodes, start, mid - 1);
        new_root->right = array_to_bts(nodes, mid + 1, end);

        return new_root;
    }

public:
    Course *root;
    bst() { root = nullptr; }

    ~bst()
    {
        delete root;
    }

    Course *addcourse(int idcourse, string namecourse, int creditscourse, string teachers, int limit, int prerequisite_size)
    {
        Course *newcourse = new Course(idcourse, namecourse, creditscourse, teachers, limit, 0); // the 0 is the number of students enrolled to the course

        for (int i = 0; i < prerequisite_size; i++) // loop le8ayet ma 3adad el prerequisite yigi 3ashan nezawedhom
        {
            while (true)
            { // loop 3ashan alw 7at rakam 8alat
                cout << "Enter prerequisite course ID: ";
                int course_id;
                cin >> course_id;
                Course *prerequisite = binary_search_course(root, course_id);
                if (prerequisite)
                {
                    newcourse->stack.push(course_id);
                    break; // law el rakam sa7 break 3alatol men el loop el gowa
                }
                else if (course_id < 1)
                {
                    cout << "Skip! " << endl;
                    break; // law 7at rakam negative aw 0 ye3mel skip lel ittration di
                }
                else
                {
                    cout << "Error: Course ID " << course_id << " does not exist. Enter 0 to Skip" << endl; // law 7at rakam 8alat teb2a le8ayet ma yekteb rakam sa7 aw 0
                }
            }
        }

        // Add course to the BST
        if (root == nullptr)
        {
            root = newcourse;
            return newcourse;
        }
        Course *temp = root;
        Course *parent = nullptr;

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
                cout << "Error: Course with ID " << idcourse << " already exists." << endl;
                delete newcourse;
                return nullptr;
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

        cout << "Course " << namecourse << " added successfully." << endl;
        return newcourse;
    }
    int deleteCourse(int id)
    {
        Course *temp = root;
        Course *parent = nullptr;

        // With one or no children
        while (temp != nullptr && temp->id != id) // binary search
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

        if (temp == nullptr) // not found
        {
            return 0;
        }

        if (temp->left == nullptr || temp->right == nullptr) // one childern so you will add it to the parent directly
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
            return 1;
        }

        else // ESHRA7O L NAFSAK DA
        {    // with 2 children
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
            return 1;
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
    void displayPrerequisites(Course *course) // Mesh matloba bas 3amltaha wana ba-Debug
    {
        if (!course)
        {
            cout << "Error: Course not found!" << endl;
            return;
        }

        cout << "Prerequisites for course " << course->name << " (ID: " << course->id << "):" << endl;

        if (course->stack.isEmpty())
        {
            cout << "No prerequisites." << endl;
            return;
        }
        stackcourses tempStack = course->stack;

        while (!tempStack.isEmpty())
        {
            cout << "- Course ID: " << tempStack.top->CourseID << endl;
            tempStack.pop();
        }
    }

    // a function to balance the BST Karim
    Course *balance_bst()
    {
        vector<Course *> bts_nodes;
        in_order_bts_to_array(root, bts_nodes);
        Course *new_root = array_to_bts(bts_nodes, 0, bts_nodes.size() - 1);
        root = new_root;
        return new_root;
    }
};

// search on the SLL
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

// search on the BST
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

        else if (course_id < current->id)
        {
            current = current->left;
        }
    }

    return current;
}

// Merge the singly linked lists
Student *merge(Student *left, Student *right)
{
    if (!right)
        return left;
    if (!left)
        return right;

    Student *result = nullptr;
    Student *tail = nullptr;

    if (left->id <= right->id)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

//split SLL
void split(Student *head, Student **left, Student **right)
{
    //case where there is no head or only the head
    if (!head || !head->next) {
        *left = head;
        *right = nullptr;
        return;
    }

    //get the middle
    Student *slow = head;
    Student *fast = head->next;

    //move fast two steps and slow one step to get the middle
    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    //split on the half to two halves
    *left = head;
    *right = slow->next;
    slow->next = nullptr;  //Break the link between the two halves
}

// Merge-Sort the SLL
Student *mergesort(Student *head)
{
    if (!head || !head->next)
        return head;

    Student *left;
    Student *right;

    split(head, &left, &right);

    left = mergesort(left);
    right = mergesort(right);
    
    return merge(left, right);
}

void sort_student(Student **head)
{
    *head = mergesort(*head);
}

// HASH TABLE "BONUS"
class hash_table
{
private:
    struct hash_node
    {
        int key;
        Course *value;
        hash_node *next_node;

        ~hash_node()
        {
            delete next_node;
        }
    };
    hash_node **table; // initialize to an array of pointers
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
        table = new hash_node *[table_size]; // initialize an array of pointers of the hash_node with the default size
        for (int i = 0; i < table_size; ++i)
        {
            table[i] = NULL;
        }
    }
    ~hash_table()
    {
        delete table;
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
        if (key < 0)
        {
            return NULL;
        }
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

// function to validate the the Prerequisites using a stack
void copyStack(stackcourses &source, stackcourses &temp)
{
    stackcourses auxStack;

    while (!source.isEmpty())
    {
        auxStack.push(source.pop());
    }

    while (!auxStack.isEmpty())
    {
        int courseID = auxStack.pop();
        source.push(courseID);
        temp.push(courseID);
    }
}

bool validatePrerequisites(Course *course, Student *Student)
{
    stackcourses temp;
    copyStack(course->stack, temp);

    while (!temp.isEmpty())
    {
        int id = temp.pop();
        int check = Student->enrollmentHistory->check_course_enrollment(id);
        if (!check)
        {
            return false;
        }
    }
    return true;
}

// function to display the remaining Prerequisites in the course
void Display_remaining_Prerequisites(Course *course, Student *Student)
{
    stackcourses temp;
    copyStack(course->stack, temp);

    bool flag = true;

    while (!temp.isEmpty())
    {
        int id = temp.pop();
        flag = Student->enrollmentHistory->check_course_enrollment(id);
        if (flag == false)
        {
            cout << "Didn't take Course with ID: " << id << endl;
        }
    }
}

int int_checker()
{
    int value;
    while (true)
    {
        string input;
        getline(cin, input);
        try
        {
            value = stoi(input);
            break;
        }
        catch (...)
        {
            cout << "Invalid input! Please enter a valid number: ";
        }
    }
    return value;
}

bool inOrderTraversal(Course *root, int student_id)
{ // helper function to traverse the whole bst
    if (root == nullptr)
        return false;

    if (inOrderTraversal(root->left, student_id))
    {
        return true;
    }

    if (root->waitlist.seach_in_waitlist(student_id))
    {
        return true;
    }

    if (inOrderTraversal(root->right, student_id))
    {
        return true;
    }

    return false;
}

bool check_student_in_queue(Course *root, Student *student)
{ // check if the studnet is teh queue of any course
    if (root == nullptr || student == nullptr)
        return false;

    return inOrderTraversal(root, student->id);
}

bool check_any_student_enrolled(Student *head, int idcourse)
{ // check if any student enrolled to a specific course
    if (head == NULL)
    {
        return NULL;
    }
    Student *current = head;
    while (current != NULL)
    {
        if (current->enrollmentHistory->check_course_enrollment(idcourse))
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
