#ifndef CUST_H
#define CUST_H
#include <iostream>
#include <fstream>
using namespace std;
class Cust
{
  public:
    Cust(string name, bool identity, int arr_time, int no_of_items);
    ~Cust();
    void print_entered(ostream &os, int clock);
    void print_done_shopping(ostream &os, int clock);
    void print_started(ostream &os, int clock, int checker);
    void print_done_checkout(ostream &os, int clock, int items, int amount, int checker);
    int getItems();
    int getArrivalTime();
    bool getType();
  private:
    string m_name;
    bool m_identity;
    int m_arrivaltime;
    int m_items;
};

#endif
