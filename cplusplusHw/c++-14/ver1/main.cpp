#include <iostream>
#include <string.h>

struct Student {

    struct Grades {
        float maths=0;
        float english=0;
        float physics=0;
        float chemistry=0;
        float cs=0;
    };

    char name[25];
    unsigned short age;
    float gpa;
    char email[50];
    char phone[20];
    Grades grades;
};

void display_student(Student* students, int size);
void add_student(Student*& students, int& size, Student new_student);
void delete_student(Student*& students, int& size, int index);
void update_grades(Student* students, int index);
void remove_student_by_attributes(Student*& students, int& size, char* name, unsigned short age, float gpa, char* email, char* phone );
void find_student_by_attributes(Student* students, int size, char* name, unsigned short age, float gpa, char* email, char* phone );


int main() {
    int size=0;
    Student new_student;
    auto* students = new Student[size];
    while (true) {
        int choice;
        std::cout << "\n";
        std::cout<<"1. Display students\n"
        "2. Add student\n"
        "3. Remove student(only by index)\n"
        "4. Update grades\n"
        "5. Remove student(by all attributes)\n"
        "6. Find student\n"
        "7. Exit\n"
        <<std::endl;
        std::cout<<"Enter your choice: ";
        std::cin >> choice;
        switch(choice) {
            case 1:
                if (size == 0) {
                    std::cout << "No students to display!\n";
                } else {
                    display_student(students, size);
                }
            break;
            case 2:
                char name[25];
                unsigned short age;
                float gpa;
                char email[50];
                char phone[20];
                std::cout<<"Enter name: ";
                std::cin >> name;
                std::cout<<"Enter age: ";
                std::cin >> age;
                std::cout<<"Enter gpa: ";
                std::cin >> gpa;
                std::cout<<"Enter email: ";
                std::cin >> email;
                std::cout<<"Enter phone: ";
                std::cin >> phone;

                strcpy(new_student.name,name);
                new_student.age = age;
                new_student.gpa = gpa;
                strcpy(new_student.email,email);
                strcpy(new_student.phone,phone);

                add_student(students, size, new_student);
                break;
            case 3:
                if (size == 0) {
                    std::cout << "No students to delete!\n";
                } else {
                    int index;
                    std::cout << "Enter index to delete (1-" << size << "): ";
                    std::cin >> index;
                    delete_student(students, size, index);
                }
                break;
            case 4:
                if (size == 0) {
                    std::cout << "No students to update!\n";
                }else {
                    int index;
                    std::cout << "Enter index of the student to update grades (1-" << size << "): ";
                    std::cin >> index;
                    if (index >= 1 && index <= size) {
                        update_grades(students, index);
                    }
                    else {
                        std::cout << "Invalid index!\n";
                    }
                }
            break;
            case 5:
                if (size == 0) {
                    std::cout << "No students to delete!\n";
                }else {
                    while (true) {
                        int choice;
                        std::cout << "1. By name\n"
                        "2. By age\n"
                        "3. By gpa\n"
                        "4. By email\n"
                        "5. By phone\n"
                        "6. Exit\n"
                        <<std::endl;
                        std::cout<<"your choice: ";
                        std::cin >> choice;
                        char name[25];
                        unsigned short age;
                        float gpa;
                        char email[50];
                        char phone[20];

                        if (choice == 6) break;

                        switch (choice) {
                            case 1:
                                std::cout << "Enter name: ";
                            std::cin >> name;
                            remove_student_by_attributes(students, size, name, 0, 0.0, nullptr, nullptr);
                            break;
                            case 2:
                                std::cout << "Enter age: ";
                            std::cin >> age;
                            remove_student_by_attributes(students, size, nullptr, age, 0.0, nullptr, nullptr);
                            break;
                            case 3:
                                std::cout << "Enter gpa: ";
                            std::cin >> gpa;
                            remove_student_by_attributes(students, size, nullptr, 0, gpa, nullptr, nullptr);
                            break;
                            case 4:
                                std::cout << "Enter email: ";
                            std::cin >> email;
                            remove_student_by_attributes(students, size, nullptr, 0, 0.0, email, nullptr);
                            break;
                            case 5:
                                std::cout << "Enter phone: ";
                            std::cin >> phone;
                            remove_student_by_attributes(students, size, nullptr, 0, 0.0, phone, nullptr);
                            break;
                            default:
                                std::cout << "Invalid choice!\n";
                            break;
                        }
                    }
                }
            break;
            case 6:
                if (size == 0) {
                    std::cout << "No students to find!\n";
                }else {
                     while (true) {
                        int choice;
                        std::cout << "1. By name\n"
                        "2. By age\n"
                        "3. By gpa\n"
                        "4. By email\n"
                        "5. By phone\n"
                        "6. Exit\n"
                        <<std::endl;
                        std::cout<<"your choice: ";
                        std::cin >> choice;
                        char name[25];
                        unsigned short age;
                        float gpa;
                        char email[50];
                        char phone[20];

                        if (choice == 6) break;

                        switch (choice) {
                            case 1:
                                std::cout << "Enter name: ";
                            std::cin >> name;
                            find_student_by_attributes(students, size, name, 0, 0.0, nullptr, nullptr);
                            break;
                            case 2:
                                std::cout << "Enter age: ";
                            std::cin >> age;
                            find_student_by_attributes(students, size, nullptr, age, 0.0, nullptr, nullptr);
                            break;
                            case 3:
                                std::cout << "Enter gpa: ";
                            std::cin >> gpa;
                            find_student_by_attributes(students, size, nullptr, 0, gpa, nullptr, nullptr);
                            break;
                            case 4:
                                std::cout << "Enter email: ";
                            std::cin >> email;
                            find_student_by_attributes(students, size, nullptr, 0, 0.0, email, nullptr);
                            break;
                            case 5:
                                std::cout << "Enter phone: ";
                            std::cin >> phone;
                            find_student_by_attributes(students, size, nullptr, 0, 0.0, phone, nullptr);
                            break;
                            default:
                                std::cout << "Invalid choice!\n";
                            break;
                        }
                    }
                }
        }
    }

    return 0;
}


