# 🛠️ 00-Setup: Get Ready to Program!

## 🎯 What You'll Do Here
Install everything you need to start programming in C. Don't worry - we'll guide you through every step!

## 🎪 Choose Your Setup Method

### 🌟 **Method 1: Code::Blocks (EASIEST - Recommended for Beginners)**
Everything in one package!

#### Windows:
1. Go to [codeblocks.org](http://www.codeblocks.org/)
2. Download → Binary releases → **"codeblocks-20.03mingw-setup.exe"** 
3. Run installer → Next → Next → Install
4. Open Code::Blocks → You're ready! ✅

#### Linux (Ubuntu/Debian):
```bash
sudo apt update
sudo apt install codeblocks
```

#### macOS:
```bash
# Install Homebrew first (if you don't have it)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
# Then install Code::Blocks
brew install --cask codeblocks
```

### 💻 **Method 2: VS Code + Compiler (More Popular)**
Separate tools, more control.

#### Step 1: Install VS Code
1. Go to [code.visualstudio.com](https://code.visualstudio.com/)
2. Download for your OS
3. Install normally

#### Step 2: Install C/C++ Extension
1. Open VS Code
2. Click Extensions (square icon on left)
3. Search "C/C++" 
4. Install the Microsoft one

#### Step 3: Install Compiler

**Windows:**
1. Go to [winlibs.com](https://winlibs.com/)
2. Download latest release (UCRT runtime)
3. Extract to `C:\mingw64`
4. Add `C:\mingw64\bin` to PATH:
   - Windows key → Search "environment variables"
   - Edit system environment variables
   - Environment Variables → Path → Edit → New
   - Add: `C:\mingw64\bin`
   - OK everything

**Linux:**
```bash
sudo apt update
sudo apt install build-essential
```

**macOS:**
```bash
xcode-select --install
```

## ✅ Test Your Setup

### Test Code::Blocks:
1. Open Code::Blocks
2. File → New → Project → Console Application → C → Next
3. Name: "TestSetup" → Finish
4. You'll see code already there
5. Press F9 (Build and Run)
6. Should see "Hello world!" ✅

### Test VS Code:
1. Create folder "TestSetup" on Desktop
2. Open VS Code → Open Folder → Choose "TestSetup"
3. New File → Save as "test.c"
4. Type this code:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

5. Save (Ctrl+S)
6. Terminal → New Terminal
7. Type: `gcc test.c -o test`
8. Type: `./test` (Linux/Mac) or `test.exe` (Windows)
9. Should see "Hello, World!" ✅

## 🚨 Common Problems & Solutions

### "gcc is not recognized" (Windows)
**Problem:** Compiler not in PATH  
**Solution:** 
1. Restart computer
2. Check PATH setting again
3. Try Method 1 (Code::Blocks) instead

### "Permission denied" (Linux/Mac)
**Problem:** Need admin rights  
**Solution:** Add `sudo` before commands

### Code::Blocks won't start
**Problem:** Missing dependencies  
**Solution:** 
1. Run as administrator
2. Install Visual C++ Redistributable
3. Restart computer

## 🎉 Success!
If you can compile and run a program that prints "Hello, World!", you're ready for the next lesson!

## 🔗 What's Next?
**👉 Go to [01-Hello-World](../01-Hello-World/) to write your first real program!**
