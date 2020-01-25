/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetVector.h
    DATE:           20/01/2020
    STATE:          DONE
    FUNCTIONALITY:  Set class definition (vector implementation).
    ------------------------------------------------------------------------
    NOTICE: Copyright (c) 2020 Abidán Brito Clavijo.
    ------------------------------------------------------------------------ */

// TODO(abi): Add extra functionalities, such as intersection, difference,
// symmetric difference, etc.

#ifndef SETVECTOR_H
#define SETVECTOR_H

#include <optional>     // Required for std::optional and std::nullopt.
#include <vector>       // Required for std::vector.

// ---------------------------------------------------
// Set class definition.
// ---------------------------------------------------
class Set {
private:
    std::vector<double> elements;

// MEMBER FUNCTIONS - DECLARATIONS
private:
    std::optional <unsigned int> at(double); // Returns index of a given element.
    void swap(double *num1, double *num2);   // Swaps two given numbers (elements).

public:
    Set();                                          // Default constructor.
    unsigned int size() const;                      // Returns size of the set.
    void add(double element);                       // Adds a given element.
    Set join(const Set& anotherSet) const;          // Concatenates two sets.
    void remove(double element);                    // Deletes a given element.
    void empty();                                   // Empties the set.
    bool within(double element) const;              // Checks for a given element.
    bool isSubset(const Set& anotherSet) const;     // Checks for a given subset.
    std::optional <double> meanValue() const;       // Returns the average.
    void print() const;                             // Prints the set.
    void sort();                                    // Sorts using bubbleSort algorithm.
};

#endif