void display_student(Student* students, int size) {
    for (int i = 0; i < size; i++) {
        std::cout<<"\n";
        std::cout <<"student number: "<<i+1<<std::endl;
        std::cout<<"\n";
        std::cout <<"Name: "<< students[i].name << std::endl;
        std::cout <<"Age: "<< students[i].age << std::endl;
        std::cout <<"GPA: "<<students[i].gpa << std::endl;
        std::cout <<"E-mail: "<< students[i].email << std::endl;
        std::cout <<"Phone number: "<< students[i].phone << std::endl;

        std::cout<<"\n";
        std::cout << "Grades:\n";
        std::cout<<"\n";
        std::cout << "Maths: " << students[i].grades.maths << "\n";
        std::cout << "English: " << students[i].grades.english << "\n";
        std::cout << "Physics: " << students[i].grades.physics << "\n";
        std::cout << "Chemistry: " << students[i].grades.chemistry << "\n";
        std::cout << "Computer Science (CS): " << students[i].grades.cs << "\n";

    }
}
void add_student(Student*& students, int& size, Student new_student) {
    auto* temp_student = new Student[size+1];

    for(int i=0; i < size; i++) {
        temp_student[i] = students[i];
    }

    temp_student [size] = new_student;

    delete[] students;
    students = temp_student;
    size++;
}

void delete_student(Student*& students, int& size, int index) {
    auto* temp_student = new Student[size-1];

    for(int i=0; i < index-1; i++) {
        temp_student[i] = students[i];
    }

    for(int i = index-1; i < size-1; i++) {
        temp_student[i] = students[i+1];
    }

    delete[] students;
    students = temp_student;
    size--;
}
void update_grades(Student* students, int index) {
    Student& student =students[index - 1];
    std::cout << "Updating grades for: " << student.name << "\n";

    std::cout << "Enter new maths grade: ";
    std::cin >> student.grades.maths;
    std::cout << "Enter new english grade: ";
    std::cin >> student.grades.english;
    std::cout << "Enter new physics grade: ";
    std::cin >> student.grades.physics;
    std::cout << "Enter new chemistry grade: ";
    std::cin >> student.grades.chemistry;
    std::cout << "Enter new computer science (CS) grade: ";
    std::cin >> student.grades.cs;
}

void remove_student_by_attributes(Student*& students, int& size, char* name, unsigned short age, float gpa, char* email, char* phone) {
    Student* temp_students = new Student[size];
    int new_size = 0;

    for (int i = 0; i < size; i++) {
        bool match = false;
        if (name != nullptr && strcmp(students[i].name, name) == 0) match = true;
        if (age != 0 && students[i].age == age) match = true;
        if (gpa != 0.0f && students[i].gpa == gpa) match = true;
        if (email != nullptr && strcmp(students[i].email, email) == 0) match = true;
        if (phone != nullptr && strcmp(students[i].phone, phone) == 0) match = true;

        if (!match) {
            temp_students[new_size++] = students[i];
        } else {
            std::cout << "Student removed"<< std::endl;
        }
    }

    delete[] students;
    students = temp_students;
    size = new_size;
}

void find_student_by_attributes(Student* students, int size, char* name, unsigned short age, float gpa, char* email, char* phone ) {
        for (int i = 0; i < size; i++) {
            bool match = false;
            if (strcmp(students[i].name, name) == 0 && name!=nullptr) match = true;
            if (students[i].age == age && age!=0) match = true;
            if (students[i].gpa == gpa && gpa!=0) match = true;
            if (strcmp(students[i].email, email) == 0 && email!=nullptr) match = true;
            if (strcmp(students[i].phone, phone)==0 && phone!=nullptr) match = true;
            if(match == true) {
                std::cout<<"\n";
                std::cout<<"Student found:\n";
                std::cout<<"Name: "<<students[i].name<<std::endl;
                std::cout<<"Age: "<<students[i].age<<std::endl;
                std::cout<<"GPA: "<<students[i].gpa<<std::endl;
                std::cout<<"Email: "<<students[i].email<<std::endl;
                std::cout<<"Phone number: "<<students[i].phone<<std::endl;
                std::cout<<"\n";
            }
        }
    }
