[![Codacy Badge](https://api.codacy.com/project/badge/Grade/52581286a76540a7b67cf4dcd7476673)](https://www.codacy.com/manual/abidanBrito/Set-Class?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=abidanBrito/Set-Class&amp;utm_campaign=Badge_Grade)

A rather basic set class in C++17, originally written for a school assignment.
There are two separate implementations. One uses a static array, while the 
other relies on a vector container for optimized memory usage and ease-of-use. 
However, they are completely interchangeable, as they share member function 
signatures.  

## FEATURES
### Implemented
*   [x] Set creation.
*   [x] Add elements.
*   [x] Delete elements.
*   [x] Get the size.
*   [x] Check for an element.
*   [x] Sort elements.
*   [x] Union of two sets.
*   [x] Empty a set.
*   [x] Print out all elements.

### To Do
*   [ ] Complement of a set.
*   [ ] Intersection of two sets.
*   [ ] Difference of two sets.
*   [ ] Symmetric difference of two sets.

## USAGE
Add `Conjunto.h` and `Conjunto.cpp`, or `ConjuntoVector.h` and `ConjuntoVector.cpp` 
to your codebase of choice. Make sure to include the right header file for your needs: 

```cpp
#include "Conjunto.h"
``` 
```cpp
#include "ConjuntoVector.h"
``` 

## COMPILATION
I have written two source files to try out the class: `mainPruebas.cpp` and 
`mainPruebasEspecificas.cpp`. If you feel inclined to compile them, make sure to 
comment / uncomment the following line at the top, to switch between implementations.

``` cpp
#define VECTOR
```
Feel free to build using the provided `makefile` or `code/build.bat`, if you're on Windows. If you wish to compile it on your own, make sure to configure the compiler toolchain for C++17.

### Array implementation
`g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasArray.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebas.cpp`

`g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasArrayEspecificas.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebasEspecificas.cpp`

### Vector implementation
`g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasVector.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebas.cpp`

`g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasVectorEspecificas.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebasEspecificas.cpp`
