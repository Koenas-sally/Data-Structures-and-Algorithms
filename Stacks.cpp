#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class BaseStack {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void peek() const = 0;
    virtual int size() const = 0;
    virtual void print() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~BaseStack() {}
};

class StackLinkedList : public BaseStack {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;
    int count;

public:
    StackLinkedList() : top(nullptr), count(0) {}

    void push(int value) override {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        count++;
    }

    void pop() override {
        if (top == nullptr) {
            std::cerr << "Stack is empty!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    void peek() const override {
        if (top == nullptr) {
            std::cerr << "Stack is empty!" << std::endl;
            return;
        }
        cout << "Peeked: " << top->data << endl;
    }

    int size() const override {
        return count;
    }

    void print() const override {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack elements: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    bool isEmpty() const override {
        return top == nullptr;
    }

    ~StackLinkedList() override {
        while (!isEmpty()) {
            pop();
        }
    }
};

class StackVector : public BaseStack {
private:
    vector<int> elements;

public:
    void push(int value) override {
        elements.push_back(value);
    }

    void pop() override {
        if (!elements.empty()) {
            cout << "Popped: " << elements.back() << endl;
            elements.pop_back();
        } else {
            cerr << "Stack is empty. Cannot pop.\n";
        }
    }

    void peek() const override {
        if (!elements.empty()) {
            cout << "Peeked: " << elements.back() << endl;
        } else {
            cerr << "Stack is empty. Cannot peek.\n";
        }
    }

    int size() const override {
        return elements.size();
    }

    void print() const override {
        cout << "Print: ";
        for (const int& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

    bool isEmpty() const override {
        return elements.empty();
    }
};

class StackList : public BaseStack {
private:
    list<int> elements;

public:
    void push(int value) override {
        elements.push_front(value);
    }

    void pop() override {
        if (!elements.empty()) {
            cout << "Popped: " << elements.front() << endl;
            elements.pop_front();
        } else {
            cerr << "Stack is empty. Cannot pop.\n";
        }
    }

    void peek() const override {
        if (!elements.empty()) {
            cout << "Peeked: " << elements.front() << endl;
        } else {
            cerr << "Stack is empty. Cannot peek.\n";
        }
    }

    int size() const override {
        return elements.size();
    }

    void print() const override {
        cout << "Print: ";
        for (const int& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

    bool isEmpty() const override {
        return elements.empty();
    }
};