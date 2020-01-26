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
    std::optional <unsigned int> at(double);             // Returns index of a given element.

public:
    unsigned int size() const;                           // Returns size of the set.
    void add(double element);                            // Adds a given element.
    void remove(double element);                         // Deletes a given element.
    void empty();                                        // Empties the set.
    bool within(double element) const;                   // Checks for a given element.
    bool isSubset(Set const & referenceSet) const;       // Checks for a subset.
    bool isProperSubset(Set const & referenceSet) const; // Checks for a proper subset.
    Set join(Set const & anotherSet) const;              // Concatenates two sets.
    Set complement(Set const & universalSet) const;      // Complement, given a universal set.
    std::optional <double> meanValue() const;            // Returns the average.
    void print() const;                                  // Prints the set.
    void sort();                                         // Sorts using bubbleSort algorithm.
};

#endif
