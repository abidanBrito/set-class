/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetVector.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  File containing all member functions definitions for
                    the set class (vector implementation).
    ------------------------------------------------------------------------
    NOTICE: Copyright (c) 2020 Abidán Brito Clavijo.
    ------------------------------------------------------------------------ */

#include <iostream>    // Required for std::cout and std::endl.
#include <iomanip>     // Required for std::setprecision().
#include "SetVector.h" // Set class (vector).

//// MEMBER FUNCTIONS - DEFINITIONS ////
// ----------------------------------------
// -> Set() -> Set
// ----------------------------------------
Set::Set()
{}

// ----------------------------------------
// Set -> size() -> N
// ----------------------------------------
unsigned int Set::size() const {
    return this->elements.size();
}

// ----------------------------------------
// Set, R -> add() -> Set
// ----------------------------------------
void Set::add(const double newElement) {
    if (!this->within(newElement)) {
        this->elements.emplace_back(newElement);
    }
}

// ----------------------------------------
// Set, R -> at() -> N (optional)
// ----------------------------------------
std::optional <unsigned int> Set::at(const double element) {
    for (unsigned int i  = 0; i < this->elements.size(); ++i) {
        if (this->elements[i] == element) {
            return i;
        }
    }

    return std::nullopt;    // Element not found
}

// ----------------------------------------
// Set, R -> remove() -> Set
// ----------------------------------------
void Set::remove(const double element) {
    std::optional <unsigned int> index = this->at(element);

    if (index) {
        this->elements.erase(this->elements.begin() + *index);
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
bool Set::within(const double element) const {
    // Non-empty set
    for (unsigned int i = 0; i < this->elements.size(); ++i) {
        if (this->elements[i] == element) {
            return true;
        }
    }

    return false;
}

// ----------------------------------------
// Set, Set -> join() -> Set
// ----------------------------------------
Set Set::join(const Set& anotherSet) const {
    // anotherSet is empty
    if (anotherSet.elements.empty()) {
        return (*this);
    }

    // (*this) is empty
    if (this->elements.empty()) {
        return anotherSet;
    }

    // Concatenate sets
    Set superSet;
    for (unsigned int i = 0; i < this->elements.size(); ++i) {
        superSet.add(this->elements[i]);
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
    if (this->elements.empty()) {
        std::cout << "The set is empty, no need to sort!";
        return;
    }

    for (unsigned int i = 0; i < (this->elements.size() - 1); ++i) {
        // Last i elements already in place
        for (unsigned int j = 0; j < (this->elements.size() - i - 1); ++j) {
            if (this->elements[j] > this->elements[j+1])
                swap(&(this->elements[j]), &(this->elements[j+1]));
        }
    }
}

// ----------------------------------------
// R, R -> swap() -> R, R
// ----------------------------------------
void Set::swap(double *num1, double *num2) {
    double aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

// ----------------------------------------
// Set -> print() ->
// ----------------------------------------
void Set::print() const {
    if (this->elements.empty()) {
        std::cout << "The set is empty!";
        return;
    }

    for (unsigned int i = 0; i < (this->elements.size() - 1); ++i) {
        std::cout << this->elements[i] << ", ";
    }
    std::cout << std::setprecision(4) << this->elements[this->elements.size() - 1];
    std::cout << std::endl;
}

// ----------------------------------------
// Set -> meanValue() -> R (optional)
// ----------------------------------------
std::optional <double> Set::meanValue() const {
    if (this->elements.empty()) {
        return 0.0;    // Empty set
    }

    double sum = 0.0;
    for (unsigned int i = 0; i < this->elements.size(); ++i) {
        sum += this->elements[i];
    }

    double meanValue = sum / this->elements.size();

    return meanValue;
}

// ----------------------------------------
// Set, Set -> isSubset() -> T/F
// ----------------------------------------
bool Set::isSubset(const Set& anotherSet) const {
    // NOTE: Empty set is a subset of any set.
    for (unsigned int i = 0; i < anotherSet.elements.size(); ++i) {
        if (!anotherSet.within(this->elements[i])) {
            return false;
        }
    }

    return true;
}
