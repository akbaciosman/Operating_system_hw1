/* 
 * File:   CPU.cpp
 * Author: osman
 * 
 * Created on March 8, 2016, 11:59 AM
 */

#include "CPU.h"

CPU::CPU() {
    mode=-1;
}

CPU::CPU(const CPU& orig) {

}

CPU::~CPU() {
}

void CPU::SetMemorySize(int memorySize) {
    this->memorySize = memorySize;
}

int CPU::GetMemorySize() const {
    return memorySize;
}

void CPU::SetInsSize(int insSize) {
    this->insSize = insSize;
}

int CPU::GetInsSize() const {
    return insSize;
}

void CPU::SetMemory(vector<Cell> memory) {
    this->memory = memory;
}

vector<Cell> CPU::GetMemory() const {
    return memory;
}

void CPU::SetInstruction(vector<Instruction> instruction) {
    this->instruction = instruction;
}

vector<Instruction> CPU::GetInstruction() const {
    return instruction;
}

void CPU::SetMode(int mode) {
    this->mode = mode;
}

int CPU::GetMode() const {
    return mode;
}

bool CPU::parseFile(char fileName[80]){
    ifstream infile;
    infile.open(fileName);
    bool flagData = false,flagInstruction = false;
    //char buff[1024]="";

    string buff;

    Cell *cel = new Cell();
    Instruction *ins = new Instruction();
    vector<string> vec;
    vec.clear();
    int i=0;
    
    while(getline(infile,buff)){
        
        /*Chapter Data*/
        if(buff=="End Data Section"){
            flagData = false;
            printData();
            cout<<"End Data Section"<<endl;
            
        }
        if(flagData==true){
            vec.clear();
            parseString(buff,&vec);
            cel->SetAddress(atof(vec.at(0).c_str()));
            cel->SetValue(atof(vec.at(1).c_str()));
            memory.push_back(*cel);
            vec.clear();
        }
        
       
       
        if(buff == "Begin Data Section" ){
            flagData = true;
            cout<<"Begin Data Section"<<endl;
        }
        /*End Chapter Data*/
        
        /*Chapter Instruction*/
        if(buff=="End Instruction Section"){
            flagInstruction = false;
            printInstruction();
            cout<<"End Instruction Section"<<endl; 
            break;
        }
        if(flagInstruction==true){
            vec.clear();
            parseString(buff,&vec);
            if(vec.at(1).compare("HLT")==0){
                ins->SetIndex(atof(vec.at(0).c_str()));
                ins->SetCommand(vec.at(1));
                ins->SetParameter_one(-1);
                ins->SetParameter_two(-1);
            }else{
                ins->SetIndex(atof(vec.at(0).c_str()));
                ins->SetCommand(vec.at(1));
                ins->SetParameter_one(atoi(vec.at(2).c_str()));
                ins->SetParameter_two(atoi(vec.at(3).c_str()));
            }
            
            addInstruction(*ins);
        }
        
        if(buff=="Begin Instruction Section"){
            flagInstruction = true;
            cout<<"Begin Instruction Section"<<endl;
            
        }
        /*End Chapter Instruction*/
        
    }
    
   
    infile.close();
    return true;
}


bool CPU::parseString(string str,vector<string> *vec){
    istringstream iss(str);
    string sub;
    do{  
        iss >>sub;
        vec->push_back(sub);
    } while(iss);
}

void CPU::printData() const{
    int i,j=0;
    
    for (i = 0; i <memory.size(); i++){
        cout<<memory.at(i).GetAddress() <<" "<<memory.at(i).GetValue();
        if((memory.size()-1 == i))
            cout<<" \n\n";
        else
            cout<<" ,";
        if(j==9){
            cout<<endl;
            j=-1;
        }
        j++;
    }
    
}

void CPU::printInstruction() const{
    int i;
    for (i = 0; i <instruction.size(); i++){
        cout<<instruction.at(i).GetIndex()<<" "<<instruction.at(i).GetCommand() <<" ";
        if(instruction.at(i).GetCommand().compare("HLT")!=0)
            cout<<instruction.at(i).GetParameter_one()<<" "<<instruction.at(i).GetParameter_two()<< endl;
        else 
            cout<<endl;
    }
}


bool CPU::addInstruction(Instruction ins){
	if(strcmp(ins.GetCommand().c_str()," ")==0){
        return false;
    }
    
    instruction.push_back(ins);
    return true;
}

bool CPU::addCell(Cell cel){
    if(cel.GetAddress()==-1 && cel.GetValue()==-1){
        return false;
    }
    memory.push_back(cel);
    return true;
}

//set B(value) A(address))
bool CPU::set(const int value,const int address){
    
    
    if(address!=0){
        memory.at(0).SetValue(memory.at(0).GetValue()+1); //Pc + 1
        memory.at(address).SetValue(value);
    }else
        memory.at(address).SetValue(value); //set 
    return true;
}


bool CPU::add(const int value,int address){
    memory.at(address).SetValue(memory.at(address).GetValue() + value);
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}

//a1 deki degeri al a2 degerle topla a2 ye ata
bool CPU::addI(const int address1,int address2){
    memory.at(address2).SetValue(memory.at(address1).GetValue()+memory.at(address2).GetValue());
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}

//a1 deki degeri al a2 degerle cikar a2 ye ata
bool CPU::subI(const int address1,int address2){
    memory.at(address2).SetValue(memory.at(address1).GetValue() - memory.at(address2).GetValue());
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}
    
//a1 indexindeki degeri a2 deki indexe kopyala

bool CPU::cpy(const int address1,const int address2){
    memory.at(address2).SetValue(memory.at(address1).GetValue());
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}
//a1 deki indexteki address içerigini all a2 yükle
bool CPU::cpyI(const int address1,const int address2){
    memory.at(address2).SetValue(memory.at(memory.at(address1).GetValue()).GetValue());
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}

//a1 deki içerigini all a2 index indeki addrese yükler
bool CPU::cpyI2(const int address1,const int address2){
    memory.at(memory.at(address2).GetValue()).SetValue(memory.at(memory.at(address1).GetValue()).GetValue());
    memory.at(0).SetValue(memory.at(0).GetValue()+1);
    return true;
}


bool CPU::JIF(const int address1,const int value){
    if(memory.at(address1).GetValue()<=0)
        memory.at(0).SetValue(value);
    else
        memory.at(0).SetValue(memory.at(0).GetValue()+1);
        
    return true;
}

bool CPU::isHalted(){
    if(instruction.at(memory.at(0).GetValue()).GetCommand().compare("HLT")==0){
        return true;
    }
    return false;
}


void CPU::tick(){
    int pC = memory.at(0).GetValue();
    string ins=instruction.at(pC).GetCommand();

    if(ins.compare("SET")==0){
        set(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("ADD")==0){
        add(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("ADDI")==0){
        addI(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());  
    }else if(ins.compare("SUBI")==0){
        subI(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("CPY")==0){
        cpy(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("CPYI")==0){
        cpyI(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("CPYI2")==0){
        cpyI2(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else if(ins.compare("JIF")==0){
        JIF(instruction.at(pC).GetParameter_one(),instruction.at(pC).GetParameter_two());
    }else
        cerr<<"Does not match any instruction\n";
 }


