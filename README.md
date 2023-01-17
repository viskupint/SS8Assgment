# SS8Assgment
1. SS8 Assignment

The assignment is as follows:

 Write a program simulating a "cd" Unix command that changes a current directory in a file system. The simulated command takes two path strings from the command line and prints either a new path or an error.
The first path is a current directory. The second path is a new directory.  To make it simple let's assume that a directory name can only contain alphanumeric characters. A single dot (".") indicates a current directory, and the two dots ("..") indicate a step to a previous directory, up from the current one. A single forward slash "/" indicates a root directory. Multiple consecutive slashes are treated as equivalent to one.
The program needs to check that the new directory path is valid without relying on any OS call or shell command for verification, to construct a new path, and print it out. This is a pure string manipulation exercise.

Examples ('#' is a shell prompt in Unix):
 
# mycd / abc
/abc
# mycd /abc/def ghi
/abc/def/ghi
# mycd /abc/def ..
/abc
# mycd /abc/def /abc
/abc
# mycd /abc/def /abc/klm
/abc/klm
# mycd /abc/def ../..
/
# mycd /abc/def ../../..
/
# mycd /abc/def .
/abc/def
# mycd /abc/def ..klm
..klm: No such file or directory
# mycd /abc/def //////
/
# mycd /abc/def ......
......: No such file or directory
# mycd /abc/def ../gh///../klm/.
/abc/klm

2.System Requirements

  a.) Ubuntu Linux
  
  b.) c++ 14
  
  c.) cmake
  
  d.) Git
  
  e.) GTest
  
  
3. Download the code from https://github.com/viskupint/SS8Assgment

4. Edit the CMakeLists.txt from cpp folder and ensure the all path are correct based on environment setup to run the application without error.

5. Build (Note: rmove the CMakeCache.txt file before start building the application)

    a. cmake ..
    
    b. make
    
6. Run the application

    a. ./cmdLine mycd /abc/def/ klm
    
7. Run unit testing

    a. Add/edit the test cases in cpp/test/tests.cpp folder
    
    b. ./TestCmdLine
    
