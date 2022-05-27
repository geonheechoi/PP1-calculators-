#include "CalcList.hpp"
#include <iomanip>
#include <iostream>

// constructor
CalcList::CalcList():CalcListInterface()   {
  header = new CalcNode; 

  trailer = new CalcNode;

  header->next = trailer; // have them point to each other
  trailer->prev = header;
  counter = 0;
  current = 0;
  

}
// destructor
CalcList::~CalcList() {
  while (!empty()) { // = remove all but sentinels
//    std::cout<<header<<std::endl;
   //  std::cout<<trailer<<std::endl;
    
    removal(header->next);
 //  removeLastOperation();
  }
  delete header; // remove the sentinels
  delete trailer;
 // std::cout<<header<<std::endl;
 //    std::cout<<trailer<<std::endl;
}
const CalcNode*CalcList::getfirst() const{return header;}


void CalcList ::add_p(CalcNode *v, const double &E) {
  ++counter_2;
  CalcNode *node = new CalcNode;
  node->next = v;
  node->num_of_node = v->prev->num_of_node;
  node->prev = v->prev;
  v->prev = node;

 
}
/*
bool CalcList::sec_empty() const { return header==nullptr; }
*/

void CalcList::removal(CalcNode *v) { // remove node v

  if(empty()){throw("Error on re");}
  else{
  --counter_2;
  CalcNode *b = v->prev; // predecessor
  std:: cout<<b;
  
  CalcNode *a = v->next; // successor
  std::cout<<a<<"removal 1\n";
  b->next = a;// unlink v from list
  std::cout<<a<<"removal2\n";
  
  a->prev = b;
  std::cout<<b<<"removal3\n";
  
  delete v;

  std::cout<<counter<<"counter removal";
      }
  }

double CalcList::total() const { return current; }

void CalcList::newOperation(const FUNCTIONS func, const double operand) {





  CalcNode *oper = new CalcNode;
 // add_p(oper,0.0)


  char cal;
  double total_oper;

  switch (func) {
  case ADDITION:

    total_oper = current + operand;
    cal = '+';

    break;
  case SUBTRACTION:

    total_oper = current - operand;
    cal = '-';

    break;
  case MULTIPLICATION:

    total_oper = current * operand;
    cal = '*';

    break;
  case DIVISION:

    if (operand == 0) {removeLastOperation() ;throw("No 0");}
      else{
    
    total_oper = current / operand;
    cal = '/';

    break;
        }
  default:
    throw("Integers arguments must be positive");

    break;
  }
  oper->new_total = total_oper;
  oper->temp_oper = cal;
  oper->temp_operand = operand;
  oper->temp_total = current;
  
  current = total_oper;
  
  oper->next = header;
  header = oper;

  counter++;

}

void CalcList::removeLastOperation() {
 /*
  CalcNode *temp = header;

  if (header != nullptr) {
    if (header->next != nullptr) {
      CalcNode *temp = header;
      delete header;
      counter--;
    }
  }*/
  //removal(trailer->prev);
   if(empty()){throw("Not the end");}else{
    CalcNode *new_node=header;
     current=new_node->temp_total;
     header=header->next;
     delete new_node;
     counter--;
     
   }
  }


std::string CalcList::toString(unsigned short precision) const {
  CalcNode *temp_node = trailer;

  std::string temp_st = "";
  int temp_int = counter_2;
  std::stringstream flow;
  flow.precision(precision);
 
    
    while(temp_node != header) {
     
    flow << temp_int << ":";
    flow << std::fixed << temp_node->prev->prev->num_of_node;
    if (temp_node->prev->temp_operation == ADDITION) {
      flow << "+";
    }
    else if (temp_node->prev->temp_operation == SUBTRACTION) {
      flow << "-";
    }
    else if (temp_node->prev->temp_operation == MULTIPLICATION) {
      flow << "*";
    }
    else if (temp_node->prev->temp_operation == DIVISION) {
      flow << "/";
    }
    flow << temp_node->prev->temp_operation;
    flow << "=";
    flow << temp_node->prev->num_of_node;
    flow << std::endl;
     temp_node = temp_node->prev;
    --temp_int;
  }
  temp_st = flow.str();
  return temp_st;
}
