/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           SetArray.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  File containing all member functions definitions for
                    the set class (array implementation).
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

#include <iostream>   // Required for std::cout and std::endl
#include <iomanip>    // Required for std::setprecision()
#include "SetArray.h" // Set class (array)

#define EMPTY_SET 0

//// MEMBER FUNCTIONS - DEFINITIONS ////
// ----------------------------------------
// -> Set() -> Set
// ----------------------------------------
Set::Set() :
    elements{},
    size(0)
{}

// ----------------------------------------
// Set -> size() -> N
// ----------------------------------------
unsigned int Set::size() const {
    return this->size;
}

// ----------------------------------------
// Set, R -> add() -> Set
// ----------------------------------------
void Set::add(const double newElement) {
    if(!this->within(newElement)) {
        this->elements[this->size] = newElement;
        this->size++;
    }
}

// ----------------------------------------
// Set, R -> at() -> N
// ----------------------------------------
std::optional <unsigned int> Set::at(const double element) {
    for(unsigned int i  = 0; i < this->size; i++) {
        if(this->elements[i] == element) {
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

    if(index) {
        auto arrayIndex = *index;
        for(unsigned int i = arrayIndex; i < this->size; i++) {
            this->elements[i] = this->elements[i + 1];
        }
        this->size--;
    }
}

// ----------------------------------------
// Set -> empty() -> Set
// ----------------------------------------
void Set::empty() {
    this->size = 0;
}

// ----------------------------------------
// Set, R -> within() -> T/F
// ----------------------------------------
bool Set::within(const double element) const {
    // Non-empty set
    for(unsigned int i = 0; i < this->size; i++) {
        if(this->elements[i] == element) {
            return true;
        }
    }

    return false;
}

// ----------------------------------------
// Set, Set -> join() -> Set
// ----------------------------------------
Set Set::join(const Set& anotherSet) const {
    // Set to be added is empty
    if(anotherSet.size == EMPTY_SET) {
        return (*this);
    }

    // Set to be added is empty
    if(this->elements.size == EMPTY_SET) {
        return anotherSet;
    }

    // Concatenate sets
    Set superSet;
    for(unsigned int i = 0; i < this->size; i++) {
        superSet.add(this->elements[i]);
    }
    for(unsigned int i = 0; i < anotherSet.size; i++) {
        superSet.add(anotherSet.elements[i]);
    }

    return superSet;
}

// ----------------------------------------
// Set -> sort() -> Set
// ----------------------------------------
void Set::sort() {
    if(this->size == EMPTY_SET) {
        std::cout << "The set is empty, no need to sort!";
        return;
    }

    for (unsigned int i = 0; i < (this->size - 1); i++) {
        // Last i elements already in place
        for (unsigned int j = 0; j < (this->size - i - 1); j++) {
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
    if(this->size == EMPTY_SET) {
        std::cout << "The set is empty!";
        return;
    }

    for(unsigned int i = 0; i < (this->size - 1); i++) {
        std::cout << this->elements[i] << ", ";
    }
    std::cout << std::setprecision(4) << this->elements[this->size() - 1] << std::endl;
}
