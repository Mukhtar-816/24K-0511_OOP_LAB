#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class User {
public:
    string user_id, first_name, last_name, address, email;
    User(string id, string f, string l, string a, string e)
        : user_id(id), first_name(f), last_name(l), address(a), email(e) {}

    static void addDummyUsers() {
        ofstream file("users.txt");
        file << "u1,Linus,Torvalds,Finland,linus@example.com\n";
        file << "u2,Bill,Gates,USA,bill@example.com\n";
        file.close();
    }
};

class Product {
public:
    string product_id, product_name, description;
    int price;

    Product(string id, string name, string desc, int p)
        : product_id(id), product_name(name), description(desc), price(p) {}

    static void addDummyProducts() {
        ofstream file("products.txt");
        file << "p1,Laptop,High-end laptop,1200\n";
        file << "p2,Mouse,Wireless Mouse,20\n";
        file << "p3,Keyboard,Mechanical Keyboard,50\n";
        file.close();
    }
};

class Order {
public:
    string order_id, user_id, product_id;
    int total_paid;

    Order(string o, string u, string p, int t)
        : order_id(o), user_id(u), product_id(p), total_paid(t) {}

    static void addDummyOrders() {
        ofstream file("orders.txt");
        file << "o1,u1,p1,1200\n";
        file << "o2,u1,p2,20\n";
        file << "o3,u2,p3,50\n";
        file.close();
    }

    static void getProductsByUserFirstName(const string& firstName) {
        unordered_map<string, string> userMap;
        ifstream userFile("users.txt");
        string line;
        while (getline(userFile, line)) {
            stringstream ss(line);
            string id, fname, lname, addr, email;
            getline(ss, id, ',');
            getline(ss, fname, ',');
            if (fname == firstName) {
                userMap[id] = fname;
            }
        }

        vector<string> productIDs;
        ifstream orderFile("orders.txt");
        while (getline(orderFile, line)) {
            stringstream ss(line);
            string oid, uid, pid;
            int total;
            getline(ss, oid, ',');
            getline(ss, uid, ',');
            getline(ss, pid, ',');
            ss >> total;

            if (userMap.find(uid) != userMap.end()) {
                productIDs.push_back(pid);
            }
        }

        cout << "\nProducts ordered by " << firstName << ":\n";
        ifstream prodFile("products.txt");
        while (getline(prodFile, line)) {
            stringstream ss(line);
            string pid, pname, desc;
            int price;
            getline(ss, pid, ',');
            getline(ss, pname, ',');
            getline(ss, desc, ',');
            ss >> price;

            if (find(productIDs.begin(), productIDs.end(), pid) != productIDs.end()) {
                cout << "- " << pname << endl;
            }
        }
    }
};

int main() {
    User::addDummyUsers();
    Product::addDummyProducts();
    Order::addDummyOrders();

    Order::getProductsByUserFirstName("Linus");

    return 0;
}
