/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetVector.h
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  Set class definition (vector implementation).
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

// TODO(abi): Add extra functionalities, such as intersection, difference,
// symmetric difference, etc.

#ifndef SETVECTOR_H
#define SETVECTOR_H

#include <optional>     // Required for std::optional and std::nullopt
#include <vector>       // Required for std::vector

// ---------------------------------------------------
// Set class definition
// ---------------------------------------------------
class Set {
private:
    std::vector<double> elements;

// MEMBER FUNCTIONS - DECLARATIONS
private:
    std::optional <unsigned int> at(double); // Returns index of a given element
    void swap(double *num1, double *num2);   // Swaps two given numbers (elements)

public:
    Set();                                   // Default constructor
    unsigned int size() const;               // Returns size of the set
    void add(double element);                // Adds a given element
    bool within(double element) const;       // Checks for a given element
    Set join(const Set& anotherSet) const;   // Concatenates two sets
    void remove(double element);             // Deletes a given element
    void empty();                            // Empties the set
    void print() const;                      // Prints the set
    void sort();                             // Sorts using bubbleSort algorithm
};

#endif
