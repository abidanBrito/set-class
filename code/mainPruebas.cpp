/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           mainPruebas.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  Automated testing for the set class implementations.
                    One uses a static array, the other a vector container.
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

// ------------------------------------------------------------------------------------------------------------------------------
// IMPORTANT(abi): Make sure to configure the toolchain to use c++17.
//
// ARRAY IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasArray.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebas.cpp
//
// VECTOR IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasVector.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebas.cpp
// ------------------------------------------------------------------------------------------------------------------------------

// NOTE(abi): Un/comment the line below to switch between implementations.
#define VECTOR_SET

#include <iostream>             // Required for std::cout and std::endl
#include <cstdlib>              // Required for rand()
#include <cmath>                // Required for floor()

#ifdef VECTOR_SET
#   include "ConjuntoVector.h"  // Set class (vector)
#else
#   include "ConjuntoArray.h"   // Set class (array)
#endif

//// FUNCTION PROTOTYPES ////
double randomFloat(double a, double b);
void addSeveralElements(Conjunto& set, const unsigned int setSize);
void pruebaTalla(const unsigned int setSize, unsigned int* testCounter);
void pruebaContiene(bool isEmpty, unsigned int* testCounter);
void pruebaAnyadir(unsigned int* testCounter);
void pruebaEliminar(unsigned int* testCounter);
void pruebaVaciar(const unsigned int setSize, unsigned int* testCounter);
void pruebaUnir(unsigned int* testCounter);
void runTests();

//// PROGRAM EXECUTION ////
int main() {
    std::cout << "----------------------------------------\n";
#ifdef VECTOR_SET
    std::cout << "** AUTOMATED TESTS - VECTOR SET CLASS **\n";
#else
    std::cout << "** AUTOMATED TESTS -- ARRAY SET CLASS **\n";
#endif
    std::cout << "----------------------------------------\n\n";

    // Automated testing
    runTests();

    return 0;
}

//// FUNCTION DEFINITIONS ////
void pruebaTalla(const unsigned int setSize, unsigned int* testCounter) {
    Conjunto set;

    // Add elements (if necessary)
    addSeveralElements(set, setSize);

    // Get set size
    const unsigned int numElements = set.talla();
    (*testCounter)++;

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
    if(numElements != setSize) {
        std::cout << "failed!\n";
        return;
    }
    std::cout << "passed!\n";
}

void pruebaContiene(bool isEmpty, unsigned int* testCounter) {
    Conjunto set;

    // Generate a new random element
    const double n = randomFloat(-50.0, 50.0);

    // Add element to the set if isEmpty is true
    if(!isEmpty) {
        set.anyadir(n);
    }

    // Check for n within the set
    bool isContained = set.contiene(n);
    (*testCounter)++;

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
    if ((!isContained && !isEmpty) || (isContained && isEmpty)) {
        std::cout << "failed!\n";
        return;
    }
    std::cout << "passed!\n";
}

void pruebaAnyadir(unsigned int* testCounter) {
    Conjunto set;

    // Add a new random element
    const double n = randomFloat(-50.0, 50.0);
    set.anyadir(n);
    (*testCounter)++;

    // Check for n within the set
    bool isContained = set.contiene(n);

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if (isContained){
        std::cout << "passed!\n";
        return;
	}
    std::cout << "failed!\n";
}

void pruebaEliminar(unsigned int* testCounter) {
    Conjunto set;

    // Add a new random element
    const double n = randomFloat(-50.0, 50.0);
    set.anyadir(n);

    // Delete the element
    set.eliminar(n);
    (*testCounter)++;

    // Check for n within the set and get set size
    bool isContained = set.contiene(n);
    unsigned int numElements = set.talla();

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if (!isContained && numElements == 0){
        std::cout << "passed!\n";
        return;
	}
    std::cout << "failed!\n";
}

void pruebaVaciar(const unsigned int setSize, unsigned int* testCounter) {
    Conjunto set;

    // Add several elements (if necessary)
    addSeveralElements(set, setSize);

    // Empty the set
    set.vaciar();
    (*testCounter)++;

    // Get set size
    const unsigned int numElements = set.talla();

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if(numElements > 0) {
        std::cout << "failed!\n";
        return;
	}
    std::cout << "passed!\n";
}

void pruebaUnir(unsigned int* testCounter) {
    Conjunto set1, set2, superSet;

    // Generate a couple of common numbers
    // Different ranges to avoid the slim chance of generating the same number
    const double commonNum1 = randomFloat(-15.0, 0.0); // [-15, 0)
    const double commonNum2 = randomFloat(0.0, 15.0);  // [0, 15)

    // Fill in sets
    set1.anyadir(commonNum1);
    set1.anyadir(commonNum2);
    set1.anyadir(18.5);

    set2.anyadir(commonNum1);
    set2.anyadir(commonNum2);
    set2.anyadir(-18.5);

    unsigned int superSetElements = 4;

    // Concatenate set1 and set2
    superSet = set1.unir(set2);
    (*testCounter)++;

    // Get superSet size via talla()
    const unsigned int superSetSize = superSet.talla();

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
    if (superSetSize == superSetElements) {
        std::cout << "passed!\n";
        return;
	}
    std::cout << "failed!\n";
}

double randomFloat(double a, double b) {
    return ((double)rand() / RAND_MAX) * (b - a) + a;
}

void addSeveralElements(Conjunto& set, const unsigned int setSize) {
    // Add elements (if necessary)
    if(setSize > 0) {
        for(unsigned int i = 0; i < setSize; i++) {
            double n = randomFloat(-50.0, 50.0);
            set.anyadir(n);
        }
    }
}

void runTests() {
    unsigned int testCounter = 0;

    // talla()
    std::cout << "-> talla()" << std::endl;
    pruebaTalla(0, &testCounter);
    pruebaTalla(7, &testCounter);
    pruebaTalla(15, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // contiene()
    std::cout << "-> contiene()" << std::endl;
    pruebaContiene(true, &testCounter);
    pruebaContiene(false, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // anyadir()
    std::cout << "-> anyadir()" << std::endl;
    pruebaAnyadir(&testCounter);
    pruebaAnyadir(&testCounter);
    pruebaAnyadir(&testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // eliminar()
    std::cout << "-> eliminar()" << std::endl;
    pruebaEliminar(&testCounter);
    pruebaEliminar(&testCounter);
    pruebaEliminar(&testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // vaciar()
    std::cout << "-> vaciar()" << std::endl;
    pruebaVaciar(0, &testCounter);
    pruebaVaciar(5, &testCounter);
    pruebaVaciar(15, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // unir()
    std::cout << "-> unir()" << std::endl;
    pruebaUnir(&testCounter);
    pruebaUnir(&testCounter);
    pruebaUnir(&testCounter);
    std::cout << std::endl;
}
