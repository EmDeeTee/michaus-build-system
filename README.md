# iterkocze-build-system
C/C++ Build system, but Iterkocze

 # Usage
 In your C/C++ project directory, create a file named `mbs`.
 Example mbs file:
 ```
FILES = main.c,main.h
COMPILER = gcc
FLAGS = -s,-O2
 ```
 
 Run iterkocze-build-system binary in the same folder as you mbs file 
 
 # Building
 CMake can be used to compile MBS. But it can also be compiled using itself
