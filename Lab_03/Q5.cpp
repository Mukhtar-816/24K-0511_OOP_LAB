#include <iostream>
using namespace std;

class Book {
private:
    string bookName;
    string isbn;
    string author;
    string publisher;

public:
    Book(string bookName, string isbn, string author, string publisher) {
        this->bookName = bookName;
        this->isbn = isbn;
        this->author = author;
        this->publisher = publisher;
    }

    string getBookName() { return this->bookName; }
    string getISBN() { return this->isbn; }
    string getAuthor() { return this->author; }
    string getPublisher() { return this->publisher; }

    string getBookInfo() {
        return "Book Name: " + this->bookName + "\nISBN: " + this->isbn + "\nAuthor: " + this->author + "\nPublisher: " + this->publisher;
    }
};

int main() {
    Book books[5] = {
        Book("The Catcher in the Rye", "978-0-316-76948-0", "J.D. Salinger", "Little, Brown and Company"),
        Book("1984", "978-0-452-28423-4", "George Orwell", "Secker & Warburg"),
        Book("To Kill a Mockingbird", "978-0-06-112008-4", "Harper Lee", "J.B. Lippincott & Co."),
        Book("The Great Gatsby", "978-0-7432-7356-5", "F. Scott Fitzgerald", "Charles Scribner's Sons"),
        Book("Moby Dick", "978-0-14-243724-7", "Herman Melville", "Harper & Brothers")
    };

    for (int i = 0; i < 5; i++) {
        cout << "Book " << i + 1 << " Info:\n" << books[i].getBookInfo() << "\n\n";
    }

    return 0;
}






// using namespace std;
// #include <string.h>

// class Book {
//     public :
//     string bookName;
//     string ISBNNumber;
//     string authorName;
//     string publisherName;
//     int index = 0;


//     void AddBook(Book *book){
//         cout << "Enter BookName, ISBN number, AuthorName, and PublisherName respectively :" << endl;
//         cin >> book[index].bookName >> book[index].ISBNNumber >> book[index].authorName >> book[index].publisherName;
//         index++;
//         cout << "Book Added." << endl;
//     }

//     void RemoveBook(Book *book){
//         string tempID; int found = 0;
//         cout << "Enter Book ISBN Number to remove :" << endl;
//         cin >> tempID;

//         for (int i = 0; i < 5; ++i){
//             if (tempID == book[i].ISBNNumber){
//                 book[i].bookName = "";
//                 book[i].ISBNNumber = "";
//                 book[i].authorName = "";
//                 book[i].publisherName = "";
//                 found = 1;
//                 cout << "Book Removed." << endl;
//                 break;
//             }
//         }
//         if (!found){
//             cout << "Book not found." << endl;
//         }
//     };

//     void SearchBook(Book *book){
//         string tempID; int found = 0;
//         cout << "Enter Book ISBN Number :" << endl;
//         cin >> tempID;

//         for (int i = 0; i < 5; ++i){
//             if (tempID == book[i].ISBNNumber){
//                 cout << "BookName :" << book[i].bookName << endl;
//                 cout << "ISBN :" << book[i].ISBNNumber << endl;
//                 cout << "AuthorName :" << book[i].authorName << endl;
//                 cout << "PublisherName :" << book[i].publisherName << endl;
//                 found = 1;
//                 break;
//             }

//         }
//         if (!found){
//             cout << "Book not found." << endl;
//         }
//     };

// };

// int main(){
//     Book book[5];
//     string options[5] = {"Add Book.", "Remove Book.", "Search Book.", "See Book Info.", "Exit."};
//     int tempOption;

//     while (tempOption != 5){
//         for (int i = 0; i < 5; ++i){
//             cout << i + 1 << ". " << options[i] << endl;
//         }
    
//         cout << "Enter your choice..!" << endl;
//         cin >> tempOption;
    
//         if (tempOption == 5){
//             exit;
//         }
//         else if (tempOption == 1) {
//             book->AddBook(book) ;
//         }
//         else if (tempOption == 2) {
//             book->RemoveBook(book);
//         }
//         else if (tempOption == 3) {
//             book->SearchBook(book);
//         }
//         else if (tempOption == 4) {
//             book->AddBook(book);
//         }
//     }

// }