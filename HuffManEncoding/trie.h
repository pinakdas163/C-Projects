/**
 * @file trie.h Trie class definition
 *
 * @author Pinak Das
 * @date 5/14/2016
 */

#ifndef TRIE_H
#define TRIE_H

#include<iostream>
#include<string>
#include<map>
#include "node.h"
#include "priority_queue.h"
using namespace std;

class Trie{
  private:
    Node<char> *root;
    int priority;
  public:
    Trie() { root=NULL; priority=0;}
    ~Trie();
    Trie(Node<char> *n, int priority) { this->root=n; this->priority=priority;}
    Trie(const Trie &other);
    Trie& operator=(const Trie &copy);
    Node<char> *copy(Node<char> *node);
    Node<char>* getRoot() { return root;}
    void setRoot(Node<char> *n) { this->root=copy(n);}
    void setPriority(int prior){ this->priority=prior;}
    int getPriority() { return priority;}
    void traverseTrie(Node<char> *node, map<char,string> &huffmanCode,
        string bits);
    void deleteNode(Node<char> *node);
  
};

#endif
