/**
 * @file MinPriority.cpp   
 * 
 * @brief MinPriority Queue implementation
 * 
 * @author Pinak Das
 * @date 5/6/2016
 */

#include <iostream>
#include <string>
#include "math.h"
#include <vector>
#include "minpriority.h"
using namespace std;
using std::string;

/**
 * @brief Constructor of class
 * MinPriorityQ
 *
 * @param N/A
 */
MinPriorityQ::MinPriorityQ()
{
}

/**
 * Destructor of class MinPriorityQ
 * @param N/A
 */
MinPriorityQ::~MinPriorityQ()
{
}

/**
 * Insert function to insert element in MinPriorityQ
 * @param string id
 * @param int key
 */
void MinPriorityQ::insert(string id, int key)
{
  element.id=id;
  element.key=key;
  minHeap.push_back(element);
	buildMinHeap();
  //decreaseKey(element.id,element.key);
}

/**
 * @brief Function to get the parent of an element
 * in MinPriorityQ
 * @param int
 * @return int
 */
int MinPriorityQ::parent(int i)
{
  return floor(i/2);
}

/**
 * @brief Function to get the left child of an element
 * in MinPriorityQ
 * @param int
 * @return int
 */
int MinPriorityQ::left(int i)
{
  return (2*i);
}

/**
 * @brief Function to get the right child of an element
 * in MinPriorityQ
 * @param int
 * @return int
 */
int MinPriorityQ::right(int i)
{
  return (2*i+1);
}

/**
 * @brief Function to decrease the priority of a min heap
 * @param string
 * @param int
 * @return N/A
 */
void MinPriorityQ::decreaseKey(string id, int newKey)
{
  unsigned int i;
  for(i=0;i<minHeap.size();i++)
  {
    if(id==minHeap[i].id)
    {
      break;
    }
  }
  if(newKey>minHeap[i].key)
  {
    return;
  }
  minHeap[i].key=newKey;
  while(i>0 && minHeap[i].key<minHeap[parent(i)].key)
  {
    std::swap(minHeap[i],minHeap[parent(i)]);
    i=parent(i);
  }
}

/**
 * @brief Function to extract the first element
 * in the queue
 * @return string
 */
string MinPriorityQ::extractMin()
{
  string minimum;
  unsigned int j=minHeap.size();
  if(j<1)
  {
    return "empty";
  }
  minimum=minHeap[0].id;
  minHeap[0]=minHeap[j-1];
  minHeapify(0);
  minHeap.resize(j-1);
  return minimum;
}

/**
 * @brief Function to build min heap
 */
void MinPriorityQ::buildMinHeap()
{
	//cout<<minHeap.size()<<endl;
  unsigned int j=minHeap.size();
  for(int i=floor(j/2)-1;i>=0;i--)
  {
    minHeapify(i);
  }
}

/**
 * @brief Funtion to modify min heap from
 * in the MinPriorityQ
 * @param int
 */
void MinPriorityQ::minHeapify(int i)
{
  int smallest=0;
  unsigned int l=left(i);
  unsigned int r=right(i);
  if(l<minHeap.size() && minHeap[l].key<minHeap[i].key)
  {
    smallest=l;
  }
  else
    smallest=i;
  if(r<minHeap.size() && 
    minHeap[r].key<minHeap[smallest].key)
  {
    smallest=r;
  }
  if(smallest!=i)
  {
    std::swap(minHeap[smallest],minHeap[i]);
    minHeapify(smallest);
  }
}
