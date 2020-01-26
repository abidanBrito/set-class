/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetVector.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  File containing all member function definitions for
                    the set class (vector implementation).
    ------------------------------------------------------------------------
    NOTICE: Copyright (c) 2020 Abidán Brito Clavijo.
    ------------------------------------------------------------------------ */

#include <iostream>    // Required for std::cout and std::endl.
#include <iomanip>     // Required for std::setprecision().
#include <utility>     // Required for std::swap().
#include "SetVector.h" // Set class (vector).

//// MEMBER FUNCTIONS - DEFINITIONS ////
// ----------------------------------------
// Set -> size() -> N
// ----------------------------------------
unsigned int Set::size() const {
    return elements.size();
}

// ----------------------------------------
// Set, R -> add() -> Set
// ----------------------------------------
void Set::add(double const newElement) {
    if (!within(newElement)) {
        elements.emplace_back(newElement);
    }
}

// ----------------------------------------
// Set, R -> at() -> N (optional)
// ----------------------------------------
std::optional <unsigned int> Set::at(double const element) {
    for (unsigned int i  = 0; i < elements.size(); ++i) {
        if (elements[i] == element) {
            return i;
        }
    }

    return std::nullopt;    // Element not found
}

// ----------------------------------------
// Set, R -> remove() -> Set
// ----------------------------------------
void Set::remove(double const element) {
    std::optional <unsigned int> index = at(element);

    if (index) {
        elements.erase(elements.begin() + *index);
    }
}

// ----------------------------------------
// Set -> empty() -> Set
// ----------------------------------------
void Set::empty() {
    this->elements.clear();
}

// ----------------------------------------
// Set, R -> within() -> T/F
// ----------------------------------------
bool Set::within(double const element) const {
    // Non-empty set
    for (unsigned int i = 0; i < elements.size(); ++i) {
        if (elements[i] == element) {
            return true;
        }
    }

    return false;
}

// ----------------------------------------
// Set, Set -> join() -> Set
// ----------------------------------------
Set Set::join(Set const & anotherSet) const {
    // anotherSet is empty
    if (anotherSet.elements.empty()) {
        return (*this);
    }

    // (*this) is empty
    if (elements.empty()) {
        return anotherSet;
    }

    // Concatenate sets
    Set superSet;
    for (unsigned int i = 0; i < elements.size(); ++i) {
        superSet.add(elements[i]);
    }
    for (unsigned int i = 0; i < anotherSet.elements.size(); ++i) {
        superSet.add(anotherSet.elements[i]);
    }

    return superSet;
}

// ----------------------------------------
// Set -> sort() -> Set
// ----------------------------------------
void Set::sort() {
    if (elements.empty()) {
        std::cout << "The set is empty, no need to sort!";
        return;
    }

    for (unsigned int i = 0; i < (elements.size() - 1); ++i) {
        // Last i elements already in place
        for (unsigned int j = 0; j < (elements.size() - i - 1); ++j) {
            if (elements[j] > elements[j+1])
                std::swap(elements[j], elements[j+1]);
        }
    }
}

// ----------------------------------------
// Set -> print() ->
// ----------------------------------------
void Set::print() const {
    if (elements.empty()) {
        std::cout << "The set is empty!";
        return;
    }

    for (unsigned int i = 0; i < (elements.size() - 1); ++i) {
        std::cout << elements[i] << ", ";
    }
    std::cout << std::setprecision(4) << elements[elements.size() - 1];
    std::cout << std::endl;
}

// ----------------------------------------
// Set -> meanValue() -> R (optional)
// ----------------------------------------
std::optional <double> Set::meanValue() const {
    if (elements.empty()) {
        return 0.0;    // Empty set
    }

    double sum = 0.0;
    for (unsigned int i = 0; i < elements.size(); ++i) {
        sum += elements[i];
    }

    double meanValue = sum / elements.size();

    return meanValue;
}

// ----------------------------------------
// Set, Set -> isSubset() -> T/F
// ----------------------------------------
bool Set::isSubset(Set const & referenceSet) const {
    // NOTE(abi): Empty set is a subset of any set.
    for (unsigned int i = 0; i < elements.size(); ++i) {
        if (!referenceSet.within(elements[i])) {
            return false;
        }
    }

    return true;
}

// ----------------------------------------
// Set, Set -> isProperSubset() -> T/F
// ----------------------------------------
bool Set::isProperSubset(Set const & referenceSet) const {
    for (unsigned int i = 0; i < elements.size(); ++i) {
        if (!referenceSet.within(elements[i])) {
            return false;
        }
    }

    // Sets are equal.
    // NOTE(abi): A set is not a proper subset of itself.
    if (elements.size() == referenceSet.elements.size()) {
        return false;
    }

    return true;
}

// ----------------------------------------
// Set, Set -> complement() -> Set
// ----------------------------------------
Set Set::complement(Set const & universalSet) const {
    // NOTE(abi): Complement of an empty set is the universal set.
    if (elements.empty()) {
        return universalSet;
    }

    Set complementSet;
    for (unsigned int i = 0; i < universalSet.elements.size(); ++i) {
        if (!within(universalSet.elements[i])) {
            complementSet.elements[i];
        }
    }

    return complementSet;
}
