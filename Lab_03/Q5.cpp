#include <iostream>
using namespace std;


class Book {
    public :
    string _BookName;
    int _ISBNNumber;
    string _AuthorName;
    string _PublisherName;

    void AddBook(){
        cout << "Enter the BookName, ISBNNumber AuthorName, and PublisherName :" << endl;
        cin >> _BookName >> _ISBNNumber >> _AuthorName >> _PublisherName;
    };
    void RemoveBook(Book *book_arr){
        int ID = 0;
        for (int i = 0; i < 5; ++i){
            cout << i + 1 << ". " << book_arr[i]._BookName << " " << book_arr[i]._ISBNNumber << " " << book_arr[i]._AuthorName << " " << book_arr[i]._PublisherName << endl;
    }
    cout << endl << "Enter ID : ";
    cin >> ID;
};};



int main(){
    Book book_arr[5];
    string options_arr[5] = {"Add Book.", "Remove Book", "Search Book by ISBN Number.", "See Book Info.", "Upadte Book."};
    int current_option;

    cout << "Choose from the optioms below : \n";
    for (int i = 0; i < 5; i++){
        cout << i + 1 << "." << options_arr[i] << endl;
    }
    cout << "Enter your option : ...." << endl;
    cin >> current_option;

    if (current_option - 1 == 0){
        book_arr[0].AddBook();
    }
    else if (current_option - 1 == 1){
        book_arr[1].RemoveBook(book_arr);
    }
}