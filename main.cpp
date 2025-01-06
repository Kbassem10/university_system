#include "university.cpp"


class university_main
{
private:
    Course_enrollment_History course_enrollment_DLL;
    StudentRecords student_records;
    hash_table hash;
    bst courses_bst;
    // course_registration_stack
public:
    university_main()
        : course_enrollment_DLL(), student_records(), hash(), courses_bst()
    {
    }
    // single linked list
    void add_student(int id, string name, string email, string phone, string address, string password)
    {
        student_records.add(id, name, email, phone, address, password);
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
         return courses_bst.search(id) != nullptr;

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
            cin >> creditscourse;
            cout << "Enter instructor name: ";
            cin >> teachers;
            cout << "Enter course enrollment limit: ";
            cin >> limit;
            courses_bst_add(idcourse, namecourse, credithours, teachers, limit);
            cout<<"Course is added";
         }
    }
    void displaycourses(){
        cout<<"display all courses \n";
        courses_bst.display();

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
        Course *course=courses_bst.find(idcourse);
        displayPrerequisites(course);
    }
    void waitlist(){
         int idcourse;
        cout << "Enter course id to see the waiting list: ";
        cin >> idcourse;
        Course *course=courses_bst.find(idcourse);
        if(!course){
            cout<<"not found any course with this id."<<endl;
            return;
        }
        if(course->idcourse.size() <= course->limit){
            cout<<"no waiting list"<<endl;
        }
        else{
            course->waitlist.displayWaitlist();
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
    void search_student(int student_id)
    {
        Student *student = linear_search_student(student_records.get_head(), student_id);
        if (student == NULL)
        {
            cout << "Student Not Found!" << endl;
        }
        else
        {
            cout << "Student Found, Name: " << student->name << endl;
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
