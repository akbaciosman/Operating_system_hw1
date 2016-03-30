/* 
 * File:   main.cpp
 * Author: osman
 *
 * Created on March 8, 2016, 10:25 AM
 */
#include "CPU.h"
#include <cstdio>



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CPU *cp = new CPU();
   
    if(argc==4){
        cp->SetMode(atoi(argv[3]));
        cp->parseFile(argv[1]);
    }else{
        cout<<"ERROR!!\nNumber of Arguments mut be 4\n";
        cout<<"Simulate 'filename' -D 'mode'\n";
        exit(1);
    }
   
    
    
    do{
        cp->tick();
        if(cp->GetMode()==0){
            //nothing
        }if(cp->GetMode()==1){
            cp->printData();
        }else if(cp->GetMode()==2){
            cout<<"\nPlease enter key for continue>>";
            cin.ignore();
            cout<<"\n";
            cp->printData();
        }else if(!(cp->GetMode()==0)){
            cout<<"Wrong Mode!!\nPlease enter truth arguments\n";
            break;
        }
    }while(!cp->isHalted());
    
    if(cp->GetMode()==0){
           cp->printData();
    }

    return 0;
}



