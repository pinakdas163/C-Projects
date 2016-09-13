#ifndef PQUEUE_H
#define PQUEUE_H
#include "cust.h"

class Pqueue
{
  public:
    ~Pqueue();
    void enqueue(Cust* cust, int priority);
    Cust* dequeue();
    bool empty();
    int size();
    int getPriority();
  private:
    class Node{
      public:
        Node(Cust* cust, int priority, Node* next)
        {
          m_cust=cust;
          m_priority=priority;
          m_next=next;
        }
        Cust* m_cust;
        int m_priority;
        Node* m_next;
      };
      Node* m_head=NULL;
    };

#endif
