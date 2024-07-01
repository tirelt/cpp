# Prequisites 

OS: Raspbian GNU/Linux

Install compiler and check version. On linux GNU is generally installed by default, to check:

```Bash
g++ --version
```

c.f. [VS Code guide](https://code.visualstudio.com/docs/languages/cpp)

# Getting Started

## Run your first program

To compile from a console
```Bash
g++ [file_name]
```
UNIX compilers tend to put their executables in files named a.out.
To execute:
```Bash
./a.out #./[executable_name]
```
To obtain the status:
```Bash
echo $?
```
If you want to specify the name of the executable directly 

```Bash
g++ -o [executable_name] [source_name]
```

Run program with arguments e.g.
```cpp
int main(int argc, char **argv) { ... }
```
run 
```bash
/[executable_name] [arg_1] [arg_2] ...
```
Example:
```bsah
prog -d -o ofile data0
```
`argc=5`,  `argv[0] = "prog"`,..., `argv[4] = "data0"`, `argv[5] = 0`

### Separate compilation 

To compile from a console multiple files
```Bash
g++ [file_name_1] [file_name_2] ... -o [executable_name]
```
If we change just one file it might be preferable to recompile only this file.  We can seperatly compile files using 
```Bash
g++ -c [file_name] 
```
It genereates an object file (`.o` estension). Then we can combine object code with 
```Bash
g++ [obj_file_1] [obj_file_2 ] ... -o [executable_name]
```

## User input 

- end of file is `control-d` on UNIX (`control-z` on windows)
- Instead of manual input/output you can use filed `[executable_name] <[infile]> [outfile]`

# Makefile

For large project it is often prefereble to use a tool to help us compile. The industry standard is [CMake](https://cmake.org/) which is cross plateform. It doesn't actually compile. Instead it calls `Makefile` to do the heavy lifting [c.f.](https://earthly.dev/blog/cmake-vs-make-diff/#:~:text=In%20summary%3A%20The%20difference%20between,used%20to%20create%20a%20Makefile).

We created an interesting example of project using `Makefile` in `testing/makefile`. It shows how to use libraries, to only re-compile modified source or hearder files and to link everything together.

- [source material](https://opensource.com/article/18/8/what-how-makefile)
- [how to use libraries example](https://stackoverflow.com/questions/10358745/how-to-use-libraries)


# Debug



# Useful doc

## Structure project:

https://medium.com/swlh/c-project-structure-for-cmake-67d60135f6f5

https://slaptijack.com/programming/project-structure-for-cpp.html

 

## CMAKE:

https://code.visualstudio.com/docs/cpp/CMake-linux

https://cmake.org/

https://cliutils.gitlab.io/modern-cmake/

 

## How to use libraries:

https://stackoverflow.com/questions/10358745/how-to-use-libraries

https://cplusplus.com/forum/beginner/269130/

https://stackoverflow.com/questions/30064686/making-and-compiling-c-projects-with-multiple-files

https://stackoverflow.com/questions/74742297/linking-external-libraries-in-c-in-visual-studio-code

 

## g++

https://man7.org/linux/man-pages/man1/g++.1.html

https://stackoverflow.com/questions/33662375/how-can-you-compile-all-cpp-files-in-a-directory

## Makefile

https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
https://earthly.dev/blog/cmake-vs-make-diff/#:~:text=In%20summary%3A%20The%20difference%20between,used%20to%20create%20a%20Makefile.
https://opensource.com/article/18/8/what-how-makefile
