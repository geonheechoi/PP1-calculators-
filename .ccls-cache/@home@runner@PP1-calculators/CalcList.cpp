#include "CalcList.hpp"
#include <iomanip>
#include <iostream>

// constructor
CalcList::CalcList() : CalcListInterface() {
  header = new CalcNode; // create sentinels
  trailer = new CalcNode;

  header->next = trailer; // have them point to each other
  trailer->prev = header;
  counter = 0;
  current = 0;

}
// destructor
CalcList::~CalcList() {
  while (!empty()) { // = remove all but sentinels
    removeLastOperation();
  }
  delete header; // remove the sentinels
  delete trailer;
}

bool CalcList::empty() const { return (header->next == nullptr); }

void CalcList ::add_p(CalcNode *v, const double &E) {
  ++counter;
  CalcNode *node = new CalcNode;
  node->next = v;
  node->num_of_node = v->prev->num_of_node;
  node->prev = v->prev;
  v->prev = node;

 
}



void CalcList::removal(CalcNode *v) { // remove node v
  --counter;
  CalcNode *ub = v->prev; // predecessor
  CalcNode *wa = v->next; // successor
  ub->next = wa;          // unlink v from list
  wa->prev = ub;
  delete v;
}

double CalcList::total() const { return current; }

void CalcList::newOperation(const FUNCTIONS func, const double operand) {


  //  double res;

  // add(oper,0.0);
  /*
  switch(func)

  {
    case  ADDITION :

     header->tot=res;
     res+=operand;
    header->next=trailer;
    trailer->prev=header;


    break;
    case SUBTRACTION:
      header->tot=res;
      res -=operand;
      header->next=trailer;
      trailer->prev=header;

    break;
    case MULTIPLICATION :
      header->tot=res;
      res =res *operand;
      header->next=trailer;
      trailer->prev=header;
    break;
    case DIVISION:
      header->tot=res;
      res=res/operand;
     header->next=trailer;
      trailer->prev=header;


    break;


   default:
                throw std::invalid_argument("AddPositiveIntegers arguments must
  be positive");

            break;




  }
*/
  /*
  switch(func){
     case  ADDITION :

       oper->new_total=oper->total+operand;
       oper->operation='+';
       oper->operand=operand;
      std::cout<< oper->operand;
          std::cout<< oper->new_total;

      break;
      case SUBTRACTION:
         oper->new_total=oper->total-operand;
       oper->operation='-';
       oper->operand=operand;


      break;
      case MULTIPLICATION :
       oper->new_total=oper->total*operand;
       oper->operation='*';
       oper->operand=operand;
       std::cout<< oper->operand;
      break;
      case DIVISION:

    if(operand==0){
        throw("No 0");

    }
       oper->new_total=oper->total/operand;
       oper->operation='/';
       oper->operand=operand;
           std::cout<< oper->operand;
      break;


     default:
                  throw ("Integers arguments must be positive");

              break;

  }
    */
  /*
   CalcNode *oper= new CalcNode;
  CalcNode *tail = nullptr;
  //add(tail,0.0);

  oper->pv=current;
  oper->op2=operand;
  if(func==ADDITION){
    oper->tot=oper
    current+=operand;
  oper->opop=ADDITION;
  }
   else if(func==SUBTRACTION){
    current-=operand;
  oper->opop=SUBTRACTION;
  }
   else if(func==MULTIPLICATION){


      current*=operand;
      oper->opop=MULTIPLICATION;

  }
   else   if(func==DIVISION){
      if(operand==0){
        delete oper;
        throw std::invalid_argument ("NO");
      }else{
    current/=operand;
  oper->opop=DIVISION;
  }



}
tail=trailer->prev;
  tail->next=oper;
  oper->prev=tail;
  oper->next=trailer;
  trailer->prev=oper;
  */
  
   


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

    if (operand == 0) {
      removeLastOperation();
      throw("No 0");
      break;
    }
    total_oper = current / operand;
    cal = '/';

    break;

  default:
    throw("Integers arguments must be positive");

    break;
  }
  oper->total = total_oper;
  oper->temp_oper = cal;
  oper->temp_operand = operand;
  oper->total = current;
  current = total_oper;
  oper->next = header;
  header = oper;

  counter++;

}

void CalcList::removeLastOperation() {
 
  CalcNode *temp = header;

  if (header != nullptr) {
    if (header->next != nullptr) {
      CalcNode *temp = header;
      delete header;
      counter--;
    }
  }
  removal(trailer->prev);
  // remove(trailer->prev);
}

std::string CalcList::toString(unsigned short precision) const {
  CalcNode *temp_node = trailer;
  std::stringstream flow;
  std::string temp_st = "";
  int temp_int = counter_2;

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
