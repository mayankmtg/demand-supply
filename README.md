# Clover Ventures
## Demand Supply Problem

## Running the solution
Ensure g++ is installed.
Code is shipped with Makefile to handle compiling and linking


```
mkdir build/
mkdir bin/
make clean
make
./bin/runner < sample/input.txt
```

Note: Any input file should have an empty line in the end for the code to work
Also: The program is accepting input from stdin; empty line terminates input

## Generating random test files

```
cd sample
python gen.py > filename.txt
```

Note: The test files generated are only for the demand supply logic; produce and time are fixed

## Navigating through the code

### src
- main.cpp/h: The program execution start here
- domain.cpp/h: This contains the domain logic (brain) for the application
- order.cpp/h: The order struct class for the orders (supply/demand) and necessary functions
- transaction.cpp/h: The transaction struct class to contains the mapping between a supply and demand order
- string_utils.cpp/h: General string processing/helper functions

### bin

This directory contains the executable binary for code execution

### sample

This directory contains the sample input files