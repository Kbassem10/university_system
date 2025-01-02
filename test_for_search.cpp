#include<iostream>
using namespace std;

struct Student {
    int id;
    string name;
    string email;
    Student* next;
};

class StudentRecords {
private:
    Student* head;

public:

    Student* get_head(){
        return head;
    }

    StudentRecords() : head(nullptr) {}

    void add(int id, const string& name, const string& email) {
        Student* newStudent = new Student{id, name, email, nullptr};
        if (!head) {
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student added: " << name << endl;
    }

    void remove(int id) {
        if (!head) {
            cout << "Student not found.\n";
            return;
        }

        if (head->id == id) {
            Student* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Student removed.\n";
            return;
        }

        Student* temp = head;
        while (temp->next && temp->next->id != id) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Student not found.\n";
            return;
        }

        Student* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Student removed.\n";
    }

    void display() const {
        Student* temp = head;
        cout << "Student Records:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    Student* getHead() const {
        return head;
    }
};

struct Course {
    int id;
    string name;
    int credits;
    Course* left;
    Course* right;

    Course(int id, const string& name, int credits)
        : id(id), name(name), credits(credits), left(nullptr), right(nullptr) {}
};

class CourseRecords {
private:
    Course* root;

    void addCourseHelper(Course*& node, int id, const string& name, int credits) {
        if (!node) {
            node = new Course(id, name, credits);
            cout << "Course added: " << name << endl;
            return;
        }
        if (id < node->id) {
            addCourseHelper(node->left, id, name, credits);
        } else if (id > node->id) {
            addCourseHelper(node->right, id, name, credits);
        } else {
            cout << "Course ID already exists.\n";
        }
    }

    void displayCoursesHelper(Course* node) const {
        if (!node) return;
        displayCoursesHelper(node->left);
        cout << "ID: " << node->id << ", Name: " << node->name << ", Credits: " << node->credits << endl;
        displayCoursesHelper(node->right);
    }

public:

    Course* get_root(){
        return root;
    }

    CourseRecords() : root(nullptr) {}

    void addCourse(int id, const string& name, int credits) {
        addCourseHelper(root, id, name, credits);
    }

    void displayCourses() const {
        cout << "Course Records:\n";
        displayCoursesHelper(root);
    }
};
