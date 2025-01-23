#include <iostream>
#include <stdexcept>

// Base Vector class template
template <typename Thing>
class BaseVector {
protected:
    Thing* data;        
    int n_items;       
    int n_allocated;    

    void reallocate(size_t new_size) {
        Thing* new_data = new Thing[new_size];
        for (size_t i = 0; i < n_items; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        n_allocated = new_size;
    }

public:
    BaseVector() : data(nullptr), n_items(0), n_allocated(0) {}

    virtual ~BaseVector() {
        delete[] data;
    }

    size_t size() const {
        return n_items;
    }

    size_t allocated_length() const {
        return n_allocated;
    }

    Thing& operator[](size_t index) {
        if (index < 0 || index >= n_items) throw std::out_of_range("Index out of range");
        return data[index];
    }

    const Thing& at(size_t index) const {
        if (index < 0 || index >= n_items) throw std::out_of_range("Index out of range");
        return data[index];
    }

    Thing& front() {
        if (n_items == 0) throw std::out_of_range("Vector is empty");
        return data[0];
    }

    Thing& back() {
        if (n_items == 0) throw std::out_of_range("Vector is empty");
        return data[n_items - 1];
    }

    Thing* begin() {
        return data;
    }

    Thing* end() {
        return data + n_items;
    }

    virtual void push(const Thing& item) = 0;
    virtual void pop() = 0;
};

// Derived class for push_back and pop_back
template <typename Thing>
class MyVectorBack : public BaseVector<Thing> {
public:
    void push(const Thing& item) override {
        if (this->n_allocated == 0) {
            this->reallocate(1);
        } else if (this->n_items >= this->n_allocated) {
            this->reallocate(2 * this->n_allocated);
        }
        this->data[this->n_items] = item;
        ++this->n_items;
    }

    void pop() override {
        if (this->n_items > 0) {
            --this->n_items;
            if (this->n_items < this->n_allocated / 4 && this->n_allocated > 1) {
                size_t new_allocated = this->n_allocated / 2;
                this->reallocate(new_allocated);
                this->n_allocated = new_allocated;
            }
        } else {
            throw std::out_of_range("Vector is empty");
        }
    }
};

// Derived class for push_front and pop_front
template <typename Thing>
class MyVectorFront : public BaseVector<Thing> {
public:
    void push(const Thing& item) override {
        if (this->n_items >= this->n_allocated) {
            this->reallocate(this->n_allocated == 0 ? 1 : 2 * this->n_allocated);
        }
        for (size_t i = this->n_items; i > 0; --i) {
            this->data[i] = this->data[i - 1];
        }
        this->data[0] = item;
        ++this->n_items;
    }

    void pop() override {
        if (this->n_items == 0) {
            throw std::out_of_range("Vector is empty");
        }
        for (size_t i = 0; i < this->n_items - 1; ++i) {
            this->data[i] = this->data[i + 1];
        }
        --this->n_items;
    }
};