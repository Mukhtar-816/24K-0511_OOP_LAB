#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logger {
private:
    vector<string> logs;
    const int MAX_LOGS = 1000;

    void addLog(const string& severity, const string& module, const string& message) {
        string log = "[" + severity + "] [" + module + "] " + message;
        if (logs.size() >= MAX_LOGS) {
            logs.erase(logs.begin());
        }
        logs.push_back(log);
    }

public:
    void logInfo(const string& module, const string& message) {
        addLog("INFO", module, message);
    }

    void logWarning(const string& module, const string& message) {
        addLog("WARN", module, message);
    }

    void logError(const string& module, const string& message) {
        addLog("ERROR", module, message);
    }

    friend class Auditor;
};

class Auditor {
private:
    string correctPassword = "admin123";

public:
    void getLogs(const Logger& logger, const string& password) {
        if (password == correctPassword) {
            cout << "\n=== Retrieved Logs ===\n";
            for (const string& log : logger.logs) {
                cout << log << endl;
            }
        } else {
            cout << "❌ Unauthorized access.\n";
        }
    }
};

int main() {
    Logger logger;
    logger.logInfo("Network", "Connected to server");
    logger.logWarning("Database", "Slow query detected");
    logger.logError("Auth", "Invalid login attempt");

    Auditor auditor;
    auditor.getLogs(logger, "wrongpass");
    auditor.getLogs(logger, "admin123");

    return 0;
}
