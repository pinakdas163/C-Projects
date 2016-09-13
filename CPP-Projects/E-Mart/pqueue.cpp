#include "pqueue.h"
#include<iostream>
using namespace std;

Pqueue::~Pqueue()
{
  while (m_head != NULL) 
  {
    Node *temp=m_head;                                       
    m_head= m_head->m_next;                               
    delete temp->m_cust;
    delete temp;               
  }
}

int Pqueue::getPriority()
{
  if(m_head==NULL)
  {
    return -1;
  }
  return m_head->m_priority;
}

void Pqueue::enqueue(Cust* cust, int priority)
{
  if((m_head==NULL) || (priority < m_head->m_priority))
  {
    m_head=new Node(cust, priority, m_head);
  }
  else{
    Node* ptr=m_head;
    while(ptr->m_next!=NULL && priority >= ptr->m_next->m_priority)
    {
      ptr=ptr->m_next;
    }
    ptr->m_next=new Node(cust, priority, ptr->m_next);
  }
}

Cust* Pqueue::dequeue()
{
  if(m_head==NULL)
  {
    return NULL;
  }
    Cust* cust = m_head->m_cust;
    m_head=m_head->m_next;
    return cust;
    delete m_head;
}

int Pqueue::size()
{
  int size=0;
  Node* ptr=m_head;
  while(ptr!=NULL)
  {
    size++;
    ptr=ptr->m_next;
  }
  return size;
}

bool Pqueue::empty()
{
  if(m_head==NULL)
  {
    return true;
  }
  else
    return false;
}