#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;
public:
    Media(string t, string date, string id, string pub)
        : title(t), publicationDate(date), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    virtual void displayInfo() {
        cout << title << " " << publicationDate << " " << uniqueID << " " << publisher << endl;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << "Checked out successfully" << endl;
        } else {
            cout << "Already checked out" << endl;
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << "Returned successfully" << endl;
        } else {
            cout << "Item was not checked out" << endl;
        }
    }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, isbn;
    int pageCount;
public:
    Book(string t, string date, string id, string pub, string a, string code, int pages)
        : Media(t, date, id, pub), author(a), isbn(code), pageCount(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Book " << author << " " << isbn << " " << pageCount << " pages" << endl;
    }
};

class DVD : public Media {
private:
    string director, rating;
    int runtime;
public:
    DVD(string t, string date, string id, string pub, string dir, int time, string rate)
        : Media(t, date, id, pub), director(dir), runtime(time), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "DVD " << director << " " << runtime << " mins " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist, genre;
    int tracks;
public:
    CD(string t, string date, string id, string pub, string ar, int tCount, string g)
        : Media(t, date, id, pub), artist(ar), tracks(tCount), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "CD " << artist << " " << tracks << " tracks " << genre << endl;
    }
};

void search(string title) {
    cout << "Searching by title: " << title << endl;
}

void search(int year) {
    cout << "Searching by year: " << year << endl;
}

void searchByAuthor(string name) {
    cout << "Searching by author: " << name << endl;
}

int main() {
    Book b("C++ Primer", "2020", "B101", "Pearson", "Lippman", "978-0321714114", 970);
    DVD d("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD c("Thriller", "1982", "C303", "Epic", "Michael Jackson", 9, "Pop");

    b.displayInfo();
    d.displayInfo();
    c.displayInfo();

    b.checkOut();
    b.returnItem();

    search("Inception");
    search(2020);
    searchByAuthor("Lippman");

    return 0;
}
