#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
};

Book linearSearch(const vector<Book>& books, int id) {
    for (const auto& book : books) {
        if (book.id == id) {
            return book;
        }
    }
    return {-1, ""};
}

void testNormalCase() {
    vector<Book> books = {
        {1, "C++ Basics"},
        {2, "Data Structures"},
        {3, "Algorithms"}
    };

    Book result = linearSearch(books, 2);
    assert(result.id == 2);
    assert(result.title == "Data Structures");
}

void testBoundaryCase() {
    vector<Book> books = {
        {1, "C++ Basics"}
    };

    Book result = linearSearch(books, 1);
    assert(result.id == 1);
}

void testInvalidCase() {
    vector<Book> books = {
        {1, "C++ Basics"},
        {2, "Algorithms"}
    };

    Book result = linearSearch(books, 99);
    assert(result.id == -1);
}

int main() {
    testNormalCase();
    testBoundaryCase();
    testInvalidCase();

    cout << "All tests passed successfully!" << endl;

    return 0;
}
