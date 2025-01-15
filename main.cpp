#include "university.cpp"

class university_main
{
public:
    StudentRecords student_records;
    hash_table hash;
    bst courses_bst;
    university_main()
        :student_records(), hash(), courses_bst()
    {
    }

    // single linked list
    void add_student()
    {
        cout << "Enter student id: \n";
        int id = int_checker();
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            string name;
            string email;

            cout << "Enter student name: \n";
            getline(cin, name);

            cout << "Enter student email: \n";
            cin >> email;

            student_records.add(id, name, email);
            cout << "Added Student with id " << id << endl;
        }
        else
        {
            cout << "already exists" << endl;
        }

    }
    void delete_student()
    {
        cout << "Enter student id: \n";
        int id = int_checker();
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            cout << "Not found.\n";
        }
        else
        {
            bool check_in_queue = check_student_in_queue(courses_bst.root , student);
            if(student->enrollmentHistory->head != NULL){
                cout << "This Student Cannot be deleted because he is enrolled in courses. "<< endl;
            }
            else if(check_in_queue){
                cout << "This Student Cannot be deleted because he is in waitlits of a course. "<< endl;
            }
            else{
                student_records.remove(id);
                cout << "Deleted Student: " << id << endl;
            }
        }
    }

    void display_student_details()
    {
        cout << "Enter student id: \n";
        int id = int_checker();
        student_records.display_details(id);
    }
    void display_students()
    {
        student_records.display();
    }
    // bst
    bool courseexist(int id)
    {
        return binary_search_course(courses_bst.root, id) != nullptr;
    }
    void addcourse()
    {
        cout << "Enter id course:" << endl;
        int idcourse = int_checker();
        if (courseexist(idcourse))
        {
            cout << " Course with this id is already exist \n";
            return;
        }
        else
        {
            string teachers, namecourse;
            cout << "Enter course enrollment limit: \n";
            int limit;
            while (true)
            {
                string input;
                
                getline(cin, input);
                try
                {
                    limit = stoi(input);
                    if(limit < 1){
                        cout << "Invalid input! Please enter a valid number (number > 0): ";
                        continue;
                    }
                    break;
                }
                catch (...)
                {
                    cout << "Invalid input! Please enter a valid number: ";
                }
            }
            cout << "Enter number of credits: \n";
            int credithours = int_checker();

            cout << "Enter course name: \n";
            getline(cin, namecourse);

            cout << "Enter instructor name: \n";
            getline(cin, teachers);

            cout << "How many prerequisites does this course have? ";
            int size;
            cin >> size;

            Course* course = courses_bst.addcourse(idcourse, namecourse, credithours, teachers, limit, size);
            courses_bst.balance_bst();
            hash.insert_hash(course);
        }
    }
    void displaycourses()
    {
        cout << "display all courses: \n";
        courses_bst.display(courses_bst.root);
    }
    void Removecourse()
    {
        cout << "Enter id course:" << endl;
        int idcourse = int_checker();
        if (courseexist(idcourse) == false)
        {
            cout << "This course does not exist.\n";
            return;
        }
        else
        {
            if(check_any_student_enrolled(student_records.head ,idcourse)){
                cout<<"You cannot delete this course while there is someone enrolled to it! "<<endl;
                return;
            }
            courses_bst.deleteCourse(idcourse);
            hash.remove_from_hash(idcourse);

            cout << "Course removed.\n";
        }
    }

    void viewpre()
    {
        cout << "Enter course id to see the prequist: " << endl;
        int course_id = int_checker();
        cout << "Enter Student id:" << endl;
        int student_id = int_checker();

        Course *course = binary_search_course(courses_bst.root, course_id);
        Student *student = linear_search_student(student_records.head, student_id);

        if (course && student)
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
        cout << "Enter course id to see the waiting list: \n";
        int idcourse = int_checker();
        Course *course = binary_search_course(courses_bst.root, idcourse);
        if (!course)
        {
            cout << "Didn't find any course with this id." << endl;
            return;
        }
        if (course->waitlist.queue_is_empty())
        {
            cout << "no waiting list" << endl;
        }
        else
        {
            course->waitlist.displayWaitlist();
        }
    }

    void enroll_course()
    {
        cout << "Enter student ID: ";
        int student_id = int_checker();
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }

        cout << "Enter course ID: ";
        int course_id = int_checker();
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

        Student* student_in_queue = course->waitlist.seach_in_waitlist(student_id);
        if(student_in_queue){
            cout<<"You can't enroll now because it's full and you are already IN THE WAITING LIST!! WHEN SOMEONE DROP YOU WILL BE ADDED"<<endl;
            return;
        }

        bool validate_Prerequisites = validatePrerequisites(course, student);

        if (validate_Prerequisites && course->current_number_of_enrollments < course->course_limit)
        {
            student->enrollmentHistory->enroll_course(course, student);
            cout << "Student " << student->id << " Enrolled " << course->id << endl;
        }
        else if (course->current_number_of_enrollments >= course->course_limit && validate_Prerequisites)
        {
            cout << " Course is full so you were add to waitlist.\n";
            course->waitlist.enqueue_to_waitlist(student);
        }
        else if (validate_Prerequisites == false)
        {
            cout << "This Course is unavailable due to:\n";
            Display_remaining_Prerequisites(course, student);
        }
    }
    void auto_enroll_course(Course *course, Student *student)
    {
        student->enrollmentHistory->enroll_course(course, student);
    }

    void student_drop_course()
    {
        cout << "Enter student ID: ";
        int student_id = int_checker();
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
        }
        else
        {
            cout << "Enter course ID: ";
            int course_id = int_checker();
            Course *course = binary_search_course(courses_bst.root, course_id);
            if (course == NULL)
            {
                cout << "Course Not Found!" << endl;
            }
            else if (student->enrollmentHistory->check_course_enrollment(course_id))
            {
                student->enrollmentHistory->student_drop_course(course_id);
                auto_enroll_course(course, course->waitlist.dequeue_from_waitlist()->student);
            }
            else
            {
                cout << "course not enrolled.\n";
            }
        }
    }
    void display_enrollments()
    {
        cout << "Enter student id: \n";
        int id = int_checker();
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
        cout << "Enter student ID: ";
        int student_id = int_checker();
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
            return 0;
        }
    }
    void display_course()
    {
        cout << "Enter course ID: ";
        int course_id = int_checker();
        Course *course = binary_search_course(courses_bst.root, course_id);
        if (course != NULL)
        {
            courses_bst.display(course);
        }
        else
        {
            cout << "Course not found.\n";
        }
    }
    // sort
    void sort_linked_list_by_id()
    {
        Student *student_sort = sort_student(student_records.head);
        student_records.display();
    }

    // hash function
    void searchWithHashing()
    {
        cout << "Enter course ID: ";
        int course_id = int_checker();
        Course *Course = hash.searchWithHashing(course_id);
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
