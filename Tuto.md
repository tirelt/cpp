# Get Started

Install compiler and check version. On linuc GNU is generally ionstalled 

```Bash
g++ --version
```

c.f. [VS Code guide](https://code.visualstudio.com/docs/languages/cpp)

# Run your first program

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
# Input/Output (IO) standard library

