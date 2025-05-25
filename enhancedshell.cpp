#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <direct.h>
#include <windows.h>
#include <fstream>
#include <ctime>
using namespace std;

class EnhancedShell {
private:
    bool isRunning;
    string currentDir;
    vector<string> commandHistory;
    const int MAX_HISTORY = 100;

    string getCurrentDir() {
        char buffer[FILENAME_MAX];
        _getcwd(buffer, FILENAME_MAX);
        return string(buffer);
    }

    vector<string> parseCommand(string command) {
        vector<string> tokens;
        stringstream ss(command);
        string token;
        
        while (ss >> token) {
            tokens.push_back(token);
        }
        return tokens;
    }

    void showHelp() {
        cout << "\n=== File Operations ===\n";
        cout << "  dir          - List files and directories\n";
        cout << "  cd <dir>     - Change directory\n";
        cout << "  pwd          - Print working directory\n";
        cout << "  mkdir <dir>  - Create directory\n";
        cout << "  rmdir <dir>  - Remove directory\n";
        cout << "  type <file>  - Display file contents\n";
        cout << "  del <file>   - Delete files\n";
        cout << "  copy <s> <d> - Copy file\n";
        cout << "  move <s> <d> - Move file\n";
        cout << "  rename <o> <n> - Rename file\n";
        cout << "\n=== System Commands ===\n";
        cout << "  cls/clear    - Clear screen\n";
        cout << "  date         - Show current date/time\n";
        cout << "  systeminfo   - System information\n";
        cout << "  tasklist     - Show running processes\n";
        cout << "\n=== Shell Features ===\n";
        cout << "  history      - Show command history\n";
        cout << "  echo <text>  - Print text\n";
        cout << "  help         - Show this help\n";
        cout << "  exit         - Exit shell\n\n";
    }

    void showHistory() {
        cout << "\nCommand History:\n";
        for (size_t i = 0; i < commandHistory.size(); i++) {
            cout << i + 1 << ": " << commandHistory[i] << endl;
        }
        cout << endl;
    }

    void showDate() {
        time_t now = time(0);
        cout << ctime(&now);
    }

    bool createFile(const string& filename) {
        ofstream file(filename);
        return file.good();
    }

    void executeCommand(const vector<string>& tokens) {
        if (tokens.empty()) return;

        string cmd = tokens[0];

        if (cmd == "exit") {
            isRunning = false;
            cout << "Goodbye!\n";
        }
        else if (cmd == "help") {
            showHelp();
        }
        else if (cmd == "cls" || cmd == "clear") {
            system("cls");
        }
        else if (cmd == "cd") {
            if (tokens.size() > 1) {
                if (_chdir(tokens[1].c_str()) == 0) {
                    currentDir = getCurrentDir();
                } else {
                    cout << "Error: Directory not found - " << tokens[1] << endl;
                }
            }
        }
        else if (cmd == "pwd") {
            cout << currentDir << endl;
        }
        else if (cmd == "history") {
            showHistory();
        }
        else if (cmd == "date") {
            showDate();
        }
        else if (cmd == "echo") {
            for (size_t i = 1; i < tokens.size(); i++) {
                cout << tokens[i] << " ";
            }
            cout << endl;
        }
        else if (cmd == "touch") {
            if (tokens.size() > 1) {
                if (createFile(tokens[1])) {
                    cout << "File created: " << tokens[1] << endl;
                } else {
                    cout << "Error creating file: " << tokens[1] << endl;
                }
            }
        }
        else {
            // Execute other commands using cmd.exe
            string fullCommand = "cmd /c " + cmd;
            for (size_t i = 1; i < tokens.size(); i++) {
                fullCommand += " " + tokens[i];
            }
            int result = system(fullCommand.c_str());
            if (result != 0) {
                cout << "Error executing command: " << cmd << endl;
            }
        }
    }

    void addToHistory(const string& command) {
        if (commandHistory.size() >= MAX_HISTORY) {
            commandHistory.erase(commandHistory.begin());
        }
        commandHistory.push_back(command);
    }

public:
    EnhancedShell() : isRunning(true) {
        currentDir = getCurrentDir();
        SetConsoleTitle("Enhanced Windows Shell");
    } 

    void run() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        
        cout << "Enhanced Windows Shell v1.0\n";
        cout << "Type 'help' for commands, 'exit' to quit\n\n";

        while (isRunning) {
            // Set prompt color
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << currentDir << "> ";
            
            // Reset color for user input
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            
            string command;
            getline(cin, command);

            if (command.empty()) continue;

            addToHistory(command);
            vector<string> tokens = parseCommand(command);
            executeCommand(tokens);
        }
    }
};

int main() {
    EnhancedShell shell;
    shell.run();
    return 0;
}