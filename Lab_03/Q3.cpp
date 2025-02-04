#include <iostream>
using namespace std;

class Glass {
    public :
    int LiquidLevel;


    int drink(int milimeters){
        LiquidLevel -= milimeters;
        return 1;
    }

    void Refill(){
        LiquidLevel = 200;
    }
};



int main(){
    Glass glass;

    glass.LiquidLevel = 200;

    while(1){
        if (glass.LiquidLevel < 100){
            glass.Refill();
        };
        
        int temp = 0;
        cin >> temp;
        glass.drink(temp);
        cout << "The current Liquid Level is : " << glass.LiquidLevel << endl;

        
    };
}