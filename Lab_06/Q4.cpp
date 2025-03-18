#include <iostream>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}
    virtual void display() {
        cout << "Genre: " << genre << endl;
    }
};

class Novel : public Books {
private:
    string title;
    string author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "-------------------------" << endl;
    }
};

class Mystery : public Books {
private:
    string title;
    string author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}
    void display() override {
        cout << "Genre: " << genre << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    Novel book1("To Kill a Mockingbird", "Harper Lee");
    Mystery book2("Sherlock Holmes", "Arthur Conan Doyle");
    
    book1.display();
    book2.display();
    
    return 0;
}