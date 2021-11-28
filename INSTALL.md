# How to Install

Here is how you install this game.

## Windows

Here is what you do on Windows.

First, clone this repository by running

```bash
git clone https://github.com/Hello56721/wars --recursive
```

The recursive flag is neccessary to make sure that the dependencies are cloned properly.

Then, first install the following softwares:

- [CMake](https://www.cmake.org). Make sure that you added it to PATH.
- [Microsoft Visual Studio for C/C++](https://visualstudio.microsoft.com/downloads/)

Then, simply double click on `setup.bat` to build the project. If you are running it from the terminal make sure that it's CWD is the project root, because otherwise it won't work.

This will create a folder called `bin` in the project root directory. Inside the `bin` directory, you will find a file called `wars.exe`. Run this file to play the game.

Open a GitHub issue on this repository if this install instruction doesn't work for you.

## Linux

Here is what you do on Linux.

First, clone this repository by running

```bash
git clone https://github.com/Hello56721/wars --recursive
```

You can ommit the `--recursive` flag if you decided to use your distribution's GLFW package instead of the one I added as a submodule.

Then, first install the following softwares:

- [CMake](https://www.cmake.org). Make sure that you added it to PATH.
- A C/C++ compiler of your choice.
- A build system of your choice.
- GLFW 3.3 development files (Optional. Only needed if you would like to use your distribution's version of GLFW rather than the one I added as a submodule).

After those are all installed on your Linux system (you know how to do that if you know how to use Linux, right?) simply run

```bash
./setup.sh
```

in the root directory of the wars repository you have cloned. This will produce a file called `wars.out` in a directory called `bin`. Run it to play the game.

Open a GitHub issue on this repository if this install instruction doesn't work for you.

## macOS

macOS is currently not supported. Feel free to add a pull request or open an issue.
