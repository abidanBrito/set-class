[![Build Status](https://travis-ci.org/abidanBrito/Set-Class.svg?branch=master)](https://travis-ci.org/abidanBrito/Set-Class)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/52581286a76540a7b67cf4dcd7476673)](https://www.codacy.com/manual/abidanBrito/Set-Class?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=abidanBrito/Set-Class&amp;utm_campaign=Badge_Grade)

A rather basic set class in C++17, originally written for a school assignment.
There are two separate implementations. One uses a static array, while the 
other relies on a vector container for optimized memory usage and ease-of-use. 
However, they are completely interchangeable, as they share member function 
signatures.  

## FEATURES
### Implemented
*   [x] Set creation / deletion.
*   [x] Add elements.
*   [x] Delete elements.
*   [x] Empty a set.
*   [x] Get the size.
*   [x] Check for an element.
*   [x] Check for a subset.
*   [x] Check for a proper subset.
*   [x] Complement of a set, given a universal set.
*   [x] Union of two sets.
*   [x] Arithmetic mean of a set.
*   [x] Sort elements of a set.
*   [x] Print out a set.

### To Do
*   [ ] Difference of two sets.
*   [ ] Reverse difference of two sets.
*   [ ] Symmetric difference of two sets.
*   [ ] Intersection of two sets.
*   [ ] Cartesian product of two sets.
*   [ ] Mutable universal set.

## USAGE
Add `SetArray.h` and `SetArray.cpp`, or `SetVector.h` and `SetVector.cpp` 
to your codebase of choice. Make sure to include the right header file for your needs: 

```cpp
#include "SetArray.h"
``` 
```cpp
#include "SetVector.h"
``` 

## COMPILATION
I have written two source files to try out the class: `mainTests.cpp` and 
`mainTestsEspecific.cpp`. If you feel inclined to compile them, make sure to 
comment / uncomment the following line at the top, to switch between implementations.

``` cpp
#define VECTOR
```
Feel free to use the provided `makefile` or `code/build.bat` (if you're on Windows). If you wish to compile it on your own, make sure to configure the compiler toolchain for C++17.
