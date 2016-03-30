/* 
 * File:   Instruction.h
 * Author: osman
 *
 * Created on March 8, 2016, 11:48 AM
 */

#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
#include <string>

using namespace std;

class Instruction {
public:
    Instruction();
    Instruction(const Instruction& orig);
    
    void SetCommand(string command);
    string GetCommand() const;
    
    void SetParameter_two(int parameter_two);
    int GetParameter_two() const;
    
    void SetParameter_one(int parameter_one);
    int GetParameter_one() const;
    
    void SetIndex(int index);
    int GetIndex() const;
    
    ~Instruction();
private:
    int index;
    int parameter_one;
    int parameter_two;
    string command;
};

#endif	/* INSTRUCTION_H */

