#include <iostream>

struct StudentNode {
    int rollNo;
    std::string name;
    StudentNode* next;
};

struct CourseNode {
    int rollNo;
    std::string courseName;
    CourseNode* next;
};

struct CgpaNode {
    int rollNo;
    float cgpa;
    CgpaNode* next;
};

void insertStudentNode(StudentNode** head, int rollNo, const std::string& name) {
    StudentNode* newNode = new StudentNode;
    newNode->rollNo = rollNo;
    newNode->name = name;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        StudentNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertCourseNode(CourseNode** head, int rollNo, const std::string& courseName) {
    CourseNode* newNode = new CourseNode;
    newNode->rollNo = rollNo;
    newNode->courseName = courseName;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        CourseNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertCgpaNode(CgpaNode** head, int rollNo, float cgpa) {
    CgpaNode* newNode = new CgpaNode;
    newNode->rollNo = rollNo;
    newNode->cgpa = cgpa;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        CgpaNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void findCommonRollNumbers(StudentNode* headStudents, CourseNode* headCourses, CgpaNode* headCgpa) {
    StudentNode* studentNode = headStudents;
    CourseNode* courseNode = headCourses;
    CgpaNode* cgpaNode = headCgpa;

    while (studentNode != NULL && courseNode != NULL && cgpaNode != NULL) {
        if (studentNode->rollNo == courseNode->rollNo && courseNode->rollNo == cgpaNode->rollNo) {
            std::cout << "Common Roll No: " << studentNode->rollNo << std::endl;
            studentNode = studentNode->next;
            courseNode = courseNode->next;
            cgpaNode = cgpaNode->next;
        } else if (studentNode->rollNo < courseNode->rollNo) {
            studentNode = studentNode->next;
        } else if (courseNode->rollNo < cgpaNode->rollNo) {
            courseNode = courseNode->next;
        } else {
            cgpaNode = cgpaNode->next;
        }
    }
}

int main() {
    StudentNode* headStudents = NULL;
    CourseNode* headCourses = NULL;
    CgpaNode* headCgpa = NULL;

    // Insert data into the linked lists
    insertStudentNode(&headStudents, 1, "John");
    insertStudentNode(&headStudents, 2, "Alice");
    insertStudentNode(&headStudents, 3, "Bob");
    insertStudentNode(&headStudents, 4, "Emma");

    insertCourseNode(&headCourses, 1, "BE");
    insertCourseNode(&headCourses, 2, "BCA");
    insertCourseNode(&headCourses, 3, "BE");
    insertCourseNode(&headCourses, 4, "BBA");

    insertCgpaNode(&headCgpa, 1, 8.5f);
    insertCgpaNode(&headCgpa, 3, 7.2f);
    insertCgpaNode(&headCgpa, 8, 9.1f);

    // Find common roll numbers
    findCommonRollNumbers(headStudents, headCourses, headCgpa);

    // Clean up memory (deallocate nodes)
    StudentNode* currentStudent = headStudents;
    while (currentStudent != NULL) {
        StudentNode* temp = currentStudent;
        currentStudent = currentStudent->next;
        delete temp;
    }

    CourseNode* currentCourse = headCourses;
    while (currentCourse != NULL) {
        CourseNode* temp = currentCourse;
        currentCourse = currentCourse->next;
        delete temp;
    }

    CgpaNode* currentCgpa = headCgpa;
    while (currentCgpa != NULL) {
        CgpaNode* temp = currentCgpa;
        currentCgpa = currentCgpa->next;
        delete temp;
    }

    return 0;
}

