#include <iostream>
#include <thread>
#include <windows.h>

class Blend {
public:
    void blend() {
        for (int i = 0; i < 5; ++i) {
            std::cout << "Blending fruit " << i + 1 << "...\n";
            Sleep(1);
        }
    }
};

class Grind {
public:
    void grind() {
        std::cout << "Grinding ingredients...\n";
        Sleep(5);
    }
};

class JuiceMaker {
private:
    Blend blend;
    Grind grind;

public:
    void blendJuice() {
        blend.blend();
    }

    void grindJuice() {
        grind.grind();
    }
};

int main() {
    JuiceMaker juiceMaker;
    juiceMaker.blendJuice();
    juiceMaker.grindJuice();
    
    return 0;
}