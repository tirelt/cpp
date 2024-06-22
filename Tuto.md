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

