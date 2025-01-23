#include <iostream>
using namespace std;

int main(){
    int sum = 0, arr[20];
    int *ptr = arr;

    for (int i = 0; i < 20; ++i){
        cout << "Enter number " << i + 1 << ": ";
        cin >> *(ptr + i) ;
    }

    for (int i = 0; i < 20; ++i){
        sum += *(ptr + i);
    }

    cout << "The sum of the numbers is: " << sum << endl;
}