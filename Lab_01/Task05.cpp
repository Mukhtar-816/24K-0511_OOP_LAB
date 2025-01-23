#include <iostream>
using namespace std;

int main(){
    string movie_name;
    int adult_tickets_price = 0, child_tickets_price = 0, adult_tickets_sold = 0, child_tickets_sold = 0;
    float gross_amount = 0, net_amount_for_charity = 0, net_sale = 0;

    cout << "Enter the name of the movie: ";
    cin >> movie_name;

    cout << "Enter the price of an adult ticket: ";
    cin >> adult_tickets_price;

    cout << "Enter the price of child ticket: ";
    cin >> child_tickets_price;

    cout << "Enter the numer of adult tickets sold: ";
    cin >> adult_tickets_sold;

    cout << "Enter the number of child tickets sold: ";
    cin >> child_tickets_sold;

    gross_amount =  (adult_tickets_price * adult_tickets_sold) + (child_tickets_price * child_tickets_sold);
    net_amount_for_charity = gross_amount * 0.10;
    net_sale = gross_amount - net_amount_for_charity;

    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl;
    cout << "Movie Name : .............................. " << movie_name << endl;
    cout << "Number of Tickets Sold : .................." << adult_tickets_sold + child_tickets_sold << endl;
    cout << "Gross Amount : ...........................$ " << gross_amount << endl;
    cout << "Percentage of Gross Amount Donated : ......10.00%"<<endl;
    cout << "Amount Donated : .........................." << net_amount_for_charity << endl;
    cout << "Net Sale : ...............................$" << net_sale << endl;



}