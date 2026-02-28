#include <iostream>
#include <cstring>

class TeamMember {
private:
    char _name[50];
    char _role[50];
public:

    TeamMember(const char* name, const char* role) {
        strcpy(_name, name);
        strcpy(_role, role);
    }

    inline char* getName() {
        return _name;
    }

    inline void setName(const char* newName) {
        if (newName != nullptr) {
            strcpy(_name, newName);
        }
    }

    inline char* getRole() {
        return _role;
    }

    inline void setRole(const char* newRole) {
        if (newRole != nullptr) {
            strcpy(_role, newRole);
        }
    }

    void display() const {
        std::cout << "Name: " << _name << ", Role: " << _role << std::endl;
    }
};

class Task {
private:
    char _title[50];
    char _status[20];
    int _assignedMember;

public:
    Task() {
        strcpy(_title, "Untitled");
        strcpy(_status, "new");
        _assignedMember = -1;
    }

    Task(const char* title, const char* status, int assignedMember) {
        strcpy(_title, title);
        strcpy(_status, status);
        _assignedMember = assignedMember;
    }

    inline char* getTitle() {
        return _title;
    }

    inline void setTitle(const char* newTitle) {
        if (newTitle != nullptr) {
            strcpy(_title, newTitle);
        }
    }

    inline char* getStatus() {
        return _status;
    }

    inline void setStatus(const char* newStatus) {
        if (newStatus != nullptr) {
            strcpy(_status, newStatus);
        }
    }

    inline int getAssignedMember() const {
        return _assignedMember;
    }

    inline void setAssignedMember(int assignedMember) {
        _assignedMember = assignedMember;
    }

    void display() const {
        std::cout << "Title: " << _title << ", Status: " << _status<< ", Assigned to member index: " << _assignedMember << std::endl;
    }
};

class Project {
private:
    char _name[50];
    Task _tasks[10];
    int _taskCount;

public:

    Project(const char* name) {
        strcpy(_name, name);
        _taskCount = 0;
    }

    inline char* getName() {
        return _name;
    }

    inline void setName(const char* newName) {
        if (newName != nullptr) {
            strcpy(_name, newName);
        }
    }

    void addTask(const Task& task) {
        if (_taskCount < 10) {
            _tasks[_taskCount++] = task;
        } else {
            return;
        }
    }

    void displayTasks() const {
        std::cout << "Project: " << _name << " has " << _taskCount << " tasks:" << std::endl;
        for (int i = 0; i < _taskCount; i++) {
            _tasks[i].display();
        }
    }

    void displayTasksByMember(int memberIndex) const {
        std::cout << "Tasks assigned to member index " << memberIndex << ":" << std::endl;
        for (int i = 0; i < _taskCount; i++) {
            if (_tasks[i].getAssignedMember() == memberIndex) {
                _tasks[i].display();
            }
        }
    }
};

int main() {
    Project project("Game");
    TeamMember member1("Catherine", "Game Developer");
    TeamMember member2("William", "Designer");

    member1.display();
    member2.display();

    Task task1("Log in to Game", "new", 0);  // assigned to member1 (Alice)
    Task task2("Design Home Page", "in progress", 1);  // assigned to member2 (Bob)


    project.addTask(task1);
    project.addTask(task2);

    project.displayTasks();

    project.displayTasksByMember(0);

    return 0;
}
