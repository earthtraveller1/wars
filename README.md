# Wars

My implementation of Wars, a 2D game that was designed (but never implemented) by @meplaz. It uses OpenGL and is mainly written in C++. It is still in development, but you can try it out if you want by compiling it from source.

## Installing

I still haven't created any binaries yet, so for now, just compile from source. Clone or download the content of this repository and follow the instructions specific for your operating system.

### Windows

On Windows, first ensure that you have the following softwares installed on your computer:

- A working C/C++ compiler that supports at least C++17
- [CMake](https://cmake.org/)
- A build tool that is supported by CMake ([Visual Studio](https://visualstudio.microsoft.com/), [Make](https://www.gnu.org/software/make/), or [Ninja](https://ninja-build.org/)).

Once you have those installed, download [GLFW](https://www.glfw.org) and [compile it (GLFW, that is) from source](https://www.glfw.org/docs/latest/compile.html). Then, create a folder called "GLFW" (all capitalized) in the `deps` folder of this repository. Then, copy GLFW's `include` folder into this folder that you have just created. After that, create another folder called `libs` inside the `deps/GLFW` folder that you have created. Then, copy GLFW's binary (usually called `libglfw3.a` or `glfw3.lib` and usually found inside the `build/src` folder inside GLFW's root directory) into this folder that you have just created. Finally, go to this project's root directory and run `cmake -S . -B build`.

Go to the the `build` directory to find the `wars.exe` file. Double click on that file to run it.

### Linux

On Ubuntu (and other Debian based distributions?), just install the `build-essentials`, `cmake`, and `libglfw3-dev` packages, and run the `cmake -S . -B build` command at the project's root directory. It should be a similar process for other distributions. Note that if your distribution doesn't provide you with a CMake version newer than 3.13, then you would have to download it from [CMake's website](https://cmake.org/download/) yourself.

To play the game, run `cd build; ./wars` at the project's root directory.

### macOS

Currently, there is no official macOS support, since I do not have a Mac computer to test it on. For now, if you wanted to play this on a Mac, just try and compile it from source (tweak it if neccessary) and see if it works. Note that I am **not** responsible for any damage done to your computer from trying to compile and run my software(s) on unsupported systems.

## Gameplay

The game is still not finished yet, so for now it's just a main menu plus a player sprite that you can move around with the W and S keys for now, though this is likely going to change soon. Also, the "Other" button doesn't do anything yet.

## Final Words

That's all for this README file. If you have any questions or comments about this repository, leave it [here](https://github.com/Hello56721/wars/discussions/3). If you would like to submit a suggestion or a bug report, go [here](https://github.com/Hello56721/wars/issues). And that's about it. Oh, and by the way, my friend owns a [Discord](https://discord.com) server, which you can join [here](https://discord.gg/pYWpJXSgZt). Note that he can be a little rude when new people join.
