#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

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

    Course(int id, const string &name, int credits)
        : id(id), name(name), credits(credits), left(nullptr), right(nullptr) {}
};

class CourseRecords // Fahmy yeshel w yktbha Raqam 2
{
private:
    Course *root;

    void addCourseHelper(Course *&node, int id, const string &name, int credits)
    {
        if (!node)
        {
            node = new Course(id, name, credits);
            cout << "Course added: " << name << endl;
            return;
        }
        if (id < node->id)
        {
            addCourseHelper(node->left, id, name, credits);
        }
        else if (id > node->id)
        {
            addCourseHelper(node->right, id, name, credits);
        }
        else
        {
            cout << "Course ID already exists.\n";
        }
    }

    void displayCoursesHelper(Course *node) const
    {
        if (!node)
            return;
        displayCoursesHelper(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Credits: " << node->credits << endl;
        displayCoursesHelper(node->right);
    }

public:
    Course *get_root()
    {
        return root;
    }

    CourseRecords() : root(nullptr) {}

    void addCourse(int id, const string &name, int credits)
    {
        addCourseHelper(root, id, name, credits);
    }

    void displayCourses() const
    {
        cout << "Course Records:\n";
        displayCoursesHelper(root);
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

int main()
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
    CourseRecords courseRecords;
    courseRecords.addCourse(5, "Data Structures", 3);
    courseRecords.addCourse(4, "Algorithms", 4);
    courseRecords.addCourse(8, "Operating Systems", 3);
    courseRecords.displayCourses();

    // Search Test
    Student *student = linear_search_student(studentRecords.get_head(), 3);
    Course *course = binary_search_course(courseRecords.get_root(), 4);

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
    Course *testCourse = new Course(10, "Artificial Intelligence", 4);
    testCourse->waitlist.enqueue("John Doe");
    testCourse->waitlist.enqueue("Lionel Messi");
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    testCourse->waitlist.displayWaitlist();

    testCourse->waitlist.dequeue();
    delete testCourse;

    return 0;
}