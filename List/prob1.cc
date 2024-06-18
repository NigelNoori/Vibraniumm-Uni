#include "List.h"
#include <iostream>
#include <algorithm>

using namespace std;

class LineEditor {
public:
    // Constructor
    LineEditor();

    // Member functions
    void left();
    void right();
    void insert(const string& s);
    void erase();
    void change(char c);
    void apply(char (*f)(char c));
    friend ostream &operator<<(ostream& os, const LineEditor& le);

private:
    List line;
    List::Iterator cursor;
};

// Constructor
LineEditor::LineEditor() {
    cursor = line.end();
}

// Member function definitions...
// (same as provided in the original solution)

int main() {
    // Example usage
    LineEditor editor;
    editor.insert("Hello, ");
    editor.insert("world!");
    cout << editor;
    return 0;
}
