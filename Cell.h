/* 
 * File:   Cell.h
 * Author: osman
 *
 * Created on March 8, 2016, 11:16 AM
 */

#ifndef CELL_H
#define	CELL_H

class Cell {
public:
    Cell();
    Cell(int,int);
    Cell(const Cell& orig);
    
    void SetAddress(int address);
    int GetAddress() const;
    void SetValue(int value);
    int GetValue() const;
    
    ~Cell();
private:
    int address;
    int value;

};

#endif	/* CELL_H */

