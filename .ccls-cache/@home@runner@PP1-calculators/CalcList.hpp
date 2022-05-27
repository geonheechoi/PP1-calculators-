
#ifndef CALCLIST_H
#define CALCLIST_H

#include<iostream>
#include<string>
#include <cstdlib>
#include<sstream>
#include<iomanip>

#include "CalcListInterface.hpp"
//class Calculus;

class CalcNode{

/*
  double operand;
  double total;
  double new_total;
  FUNCTIONS operation;
  CalcNode *prev=NULL; // previous node in list
  CalcNode *next=NULL; // next node in list
  friend class CalcList;
*/
  friend class CalcList;
  double temp_operand=0.0;
 double new_total=0.0;
  double temp_total=0.0;
  char temp_oper=0.0;
  double num_of_node=0.0;
    double current=0.0;
   int counter=0;
   char opop;
  FUNCTIONS temp_operation;
  CalcNode *prev=nullptr; // previous node in list
  CalcNode *next=nullptr; // next node in list

};

class CalcList :  CalcListInterface

{ 
private:
   CalcNode* header;
  CalcNode* trailer;
  double current=0.0;
   int counter=0;
   char opop;
 

// local utilities
 //insert new node before v
  // remove node v
protected:
void add_p(CalcNode *v,const double& E);
 void removal(CalcNode* v);
  bool empty() const{
    return header->next=trailer;
  }

public:
    int counter_2=0;
  CalcList(); // constructor
  ~CalcList(); // destructor
 // is list empty?
  double total() const;
  void newOperation(const FUNCTIONS func, const double operand);
  void removeLastOperation();
  std::string toString(unsigned short precision) const;
 //bool sec_empty() const;
  const CalcNode* getfirst() const;
};

#endif


