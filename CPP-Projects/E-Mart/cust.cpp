#include <iostream>
#include <fstream>
#include "cust.h"
#include <assert.h>
using namespace std;

Cust::Cust(string name, bool identity, int arr_time, int no_of_items)
{
  m_name=name;
  m_identity=identity;
  m_arrivaltime=arr_time;
  m_items=no_of_items;
}

Cust::~Cust()
{
  
}

int Cust::getItems()
{
  return m_items;
}

int Cust::getArrivalTime()
{
  return m_arrivaltime;
}

bool Cust::getType()
{
  return m_identity;
}

void Cust::print_entered(ostream & os, int clock)
{
  assert(clock == m_arrivaltime);
  os << clock << ": " << m_name << " entered store" << endl;
}

void Cust::print_done_shopping(ostream &os, int clock)
{
  os << clock << ": " << m_name << " done shopping" << endl;
}

void Cust::print_started(ostream &os, int clock, int checker)
{
  os<< clock <<": "<<m_name<<" started checkout with checker "<<checker<<endl;
}

void Cust::print_done_checkout(ostream &os, int clock, int amount, int items, int checker)
{
  if(m_identity==false)
  {
    os<<clock<<": "<<m_name<<" stole $"<<amount<<" and "<<items<<( (items>1)?" items": " item")<<" from checker "<<checker<<endl;
  }
  else
  {
    os<<clock<<": "<<m_name<<" paid $"<<amount<<" for "<<items<<( (items>1)?" items":" item")<<" to checker "<<checker<<endl;
  }
}