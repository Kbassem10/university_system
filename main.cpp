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
    void add_student()
    {
        int id;
        cout << "Enter student id: \n";
        cin >> id;
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            string name;
            string email;
            cout << "Enter student name: \n";
            cin >> name;
            cout << "Enter student email: \n";
            cin >> email;
            student_records.add(id, name, email);
            cout << "Added Student with id " << id << endl ;
        }
        else
        {
            cout << "already exists" << endl;
        }
    }
    void delete_student()
    {
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        student_records.remove(id);
        cout<< "Deleted Student" << id << endl;
    }
    void display_student_details()
    {
        int id;
        cout << "Enter student ID: ";
        cin >> id;
        student_records.display_details(id);
    }
    void display_students(){
        student_records.display();
    }
    // bst
    bool courseexist(int id)
    {
        return binary_search_course(courses_bst.root, id) != nullptr;
    }
    void addcourse()
    {
        int idcourse, credithours, limit;
        string teachers, namecourse;
        cout << "Enter id course:" << endl;
        cin >> idcourse;
        if (courseexist(idcourse))
        {
            cout << " Course with this id is already exist \n";
            return;
        }
        else
        {
            cout << "Enter course name: \n";
            cin >> namecourse;
            cout << "Enter number of credits: \n";
            cin >> credithours;
            cout << "Enter instructor name: \n";
            cin >> teachers;
            cout << "Enter course enrollment limit: \n";
            cin >> limit;
            courses_bst.addcourse(idcourse, namecourse, credithours, teachers, limit);
        }
    }
    void displaycourses()
    {
        cout << "display all courses: \n";
        courses_bst.display(courses_bst.root);
    }
    void Removecourse()
    {
        int idcourse;
        cout << "Enter course id that you want to remove:\n";
        cin >> idcourse;
        if (courseexist(idcourse) == false)
        {
            cout << "This course does not exist.\n";
            return;
        }
        else
        {
            courses_bst.deleteCourse(idcourse);
            cout << "Course removed.\n";
        }
    }
    void viewpre()
    {
        int course_id;
        int student_id;
        cout << "Enter course id to see the prequist: " << endl;
        cin >> course_id;
        cout << "Enter Student id:" << endl;
        cin >> student_id;

        Course *course = binary_search_course(courses_bst.root, course_id);
        Student *student = linear_search_student(student_records.head, student_id);

        if (course_id && student_id)
        {
            Display_remaining_Prerequisites(course, student);
        }
        else
        {
            cout << "There is no Student or course with that id" << endl;
        }
    }

    void waitlist()
    {
        int idcourse;
        cout << "Enter course id to see the waiting list: \n";
        cin >> idcourse;
        Course *course = binary_search_course(courses_bst.root, idcourse);
        if (!course)
        {
            cout << "Didn't find any course with this id." << endl;
            return;
        }
        if (course->current_number_of_enrollments <= course->course_limit)
        {
            cout << "no waiting list" << endl;
        }
        else
        {
            // el ta7t di el tari2a el wa7ida bel shakl el 7ali ya2ema hanetar ne8ayar 7agat ketir mooot
            course->waitlist.displayWaitlist();
        }
    }

    void enroll_course()
    {

        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }
        int course_id;
        cout << "Enter course ID: ";
        cin >> course_id;
        Course *course = binary_search_course(courses_bst.root, course_id);
        if (student->enrollmentHistory->check_course_enrollment(course_id))
        {
            cout << "Course already enrolled\n";
            return;
        }
        if (course == NULL)
        {
            cout << "Course Not Found!" << endl;
            return;
        }
        if (validatePrerequisites(course, student) && course->current_number_of_enrollments < course->course_limit)
        {
            student->enrollmentHistory->enroll_course(course, student);
            cout << "Student " << student->id << " Enrolled " << course->id << endl;
        }
        else if (course->current_number_of_enrollments >= course->course_limit)
        {
            cout << " Course is full so you were add to waitlist.\n";
            course->waitlist.enqueue_to_waitlist(student);
        }else if(validatePrerequisites(course, student)==false){
            cout<< "This Course is unavailable due to:\n"
            Display_remaining_Prerequisites(course, student);
        }
    }
    void auto_enroll_course(Course *course, Student *student)
    {
        student->enrollmentHistory->enroll_course(course, student);
    }

    void student_drop_course()
    {
        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }
        int course_id;
        cout << "Enter course ID: ";
        cin >> course_id;
        Course *course = binary_search_course(courses_bst.root, course_id);
        if (course == NULL)
        {
            cout << "Course Not Found!" << endl;
            return;
        }
        if (student->enrollmentHistory->check_course_enrollment(course_id))
        {
            student->enrollmentHistory->student_drop_course(course_id);
            auto_enroll_course(course, course->waitlist.dequeue_from_waitlist()->student);
            return;
        }
    }
    void display_enrollments()
    {
        int id;
        cout << "Enter student ID: \n";
        cin >> id;
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }
        student->enrollmentHistory->view_enrollment_History();
    }
    // search
    void search_student()
    {
        int student_id;
        cout << "Enter student ID: ";
        cin >> student_id;
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student not found";
        }
        else
        {
            student_records.display_details(student_id);
        }
    }

    bool search_course(int course_id)
    {
        Course *course = binary_search_course(courses_bst.root, course_id);

        if (course != NULL)
        {
            return 1;
        }
        else
        {
            cout << "Course Not Found!" << endl;
        }
    }

    // sort
    void sort_linked_list_by_id()
    {
        Student *student_sort = sort_student(student_records.head);
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
