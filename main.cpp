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
    void add_student(int id, string name, string email)
    {
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            student_records.add(id, name, email);
            cout << "Student Added!" << endl;
        }
        else
        {
            cout << "already exists" << endl;
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
     bool courseexist(int id){
         return binary_search_course(courses_bst.root ,id) != nullptr;
    }
    void addcourse(){
        int idcourse,credithours,limit;
        string teachers, namecourse;
         cout<<"Enter id course: "<<endl;
         cin>>idcourse;
         if(courseexist(idcourse)){
            cout<<" Course with this id is already exist \n";
             return;
         }else{
            cout << "Enter course name: ";
            cin >> namecourse;
            cout << "Enter number of credits: ";
            cin >> credithours;
            cout << "Enter instructor name: ";
            cin >> teachers;
            cout << "Enter course enrollment limit: ";
            cin >> limit;
            courses_bst.addcourse(idcourse, namecourse, credithours, teachers, limit);
            cout<<"Course is added";
         }
    }
    void displaycourses(){
        cout<<"display all courses \n";
        courses_bst.display(courses_bst.root);

    }
    void Removecourse(){
        int idcourse;
        cout<< "Enter course id that you want to remove"<<endl;
        cin>>idcourse;
        if(courseexist(idcourse)==false){
            cout<<"This course is not exist.";
            return;
        }else{
            courses_bst_drop(idcourse);
            cout<<"Course removed";
        }
    }
    void viewpre(){
        int idcourse;
        cout<< "Enter course id to see the prequist: "<<endl;
        cin>>idcourse;
        Course *course= binary_search_course(courses_bst.root, idcourse);
        Display_remaining_Prerequisites(course);//bos di bta5od 2 inputs ro7 bos 3aleha felk a5er fel university.cpp w 3adel kol el araf da
    }
    void waitlist(){
         int idcourse;
        cout << "Enter course id to see the waiting list: ";
        cin >> idcourse;
        Course *course=binary_search_course(courses_bst.root ,idcourse);
        if(!course){
            cout<<"not found any course with this id."<<endl;
            return;
        }
        if(course->current_number_of_enrollments <= course->course_limit){
            cout<<"no waiting list"<<endl;
        }
        else{
            //el ta7t di el tari2a el wa7ida bel shakl el 7ali ya2ema hanetar ne8ayar 7agat ketir mooot
            course_enrollment_DLL.course_waitlist.displayWaitlist(course);
        }
    }

    // DLL
    void enroll_course(int course_id, int student_id)
    {

        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }

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
        if (validatePrerequisites(*course, *student))
        {
            student->enrollmentHistory->enroll_course(course, student);
            student->enrollmentHistory->view_enrollment_History();
            cout << "Student" << student->id << "Enrolled" << course->id << endl;
        }

        else
        {
            Display_remaining_Prerequisites(*course, *student);
        }
    }

    void student_drop_course(int course_id, int student_id)
    {
        Student *student = linear_search_student(student_records.head, student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }

        Course *course = binary_search_course(courses_bst.root, course_id);
        if (course == NULL)
        {
            cout << "Course Not Found!" << endl;
            return;
        }
        if (student->enrollmentHistory->check_course_enrollment(course_id))
        {
            student->enrollmentHistory->student_drop_course(course_id);
            return;
        }
    }
    void display_enrollments(int id)
    {
        Student *student = linear_search_student(student_records.head, id);
        if (student == NULL)
        {
            cout << "Student Not Found!\n";
            return;
        }
        student->enrollmentHistory->view_enrollment_History();
    }
    // search
    bool search_student(int student_id)
    {
        Student *student = linear_search_student(student_records.head, student_id);

        if (student == NULL)
        {
            cout << "festek";
            return 0;
        }
        else
        {
            return 1;
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
