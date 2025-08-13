# 🛠️ Setup Guide - Get Ready to Program!

## 👋 Welcome to Setup!

Don't worry - setting up programming tools might seem scary, but we'll guide you through every single step. By the end of this guide, you'll be ready to write your first C program!

## 🎯 What We're Installing

We need 2 things to start programming:
1. **A Compiler** - This turns your C code into a program the computer can run
2. **A Code Editor** - This is where you'll type your code (like Microsoft Word, but for code)

## 🪟 Windows Setup (Step-by-Step)

### Method 1: Code::Blocks (Easiest for Beginners) ⭐ RECOMMENDED

**Step 1: Download Code::Blocks**
1. Go to [www.codeblocks.org](http://www.codeblocks.org/)
2. Click "Downloads"  
3. Click "Download the binary release"
4. Choose **"codeblocks-20.03mingw-setup.exe"** (this includes everything you need!)

**Step 2: Install Code::Blocks**
1. Run the downloaded file
2. Click "Next" → "I Agree" → "Next" → "Install"
3. Wait for it to finish (takes 2-3 minutes)
4. Click "Finish"

**Step 3: Test It Works**
1. Open Code::Blocks
2. If it asks to choose a compiler, select "GNU GCC Compiler" and click "Set as default"
3. You're ready! 🎉

### Method 2: Visual Studio Code (For Those Who Want More Features)

**Step 1: Download Visual Studio Code**
1. Go to [code.visualstudio.com](https://code.visualstudio.com/)
2. Click "Download for Windows"
3. Run the installer and follow the steps

**Step 2: Install MinGW (The Compiler)**
1. Go to [winlibs.com](https://winlibs.com/)
2. Download "Release versions" → "UCRT runtime"
3. Extract the zip file to `C:\mingw64`
4. Add `C:\mingw64\bin` to your Windows PATH:
   - Press Windows + R
   - Type `sysdm.cpl` and press Enter
   - Click "Environment Variables"
   - In "System Variables", find "Path" and click "Edit"
   - Click "New" and add `C:\mingw64\bin`
   - Click OK on all windows

**Step 3: Install C Extension**
1. Open VS Code
2. Click the Extensions icon (square icon on left)
3. Search for "C/C++"
4. Install the Microsoft C/C++ extension

**Step 4: Test It Works**
1. Open Command Prompt (Windows + R, type `cmd`)
2. Type `gcc --version` and press Enter
3. You should see version information

## 🐧 Linux Setup (Ubuntu/Debian)

**Step 1: Open Terminal**
- Press Ctrl + Alt + T

**Step 2: Install Development Tools**
```bash
sudo apt update
sudo apt install build-essential
```

**Step 3: Test It Works**
```bash
gcc --version
```

**Step 4: Install a Code Editor (Optional)**
```bash
# For VS Code
sudo snap install --classic code

# Or for a simple editor
sudo apt install gedit
```

## 🍎 macOS Setup

**Step 1: Install Xcode Command Line Tools**
1. Open Terminal (Applications → Utilities → Terminal)
2. Type this command:
```bash
xcode-select --install
```
3. Click "Install" when prompted

**Step 2: Test It Works**
```bash
gcc --version
```

**Step 3: Install VS Code (Optional)**
1. Go to [code.visualstudio.com](https://code.visualstudio.com/)
2. Download for macOS
3. Install like any other Mac app

## 🧪 Test Your Setup

Let's make sure everything works by creating your first program!

### Using Code::Blocks:

1. **Open Code::Blocks**
2. **Create New Project**: File → New → Project
3. **Choose Console Application** → Next
4. **Select C** (not C++) → Next  
5. **Project title**: "MyFirstProgram" → Next → Finish
6. **You'll see some code already there** - that's your first program!
7. **Run it**: Press F9 or click the green "Build and run" button
8. **You should see** a black window saying "Hello world!"

### Using VS Code:

1. **Create a folder** called "MyFirstProgram" on your desktop
2. **Open VS Code**
3. **Open folder**: File → Open Folder → Choose your "MyFirstProgram" folder
4. **Create new file**: Click the "New File" icon or Ctrl+N
5. **Save as**: "hello.c" (make sure it ends with .c)
6. **Type this code**:
```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```
7. **Save the file**: Ctrl+S
8. **Open terminal**: Terminal → New Terminal
9. **Compile**: Type `gcc hello.c -o hello` and press Enter
10. **Run**: Type `./hello` (or `hello.exe` on Windows) and press Enter
11. **You should see**: "Hello, World!"

## ✅ Setup Complete!

If you can see "Hello, World!" on your screen, congratulations! 🎉 You've successfully:
- ✅ Installed a C compiler
- ✅ Set up a code editor  
- ✅ Written your first C program
- ✅ Compiled and ran it

## ❓ Troubleshooting

### Problem: "gcc is not recognized" (Windows)
**Solution**: The compiler isn't in your PATH. Try:
1. Restart your computer
2. Make sure you added `C:\mingw64\bin` to your PATH correctly
3. Try Method 1 (Code::Blocks) instead - it's easier!

### Problem: "Permission denied" (Linux/Mac)
**Solution**: Try adding `sudo` before the command:
```bash
sudo apt install build-essential
```

### Problem: Code::Blocks won't start
**Solution**: 
1. Right-click the Code::Blocks icon
2. Choose "Run as administrator"
3. If still not working, try restarting your computer

### Problem: VS Code doesn't recognize C files
**Solution**:
1. Make sure your file ends with `.c` (not `.txt`)
2. Install the C/C++ extension from Microsoft
3. Restart VS Code

## 🆘 Still Stuck?

Don't worry! Programming setup can be tricky. Here's how to get help:

1. **Try the other method**: If Code::Blocks isn't working, try VS Code (or vice versa)
2. **Ask for help**: Create an issue on our GitHub page
3. **Search online**: Copy the error message and search Google
4. **Ask a friend**: If you know someone who programs, they can help

## 🎉 What's Next?

Now that your setup is complete:

### **👉 [Go to Week 1: Your First Program](../01-C-Basics/01-hello-world/)**

You're ready to start learning C programming! The hardest part (setup) is done. Now comes the fun part - writing code! 🚀

---

*Remember: Every programmer has gone through setup struggles. You're doing great! 💪*
