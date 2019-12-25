/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           ConjuntoArray.h
    DATE:           23/12/2019
    STATE:          DONE
    FUNCTIONALITY:  Set class definition (array implementation).
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

// TODO(abi): Add extra functionalities, such as intersection, difference,
// symmetric difference, etc.

#ifndef CONJUNTOARRAY_H
#define CONJUNTOARRAY_H

#include <optional>     // Required for std::optional and std::nullopt

#define MAX_SET_LENGHT 50

// ---------------------------------------------------
// Conjunto class definition
// ---------------------------------------------------
class Conjunto {
private:
    double elementos[MAX_SET_LENGHT];
    unsigned int size;

// MEMBER FUNCTIONS - DECLARATIONS
private:
    std::optional <unsigned int> donde(const double);  // Returns index of a given element
    void swap(double *num1, double *num2);             // Swaps two given numbers (elements)

public:
    Conjunto();                                        // Default constructor
    unsigned int talla() const;                        // Returns size of the set
    void anyadir(const double element);                // Adds a given element
    bool contiene(const double element) const;         // Checks for a given element
    Conjunto unir(const Conjunto& anotherSet) const;   // Concatenates two sets
    void eliminar(const double element);               // Deletes a given element
    void vaciar();                                     // Empties the set
    void print() const;                                // Prints the set
    void ordenar();                                    // Sorts using bubbleSort algorithm
};

#endif
