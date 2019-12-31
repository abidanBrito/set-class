/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetArray.h
    DATE:           23/12/2019
    STATE:          DONE
    FUNCTIONALITY:  Set class definition (array implementation).
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

// TODO(abi): Add extra functionalities, such as intersection, difference,
// symmetric difference, etc.

#ifndef SETARRAY_H
#define SETARRAY_H

#include <optional>     // Required for std::optional and std::nullopt

#define MAX_SET_LENGTH 50

// ---------------------------------------------------
// Set class definition
// ---------------------------------------------------
class Set {
private:
    double elements[MAX_SET_LENGTH];
    unsigned int size;

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
