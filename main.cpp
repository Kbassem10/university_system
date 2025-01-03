//test 3ashan ashra7lohom

#include <iostream>
#include <string>
#include "test_for_search.cpp"

using namespace std;

Student* linear_search_student(Student* head , int student_id){
    if(head == NULL){
        return NULL;
    }
    Student* current = head;
    while(current!= NULL){
        if(current->id == student_id){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

Course* binary_search_course(Course* root, int course_id){
    Course* current = root;
    while (current != NULL){
        if(current->id == course_id){
            return current;
        }

        if(course_id > current->id){
            current = current->right;
        }

        if(course_id < current->id){
            current = current->left;
        }
    }

    return current;
}

int main() {
    // Student Records Test
    StudentRecords studentRecords;
    studentRecords.add(1001, "Alice Johnson", "alice@example.com");
    studentRecords.add(1002, "Bob Smith", "bob@example.com");
    studentRecords.display();
    studentRecords.remove(1001);
    studentRecords.display();

    // Course Records Test
    CourseRecords courseRecords;
    courseRecords.addCourse(2001, "Data Structures", 3);
    courseRecords.addCourse(2002, "Algorithms", 4);
    courseRecords.addCourse(2003, "Operating Systems", 3);
    courseRecords.displayCourses();

    //Search Test
    Student* student = linear_search_student(studentRecords.get_head(), 1002);
    Course* course = binary_search_course(courseRecords.get_root(), 2001);
    
    cout<<"Student: "<<student->name<<endl;
    cout<<"Course: "<<course->name<<endl;
    return 0;
}