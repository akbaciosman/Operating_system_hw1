/* 
 * File:   Cell.cpp
 * Author: osman
 * 
 * Created on March 8, 2016, 11:16 AM
 */

#include "Cell.h"

Cell::Cell() {
    this->address = -1;
    this->value;
}

Cell::Cell(int address,int value ) {
    this->address = address;
    this->value = value;
}

Cell::Cell(const Cell& orig) {
    this->address = orig.GetAddress();
    this->value = orig.GetValue();
}


void Cell::SetAddress(int address) {
    this->address = address;
}

int Cell::GetAddress() const {
    return address;
}

void Cell::SetValue(int value) {
    this->value = value;
}

int Cell::GetValue() const {
    return value;
}


Cell::~Cell() {
    
}

