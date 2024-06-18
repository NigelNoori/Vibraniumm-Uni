#include "List.h"

// Iterator class definition
class List::Iterator {
private:
    Element* ptr;

public:
    // Default constructor
    Iterator() : ptr(nullptr) {}

    // Private constructor
    Iterator(Element* p) : ptr(p) {}

    // Pre-increment operator
    Iterator& operator++() {
        ptr = ptr->next;
        return *this;
    }

    // Pre-decrement operator
    Iterator& operator--() {
        ptr = ptr->prev;
        return *this;
    }

    // Dereference operator
    char& operator*() {
        return ptr->data;
    }

    // Const dereference operator
    const char& operator*() const {
        return ptr->data;
    }

    // Comparison operators
    bool operator==(const Iterator& other) const {
        return ptr == other.ptr;
    }

    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }

    // Friend declaration
    friend class List;
};

// List constructor
List::List() {
    dummy = new Element('\0'); // Dummy node with null character data
    dummy->next = dummy;
    dummy->prev = dummy;
}

// List destructor
List::~List() {
    while (dummy->next != dummy) {
        erase(begin());
    }
    delete dummy;
}

// Iterator functions
List::Iterator List::begin() const {
    return Iterator(dummy->next);
}

List::Iterator List::end() const {
    return Iterator(dummy);
}

// Insert function
void List::insert(Iterator it, char c) {
    Element* newElement = new Element(c, it.ptr, it.ptr->prev);
    it.ptr->prev->next = newElement;
    it.ptr->prev = newElement;
}

// Erase function
void List::erase(Iterator it) {
    if (it.ptr != dummy) {
        it.ptr->prev->next = it.ptr->next;
        it.ptr->next->prev = it.ptr->prev;
        delete it.ptr;
    }
}
