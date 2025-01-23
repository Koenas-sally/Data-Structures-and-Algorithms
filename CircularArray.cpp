#include <iostream>
#include <stdexcept>

class Thing {
public:
    int value;
    Thing() : value(-1) {}      
    Thing(int v) : value(v) {}   
};

class CircularArray {
public:
    Thing* data;
    int n_items, n_allocated, idx_front;

    CircularArray() : data(nullptr), n_items(0), n_allocated(0), idx_front(0) {}

    ~CircularArray() {
        delete[] data;
    }

    int size() const {
        return n_items;
    }
    
    int allocated() const {
        return n_allocated;
    }

    void reallocate(int new_size) {
        Thing* new_data = new Thing[new_size];
        for (int i = 0; i < n_items; i++) {
            new_data[i] = data[(idx_front + i) % n_allocated];
        }
        delete[] data;
        data = new_data;
        idx_front = 0;
        n_allocated = new_size;
    }

    void push_back(const Thing &t) {
        if (n_items == n_allocated) {
            int new_size = (n_allocated == 0) ? 1 : n_allocated * 2;
            reallocate(new_size);
        }
        int idx_back = (idx_front + n_items) % n_allocated;
        data[idx_back] = t;
        n_items++;
    }

    void push_front(const Thing &t) {
        if (n_items == n_allocated) {
            int new_size = (n_allocated == 0) ? 1 : n_allocated * 2;
            reallocate(new_size);
        }
        idx_front = (idx_front - 1 + n_allocated) % n_allocated;
        data[idx_front] = t;
        n_items++;
    }

    void pop_back() {
        if (n_items == 0) return;
        int idx_back = (idx_front + n_items - 1) % n_allocated;
        data[idx_back] = Thing(); 
        n_items--;

        if (n_items <= n_allocated / 4 && n_allocated > 1) {
            reallocate(n_allocated / 2);
        }
    }

    void pop_front() {
        if (n_items == 0) return;
        data[idx_front] = Thing(); 
        idx_front = (idx_front + 1) % n_allocated;
        n_items--;
        if (n_items <= n_allocated / 4 && n_allocated > 1) {
            reallocate(n_allocated / 2);
        }
    }

    Thing &operator[](int index) {
        if (index < 0 || index >= n_items) throw std::out_of_range("Index out of range");
        int actual_index = (idx_front + index) % n_allocated;
        return data[actual_index];
    }

    void print(std::ostream &cout = std::cout) const {
        for (int i = 0; i < n_items; i++) {
            cout << data[(idx_front + i) % n_allocated].value << " ";
        }
        cout << "\n";
    }
};
