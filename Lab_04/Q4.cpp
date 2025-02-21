#include <iostream>
#include <vector>
using namespace std;

class Book {
public:
    string title, author, publisher;
    double price;
    int stock;

    Book(string t, string a, string p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}

    void displayDetails() {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPublisher: " << publisher
             << "\nPrice: $" << price << "\nStock: " << stock << " copies\n";
    }

    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    bool sellCopies(int quantity) {
        if (stock >= quantity) {
            stock -= quantity;
            cout << "Total cost: $" << price * quantity << endl;
            return true;
        }
        cout << "Required copies not in stock.\n";
        return false;
    }
};

class Bookshop {
public:
    vector<Book> inventory;

    void addBook(Book book) {
        inventory.push_back(book);
    }

    void searchBook(string title, string author) {
        for (auto &book : inventory) {
            if (book.isAvailable(title, author)) {
                cout << "\nBook Found!\n";
                book.displayDetails();
                int quantity;
                cout << "Enter number of copies required: ";
                cin >> quantity;
                book.sellCopies(quantity);
                return;
            }
        }
        cout << "\nBook not available.\n";
    }
};

int main() {
    Bookshop shop;
    shop.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", 10.99, 5));
    shop.addBook(Book("1984", "George Orwell", "Penguin", 8.99, 3));
    shop.addBook(Book("To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", 12.50, 4));

    string title, author;
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);

    shop.searchBook(title, author);

    return 0;
}
