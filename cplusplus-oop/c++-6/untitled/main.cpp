#include <iostream>
#include <cstring>

class Course {
protected:
    char* _title;
    int _credits;

public:
    Course(const char* title, int credits) {
        _title = new char[strlen(title) + 1];
        strcpy(_title, title);
        _credits = credits;
    }

    virtual ~Course() {
        delete[] _title;
    }

    const char* getTitle() const { return _title; }
    int getCredits() const { return _credits; }

    void setTitle(const char* newTitle) {
        delete[] _title;
        _title = new char[strlen( newTitle) + 1];
        strcpy(_title,  newTitle);
    }

    void setCredits(int credits) { _credits = credits; }

    friend void display(const Course& course) {
        std::cout << "Course Title: " << course._title << ", Credits: " << course._credits << std::endl;
    }

    virtual void display() const {
        std::cout << "Course Title: " << _title << ", Credits: " << _credits << std::endl;
    }
};

class OnlineCourse : public Course {
    char* _platform;

public:
    OnlineCourse(const char* title, int credits, const char* platform) : Course(title, credits) {
        _platform = new char[strlen(platform) + 1];
        strcpy(_platform, platform);
    }

    ~OnlineCourse() override {
        delete[] _platform;
    }

    friend void display(const OnlineCourse& course) {
        std::cout << "Online Course Title: " << course._title << ", Credits: " << course._credits
                  << ", Platform: " << course._platform << std::endl;
    }

    void display() const override {
        std::cout << "Online Course Title: " << _title << ", Credits: " << _credits
                  << ", Platform: " << _platform << std::endl;
    }
};

class OfflineCourse : public Course {
    char* _location;

public:
    OfflineCourse(const char* title, int credits, const char* location) : Course(title, credits) {
        _location = new char[strlen(location) + 1];
        strcpy(_location, location);
    }

    ~OfflineCourse() override {
        delete[] _location;
    }

    friend void display(const OfflineCourse& course) {
        std::cout << "Offline Course Title: " << course._title << ", Credits: " << course._credits
                  << ", Location: " << course._location << std::endl;
    }

    void display() const override {
        std::cout << "Offline Course Title: " << _title << ", Credits: " << _credits
                  << ", Location: " << _location << std::endl;
    }
};

class Student {
    char* _name;
    int _age;
    Course** enrolledCourses;
    int _courseCount;

public:
    Student(const char* name, int age) : _age(age), _courseCount(0) {
        _name = new char[strlen(name) + 1];
        strcpy(_name, name);
        enrolledCourses = nullptr;
    }

    ~Student() {
        delete[] _name;
        delete[] enrolledCourses;
    }

    void enrollCourse(Course* course) {
        Course** temp = new Course*[_courseCount + 1];
        for (int i = 0; i < _courseCount; ++i) {
            temp[i] = enrolledCourses[i];
        }
        temp[_courseCount] = course;
        delete[] enrolledCourses;
        enrolledCourses = temp;
        ++_courseCount;
    }

    friend void display(const Student& student) {
        std::cout << "Student Name: " << student._name << ", Age: " << student._age
                  << ", Enrolled Courses: " << student._courseCount << std::endl;
        for (int i = 0; i < student._courseCount; ++i) {
            student.enrolledCourses[i]->display();
        }
    }

    void display() const {
        std::cout << "Student Name: " << _name << ", Age: " << _age << ", Enrolled Courses: " << _courseCount << std::endl;
        for (int i = 0; i < _courseCount; ++i) {
            enrolledCourses[i]->display();
        }
    }
};

class University {
    Course** courses;
    Student** students;
    int _courseCount;
    int _studentCount;

public:
    University() : courses(nullptr), students(nullptr), _courseCount(0), _studentCount(0) {}

    ~University() {
        for (int i = 0; i < _courseCount; ++i) {
            delete courses[i];
        }
        delete[] courses;

        for (int i = 0; i < _studentCount; ++i) {
            delete students[i];
        }
        delete[] students;
    }

    void addCourse(Course* course) {
        Course** temp = new Course*[_courseCount + 1];
        for (int i = 0; i < _courseCount; ++i) {
            temp[i] = courses[i];
        }
        temp[_courseCount] = course;
        delete[] courses;
        courses = temp;
        ++_courseCount;
    }

    void addStudent(Student* student) {
        Student** temp = new Student*[_studentCount + 1];
        for (int i = 0; i < _studentCount; ++i) {
            temp[i] = students[i];
        }
        temp[_studentCount] = student;
        delete[] students;
        students = temp;
        ++_studentCount;
    }

    void enrollStudentInCourse(Student* student, Course* course) {
        student->enrollCourse(course);
    }

    friend void display(const University& uni) {
        std::cout << "University Courses:" << std::endl;
        for (int i = 0; i < uni._courseCount; ++i) {
            uni.courses[i]->display();
        }

        std::cout << "University Students:" << std::endl;
        for (int i = 0; i < uni._studentCount; ++i) {
            uni.students[i]->display();
        }
    }

    void display() const {
        std::cout << "University Courses:" << std::endl;
        for (int i = 0; i < _courseCount; ++i) {
            courses[i]->display();
        }

        std::cout << "University Students:" << std::endl;
        for (int i = 0; i <_studentCount; ++i) {
            students[i]->display();
        }
    }
};
int main() {
    University university;

    Course* online = new OnlineCourse("programming", 7, "teams");
    Course* offline = new OfflineCourse("cybersecurity", 8, "x building");

    university.addCourse(online);
    university.addCourse(offline);

    Student* student = new Student("mortis", 23);
    Student* student1 = new Student("emz", 25);
    university.addStudent(student);
    university.addStudent(student1);

    university.enrollStudentInCourse(student, online);
    university.enrollStudentInCourse(student1, offline);

    university.display();

    return 0;
}

