/**
 * @file trie.cpp Trie functions implementation
 *
 * @author Pinak Das
 * @date 5/14/2016
 */

#include<iostream>
#include<string>
#include<map>
#include"trie.h"
#include"dlist.h"
#include"priority_queue.h"
#include"node.h"
using namespace std;

//Copy Constructor
//@input type trie object
Trie::Trie(const Trie &other)
{ 
	this->root=copy(other.root); 
	this->priority=other.priority;
}

//Destructor for trie class. Calls deleteNode function
// passing root of trie
Trie::~Trie()
{
  deleteNode(root);
  root=NULL;
}
  
//operator overloading function for operator =
// @input Trie object reference
// @return Trie object reference
Trie& Trie::operator=(const Trie &other)
{
  if(other.root!=NULL && this->root!=other.root)
  {
    this->root = copy(other.root);
  }
  return *this;
}

// copy method to create new nodes recursively and pass it
// to the operator= function
// @input type node<char>
// @return type <node<char>
Node<char>* Trie::copy(Node<char> *root)
{
  if(root==NULL)
  {
    return NULL;
  }
  else
  {
    Node<char> *ptr = new Node<char>(root->value, NULL, NULL, root->priority);
    ptr->prev=copy(root->prev);
    ptr->next=copy(root->next);
    return ptr;
  }
}

// function to assign bits to the characters
//@return void
void Trie::traverseTrie(Node<char>* node,map<char,string> &huffmanCode,
  string bits)
{
  if(node==NULL){
    return;
  }
  if(node->value!='*')
  {
    char c=node->value;
    huffmanCode.insert(pair<char,string>(c,bits));
  }
  traverseTrie(node->prev, huffmanCode, bits+"1");
  
  traverseTrie(node->next, huffmanCode, bits+"0");
}

// function to delete all nodes in the trie
// @input type node<char>
//return void
void Trie::deleteNode(Node<char> *node)
{
  if(node!=NULL)
  {
    deleteNode(node->prev);
    deleteNode(node->next);
    delete node;
  }
}
