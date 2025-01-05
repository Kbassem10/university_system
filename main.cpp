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
struct stackCourseRegistration
{
    string Coursename;
    int Studentid;
    stackCourseRegistration *next;
    stackCourseRegistration(string Courseid, int Studentid) : Coursename(Courseid), Studentid(Studentid), next(nullptr) {}
};
class stackcourses
{

private:
    stackCourseRegistration *top;

public:
    stackcourses()
    {
        top = nullptr;
    }
    void push(string Coursename, int Studentid)
    {
        stackCourseRegistration *newnode = new stackCourseRegistration(Coursename, Studentid);
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty!";
            return;
        }
        else
        {
            stackCourseRegistration *temp = top;
            top = top->next;
            delete temp;
        }
    }
    bool isEmpty()
    {
        return top == nullptr;
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
    Course* addcourse(int idcourse, string namecourse, int creditscourse, string teachers)
    {
        Course *newcourse = new Course(idcourse, namecourse, creditscourse, teachers);
        if (root == nullptr)
        {
            root = newcourse;
            return newcourse;
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
                return NULL;
            }
        }
        if (idcourse < parent->id)
        {
            parent->left = newcourse;
            return newcourse;
        }
        else
        {
            parent->right = newcourse;
            return newcourse;
        }
    }
    int dropCourse(int id)
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
            return 0;
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
            return 1;
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

Course *binary_search_course(Course *root, int course_id){
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

Student *sort_student(Student *head)
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

Course *sort_courses_bts(Course *root)
{
    vector<Course *> bts_nodes;
    in_order_bts_to_array(root, bts_nodes);
    Course *new_root = array_to_bts(bts_nodes, 0, bts_nodes.size() - 1);
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
        if(key < 0){
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
