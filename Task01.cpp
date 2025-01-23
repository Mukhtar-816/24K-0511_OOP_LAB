#include <iostream>
using namespace std;


int main(){
    float arr[20] = {1, 3, 2, 8, 9, 10, 14, 20, 19, 5, 4, 6, 7, 11, 12, 13, 15, 16, 17, 18}, second_highest = arr[0], highest = arr[0];
    float *ptr = arr;
    int highest_index = 0;

    for (int i = 0; i < 20; ++i){
        if (*(ptr + i) > highest){
            highest = *(ptr + i);
            highest_index = i;
        }
    }

    arr[highest_index] = 0;

    for (int i = 0; i < 20; ++i){
        if (*(ptr + i) > second_highest){
            second_highest = *(ptr + i);
        }
    }

    cout << "The second highest number is: " << second_highest << endl;


}