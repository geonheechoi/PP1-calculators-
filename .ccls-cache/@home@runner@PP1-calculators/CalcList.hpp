
#ifndef CALCLIST_H
#define CALCLIST_H

#include<iostream>
#include<string>
#include <cstdlib>
#include<sstream>
#include<iomanip>

#include "CalcListInterface.hpp"

class CalcNode{
private:
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
  double total=0.0;
  double new_total=0.0;
  char temp_oper=0.0;
  double num_of_node=0.0;
  
  FUNCTIONS temp_operation;
  CalcNode *prev=nullptr; // previous node in list
  CalcNode *next=nullptr; // next node in list

};

class CalcList :  CalcListInterface

{ 
private:
   CalcNode* header;
  CalcNode* trailer;

   double current;
   int counter;
   char opop;

protected: // local utilities
 void add_p(CalcNode *v,const double& E); //insert new node before v
  void removal(CalcNode* v); // remove node v

public:
    int counter_2=0;
  CalcList(); // constructor
  ~CalcList(); // destructor
   bool empty() const; // is list empty?
  double total() const;
  void newOperation(const FUNCTIONS func, const double operand);
  void removeLastOperation();
  std::string toString(unsigned short precision) const;
};
/*


class CalNode{
  private:
  double tot=0.0;
  double inp=0.0;
  CalNode *prev=NULL;
  CalNode *next=NULL;
// FUNCTIONS  f;
  
  friend class CalcList;

};

class CalcList : CalcListInterface { // doubly linked list
 public:
   CalcList(); // constructor
   ~CalcList(); // destructor

   bool empty() const; // is list empty?
   double total() const;
   void newOperation(const FUNCTIONS func, const double operand);
   void removeLastOperation();
   std::string toString(unsigned short precision) const;

 private: // local type definitions
   CalNode* header; // list sentinels
   CalNode* trailer;
 //   FUNCTION f;

  double tot=0.0;
  double inp=0.0;
 protected: // local utilities
   void add(CalNode *header, double data ); //insert new node before v
   void remove(CalNode* header); // remove node v
 };
*/
/*
class CalNode{
  private:

  double tot=0.0;
  double inp=0.0;
  double tolsec=0.0;
  double data=0.0;

    double pv=0.0;
  double av=0.0;
  double op1=0.0;
  double op2=0.0;
  double current=0.0;
  double count=0.0;
  char opop;

  CalNode *prev=nullptr;
  CalNode *next=nullptr;
 // FUNCTIONS f;
  
  friend class CalcList;

};

class CalcList : public CalcListInterface

{ 
 
 private: // local type definitions
   CalNode* header; // list sentinels
   CalNode* trailer;
    double total_sec=0.0;
    double inp_sec=0.0;
  double pv;
  double av;
  double op1;
  double op2;
  double current;
  double count;
  char opop;

//    FUNCTIONS f;


 protected: // local utilities
   void add(CalNode *header,double data); //insert new node before v
   void remove(CalNode* header); // remove node v
   double total_third=0.0;
   double inp_third=0.0;
  




public:


   CalcList(); // constructor
   ~CalcList(); // destructor

   bool empty() const; // is list empty?
   double total() const;
   void newOperation(const FUNCTIONS func, const double operand);
   void removeLastOperation();
   std::string toString(unsigned short precision) const;
      int set=0;




 };
*/
#endif


