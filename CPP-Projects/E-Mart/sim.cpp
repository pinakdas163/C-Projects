#include "pqueue.h"
#include "cust.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool legal_int(char *str)
{
  while(*str!=0)
  {
    if(isdigit(*str)==0)
    {
      return false;
    }
    str++;
  }
  return true;
}

void run_simulation(Pqueue &arrival_queue, int num_checkers, int break_duration, ostream &os)
{
  struct Checker
  {
    int m_register_money;
    int m_available_time;
    Cust* m_cust;
  };
  Checker *checkers= new Checker[num_checkers];
  for(int i=0;i<num_checkers;i++)
  {
    checkers[i].m_register_money=100;
    checkers[i].m_available_time = 0;
    checkers[i].m_cust = NULL;
  }
  int num_customers=arrival_queue.size();
  Pqueue shopping_queue;
  Pqueue checker_queue;
  Cust *cust;
  int clock;
  for(clock =1; num_customers>0; clock++)
  {
    
    while(arrival_queue.empty()==false && clock==arrival_queue.getPriority())
    {
      cust= arrival_queue.dequeue();
      int shopping_time= (2* (cust->getItems())) + cust->getArrivalTime();
      cust->print_entered(os,clock);
      shopping_queue.enqueue(cust, shopping_time);
    }
    while(shopping_queue.empty()==false && clock==shopping_queue.getPriority())
    {
      cust= shopping_queue.dequeue();
      cust->print_done_shopping(os, clock);
      checker_queue.enqueue(cust, 1);
    }
    
    for(int i=0;i<num_checkers;i++)
    {
      while(checkers[i].m_cust!=NULL && checkers[i].m_available_time==clock)
      {
        cust=checkers[i].m_cust;
        if(cust->getType()==true)
        {
          int num_items=cust->getItems();
          checkers[i].m_register_money+= (num_items * 3);
          cust->print_done_checkout(os, clock, num_items*3, num_items, i);
          delete cust;
          num_customers--;
          checkers[i].m_cust=NULL;
        }
        else
        {
          int num_items=cust->getItems();
          int amount=checkers[i].m_register_money;
          checkers[i].m_register_money=0;
          cust->print_done_checkout(os, clock, amount, num_items, i);
          delete cust;
          num_customers--;
          checkers[i].m_cust=NULL;
          checkers[i].m_available_time=clock+break_duration;
        }
      }
    }
        
    for(int i=0;i<num_checkers;i++)
    {
      while(checker_queue.empty()==false && checkers[i].m_cust==NULL && checkers[i].m_available_time<=clock)
      {
        checkers[i].m_cust= checker_queue.dequeue();
        cust=checkers[i].m_cust;
        if(cust->getType()==false)
        {
          checkers[i].m_available_time=clock+4;
          cust->print_started(os, clock, i);
        }
        else{
          checkers[i].m_available_time=clock + cust->getItems();
          cust->print_started(os, clock, i);
        }
      }
    }
  }
  if(num_customers==0)
  {
    for(int i=0;i<num_checkers;i++)
    {
      os<<"registers["<<i<<"] = $"<<checkers[i].m_register_money<<endl;
    }
    os<<"time = "<<clock<<endl;
  }
}

int main(int argc, char* argv[])
{
  int num_checkers, break_duration;

  if( argc!= 5)
  {
    cerr << "Error: invalid number of command line arguments."<<endl;
    return 1;
  }
  
  if(legal_int(argv[1])==false || atoi(argv[1]) < 1)
  {
    cerr<< "Error: invalid number of checkers specified."<<endl;
    return 1;
  }
  else{
    num_checkers=atoi(argv[1]);
  }
  
  if(legal_int(argv[2])==false || atoi(argv[2]) < 0)
  {
    cerr<< "Error: invalid checker break duration specified."<<endl;
    return 1;
  }
  else{
    break_duration=atoi(argv[2]);
  }
  
  ifstream my_ifile(argv[3], ios::in);
  ofstream my_ofile(argv[4], ios::out);
  if(!my_ifile)
  {
    cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
    return 1;
  }
  if(!my_ofile)
  {
    cerr<<"Error: could not open output file <"<<argv[4]<<">."<<endl;
    return 1;
  }
  string name, role_string;
  int arrival_time, num_items;
  Pqueue arrival_queue;
  while(my_ifile>>name)
  {
    my_ifile>>role_string;
    my_ifile>> arrival_time;
    my_ifile>> num_items;
    Cust* cust= new Cust(name, (role_string=="robber"? false: true), arrival_time, num_items);
    arrival_queue.enqueue(cust, arrival_time);
  }
  run_simulation(arrival_queue, num_checkers, break_duration, my_ofile);
  return 0;
}