/*  ------------------------------------------------------------------------
    AUTHOR:         Abidan Brito Clavijo
    FILE:           ConjuntoArray.cpp
    DATE:           24/12/2019
    STATE:          DONE
    FUNCTIONALITY:  File containing all member functions definitions for
                    the set class (array implementation).
    ------------------------------------------------------------------------
    NOTICE: (C) Copyright 2019 by Abidan Brito Clavijo. All rights reserved.
    ------------------------------------------------------------------------ */

#include <iostream>            // Required for std::cout and std::endl
#include <iomanip>             // Required for std::setprecision()
#include "ConjuntoArray.h"     // Conjunto class (array)

#define EMPTY_SET 0

//// MEMBER FUNCTIONS - DEFINITIONS ////
// ----------------------------------------
// -> Conjunto() -> Conjunto
// ----------------------------------------
Conjunto::Conjunto() :
    elementos{},
    size(0)
{}

// ----------------------------------------
// Conjunto -> talla() -> N
// ----------------------------------------
unsigned int Conjunto::talla() const {
    return this->size;
}

// ----------------------------------------
// Conjunto, R -> anyadir() -> Conjunto
// ----------------------------------------
void Conjunto::anyadir(const double newElement) {
    if(!this->contiene(newElement)) {
        this->elementos[this->size] = newElement;
        this->size++;
    }
}

// ----------------------------------------
// Conjunto, R -> donde() -> N
// ----------------------------------------
std::optional <unsigned int> Conjunto::donde(const double element) {
    for(unsigned int i  = 0; i < this->size; i++) {
        if(this->elementos[i] == element) {
            return i;
        }
    }

    return std::nullopt;    // Element not found
}

// ----------------------------------------
// Conjunto, R -> eliminar() -> Conjunto
// ----------------------------------------
void Conjunto::eliminar(const double element) {
    std::optional <unsigned int> index = this->donde(element);

    if(index) {
        auto arrayIndex = *index;
        for(unsigned int i = arrayIndex; i < this->size; i++) {
            this->elementos[i] = this->elementos[i + 1];
        }
        this->size--;
    }
}

// ----------------------------------------
// Conjunto -> vaciar() -> Conjunto
// ----------------------------------------
void Conjunto::vaciar() {
    this->size = 0;
}

// ----------------------------------------
// Conjunto, R -> contiene() -> T/F
// ----------------------------------------
bool Conjunto::contiene(const double element) const {
    // Empty set
    if(this->size == EMPTY_SET) {
        return false;
    }

    // Non-empty set
    for(unsigned int i = 0; i < this->size; i++) {
        if(this->elementos[i] == element) {
            return true;
        }
    }

    return false;
}

// ----------------------------------------
// Conjunto, Conjunto -> unir() -> Conjunto
// ----------------------------------------
Conjunto Conjunto::unir(const Conjunto& anotherSet) const {
    // Set to be added is empty
    if(anotherSet.size == EMPTY_SET) {
        return (*this);
    }

    // Concatenate sets
    Conjunto superSet;
    for(unsigned int i = 0; i < this->size; i++) {
        superSet.anyadir(this->elementos[i]);
    }
    for(unsigned int i = 0; i < anotherSet.size; i++) {
        superSet.anyadir(anotherSet.elementos[i]);
    }

    return superSet;
}

//-------------------------------------------------------------------
// Conjunto -> ordenar() -> Conjunto
//-------------------------------------------------------------------
void Conjunto::ordenar() {
    if(this->size == EMPTY_SET) {
        std::cout << "The set is empty, no need to sort!";
        return;
    }

    for (unsigned int i = 0; i < (this->size - 1); i++) {
        // Last i elements already in place
        for (unsigned int j = 0; j < (this->size - i - 1); j++) {
            if (this->elementos[j] > this->elementos[j+1])
                swap(&(this->elementos[j]), &(this->elementos[j+1]));
        }
    }
}

//-------------------------------------------------------------------
// R, R -> swap() -> R, R
//-------------------------------------------------------------------
void Conjunto::swap(double *num1, double *num2) {
    double aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

// ----------------------------------------
// Conjunto -> print() ->
// ----------------------------------------
void Conjunto::print() const {
    if(this->size == EMPTY_SET) {
        std::cout << "The set is empty!";
        return;
    }

    for(unsigned int i = 0; i < (this->size - 1); i++) {
        std::cout << this->elementos[i] << ", ";
    }
    std::cout << std::setprecision(4) << this->elementos[this->talla() - 1] << std::endl;
}
