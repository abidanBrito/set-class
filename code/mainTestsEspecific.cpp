/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           mainTestsEspecific.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  Manual testing for the set class implementations.
                    One uses a static array, the other a vector container.
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

// ------------------------------------------------------------------------------------------------------------------------------
// IMPORTANT(abi): Make sure to configure the toolchain to use c++17.
//
// ARRAY IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o testsArrayEspecific.exe ..\code\SetArray.cpp ..\code\mainTestsEspecific.cpp
//
// VECTOR IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o testsVectorEspecific.exe ..\code\SetVector.cpp ..\code\mainTestsEspecific.cpp
// ------------------------------------------------------------------------------------------------------------------------------

// NOTE(abi): Un/comment the line below to switch between implementations.
#define VECTOR_SET

#include <iostream>       // Required for std::cout and std::endl

#ifdef VECTOR_SET
#   include "SetVector.h" // Set class (vector)
#else
#   include "SetArray.h"  // Set class (array)
#endif

//// FUNCTION PROTOTYPES ////
void printTitle();
void printTestHeader(const char* str);
void printIsWithin(const bool isWithin, const double number);
void printSetData(const Set& set);
void printSetSize(const Set& set);
void testRemove(Set& set);
void testAdd(Set& set);
void testWithin(const Set& set);
void testSort(Set& set);
void testJoin(const Set& set1, const Set& set2, Set& superSet);
void testEmpty(Set& set, unsigned int setNumber);

//// PROGRAM EXECUTION ////
int main() {
    printTitle();

    // Create a set
    Set set1;
    for(float i = 0.f; i <= 10.f; i += 0.5f) {
        set1.add(i);
    }
    printTestHeader("-> INITIAL SET");
    printSetData(set1);

    // Delete a couple elements
    testRemove(set1);

    // Add a couple elements
    testAdd(set1);

    // Check for a couple numbers
    testWithin(set1);

    // Sort set
    testSort(set1);

    // Create another set
    Set set2;
    for(float i = 10.5f; i <= 15.f; i += 0.5f) {
        set2.add(i);
    }
    printTestHeader("-> ANOTHER SET");
    printSetData(set2);

    // Concatenate sets
    Set superSet;
    testJoin(set1, set2, superSet);

    // Clear sets
    printTestHeader("-> CLEAR / EMPTY ALL SETS");
    testEmpty(set1, 1);
    testEmpty(set2, 2);
    testEmpty(superSet, 3);

    return 0;
}

void testRemove(Set& set) {
    printTestHeader("-> DELETE NUMBERS 2 AND 2.5 FROM THE SET");

    // Delete elements
    set.remove(2.0);
    set.remove(2.5);

    printSetData(set);
}

void testAdd(Set& set) {
    printTestHeader("-> ADD NUMBERS 15.28 AND -5.3 TO THE SET");

    // Add elements
    set.add(15.28);
    set.add(-5.3);

    printSetData(set);
}

void testWithin(const Set& set) {
    printTestHeader("-> CHECK FOR NUMBERS 15.28 AND -3.46");

    // Check for numbers as elements
    double number1 = 15.28;
    double number2 = -3.46;
    bool withinSet1 = set.within(number1);
    bool withinSet2 = set.within(number2);

    printIsWithin(withinSet1, number1);
    printIsWithin(withinSet2, number2);
    std::cout << std::endl;
}

void testSort(Set& set) {
    printTestHeader("-> SORT THE GIVEN SET");

    // Sort set
    set.sort();

    printSetData(set);
}

void testJoin(const Set& set1, const Set& set2, Set& superSet) {
    printTestHeader("-> CONCATENATE SETS TOGETHER");

    // Concatenation
    superSet = set1.join(set2);

    superSet.print();
    printSetSize(superSet);
    std::cout << std::endl;
}

void testEmpty(Set& set, unsigned int setNumber) {
    std::cout << "Set #" << setNumber << " - ";

    // Empty set
    set.empty();

    printSetSize(set);
}

void printTestHeader(const char* str) {
    std::cout << str;
    std::cout << std::endl;
}

void printIsWithin(const bool isWithin, const double number) {
    std::cout << "The number " << number;
    if(isWithin) {
        std::cout << " is within the set." << std::endl;
    }
    else {
        std::cout << " is not within the set." << std::endl;
    }
}

void printSetData(const Set& set) {
    set.print();
    printSetSize(set);
    std::cout << std::endl;
}

void printSetSize(const Set& set) {
    std::cout << "Number of elements = " << set.size() << std::endl;
}

void printTitle() {
    std::cout << "---------------------------------------\n";
#ifdef VECTOR_SET
    std::cout << "** SPECIFIC TESTS - VECTOR SET CLASS **\n";
#else
    std::cout << "** SPECIFIC TESTS -- ARRAY SET CLASS **\n";
#endif
    std::cout << "---------------------------------------\n\n";
}
