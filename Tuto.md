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

## `constexp`

is an expression whose value cannot change and that can be evaluated at compile time.

## Type Aliases 

```cpp
typedef double wages; //wages is a synony for double
using wages = double; //same
```

## 
In main cfile:
```cpp
#include "Sales_data.h"
```
In `Sales_data.h`:
we need to use `header guards`, not to import many times the same stuff. For that we use `preprocessor variable`.
```cpp
#ifndef SALES_DATA_H //#ifdef 
#define SALES_DATA_H
#include <string>
struct Sales_data {
std::string bookNo;
unsigned units_sold = 0;
double revenue = 0.0;
};
#endif
```

## Namespace `using` Declarations
To stop specifying `std::`
```cpp
using std::cin;
using std::cout;
using std::endl;
```