/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           mainTests.cpp
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
// g++ -std=c++17 -Wall -Wextra -pedantic -o testsArray.exe ..\code\SetArray.cpp ..\code\mainTests.cpp
//
// VECTOR IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o testsVector.exe ..\code\SetVector.cpp ..\code\mainTests.cpp
// ------------------------------------------------------------------------------------------------------------------------------

// NOTE(abi): Un/comment the line below to switch between implementations.
#define VECTOR_SET

#include <iostream>       // Required for std::cout and std::endl
#include <cstdlib>        // Required for rand()
#include <cmath>          // Required for floor()

#ifdef VECTOR_SET
#   include "SetVector.h" // Set class (vector)
#else
#   include "SetArray.h"  // Set class (array)
#endif

//// FUNCTION PROTOTYPES ////
double randomFloat(double a, double b);
void addSeveralElements(Set& set, const unsigned int setSize);
void testSize(const unsigned int setSize, unsigned int* testCounter);
void testWithin(bool isEmpty, unsigned int* testCounter);
void testAdd(unsigned int* testCounter);
void testRemove(unsigned int* testCounter);
void testEmpty(const unsigned int setSize, unsigned int* testCounter);
void testJoin(unsigned int* testCounter);
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
void testSize(const unsigned int setSize, unsigned int* testCounter) {
    Set set;

    // Add elements (if necessary)
    addSeveralElements(set, setSize);

    // Get set size
    const unsigned int numElements = set.size();
    (*testCounter)++;

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
    if(numElements != setSize) {
        std::cout << "failed!\n";
        return;
    }
    std::cout << "passed!\n";
}

void testWithin(bool isEmpty, unsigned int* testCounter) {
    Set set;

    // Generate a new random element
    const double n = randomFloat(-50.0, 50.0);

    // Add element to the set if isEmpty is true
    if(!isEmpty) {
        set.add(n);
    }

    // Check for n within the set
    bool isContained = set.within(n);
    (*testCounter)++;

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
    if ((!isContained && !isEmpty) || (isContained && isEmpty)) {
        std::cout << "failed!\n";
        return;
    }
    std::cout << "passed!\n";
}

void testAdd(unsigned int* testCounter) {
    Set set;

    // Add a new random element
    const double n = randomFloat(-50.0, 50.0);
    set.add(n);
    (*testCounter)++;

    // Check for n within the set
    bool isContained = set.within(n);

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if (isContained){
        std::cout << "passed!\n";
        return;
	}
    std::cout << "failed!\n";
}

void testRemove(unsigned int* testCounter) {
    Set set;

    // Add a new random element
    const double n = randomFloat(-50.0, 50.0);
    set.add(n);

    // Delete the element
    set.remove(n);
    (*testCounter)++;

    // Check for n within the set and get set size
    bool isContained = set.within(n);
    unsigned int numElements = set.size();

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if (!isContained && numElements == 0){
        std::cout << "passed!\n";
        return;
	}
    std::cout << "failed!\n";
}

void testEmpty(const unsigned int setSize, unsigned int* testCounter) {
	Set set;

    // Add several elements (if necessary)
    addSeveralElements(set, setSize);

    // Empty the set
	set.empty();
    (*testCounter)++;

    // Get set size
    const unsigned int numElements = set.size();

    // Print out test status
    std::cout << "TEST " << *testCounter << ": ";
	if(numElements > 0) {
        std::cout << "failed!\n";
        return;
	}
    std::cout << "passed!\n";
}

void testJoin(unsigned int* testCounter) {
	Set set1, set2, superSet;

    // Generate a couple of common numbers
    // Different ranges to avoid the slim chance of generating the same number
    const double commonNum1 = randomFloat(-15.0, 0.0); // [-15, 0)
    const double commonNum2 = randomFloat(0.0, 15.0);  // [0, 15)

    // Fill in sets
    set1.add(commonNum1);
    set1.add(commonNum2);
    set1.add(18.5);

    set2.add(commonNum1);
    set2.add(commonNum2);
    set2.add(-18.5);

    unsigned int superSetElements = 4;

    // Concatenate set1 and set2
	superSet = set1.join(set2);
    (*testCounter)++;

    // Get superSet size via size()
    const unsigned int superSetSize = superSet.size();

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

void addSeveralElements(Set& set, const unsigned int setSize) {
    // Add elements (if necessary)
    if(setSize > 0) {
        for(unsigned int i = 0; i < setSize; i++) {
            double n = randomFloat(-50.0, 50.0);
            set.add(n);
        }
    }
}

void runTests() {
    unsigned int testCounter = 0;

    // size()
    std::cout << "-> size()" << std::endl;
    testSize(0, &testCounter);
    testSize(7, &testCounter);
    testSize(15, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // within()
    std::cout << "-> within()" << std::endl;
    testWithin(true, &testCounter);
    testWithin(false, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // add()
    std::cout << "-> add()" << std::endl;
    testAdd(&testCounter);
    testAdd(&testCounter);
    testAdd(&testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // remove()
    std::cout << "-> remove()" << std::endl;
    testRemove(&testCounter);
    testRemove(&testCounter);
    testRemove(&testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // empty()
    std::cout << "-> empty()" << std::endl;
    testEmpty(0, &testCounter);
    testEmpty(5, &testCounter);
    testEmpty(15, &testCounter);
    testCounter = 0;
    std::cout << std::endl;

    // join()
    std::cout << "-> join()" << std::endl;
    testJoin(&testCounter);
    testJoin(&testCounter);
    testJoin(&testCounter);
    std::cout << std::endl;
}
