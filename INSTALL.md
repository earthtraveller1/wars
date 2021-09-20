# How to Install

Here is how you install this game.

## Windows

Here is what you do on Windows.

First, clone this repository by running

```bash
git clone https://github.com/Hello56721/wars
```

Then, first install the following softwares:

- [CMake](https://www.cmake.org). Make sure that you added it to PATH.
- A C/C++ compiler of your choice (This tutorial assumes [Microsoft Visual Studio for C/C++](https://visualstudio.microsoft.com/downloads/))

Next, download [GLFW](https://www.glfw.org/download).

After you have GLFW downloaded, extract the content of the zip into a folder called `deps/GLFW` in the wars repository folder that you have just cloned. Then, open that folder and renamed `lib-vc2019` to just `lib`. Open *that* folder, and delete the file `glfw3dll.lib`.

After you have done that, go to the root directory of the wars repository that you have cloned and run

```bash
cmake . -B .
```

That will create a file called `Wars.sln`. Double click on that, and it will open in Visual Studio. Then, just press Ctrl+Shift+B to compile the solution. This will create a folder called `Debug` in the root repository folder. Open that folder, and there you will find a file called `wars.exe`. Double click on that to play the game.

Open a GitHub issue on this repository if this install instruction doesn't work for you.

## Linux

Here is what you do on Linux.

First, clone this repository by running

```bash
git clone https://github.com/Hello56721/wars
```

Then, first install the following softwares:

- [CMake](https://www.cmake.org). Make sure that you added it to PATH.
- A C/C++ compiler of your choice.
- A build system of your choice (This tutorial assumes `ninja-build`)
- GLFW 3.3 development files (If your distribution provides it. If not, build GLFW from source.).

After those are all installed on your Linux system (you know how to do that if you know how to use Linux, right?), run

```bash
cmake . -B . -G Ninja 
ninja all
```

in the root directory of the wars repository you have cloned. This will produce a file called `wars.out`. Run it to play the game.

Open a GitHub issue on this repository if this install instruction doesn't work for you.

## macOS

Instructions for macOS coming soon.
