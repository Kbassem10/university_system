Student::Student(int studentId, const string &studentName, const string &studentEmail)
    : id(studentId), name(studentName), email(studentEmail), next(nullptr), enrollmentHistory(nullptr)
{
    enrollmentHistory = new Course_enrollment_History();
}

struct SLL_node{
    Student student;
    SLL_node *next;
    SLL_node *prev;
};
class StudentRecords
{
public:
    SLL_node *head;
    SLL_node *tail;

    void add(int id, const string &name, const string &email)
    {
        Student *newStudent = new Student{id, name, email};
        if (!head)
        {
            head=tail = newStudent;
        }
        else
        {
            tail->next= newStudent;
            tail = newStudent;
        }
        cout << "Student added: " << name << endl;
    }

        void remove(int id) {
        SLL_node *current = head;
        while (current && current->student.id != id) {current = current->next;}
        if (!current) {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }
        if (current == head) head = head->next;
        if (current == tail) tail = tail->prev;
        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        cout << "Student removed: " << current->student.name << endl;
        delete current;
    }

    void display() const
    {
        Student *temp = head;
        cout << "Student Records:\n";
        while (temp)
        {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
            temp = temp->next;
        }
    }

    void display_details(int id)
    {
        Student *temp = head;
        cout << "Student's Record:\n";
        while (temp)
        {
            if (temp->id == id)
            {
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Not Found";
            return;
        }
        cout << "ID: " << temp->id << ", Name: " << temp->name << ", Email: " << temp->email << endl;
        temp = temp->next;
    }
};