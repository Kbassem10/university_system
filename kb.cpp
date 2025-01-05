class university_main{
    private:
        Course_enrollment_History course_enrollment_DLL;
        StudentRecords student_records;
        Course_Waitlist course_waitlist;
        hash_table hash;
        bst courses_bst;
        //course_registration_stack
    public:
        //single linked list

        //bst
        void courses_bst_add(int idcourse, string namecourse, int credithours, string teachers){
            Course* new_course = courses_bst.addcourse(idcourse ,namecourse, credithours,teachers);
            if(new_course){
                hash.insert_hash(new_course);
            }
        }

        void courses_bst_drop(int id){
            int course_drop = courses_bst.dropCourse(id);
            if(course_drop == 1){
                hash.remove_from_hash(id);
            }
        }

        //DLL
        void course_add_DLL(string course_name){
            course_enrollment_DLL.add_course(course_name);
        }

        void view_enrollment_History_DLL(){
            course_enrollment_DLL.view_enrollment_History();
        }

        //stack

        //queue
        void Course_Waitlist_enqueue(string student_name){
            course_waitlist.enqueue(student_name);
        }

        void Course_Waitlist_dequeue(){
            course_waitlist.dequeue();
        }

        //search
        void search_student(int student_id){
            Student *student = linear_search_student(student_records.get_head(), student_id);
            if (student == NULL){
                cout << "Student Not Found!" << endl;
            }
            else{
                cout << "Student Found, Name: " << student->name << endl;
            }
        }

        void search_course(int course_id){
            Course *course = binary_search_course(courses_bst.root, course_id);

            if (course != NULL){
                cout << "Course: " << course->name << endl;
            }
            else{
                cout << "Course Not Found!" << endl;
            }
        }

        //sort
        void sort_linked_list_by_id(){
            Student *student_sort = sort_student(student_records.get_head());
            student_records.display();
        }

        void balance_courses_bts(){
            Course* sorted_courses = sort_courses_bts(courses_bst.root);
            courses_bst.display(courses_bst.root);
        }

        //hash function
        void searchWithHashing(int id){
            Course* Course = hash.searchWithHashing(id);
            if(Course){
                cout<<"Found"<<endl;
            }
            else{
                cout<<"Not Found"<<endl;
            }
        }
};