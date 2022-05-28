#include "CalcList.hpp"
#include <iomanip>
#include <iostream>

// constructor
CalcList::CalcList() :CalcListInterface() {
//  header = new CalcNode; 
header=nullptr;
//trailer = new CalcNode;
//  header->next = trailer; // have them point to each other
//  trailer->prev = header;
  counter = 0;
  current_t = 0;
}
// destructor
CalcList::~CalcList() {
  while (!empty()) { 
 //  removal(header->next);
 removeLastOperation();
  }

}
bool CalcList::empty() const{ return header == nullptr; }
double CalcList::total() const { return current_t; }
const CalcNode*CalcList::getfirst() const{return header;}


/*
void CalcList ::add_p(CalcNode *v, const double &E) {
  ++counter_2;
  CalcNode *node = new CalcNode;
  node->next = v;
  node->num_of_node = v->prev->num_of_node;
  node->prev = v->prev;
  v->prev = node;

 
}
*/
/*
bool CalcList::sec_empty() const { return header==nullptr; }
*/
/*
void CalcList::removal(CalcNode *v) { // remove node v

  if(empty()){throw("Error on removal");}
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

  std::cout<<counter_2<<"counter removal";
      }
  }
*/


void CalcList::newOperation(const FUNCTIONS func, const double operand) {





  
 // add_p(oper,0.0)


  char cal;
  double total_r;

  switch (func) {
  case ADDITION:
    total_r = current_t + operand;
    cal = '+';
    break;
  case SUBTRACTION:
    total_r = current_t - operand;
    cal = '-';
    break;
  case MULTIPLICATION:
    total_r = current_t * operand;
    cal = '*';
    break;
  case DIVISION:
    if (operand == 0){  /* division by zero now allowed */
                throw("Invalid Operation");
                break;
     //  removeLastOperation();
            }
            total_r = current_t / operand;
            cal= '/';
            break;
        default:
            throw("Invalid Operation");
            break;
  }
  CalcNode *oper = new CalcNode;
  oper->new_total = total_r;
  oper->temp_oper = cal;
  oper->temp_operand = operand;
  oper->temp_total = current_t;
  
  current_t = total_r;
  
  oper->next = header;
  header = oper;

  counter++;

}

void  CalcList::removeLastOperation() {
 
//  CalcNode *temp = header;
/*
  if (header->next==trailer) {
    throw(" no");
    }
    else{
// if (header->next != nullptr) {
      CalcNode *temp = header;
    //  delete header;
     // counter--;
   // if(header->next!=)
//temp = trailer->prev->prev;
//temp->next = trailer;
//trailer->prev = temp;
CalcNode *temp2;
temp = trailer->prev->prev;
temp2 = temp->next;
temp->next = trailer;
trailer->prev = temp;
current=temp->new_total;
      
      

  
    }
}
  */
  /*
if(header == NULL){
return;
  }
CalcNode* temp = header;
while(temp->next != nullptr)
{
temp = temp->next;
}
temp->prev->next = nullptr;
 temp_total= temp->prev->new_total;
delete temp;
counter_2--;
  }
*/
  /*
CalcNode *temp;
if(header==NULL||counter==1)
{
counter--;
if(header->temp_oper=='*')
{
temp_total/=-header->temp_oper;
}
else if(header->temp_oper=='/')
{
temp_total*=header->temp_oper;
}
else if(header->temp_oper=='-')
{
temp_total+=header->temp_oper;
}
else
{
temp_total-=header->temp_oper;
}
header=NULL;
}
else
{
counter--;
if(header->temp_oper=='*')
{
temp_total/=header->temp_oper;
}
else if(header->temp_oper=='/')
{
temp_total*=header->temp_oper;
}
else if(header->temp_oper=='-')
{
temp_total+=header->temp_oper;
}
else
{
temp_total-=header->temp_oper;
}
temp=header;
header->next->prev=nullptr;
header=temp->next;
delete temp;
}
}

*/










  
  /*
CalcNo0de* noOperations = header;
 CalcNode* prev = trailer->prev->prev; // points to the node before the one 
 CalcNode* current = prev->next; // points to node that will be 
 counter_2--;
  
 // does nothing if no operations have been done
 if (noOperations->next->next == trailer) {
 throw std::invalid_argument("no operations to remove");
 return;
 }
new_total = prev->temp_total; // removes last operation
 // unlink node and delete it
 prev->next = trailer;
 trailer->prev = prev;
 delete current;
*/

  
  
 //removal(trailer->next);
/*
  if(empty()){throw("Error on removelastoperation"); }else{
    CalcNode *new_node=header;
     current=new_node->temp_total;
     header=header->next;
     delete new_node;

     counter_2--;

  }
  */
  if(empty()){
       throw("Invalid. Empty List");
    }
    else{
        CalcNode* new_node = header;
        current_t = new_node->temp_total;
        header = header->next;

        delete new_node;

        counter--;
    }
}




  
  /*
   CalcNode *trailer = header; // save current head
    header = trailer->next;
    temp_total = header->new_total;
    delete trailer; // delete the old head
*/

std::string CalcList::toString(unsigned short precision) const{
    CalcNode* node = header;
    std::string strPrint = "";
    int i = counter;

    while(node != nullptr){
        std::stringstream strCurrTotal;
        strCurrTotal << std::fixed << std::setprecision(precision) << node->new_total;

        std::stringstream strOperand;
        strOperand << std::fixed << std::setprecision(precision) << node->temp_operand;
    
        std::stringstream strPreviousTotal;
        strPreviousTotal << std::fixed << std::setprecision(precision) << node->temp_total;

        strPrint = strPrint + std::to_string(i) + ": " + strPreviousTotal.str() + node->temp_oper + strOperand.str() + "=" + strCurrTotal.str() + "\n";

        i--;
        node = node->next;

    }
    return strPrint;
}
  
  
   
   

  

/*
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
*/