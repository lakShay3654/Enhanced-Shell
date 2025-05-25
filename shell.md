# 🖥️ Enhanced Windows Shell

**Enhanced Windows Shell** is a modernized C++ command-line environment tailored specifically for Windows users who appreciate the charm of the traditional DOS interface, yet crave the functionality and customization of a more capable shell.

---

## ✨ Introduction

This project is an educational yet powerful Windows shell emulator written in C++. It supports a wide array of internal and external commands, integrates with the Windows command processor, and brings features like command history, colored prompts, file operations, and basic system interactions.

Whether you're a student learning systems programming, a Windows enthusiast, or someone who enjoys the command-line lifestyle, this tool adds productivity and polish to your toolkit.

---

## 📦 Features

### 📁 File & Directory Operations
- `dir` – List files and directories in the current working directory
- `cd <dir>` – Change to a specified directory
- `pwd` – Print the current working directory
- `mkdir <dir>` – Create a new directory
- `rmdir <dir>` – Delete an existing directory
- `type <file>` – Display the contents of a text file
- `del <file>` – Delete a specified file
- `copy <src> <dest>` – Copy a file from source to destination
- `move <src> <dest>` – Move a file from source to destination
- `rename <old> <new>` – Rename a file
- `touch <file>` – Create an empty file

### 🧠 Shell Commands
- `help` – Display a list of supported commands
- `cls` / `clear` – Clear the terminal screen
- `echo <text>` – Print text to the console
- `history` – View past commands used in the session (up to 100 entries)
- `exit` – Exit the Enhanced Shell

### 🖥️ System Utilities
- `date` – Display the current system date and time
- `systeminfo` – Retrieve and display basic system information
- `tasklist` – Show a list of currently running processes

### 🎨 User Experience Enhancements
- Color-coded command prompts
- Status feedback and error messages for most operations
- Compact, responsive design
- Uses native Windows API calls for terminal control

---

## 🛠️ Build & Installation

### 🧱 Requirements
- Windows 10 or later
- A C++17-compatible compiler (MSVC, MinGW, etc.)
- A terminal or Command Prompt to run the application

### 🔧 Build Instructions

Compile with `g++`:

```bash
g++ -o EnhancedShell EnhancedShell.cpp
```

Or use Visual Studio by creating a new project and adding `EnhancedShell.cpp` as a source file.

Then, run it via:

```cmd
EnhancedShell.exe
```

---

## 🧪 Sample Interaction

```cmd
C:\Users\Alice> EnhancedShell.exe
Enhanced Windows Shell v1.0
Type 'help' for commands, 'exit' to quit

C:\Users\Alice> mkdir Projects
C:\Users\Alice> cd Projects
C:\Users\Alice\Projects> touch notes.txt
C:\Users\Alice\Projects> echo Hello World > notes.txt
C:\Users\Alice\Projects> type notes.txt
Hello World
C:\Users\Alice\Projects> history
1: mkdir Projects
2: cd Projects
3: touch notes.txt
4: echo Hello World > notes.txt
5: type notes.txt
```

---

## 🤔 Why Use This Project?

- Perfect for **students** exploring how shells work under the hood.
- Lightweight and runs natively on Windows—**no dependencies** beyond the standard library.
- Demonstrates **command parsing**, **process invocation**, and **directory manipulation**.
- Acts as a base framework for extending to more complex scripting or automation environments.

---

## 🚀 Future Improvements

- Auto-completion support for file paths
- Command chaining and pipes
- Configurable themes and prompt text
- Scripting support for `.eshell` files
- Enhanced error logging and debug flags

---

## 📜 Legacy with a Modern Twist

While other shells grow ever more complicated, EnhancedShell keeps things clean, simple, and productive. It captures the essence of early computing while still embracing C++’s power to make it better.

---
