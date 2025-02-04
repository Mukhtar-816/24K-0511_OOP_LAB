#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int *arr = new int[size];
    int count = 0;

    cout << "Enter -1 to stop :" << endl;
    while (true) {
        cout << "Enter: ";
        cin >> arr[count];

        if (arr[count] == -1) {
            break;
        }

        count++;

        if (count >= size * 2) {
            int newSize = size * 2;
            int *newArr = new int[newSize];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            size = newSize;
        }
    }

    int *finalArr = new int[count];
    for (int i = 0; i < count; i++) {
        finalArr[i] = arr[i];
    }

    cout << "Elements: ";
    for (int i = 0; i < count; i++) {
        cout << finalArr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    delete[] finalArr;

    return 0;
}
