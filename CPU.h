/* 
 * File:   CPU.h
 * Author: osman
 *
 * Created on March 8, 2016, 11:59 AM
 */

#ifndef CPU_H
#define	CPU_H
#include <vector>
#include "Cell.h"
#include "Instruction.h"
#include <fstream>
#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>


class CPU {
public:
    CPU();
    CPU(const CPU& orig);
    
    void SetMode(int mode);
    int GetMode() const;
    
    
    void tick();
    
    bool addInstruction(Instruction ins);
    bool addCell(Cell cel);
    
    bool parseFile(char fileName[80]);
    bool parseString(string str,vector<string> *vec);
    void printData() const;
    void printInstruction() const;
    
    //***İNSTRUCTİON OPERATİONS
    bool set(const int value,const int address);
    bool add(const int value,int address);
    //a1 deki degeri al a2 degerle topla a2 ye ata
    bool addI(const int address1,int address2);
    //a1 deki degeri al a2 degerle cikar a2 ye ata
    bool subI(const int address1,int address2);
    //a1 indexindeki degeri a2 deki indexe kopyala
    bool cpy(const int address1,const int address2);
    //a1 deki indexteki address içerigini all a2 yükle
    bool cpyI(const int address1,const int address2);
    //a1 deki içerigini all a2 index indeki addrese yükle
    bool cpyI2(const int address1,const int address2);
    bool JIF(const int address1,const int value);
    
    bool isHalted();
    
    void SetMemorySize(int memorySize);
    int GetMemorySize() const;
    void SetInsSize(int insSize);
    int GetInsSize() const;
    
    void SetMemory(vector<Cell> memory);
    vector<Cell> GetMemory() const;
    void SetInstruction(vector<Instruction> instruction);
    vector<Instruction> GetInstruction() const;
    Instruction getElement(int i){return instruction.at(i);}
    
    ~CPU();
    
private:
    vector<Instruction> instruction;
    vector<Cell> memory;
    int insSize;
    int memorySize;
    int mode;

    
};

#endif	/* CPU_H */

