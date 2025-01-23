#include <iostream>
#include <list>
#include <deque>

// Base Queue Interface
class BaseQueue {
public:
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int peek() const = 0;
    virtual int size() const = 0;
    virtual void print() const = 0;
    virtual ~BaseQueue() {}
};

// Queue using Circular Array
class CircularQueue : public BaseQueue {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) override {
        Node* newNode = new Node(value);
        if (!front) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
    }

    int dequeue() override {
        if (!front) {
            std::cerr << "Queue is empty\n";
            return -1;
        }
        int data = front->data;
        if (front == rear) {
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        return data;
    }

    int peek() const override {
        if (!front) {
            std::cerr << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    int size() const override {
        if (!front) return 0;
        int count = 0;
        Node* temp = front;
        do {
            ++count;
            temp = temp->next;
        } while (temp != front);
        return count;
    }

    void print() const override {
        if (!front) {
            std::cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        std::cout << "\n";
    }

    ~CircularQueue() {
        while (front != rear) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        delete front;
    }
};

// Queue using std::deque
class DequeQueue : public BaseQueue {
private:
    std::deque<int> data;

public:
    void enqueue(int value) override {
        data.push_back(value);
    }

    int dequeue() override {
        if (data.empty()) {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
        int front = data.front();
        data.pop_front();
        return front;
    }

    int peek() const override {
        if (data.empty()) {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
        return data.front();
    }

    int size() const override {
        return data.size();
    }

    void print() const override {
        std::cout << "Print: ";
        for (const int& val : data) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

// Queue using std::list
class ListQueue : public BaseQueue {
private:
    std::list<int> data;

public:
    void enqueue(int value) override {
        data.push_back(value);
    }

    int dequeue() override {
        if (data.empty()) {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
        int front = data.front();
        data.pop_front();
        return front;
    }

    int peek() const override {
        if (data.empty()) {
            std::cerr << "Queue is empty!\n";
            return -1;
        }
        return data.front();
    }

    int size() const override {
        return data.size();
    }

    void print() const override {
        std::cout << "Print: ";
        for (const int& val : data) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};
