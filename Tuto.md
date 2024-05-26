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
- Instead of manual input/output you can use filed `[executable_name] <[infile]> [outfile]`

## Class
member functio <> method

# Variables and BAsic Types

## Primitie Built-in Types
- arithmetic types: `bool`, `char`, `wchar_y`, `char16_t`, `char32_t`, `short`, `int`, `long`, `long long`, `float`, `double`, `long double`
- `void`
- `short`, `int`, `long` , `long long` are signed and can be unsigned (e.g. `unsigned int`)
- in practice 
1. use `unsigned` if >0
2. use `int` or `long long` for integers
3. Use `double` for floating pount computaions. `long double` is slow.


C++ is a `statically type language, the compiler `type checks`.
## Memory 
- bit: 0 or 1
- byte: smallest chunk of adressable memory. in C++ a byte has at leat as many bits as are needed to hold a character. (8bits)
- word: the basic unit of storage (32 or 64 bits)
- adress: number mapped to a byte

## Declaration vs Definition 
- a `declaration` makes a name know to the program e.g. `extern int i;`.
- a `definition` creates the associated entity e.g. `int i;`. If a declatation assigns a value it is a definition,.

## Reference - lvalue reference 

It defines an alternative name fr an object. A reference type refers to another type. It must be intialized, cannot be bound to another object. References are aliases not objects.
```cpp
int ival = 42;
int &refVal = ival; // refVal refers to ival
refVal = 0; // we assign a new value to ival
```
used in an expression `&` is called the `adress-of operator`.
## Pointer
A pointer is an object which points to another tyope. Doesn't need to be initialized and can be re-assigned. It holds the adress of another object.
```cpp
int ival = 42;
int *p = &ival; // p holds the adress of ival, p is a pointer to ival 
std::cout << p << std::endl; //yields the adress of the object 
std::cout << *p << std::endl; //yields the object 
*p = 0; // we assign a new value to ival
p = nullptr; // same than 0, null pointer, cannot assign a in to a pointer
void *pv = 0; // pv can hold a pointer of any type, it cannot operate on the object it addresses
```
used in an expression `*` is called the `dereference operator`.

## Preprocessor 

is a program that runs before the compiler. It remplaces the preprocessor variable (e.g. `NULL`) to its values.

## Constant 
To share a const object among multiple files, you must define the variable as `extern`
```cpp
// in file 1
extern const int nameConst = 42;
// in file 2
extern cost in nameConst; 
```