#include <iostream>
using namespace std;

// Node structure (shared by both singly and doubly linked lists)
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// BaseLinkedList class that can work with both singly and doubly linked lists
class BaseLinkedList {
protected:
    Node* head;
    Node* tail;

public:
    BaseLinkedList() : head(nullptr), tail(nullptr) {}
    virtual ~BaseLinkedList() {
        while (head != nullptr) {
            pop_front();
        }
    }

    virtual void push_front(int value) = 0;  // Abstract method
    virtual void pop_front() = 0;            // Abstract method
    virtual void push_back(int value) = 0;   // Abstract method
    virtual void pop_back() = 0;             // Abstract method

    virtual int size() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    Node* getLink(int index) const {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (count == index) return current;
            current = current->next;
            count++;
        }
        return nullptr;
    }

    virtual void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// SinglyLinkedList: Derived from BaseLinkedList with specific singly linked list behavior
class SinglyLinkedList : public BaseLinkedList {
public:
    void push_front(int value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front() override {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void push_back(int value) override {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() override {
        if (tail == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    }
};

// DoublyLinkedList: Derived from BaseLinkedList with specific doubly linked list behavior
class DoublyLinkedList : public BaseLinkedList {
public:
    void push_front(int value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_front() override {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void push_back(int value) override {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_back() override {
        if (tail == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
    }

    void print() const override {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Singly Linked List with Tail : Derived from BaseLinkedList with specific singly linked list with tail behavior
class SinglyLinkedListWithTail : public BaseLinkedList {
public:
    SinglyLinkedListWithTail() : BaseLinkedList() {}

    void push_back(int value) override {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() override {
        if (tail == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    }
};

// Circular Singly Linked List : Derived from BaseLinkedList with specific circular singly linked list behavior
class CircularSinglyLinkedList : public BaseLinkedList {
public:
    CircularSinglyLinkedList() : BaseLinkedList() {}

    void push_front(int value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void pop_front() override {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
    }

    void push_back(int value) override {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            head->next = head;
        } else {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    void pop_back() override {
        if (tail == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = head;
        }
    }

    void print() const override {
        if (head == nullptr) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

// Circular Doubly Linked List : Derived from BaseLinkedList with specific circular doubly linked list behavior
class CircularDoublyLinkedList : public BaseLinkedList {
public:
    CircularDoublyLinkedList() : BaseLinkedList() {}

    void push_front(int value) override {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void pop_front() override {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
    }

    void push_back(int value) override {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void pop_back() override {
        if (tail == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
    }

    void print() const override {
        if (head == nullptr) return;
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};