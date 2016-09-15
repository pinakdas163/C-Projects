/**
 * @file MinPriority.h  
 * 
 * @brief Header file to implement MinPriority queue
 * 
 * @author Pinak Das
 * @date 5/6/2016
 */

#ifndef CSCI_311_MINPRIORITYQ_H
#define CSCI_311_MINPRIORITYQ_H
#include <string>
#include<vector>
using std::string;

class MinPriorityQ
{
  public:
    MinPriorityQ();
    ~MinPriorityQ();
    void insert(string id, int key);
    void decreaseKey(string id, int newKey);
    string extractMin();
		//void print();
  private:
    class Element
    {
      public:
        string id;
        int key;
    };
    Element element;
    void buildMinHeap();
    void minHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    std::vector<Element> minHeap;
  
};

#endif // CSCI_311_MINPRIORITYQ_H
