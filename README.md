# Data Structures Course Project - Fall 2024
## University System
This project involves designing a university management system that efficiently handles
student records, course information, enrollment histories, and course registrations using a
variety of data structures. It integrates components such as linked lists, stacks, queues,
binary search trees, and hash tables to ensure optimal performance for diverse
operations.
## System Overview:
1. Student Records Management: Use a Single Linked List (SLL) to store and manage
student details.
2. Course Records Management: Implement a Binary Search Tree (BST) to organize
and search course information.
3. Course Enrollment History: Employ a Double Linked List (DLL) to track each
student's course history.
4. Course Prerequisites: Use a Stack to validate prerequisites for course registration.
5. Course Waitlists: Manage waitlists with a Queue.
6. Search Optimization: Implement Linear and Binary Search algorithms.
7. Fast Access: Utilize a Hash Table for efficient lookups.



## Functional Components:

1. Student Records Management: Single Linked List <br>
Store and manage student records in a Single Linked List. <br>
Functionalities to implement:
- add(): Add a new student with attributes such as ID, Name, Email, Phone,
Address, and Password.
- delete(): Remove a student by their ID.
- display(): Print all student details.

  
2. Course Records Management: Binary Search Tree (BST) <br>
Store course information in a Binary Search Tree (BST). <br>
Functionalities to implement: <br>
- Each node contains: CourseID, CourseName, CourseCredits, and
CourseInstructor.
- The tree is structured so that for any node, all nodes in the left subtree have
smaller IDs, and all nodes in the right subtree have larger IDs.
- Methods:
  - addCourse()
  - dropCourse()
 

3. Course Enrollment History: Double Linked List <br>
Track each student's course enrollment history using a Double Linked List. <br>
Functionalities to implement: <br>
- add(): Add a new enrollment record for a student.
- view(): Display the enrollment history of a specific student.

  
4. Course Registration: Stack <br>
Validate course prerequisites using a Stack. <br>
How it works: <br>
- Push all required prerequisites onto the stack.
- Pop completed prerequisites from the stack based on the student's record.
- If the stack is empty, the student is eligible to register.
Functionalities to implement: <br>
- validatePrerequisites(courseID, studentID): Check if a student meets the
prerequisites for a course.
- Display remaining prerequisites if validation fails.

5. Course Waitlist: Queue <br>
Manage course waitlists using a Queue. <br>
Functionalities to implement: <br>
- enqueue(): Add a student to the waitlist when a course is full.
- dequeue(): Enroll the first student on the waitlist when a spot becomes
available.


6. Search and Sort Operations <br>
Implement search and sort functionalities for: <br>
- Students by ID.
- Courses by ID.


Bonus Part: <br>
7. Fast Access Using Hashing <br>
Enhance lookup efficiency with a Hash Table. <br>
Requirements: <br>
- Design a hashing function.
- Implement collision handling (e.g., Chaining or Open Addressing).
- searchWithHashing(): to improve course search efficiency.
