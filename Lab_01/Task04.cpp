#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    float weight_Kg = 0,  weight_pounds = 0;

    cout << "Enter Weight in Kg : ";
    cin >> weight_Kg;

    if(weight_Kg < 0){
        cout << "Invalid Input" << endl;
    }

    weight_pounds = weight_Kg * 2.20462;

    cout << "The weight in Kg is : "<< fixed << setprecision(2) << weight_Kg << " Kg" << endl;
    cout << "The weight in Pounds is : "<< fixed << setprecision(2) << weight_pounds << " Pounds" << endl;

}