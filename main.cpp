#include "university.cpp"


class university_main
{
public:
    Course_enrollment_History course_enrollment_DLL;
    StudentRecords student_records;
    hash_table hash;
    bst courses_bst;
    // course_registration_stack
    university_main()
        : course_enrollment_DLL(), student_records(), hash(), courses_bst()
    {
    }
    // single linked list
    void add_student(int id, string name, string email){
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            student_records.add(id, name, email);
            cout<<"Student Added!"<<endl;
        }
        else
        {
            cout<<"already exists"<<endl;
        }
    }

    void delete_student(int id)
    {
        student_records.remove(id);
    }

    void display_student_details(int id)
    {
        student_records.display_details(id);
    }

    // bst
    void courses_bst_add(int idcourse, string namecourse, int credithours, string teachers)
    {
        int limit = 30; // Example limit value
        Course *new_course = courses_bst.addcourse(idcourse, namecourse, credithours, teachers, limit);
        if (new_course)
        {
            hash.insert_hash(new_course);
        }
    }

    void courses_bst_drop(int id)
    {
        int course_drop = courses_bst.deleteCourse(id);
        if (course_drop == 1)
        {
            hash.remove_from_hash(id);
        }
    }

    // DLL
    void course_add_DLL(int course_id, int student_id)
    {
        Student *student = linear_search_student(student_records.get_head(), student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!" << endl;
            return;
        }

        Course *course = binary_search_course(courses_bst.root, course_id);

        if (course == NULL)
        {
            cout << "Course Not Found!" << endl;
            return;
        }

        student->enrollmentHistory->enroll_course(course, student);
        student->enrollmentHistory->view_enrollment_History();
    }

    // stack

    // search
    bool search_student(int student_id)
    {
        Student *student = linear_search_student(student_records.head, student_id);
        
        if (student == NULL)
        {
            cout<<"festek";
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void search_course(int course_id)
    {
        Course *course = binary_search_course(courses_bst.root, course_id);

        if (course != NULL)
        {
            cout << "Course: " << course->name << endl;
        }
        else
        {
            cout << "Course Not Found!" << endl;
        }
    }

    // sort
    void sort_linked_list_by_id()
    {
        Student *student_sort = sort_student(student_records.get_head());
        student_records.display();
    }

    void balance_courses_bts()
    {
        Course *sorted_courses = sort_courses_bts(courses_bst.root);
        courses_bst.display(courses_bst.root);
    }

    // hash function
    void searchWithHashing(int id)
    {
        Course *Course = hash.searchWithHashing(id);
        if (Course)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
};

// int main()
// {
//     // hash_table_test();
//     // test_sort_student();
//     // test_case();
//     // test_bst();
//     Display_Menu();
//     return 0;
// }
