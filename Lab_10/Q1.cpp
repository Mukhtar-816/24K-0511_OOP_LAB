#include <iostream>
using namespace std;
#include <fstream>
// #Key=5;

int main(){
    string str;

    cout << "Enter the string" << endl;
    getline(cin, str);

    for (int i = 0; i < str.length(); ++i){
        str[i] += i + 1;
    };

    cout << "String Encrypted successfully." << endl;
    
    ofstream writefile("encryptedtext.txt");

    writefile << str;
    
    cout << "Text stored in file." << endl;

    writefile.close();

    ifstream readfile("encryptedtext.txt");

    cout << "Reading text from file" << endl;
    getline(readfile, str);

    for (int i = 0; i < str.length(); ++i){
        str[i] -= i + 1;
    };

    cout << "Text decrypted." << endl << str << endl;
}