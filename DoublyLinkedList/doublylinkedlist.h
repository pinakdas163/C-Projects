/**
 * @file doublylinkedlist.h
 *
 * @brief
 *    Template for doubly linked list class.
 *
 * @author Judy Challinger & Pinak Das
 * @date 2/9/16
 */

#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

#include<iostream>
#include<string>
using std::string;

template <class T>
class DoublyLinkedList {

 public:
   DoublyLinkedList();
   ~DoublyLinkedList();
   void append(T* data);
   bool empty() const { return (head == nullptr); }
   T* remove();
   T* first();
   T* next();

 private:
   class Node {
    public:
      //Node();
      Node(T* data);
      Node* next;
      Node* prev;
      T* data;
   };
   Node* head;
   Node* tail;
   Node* current;
};

/**
 * @brief   Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node(T* data) {
	prev=nullptr;
	next=nullptr;
	this->data=data;
}

/**
 * @brief   DoublyLinkedList constructor.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {

	head=nullptr;
	tail=nullptr;
	current=nullptr;
}

/**
 * @brief   DoublyLinkedList destructor.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node* ptr = head;
  	while (ptr != nullptr) 
  	{
  	  Node* temp=ptr;                                       
  	  ptr = ptr->next;                                    
  	  delete temp->data;
  	  delete temp;
  	}
}

/**
 * @brief   Appends a new Node at the end of the DoublyLinkedList.
 * @param   data A pointer to the data to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the list. The current Node pointer is set to point to the newly
 * appended Node.
 */
template <class T>
void DoublyLinkedList<T>::append(T* data) {
	if(head==nullptr)
	{
   	head=new Node(data);
		tail=head;
		current=head;
	}
	else
	{
		tail->next=new Node(data);
		tail->next->prev=tail;
		tail=tail->next;
		current=tail;
	}
}

/**
 * @brief   Get the first thing on the list.
 * @return  A pointer to the data stored in the first Node on the list,
 *          or nullptr if the list is empty.
 *
 * The current pointer is set to point to the first Node in the list,
 * or nullptr if the list is empty.
 */
template <class T>
T* DoublyLinkedList<T>::first() {
	if(head!=nullptr)
	{
		current=head;
		return current->data;
	}
	else
		return nullptr;
}

/**
 * @brief   Get the next thing on the list.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following whatever the current pointer is pointing
 *          to. If there is no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list,
 * or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::next() {
  if(current==nullptr)
  {
    return nullptr;
  }
  else if(current->next==nullptr)
  {	
    current=nullptr;
    return nullptr;
  }
  else
  {
    current=current->next;
    return current->data;
  }
}

/**
 * @brief   Remove the Node pointed to by the current pointer.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following the Node that was removed. If there is
 *          no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list, following
 * the Node that was removed, or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::remove() {
  if(head==nullptr)
  {
    return nullptr;
  }
  
  else if(head->next==nullptr)
  {
    Node* temp=head;
    head=nullptr;
    tail=nullptr;
    current=nullptr;
    delete temp;
    return nullptr;
  }
  
  else if(current==head)
  {
    Node* temp=head;
    head=head->next;
    delete temp;
    head->prev=nullptr;
    current=head;
    return current->data;
  }
  
  else if(current==tail)
  {
    Node* temp=tail;
    tail=tail->prev;
    delete temp;
    tail->next=nullptr;
    current=nullptr;
    return nullptr;
  }
  else
  {
    Node* temp=current;
    current=current->next;
    temp->prev->next=current;
    current->prev=temp->prev;
    delete temp;
    return current->data;
  }
}

#endif // CSCI_311_DOUBLYLINKEDLIST_H