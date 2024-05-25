# Prequisites 

OS: Raspbian GNU/Linux
(cat /etc/os-release)

Install compiler and check version. On linuc GNU is generally ionstalled 

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
To execute 
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
## Input/Output (IO) standard library: iostream

Two type `istream` for inputs and `ostram` for outputs. The library define 4 OI objects:
- `cin`: standard input
- `cout`: standard output
- `cerr`: standard error
- `clog`: general information about the execution of the progrom

We manupule then with operators (than can be chained):
- `<<` output operator. left (ostream) becomes right and return left
- `>>` input operator. right (istream) become left and return left

and manipulators:
- `std::endl`: to flush the buffer and make sure that all the ouput is actually written to the ouput stream and not sitting in memory.


To import:
```cpp
#include <iostream>
```
The name between brackets is refered as a header, we include them at the start of the program.
The `std` when calling the object of `iostream` is the `namespace`.

## Comments
- `//` 1 line comment
- `/*` & `*/` mutli lines comment

## User input 

- end of file is `control-d` on UNIX (`control-z` on windows)
