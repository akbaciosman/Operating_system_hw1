/* 
 * File:   Instruction.cpp
 * Author: osman
 * 
 * Created on March 8, 2016, 11:48 AM
 */

#include "Instruction.h"

Instruction::Instruction() {
}

Instruction::Instruction(const Instruction& orig) {
    this->index = orig.GetIndex();
    this->command = orig.GetCommand();
    this->parameter_one = orig.GetParameter_one();
    this->parameter_two = orig.GetParameter_two();
}

Instruction::~Instruction() {
}

void Instruction::SetCommand(string command) {
    this->command = command;
}

string Instruction::GetCommand() const {
    return command;
}

void Instruction::SetParameter_two(int parameter_two) {
    this->parameter_two = parameter_two;
}

int Instruction::GetParameter_two() const {
    return parameter_two;
}

void Instruction::SetParameter_one(int parameter_one) {
    this->parameter_one = parameter_one;
}

int Instruction::GetParameter_one() const {
    return parameter_one;
}

void Instruction::SetIndex(int index) {
    this->index = index;
}

int Instruction::GetIndex() const {
    return index;
}

