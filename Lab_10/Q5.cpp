#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h>

class Task
{
    int id;
    string title;
    bool isDone;
    static int counter;
    fstream taskFile;

public:
    Task() : isDone(false)
    {
        getListNumber();
    }; // default

    void addTask(string title)
    {
        taskFile.open("tasks.txt", ios::app);
        taskFile << "id :" << counter + 1 << endl;
        taskFile << "title :" << title << endl;
        taskFile << "Completed :" << (isDone ? "true" : "false") << endl;
        taskFile << endl;
        taskFile.close();
        counter++;
    };

    void markAsDone(int targetID)
    {
        ifstream inFile("tasks.txt");
        ofstream tempFile("temp.txt");

        string line;
        bool taskFound = false;

        while (getline(inFile, line))
        {
            if (line.find("id :") != string::npos)
            {
                int currentID;
                sscanf(line.c_str(), "id :%d", &currentID); 
                tempFile << line << "\n";

                if (currentID == targetID)
                {
                    getline(inFile, line);
                    tempFile << line << "\n";

                    getline(inFile, line);
                    tempFile << "Completed :true\n";

                    taskFound = true;
                }
                else
                {
                    getline(inFile, line);
                    tempFile << line << "\n";
                    getline(inFile, line);
                    tempFile << line << "\n";
                }

                tempFile << "\n";
            }
        }

        inFile.close();
        tempFile.close();

        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");

        if (taskFound)
            cout << "Task marked as done.\n";
        else
            cout << "Task ID not found.\n";
    }

    void viewAllTask()
    {
        fstream taskList;
        string taskLine;
        taskList.open("tasks.txt", ios::in);

        if (!taskList)
        {
            cout << "No tasks found.\n";
            return;
        }
        cout << "\n\n----- Task List -----\n\n";
        while (getline(taskList, taskLine))
        {
            cout << taskLine << endl;
        }
        taskList.close();
    };

    void getListNumber()
    {
        string line;
        fstream file("tasks.txt");
        counter = 0;
        while (getline(file, line))
        {
            if (line.find("id :") != string::npos)
            {
                counter++;
            }
        }
        file.close();
    }
};
int Task::counter = 0;

int main()
{
    Task tasklist;
    string options[4] = {"Add Task.", "View All Task.", "Mark Task as Done.", "Exit."};
    int selectedOpt;

    cout << "Welcome to todo-list !" << endl
         << endl;

    while (selectedOpt != 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            cout << to_string(i + 1) + ". " + options[i] << endl;
        }

        cin >> selectedOpt;

        if (selectedOpt == 1)
        {
            string temp;
            cout << "Enter the title of Task :" << endl;
            cin.ignore();
            getline(cin, temp);
            if (temp == "")
                cout << "invalid Input." << endl;
            else
            {
                tasklist.addTask(temp);
                cout << "\nTask Successfully Added.\n"
                     << endl;
            }
        }
        else if (selectedOpt == 2)
        {
            tasklist.viewAllTask();
        }
        else if (selectedOpt == 3)
        {
            int _id;
            tasklist.viewAllTask();
            cout << "\nEnter the task id to Mark it as done :" << endl;
            cin >> _id;
            tasklist.markAsDone(_id);
        }
        else if (selectedOpt == 4)
        {
            exit;
        }
        else
        {
            cout << "invalid input." << endl;
        }
    }
}