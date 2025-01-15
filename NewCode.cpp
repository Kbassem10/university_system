#include <iostream>
#include <string>
using namespace std;

class Course;
class CourseNode;
class Student;
class StudentNode;
class EnrollmentHistory;
class EnrollmentNode;
class Prerequisites;
class WaitList;

class Stack
{
private:
    struct StackNode
    {
        int courseId;
        StackNode *next;
        StackNode(int id) : courseId(id), next(nullptr) {}
    };
    StackNode *top;

public:
    Stack() : top(nullptr) {}

    void push(int courseId)
    {
        StackNode *newNode = new StackNode(courseId);
        newNode->next = top;
        top = newNode;
    }

    bool pop()
    {
        if (isEmpty())
            return false;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return true;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        StackNode *current = top;
        while (current != nullptr)
        {
            cout << current->courseId << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

class Queue
{
private:
    struct QueueNode
    {
        int studentId;
        QueueNode *next;
        QueueNode(int id) : studentId(id), next(nullptr) {}
    };
    QueueNode *front, *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int studentId)
    {
        QueueNode *newNode = new QueueNode(studentId);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;
        QueueNode *temp = front;
        int studentId = front->studentId;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        return studentId;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

class EnrollmentHistory
{
private:
    struct EnrollmentNode
    {
        int courseId;
        string grade;
        EnrollmentNode *prev;
        EnrollmentNode *next;
        EnrollmentNode(int id) : courseId(id), grade(""), prev(nullptr), next(nullptr) {}
    };
    EnrollmentNode *head;
    EnrollmentNode *tail;

public:
    EnrollmentHistory() : head(nullptr), tail(nullptr) {}

    void addEnrollment(int courseId)
    {
        EnrollmentNode *newNode = new EnrollmentNode(courseId);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    bool setGrade(int courseId, string grade)
    {
        EnrollmentNode *current = head;
        while (current)
        {
            if (current->courseId == courseId)
            {
                current->grade = grade;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display()
    {
        EnrollmentNode *current = head;
        while (current)
        {
            cout << "Course ID: " << current->courseId;
            if (!current->grade.empty())
            {
                cout << ", Grade: " << current->grade;
            }
            cout << endl;
            current = current->next;
        }
    }

    bool isEnrolled(int courseId)
    {
        EnrollmentNode *current = head;
        while (current)
        {
            if (current->courseId == courseId && current->grade.empty())
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool hasCompleted(int courseId)
    {
        EnrollmentNode *current = head;
        while (current)
        {
            if (current->courseId == courseId && !current->grade.empty())
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class Student
{
public:
    int id;
    string name;
    string email;
    string phone;
    string address;
    string password;
    EnrollmentHistory *enrollmentHistory;

    Student(int _id, string _name, string _email, string _phone, string _address, string _password)
        : id(_id), name(_name), email(_email), phone(_phone), address(_address), password(_password)
    {
        enrollmentHistory = new EnrollmentHistory();
    }

    ~Student()
    {
        delete enrollmentHistory;
    }
};

class Course
{
public:
    int id;
    string name;
    int credits;
    string instructor;
    int maxStudents;
    int currentEnrollment;
    Stack prerequisites;
    Queue waitlist;

    Course(int _id, string _name, int _credits, string _instructor, int _maxStudents)
        : id(_id), name(_name), credits(_credits), instructor(_instructor),
          maxStudents(_maxStudents), currentEnrollment(0) {}
};

class StudentRecords
{
private:
    struct StudentNode
    {
        Student *data;
        StudentNode *next;
        StudentNode(Student *student) : data(student), next(nullptr) {}
    };
    StudentNode *head;

public:
    StudentRecords() : head(nullptr) {}

    bool addStudent(int id, string name, string email, string phone, string address, string password)
    {
        if (findStudent(id) != nullptr)
        {
            cout << "Error: Student with ID " << id << " already exists" << endl;
            return false;
        }

        Student *newStudent = new Student(id, name, email, phone, address, password);
        StudentNode *newNode = new StudentNode(newStudent);

        if (!head)
        {
            head = newNode;
        }
        else
        {
            StudentNode *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Student with ID " << id << " was successfully added" << endl;
        return true;
    }

    StudentNode *findStudent(int student_id)
    {
        if (head == NULL)
        {
            return NULL;
        }
        StudentNode *current = head;
        while (current != NULL)
        {
            if (current->data->id == student_id)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }

    bool deleteStudent(int id)
    {
        if (!head)
        {
            cout << "Error: No students in the system" << endl;
            return false;
        }

        if (head->data->id == id)
        {
            StudentNode *temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
            cout << "Student with ID " << id << " was successfully deleted" << endl;
            return true;
        }

        StudentNode *current = head;
        while (current->next && current->next->data->id != id)
        {
            current = current->next;
        }

        if (current->next)
        {
            StudentNode *temp = current->next;
            current->next = temp->next;
            delete temp->data;
            delete temp;
            cout << "Student with ID " << id << " was successfully deleted" << endl;
            return true;
        }
        cout << "Error: Student with ID " << id << " not found" << endl;
        return false;
    }

    void display()
    {
        StudentNode *current = head;
        while (current)
        {
            cout << "ID: " << current->data->id << endl;
            cout << "Name: " << current->data->name << endl;
            cout << "Email: " << current->data->email << endl;
            cout << "Phone: " << current->data->phone << endl;
            cout << "Address: " << current->data->address << endl;
            cout << "Enrollment History:" << endl;
            current->data->enrollmentHistory->display();
            cout << "------------------------" << endl;
            current = current->next;
        }
    }

    ~StudentRecords()
    {
        while (head)
        {
            StudentNode *temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
    }
};

class CourseRecords
{
private:
    struct CourseNode
    {
        Course *data;
        CourseNode *left;
        CourseNode *right;
        CourseNode(Course *course) : data(course), left(nullptr), right(nullptr) {}
    };
    CourseNode *root;

    CourseNode *insertHelper(CourseNode *node, Course *course)
    {
        if (!node)
        {
            return new CourseNode(course);
        }

        if (course->id < node->data->id)
        {
            node->left = insertHelper(node->left, course);
        }
        else if (course->id > node->data->id)
        {
            node->right = insertHelper(node->right, course);
        }
        return node;
    }

public:
    CourseRecords() : root(nullptr) {}

    bool addCourse(int id, string name, int credits, string instructor, int maxStudents)
    {
        if (findCourse(id) != nullptr)
        {
            cout << "Error: Course with ID " << id << " already exists" << endl;
            return false;
        }

        Course *newCourse = new Course(id, name, credits, instructor, maxStudents);
        root = insertHelper(root, newCourse);
        cout << "Course with ID " << id << " was successfully added" << endl;
        return true;
    }

    // search on the BST
    Course *findCourse(int course_id)
    {
        CourseNode *current = root;
        while (current != NULL){
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

    bool addPrerequisite(int courseId, int prerequisiteId)
    {
        Course *course = findCourse(courseId);
        Course *prerequisite = findCourse(prerequisiteId);

        if (!course || !prerequisite)
        {
            cout << "Error: Course or prerequisite not found" << endl;
            return false;
        }

        course->prerequisites.push(prerequisiteId);
        cout << "Prerequisite (Course " << prerequisiteId << ") was successfully added to Course " << courseId << endl;
        return true;
    }

    bool enrollStudent(int courseId, int studentId, StudentRecords &students)
    {
        Course *course = findCourse(courseId);
        Student *student = students.findStudent(studentId);

        if (!course || !student)
        {
            cout << "Error: Course or student not found" << endl;
            return false;
        }

        if (student->enrollmentHistory->isEnrolled(courseId))
        {
            cout << "Error: Student " << studentId << " is already enrolled in Course " << courseId << endl;
            return false;
        }

        Stack tempStack = course->prerequisites;
        while (!tempStack.isEmpty())
        {
            int prereqId = tempStack.pop();
            if (!student->enrollmentHistory->hasCompleted(prereqId))
            {
                cout << "Error: Student " << studentId << " has not completed prerequisite Course " << prereqId << endl;
                return false;
            }
        }

        if (course->currentEnrollment >= course->maxStudents)
        {
            course->waitlist.enqueue(studentId);
            cout << "Course " << courseId << " is full. Student " << studentId << " has been added to the waitlist." << endl;
            return false;
        }

        course->currentEnrollment++;
        student->enrollmentHistory->addEnrollment(courseId);
        cout << "Student " << studentId << " was successfully enrolled in Course " << courseId << endl;
        return true;
    }

    bool dropCourse(int courseId, int studentId, StudentRecords &students)
    {
        Course *course = findCourse(courseId);
        Student *student = students.findStudent(studentId);

        if (!course || !student)
        {
            cout << "Error: Course or student not found" << endl;
            return false;
        }

        if (!student->enrollmentHistory->isEnrolled(courseId))
        {
            cout << "Error: Student " << studentId << " is not enrolled in Course " << courseId << endl;
            return false;
        }

        student->enrollmentHistory->setGrade(courseId, "F");
        course->currentEnrollment--;
        cout << "Student " << studentId << " has dropped Course " << courseId << " and received grade F" << endl;

        if (!course->waitlist.isEmpty())
        {
            int nextStudentId = course->waitlist.dequeue();
            if (enrollStudent(courseId, nextStudentId, students))
            {
                cout << "Student " << nextStudentId << " was enrolled from the waitlist for Course " << courseId << endl;
            }
            else
            {
                cout << "Could not enroll next student from waitlist" << endl;
            }
        }

        return true;
    }

    bool completeCourse(int courseId, int studentId, string grade, StudentRecords &students)
    {
        Course *course = findCourse(courseId);
        Student *student = students.findStudent(studentId);

        if (!course || !student)
        {
            cout << "Error: Course or student not found" << endl;
            return false;
        }

        if (!student->enrollmentHistory->isEnrolled(courseId))
        {
            cout << "Error: Student " << studentId << " is not enrolled in Course " << courseId << endl;
            return false;
        }

        student->enrollmentHistory->setGrade(courseId, grade);
        course->currentEnrollment--;
        cout << "Student " << studentId << " has completed Course " << courseId << " with grade " << grade << endl;

        if (!course->waitlist.isEmpty())
        {
            int nextStudentId = course->waitlist.dequeue();
            if (enrollStudent(courseId, nextStudentId, students))
            {
                cout << "Student " << nextStudentId << " was enrolled from the waitlist for Course " << courseId << endl;
            }
            else
            {
                cout << "Could not enroll next student from waitlist" << endl;
            }
        }

        return true;
    }
};
