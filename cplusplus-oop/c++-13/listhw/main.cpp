#include <iostream>


class Node {
private:
    int data;
    Node* prev;
    Node* next;

public:

    Node() : prev(nullptr), next(nullptr) {}

    int getData() const { return data; }
    void setData(int value) { data = value; }

    Node* getPrev() const { return prev; }
    void setPrev(Node* prevNode) { prev = prevNode; }

    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
};


class List {
private:
    Node* head;
    Node* tail;
    int size;

public:

    List() : head(nullptr), tail(nullptr), size(0) {}
    ~List() {
        if (head != nullptr) {
            delete head;
        }
        if (tail != nullptr) {
            delete tail;
        }
    }
    void push_front(int value) {
        Node* newNode = new Node();
        newNode->setData(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        }
        size++;
    }

    void push_back(int value) {
        Node* newNode = new Node();
        newNode->setData(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->setPrev(tail);
            tail->setNext(newNode);
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->getNext();
            head->setPrev(nullptr);
        }
        delete temp;
        size--;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->getPrev();
            tail->setNext(nullptr);
        }
        delete temp;
        size--;
    }

    void remove(int value) {
        Node* current = head;
        while (current) {
            if (current->getData() == value) {
                if (current == head) {
                    pop_front();
                } else if (current == tail) {
                    pop_back();
                } else {
                    Node* prevNode = current->getPrev();
                    Node* nextNode = current->getNext();
                    prevNode->setNext(nextNode);
                    nextNode->setPrev(prevNode);
                    delete current;
                    size--;
                }
                return;
            }
            current = current->getNext();
        }
    }

    void unique() {
        if (!head) return;
        Node* current = head;
        while (current->getNext()) {
            if (current->getData() == current->getNext()->getData()) {
                Node* duplicate = current->getNext();
                current->setNext(duplicate->getNext());
                if (duplicate->getNext()) {
                    duplicate->getNext()->setPrev(current);
                } else {
                    tail = current;
                }
                delete duplicate;
                size--;
            } else {
                current = current->getNext();
            }
        }
    }

    Node* begin() const {
        return head;
    }

    Node* end() const {
        return tail;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }
        std::cout << std::endl;
    }


    bool empty() const {
        return size == 0;
    }
};


int main() {
    List list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    std::cout << "list: ";
    list.print();

    list.remove(20);
    std::cout << "remove(20): ";
    list.print();

    list.unique();
    std::cout << "unique(): ";
    list.print();

    Node* first = list.begin();
    Node* last = list.end();

    std::cout << "begin(): " << first->getData() << std::endl;
    std::cout << "end(): " << last->getData() << std::endl;

    return 0;
}