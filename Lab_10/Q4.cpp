#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
using namespace std;

class Logger {
    const int maxSize = 1024 * 1024;
    int logIndex = 1;
    string currentFile;

public:
    Logger() {
        currentFile = "log1.txt";
    }

    void writeLog(const string& message) {
        ofstream logFile(currentFile, ios::app);
        if (!logFile) return;
        logFile << message << endl;
        logFile.close();
        rotateLogIfNeeded();
    }

private:
    void rotateLogIfNeeded() {
        ifstream in(currentFile, ios::binary | ios::ate);
        streamsize size = in.tellg();
        in.close();
        if (size >= maxSize) {
            string newFile = "log" + to_string(++logIndex) + ".txt";
            rename(currentFile.c_str(), newFile.c_str());
            currentFile = "log1.txt";
        }
    }
};

int main() {
    Logger logger;
    string input;
    cout << "Enter log messages (type 'exit' to quit):" << endl;
    while (true) {
        getline(cin, input);
        if (input == "exit") break;
        logger.writeLog(input);
    }
    return 0;
}
