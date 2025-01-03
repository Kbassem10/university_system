#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
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

void linked_list_swap(Student* node1, Student* node2){
    if (!node1 || !node2){
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

Student* sort_student(Student* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }

    Student* current = head;
    while(current!= NULL){
        Student* min = current;
        Student* next = current->next;
        while(next!=NULL){
            if(next->id < min->id){
                min = next;
            }
            next = next->next;
        }
        if(min!=current){
            linked_list_swap(min, current);   
        }
        current = current->next;
    }
    return head;
}

int main() {
    // Student Records Test
    StudentRecords studentRecords;
    studentRecords.add(7, "Alice Johnson", "alice@example.com");
    studentRecords.add(5, "Bob Smith", "bob@example.com");
    studentRecords.add(6, "Alice Johnson", "alice@example.com");
    studentRecords.add(1, "Bob Smith", "bob@example.com");
    studentRecords.add(10, "Alice Johnson", "alice@example.com");
    studentRecords.add(3, "Bob Smith", "bob@example.com");
    studentRecords.display();
    studentRecords.remove(10);
    studentRecords.display();

    // Course Records Test
    CourseRecords courseRecords;
    courseRecords.addCourse(5, "Data Structures", 3);
    courseRecords.addCourse(4, "Algorithms", 4);
    courseRecords.addCourse(8, "Operating Systems", 3);
    courseRecords.displayCourses();

    //Search Test
    Student* student = linear_search_student(studentRecords.get_head(), 10);
    Course* course = binary_search_course(courseRecords.get_root(), 4);

    if(student == NULL){
        cout<<"Student Not Found!"<<endl;
    }
    else{
        cout<<"Student: "<<student->name<<endl;
    }
    if(course == NULL){
        cout<<"Course: "<<course->name<<endl;
    }
    else{
        cout<<"Course Not Found!"<<endl;
    }

    //sort linked list by id
    Student* student_sort = sort_student(studentRecords.get_head());
    studentRecords.display();

    return 0;
}
