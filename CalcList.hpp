

#ifndef CALCLIST_H
#define CALCLIST_H

#include<iostream>
#include<string>
#include <cstdlib>
#include<sstream>
#include<iomanip>

#include "CalcListInterface.hpp"


class CalcNode{


  friend class CalcList;
  double temp_operand;  //nodes_operand
   double new_total; //currenttotal
  double temp_total;  //prev total
  char temp_oper; //currentoperator
 // double num_of_node; //double nodes_total = 0.0;

//  FUNCTIONS temp_operation;  //nodes_operator
//  CalcNode *prev=nullptr; // previous node in list
  CalcNode *next; // next node in list

};

class CalcList :  CalcListInterface

{ 
private:
   CalcNode* header;
//CalcNode* trailer;
  double current_t;//runningtotal
  double value;
   int counter;
   char opop;
// double temp_total=0.0;
//double new_total=0.0;

// local utilities
 //insert new node before v
  // remove node v
/*
protected:
void add_p(CalcNode *v,const double& E);
 void removal(CalcNode* v);
*/

public:
 //   int counter_2=0;
  CalcList(); // constructor
  ~CalcList(); // destructor
 
  double total() const;
  void newOperation(const FUNCTIONS func, const double operand);
  void removeLastOperation();
  std::string toString(unsigned short precision) const;
 //bool sec_empty() const;
  bool empty() const;
  const CalcNode* getfirst() const;

/*
{
    return header->next=trailer;
  }
*/
};

#endif


