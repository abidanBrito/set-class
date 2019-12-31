/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           mainPruebasEspecificas.cpp
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
// g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasEspecificasArray.exe ..\code\ConjuntoArray.cpp ..\code\mainPruebasEspecificas.cpp
//
// VECTOR IMPLEMENTATION
// g++ -std=c++17 -Wall -Wextra -pedantic -o pruebasEspecificasVector.exe ..\code\ConjuntoVector.cpp ..\code\mainPruebasEspecificas.cpp
// ------------------------------------------------------------------------------------------------------------------------------

// NOTE(abi): Un/comment the line below to switch between implementations.
#define VECTOR_SET

#include <iostream>             // Required for std::cout and std::endl

#ifdef VECTOR_SET
#   include "ConjuntoVector.h"  // Set class (vector)
#else
#   include "ConjuntoArray.h"   // Set class (array)
#endif

//// FUNCTION PROTOTYPES ////
void printTitle();
void printTestHeader(const char* str);
void printIsWithin(const bool isWithin, const double number);
void printSetData(const Conjunto& set);
void printSetSize(const Conjunto& set);
void testEliminar(Conjunto& set);
void testAnyadir(Conjunto& set);
void testContiene(const Conjunto& set);
void testOrdenar(Conjunto& set);
void testUnir(const Conjunto& set1, const Conjunto& set2, Conjunto& superSet);
void testVaciar(Conjunto& set, unsigned int setNumber);

//// PROGRAM EXECUTION ////
int main() {
    printTitle();

    // Create a set
    Conjunto set1;
    for(float i = 0.f; i <= 10.f; i += 0.5f) {
        set1.anyadir(i);
    }
    printTestHeader("-> INITIAL SET");
    printSetData(set1);

    // Delete a couple elements
    testEliminar(set1);

    // Add a couple elements
    testAnyadir(set1);

    // Check for a couple numbers
    testContiene(set1);

    // Sort set
    testOrdenar(set1);

    // Create another set
    Conjunto set2;
    for(float i = 10.5f; i <= 15.f; i += 0.5f) {
        set2.anyadir(i);
    }
    printTestHeader("-> ANOTHER SET");
    printSetData(set2);

    // Concatenate sets
    Conjunto superSet;
    testUnir(set1, set2, superSet);

    // Clear sets
    printTestHeader("-> CLEAR / EMPTY ALL SETS");
    testVaciar(set1, 1);
    testVaciar(set2, 2);
    testVaciar(superSet, 3);

    return 0;
}

void testEliminar(Conjunto& set) {
    printTestHeader("-> DELETE NUMBERS 2 AND 2.5 FROM THE SET");

    // Delete elements
    set.eliminar(2.0);
    set.eliminar(2.5);

    printSetData(set);
}

void testAnyadir(Conjunto& set) {
    printTestHeader("-> ADD NUMBERS 15.28 AND -5.3 TO THE SET");

    // Add elements
    set.anyadir(15.28);
    set.anyadir(-5.3);

    printSetData(set);
}

void testContiene(const Conjunto& set) {
    printTestHeader("-> CHECK FOR NUMBERS 15.28 AND -3.46");

    // Check for numbers as elements
    double number1 = 15.28;
    double number2 = -3.46;
    bool withinSet1 = set.contiene(number1);
    bool withinSet2 = set.contiene(number2);

    printIsWithin(withinSet1, number1);
    printIsWithin(withinSet2, number2);
    std::cout << std::endl;
}

void testOrdenar(Conjunto& set) {
    printTestHeader("-> SORT THE GIVEN SET");

    // Sort set
    set.ordenar();

    printSetData(set);
}

void testUnir(const Conjunto& set1, const Conjunto& set2, Conjunto& superSet) {
    printTestHeader("-> CONCATENATE SETS TOGETHER");

    // Concatenation
    superSet = set1.unir(set2);

    superSet.print();
    printSetSize(superSet);

}

void testVaciar(Conjunto& set, unsigned int setNumber) {
    std::cout << "Set #" << setNumber << " - ";

    // Empty set
    set.vaciar();

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


void printSetData(const Conjunto& set) {
    set.print();
    printSetSize(set);
    std::cout << std::endl;
}

void printSetSize(const Conjunto& set) {
    std::cout << "Number of elements = " << set.talla() << std::endl;
    std::cout << std::endl;
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
