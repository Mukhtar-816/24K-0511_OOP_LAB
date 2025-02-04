#include <iostream>
using namespace std;

struct Entity {
    int id;
    string name;
};

void _sortById(Entity* entities, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (entities[j].id > entities[j + 1].id) {
                swap(entities[j], entities[j + 1]);
            }
        }
    }
}

void _sortByName(Entity* entities, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (entities[j].name[0] > entities[j + 1].name[0]) {
                swap(entities[j], entities[j + 1]);
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the num of structure: ";
    cin >> N;

    Entity* entities = new Entity[N];

    for (int i = 0; i < N; i++) {
        cout << "Enter ID for entity " << (i + 1) << ": ";
        cin >> entities[i].id;
        cout << "Enter Name for entity " << (i + 1) << ": ";
        cin >> entities[i].name;
    }

    _sortById(entities, N);
    cout << endl << "Sorted by ID:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "ID: " << entities[i].id << ", Name: " << entities[i].name << endl;
    }

    _sortByName(entities, N);
    cout << "\nSorted by first character of Name:\n";
    for (int i = 0; i < N; i++) {
        cout << "ID: " << entities[i].id << ", Name: " << entities[i].name << endl;
    }

    delete[] entities;
    return 0;
}
