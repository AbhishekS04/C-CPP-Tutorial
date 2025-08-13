# Development Environment Setup Guide

This guide will help you set up your development environment for C/C++ programming on different operating systems.

## 📋 Table of Contents

1. [Windows Setup](#windows-setup)
2. [Linux Setup](#linux-setup)
3. [macOS Setup](#macos-setup)
4. [IDE Configuration](#ide-configuration)
5. [Testing Your Setup](#testing-your-setup)
6. [Troubleshooting](#troubleshooting)

## 🪟 Windows Setup

### Option 1: MinGW-w64 (Recommended for beginners)

1. **Download MinGW-w64**
   - Go to [mingw-w64.org](https://www.mingw-w64.org/)
   - Download the installer
   - Run the installer and follow the setup wizard

2. **Add to PATH**
   ```powershell
   # Add MinGW bin directory to your PATH
   # Usually: C:\mingw64\bin
   ```

3. **Verify Installation**
   ```powershell
   gcc --version
   g++ --version
   ```

### Option 2: Visual Studio Community

1. **Download Visual Studio Community**
   - Go to [Visual Studio Downloads](https://visualstudio.microsoft.com/downloads/)
   - Download Visual Studio Community (free)

2. **Install with C++ Support**
   - Select "Desktop development with C++"
   - This includes MSVC compiler and debugging tools

3. **Command Line Tools**
   - Use "Developer Command Prompt" for compilation
   - Or use the integrated terminal in Visual Studio

### Option 3: MSYS2 (Advanced)

1. **Install MSYS2**
   ```bash
   # Download from https://www.msys2.org/
   # Install and update package database
   pacman -Syu
   
   # Install GCC
   pacman -S mingw-w64-x86_64-gcc
   pacman -S mingw-w64-x86_64-gdb
   ```

## 🐧 Linux Setup

### Ubuntu/Debian
```bash
# Update package list
sudo apt update

# Install build essentials
sudo apt install build-essential

# Install additional tools
sudo apt install gdb valgrind

# Verify installation
gcc --version
g++ --version
make --version
```

### Fedora/RHEL/CentOS
```bash
# Install development tools
sudo dnf groupinstall "Development Tools"

# Or install individual packages
sudo dnf install gcc gcc-c++ make gdb

# Verify installation
gcc --version
g++ --version
```

### Arch Linux
```bash
# Install base development tools
sudo pacman -S base-devel

# Install additional tools
sudo pacman -S gdb valgrind

# Verify installation
gcc --version
g++ --version
```

## 🍎 macOS Setup

### Using Xcode Command Line Tools
```bash
# Install Xcode command line tools
xcode-select --install

# Verify installation
gcc --version
g++ --version
```

### Using Homebrew (Recommended)
```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install GCC
brew install gcc

# Install additional tools
brew install gdb
brew install valgrind  # Note: limited support on macOS

# Verify installation
gcc --version
g++ --version
```

## 🛠️ IDE Configuration

### Visual Studio Code

1. **Install VS Code**
   - Download from [code.visualstudio.com](https://code.visualstudio.com/)

2. **Install C/C++ Extension**
   ```json
   {
     "extensions": [
       "ms-vscode.cpptools",
       "ms-vscode.cmake-tools",
       "twxs.cmake"
     ]
   }
   ```

3. **Configure IntelliSense**
   - Create `.vscode/c_cpp_properties.json`
   ```json
   {
     "configurations": [
       {
         "name": "Win32",
         "includePath": [
           "${workspaceFolder}/**"
         ],
         "defines": [
           "_DEBUG",
           "UNICODE",
           "_UNICODE"
         ],
         "compilerPath": "C:/mingw64/bin/gcc.exe",
         "cStandard": "c17",
         "cppStandard": "c++17"
       }
     ],
     "version": 4
   }
   ```

4. **Build Configuration**
   - Create `.vscode/tasks.json`
   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "label": "build C",
         "type": "shell",
         "command": "gcc",
         "args": [
           "-g",
           "-Wall",
           "-Wextra",
           "${file}",
           "-o",
           "${fileDirname}/${fileBasenameNoExtension}"
         ],
         "group": {
           "kind": "build",
           "isDefault": true
         }
       },
       {
         "label": "build C++",
         "type": "shell",
         "command": "g++",
         "args": [
           "-g",
           "-Wall",
           "-Wextra",
           "-std=c++17",
           "${file}",
           "-o",
           "${fileDirname}/${fileBasenameNoExtension}"
         ],
         "group": "build"
       }
     ]
   }
   ```

### CLion (JetBrains)

1. **Download CLion**
   - Student license available
   - 30-day free trial

2. **Configure Toolchain**
   - Go to File → Settings → Build, Execution, Deployment → Toolchains
   - Set up your compiler path

3. **CMake Integration**
   - CLion uses CMake by default
   - Supports multiple build configurations

### Code::Blocks

1. **Download Code::Blocks**
   - Get version with MinGW included (Windows)
   - Free and cross-platform

2. **Configure Compiler**
   - Settings → Compiler
   - Select GNU GCC Compiler
   - Set installation directory

## 🧪 Testing Your Setup

### Create Test Files

1. **C Test Program** (`test.c`)
   ```c
   #include <stdio.h>
   
   int main() {
       printf("Hello, C World!\n");
       printf("Your C compiler is working correctly.\n");
       return 0;
   }
   ```

2. **C++ Test Program** (`test.cpp`)
   ```cpp
   #include <iostream>
   #include <vector>
   #include <string>
   
   int main() {
       std::cout << "Hello, C++ World!" << std::endl;
       
       std::vector<std::string> languages = {"C", "C++", "Python", "Java"};
       std::cout << "My favorite programming languages:" << std::endl;
       
       for (const auto& lang : languages) {
           std::cout << "- " << lang << std::endl;
       }
       
       return 0;
   }
   ```

### Compile and Run

#### Command Line
```bash
# Compile C program
gcc -o test test.c
./test

# Compile C++ program
g++ -std=c++17 -o testcpp test.cpp
./testcpp

# With debugging info and warnings
gcc -g -Wall -Wextra -o test test.c
g++ -g -Wall -Wextra -std=c++17 -o testcpp test.cpp
```

#### Windows PowerShell
```powershell
# Compile C program
gcc -o test.exe test.c
.\test.exe

# Compile C++ program
g++ -std=c++17 -o testcpp.exe test.cpp
.\testcpp.exe
```

## 🔧 Troubleshooting

### Common Issues

#### 1. "gcc is not recognized as an internal or external command" (Windows)
**Solution**: Add compiler to PATH
```powershell
# Add to system PATH environment variable
# Control Panel → System → Advanced → Environment Variables
# Add: C:\mingw64\bin (or your MinGW installation path)
```

#### 2. Permission denied (Linux/macOS)
**Solution**: Make executable or use sudo for installation
```bash
# Make file executable
chmod +x filename

# Or for installation
sudo apt install build-essential
```

#### 3. Header files not found
**Solution**: Check include paths
```bash
# Find standard headers
gcc -v -E - < /dev/null

# For Windows, typically in:
# C:\mingw64\include
# C:\mingw64\lib\gcc\x86_64-w64-mingw32\version\include
```

#### 4. Linking errors
**Solution**: Check library paths and link order
```bash
# Link math library (common need)
gcc program.c -lm -o program

# Link multiple libraries
g++ program.cpp -pthread -lrt -o program
```

### Performance Optimization

#### Compiler Flags
```bash
# Debug build (development)
gcc -g -O0 -Wall -Wextra program.c -o program_debug

# Release build (production)
gcc -O2 -DNDEBUG program.c -o program_release

# Maximum optimization (use carefully)
gcc -O3 -march=native program.c -o program_optimized
```

### Debugging Setup

#### GDB Configuration
```bash
# Install GDB
# Ubuntu/Debian: sudo apt install gdb
# Fedora: sudo dnf install gdb
# Windows: included with MinGW

# Basic GDB commands
gdb ./program
(gdb) run
(gdb) break main
(gdb) step
(gdb) print variable_name
(gdb) quit
```

#### Valgrind (Linux/macOS)
```bash
# Install Valgrind
sudo apt install valgrind  # Ubuntu/Debian

# Check for memory leaks
valgrind --leak-check=full ./program

# Check for memory errors
valgrind --tool=memcheck ./program
```

## 📚 Next Steps

After setting up your environment:

1. **Start with C Basics**: Go to `01-C-Basics/`
2. **Practice Daily**: Write small programs to test your setup
3. **Learn Your IDE**: Master your chosen development environment
4. **Version Control**: Set up Git for your projects
5. **Read Documentation**: Familiarize yourself with compiler options

## 🔗 Useful Resources

- **GCC Manual**: [gcc.gnu.org/onlinedocs](https://gcc.gnu.org/onlinedocs/)
- **VS Code C++ Docs**: [code.visualstudio.com/docs/languages/cpp](https://code.visualstudio.com/docs/languages/cpp)
- **CMake Tutorial**: [cmake.org/cmake/help/latest/guide/tutorial](https://cmake.org/cmake/help/latest/guide/tutorial/)
- **Debugging Guide**: [sourceware.org/gdb/current/onlinedocs/gdb](https://sourceware.org/gdb/current/onlinedocs/gdb/)

Remember: A properly configured development environment is crucial for productive programming. Take time to set it up correctly – it will save you hours of frustration later!
