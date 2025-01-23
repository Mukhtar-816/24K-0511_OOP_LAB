#include <iostream>
using namespace std;

int main(){
    string data;
    char name[50];
    char test_scores[5][5];
    int test_score[5];

    cout << "Enter a Data: ";
    cin >> data;

    for (int i = 0; i < data[i] != '\0'; i++){
        if (data[i] >=  65 && data[i] <= 90){
            name[i] = data[i];
        }
        else if (data[i] >= 48 && data[i] <= 57){
            for (int j = 0; j < 5; j++){
                test_scores[i][j] = data[j];
            }
        }
    }

    for (int i = 0; i < 5; i++){
        test_score[i] = stoi(test_scores[i]);
    }

    cout << test_score[0] << endl;
}