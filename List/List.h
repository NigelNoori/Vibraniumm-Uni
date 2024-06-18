#ifndef LIST_H
#define LIST_H

class List {
private:
    // Forward declaration of Element
    class Element;

public:
    // Nested Iterator class
    class Iterator;

    // Default constructor
    List();

    // Destructor
    ~List();

    // Iterator functions
    Iterator begin() const;
    Iterator end() const;

    // Modifying functions
    void insert(Iterator it, char c);
    void erase(Iterator it);

private:
    // Nested Element class
    class Element {
    public:
        char data;
        Element* next;
        Element* prev;
        Element(char c, Element* n = nullptr, Element* p = nullptr)
            : data(c), next(n), prev(p) {}
    };

    Element* dummy; // Dummy node
};

#endif

