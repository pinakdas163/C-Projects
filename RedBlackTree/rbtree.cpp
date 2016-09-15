/**
 * @file rbapp.cpp  Definition of red-black tree functions
 *
 * @author Pinak Das
 * @date 04/28/16
 */

#include <iostream>
#include<string>
#include <iomanip>
#include "rbtree.h"

using std::cout;
using std::setw;
using std::endl;

/**
* Node constructor with no arguments to initialize
* Node class member variables. Used to point to nil
*/
RBTree::Node::Node()
{
  parent=NULL;
  left=NULL;
  right=NULL;
  this->key=new string();
  this->value=new string();
  color='B';
}

/**
* Node constructor with arguments to initialize
* Node class member variables
*/
RBTree::Node::Node(const string& key, const string& value, Node* node)
{
  parent=node;
  left=node;
  right=node;
  this->key=new string(key);
  this->value=new string(value);
  color='B';
}

/**
* Node Destructor to delete pointer to strings key & value
*/
RBTree::Node::~Node()
{
  delete key;
  delete value;
}

/**
* RBTree constructor to initialize nil and point root to nil
*/
RBTree::RBTree()
{
  nil=new Node();
  root=nil;
}

/**
* RBTree destructor to delete all nodes. Calls destructHelper function
*/
RBTree::~RBTree()
{
  Node* node=root;
  destructHelper(node);
  delete nil;
}

/**
* destructHelper function to reach all nodes recursively and delete them
*/
void RBTree::destructHelper(Node *node)
{
  if(node != NULL && node!=nil && node->right != NULL && node->left != NULL)
  {
    destructHelper(node->left);
    destructHelper(node->right);
    delete node;
  }
}

/**
* Insert helper method. Create new node with key and value
* Call rbInsert function to insert node in the RBTree
* 
* @param const string key
* @param const string value
*/
void RBTree::rbInsert(const string& key, const string& value)
{
  Node* node=new Node(key, value, nil);
  rbInsert(node);
}

/**
* rbInsert function to insert node in the RBTree
* 
* @param Node* node
*/
void RBTree::rbInsert(Node* node)
{
  Node* temp=nil;
  Node* curr=root;
  while(curr!=nil)
  {
    temp=curr;
    if(*(node->key) < *(curr->key))
    {
      curr=curr->left;
    }
    else
    {
      curr=curr->right;
    }
  }
  node->parent=temp;
  if(temp==nil)
  {
    root=node;
  }
  else if(*(node->key) < *(temp->key))
  {
    temp->left=node;
  }
  else
  {
    temp->right=node;
  }
  node->left=nil;
  node->right=nil;
  node->color='R';
  rbInsertFixup(node);
}

/**
* rbInsertFixup function to balance the tree after insertion
* 
* @param Node* node
*/
void RBTree::rbInsertFixup(Node* node)
{
  Node* temp;
  while(node->parent->color=='R')
  {
    if(node->parent==node->parent->parent->left)
    {
      temp=node->parent->parent->right;
      if(temp->color=='R')
      {
        node->parent->color='B';
        temp->color='B';
        node->parent->parent->color='R';
        node=node->parent->parent;
      }
      else
      {
        if(node==node->parent->right)
        {
          node=node->parent;
          leftRotate(node);
        }
        else
        {
          node->parent->color='B';
          node->parent->parent->color='R';
          rightRotate(node->parent->parent);
        }
      }
    }
    else
    {
      temp=node->parent->parent->left;
      if(temp->color=='R')
      {
        node->parent->color='B';
        temp->color='B';
        node->parent->parent->color='R';
        node=node->parent->parent;
      }
      else
      {
        if(node==node->parent->left)
        {
          node=node->parent;
          rightRotate(node);
        }
        else
        {
          node->parent->color='B';
          node->parent->parent->color='R';
          leftRotate(node->parent->parent);
        }
      }
    }
  }
  root->color='B';
}

/**
* leftRotate function rotates the RBTree to right side
* 
* @param Node* node
*/
void RBTree::leftRotate(Node* node)
{
  Node* temp=node->right;
  node->right=temp->left;
  if(temp->left!=nil)
  {
    temp->left->parent=node;
  }
  temp->parent=node->parent;
  if(node->parent==nil)
  {
    root=temp;
  }
  else
  {
    if(node==node->parent->left)
    {
      node->parent->left=temp;
    }
    else
    {
      node->parent->right=temp;
    }
  }
  temp->left=node;
  node->parent=temp;
}

/**
* rightRotate function rotates the RBTree to left side
* 
* @param Node* node
*/
void RBTree::rightRotate(Node* node)
{
  Node* temp=node->left;
  node->left=temp->right;
  if(temp->right!=nil)
  {
    temp->right->parent=node;
  }
  temp->parent=node->parent;
  if(node->parent==nil)
  {
    root=temp;
  }
  else
  {
    if(node==node->parent->right)
    {
      node->parent->right=temp;
    }
    else
    {
      node->parent->left=temp;
    }
  }
  temp->right=node;
  node->parent=temp;
}

/**
* rbPrintTree function to call in order print function
* 
*/
void RBTree::rbPrintTree()
{
  reverseInOrderPrint(root, 0);
} 

/**
* Print function to print tree nodes in order
* 
* @param Node* x
* @param int depth
*/
void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}

/**
* rbFind function finds node using the key value
* 
* @param const string key
*/
vector<const string*> RBTree::rbFind(const string& key)
{
  Node* curr;
  Node* successor;
  Node* predecessor;
  vector<const string*> searchedNodes;
  curr=rbTreeSearch(root, key);
  if(curr==nil)
  {
    return searchedNodes;
  }
  if(curr!=nil){
    searchedNodes.push_back(curr->value);
    if(curr->left!=nil && curr->right!=nil)
    {
      successor=rbTreeSuccessor(curr);
      while(successor!=nil && *(successor->key)==key)
      {
        searchedNodes.push_back(successor->value);
        successor=rbTreeSuccessor(successor);
      }
      predecessor=rbTreePredecessor(curr);
      while(predecessor!=nil && *(predecessor->key)==key)
      {
        searchedNodes.push_back(predecessor->value);
        predecessor=rbTreePredecessor(predecessor);
      }
    }
    if(curr->right!=nil && curr->left==nil)
    {
      successor=rbTreeSuccessor(curr);
      while(successor!=nil && *(successor->key)==key)
      {
        searchedNodes.push_back(successor->value);
        successor=rbTreeSuccessor(successor);
      }
    }
    if(curr->left!=nil && curr->right==nil)
    {
      predecessor=rbTreePredecessor(curr);
      while(predecessor!=nil && *(predecessor->key)==key)
      {
        searchedNodes.push_back(predecessor->value);
        predecessor=rbTreePredecessor(predecessor);
      }
    }
  }
  return searchedNodes;
}

/**
* rbTreeSearch function to look up node in the tree using the key value
* @param Node* node
* @param const string key
*/
RBTree::Node* RBTree::rbTreeSearch(Node* node, const string& key)
{
  if(node== nil)
  {
    return nil;
  }
  else if(key==*(node->key))
  {
    return node;
  }
  else if(key < *(node->key))
    return rbTreeSearch(node->left,key);
  else
    return rbTreeSearch(node->right,key);
}

/**
* rbTreeSuccessor function returns the successor of the node
* passed to the function
* @param Node* node
*/
RBTree::Node* RBTree::rbTreeSuccessor(Node* node)
{
  Node* temp;
  if(node->right!=nil)
    return rbTreeMinimum(node->right);
  temp=node->parent;
  while(temp!=nil && node==temp->right)
  {
    node=temp;
    temp=temp->parent;
  }
  return temp;
}

/**
* rbTreePredecessor function returns the predecessor of the node
* passed to the function
* @param Node* node
*/
RBTree::Node* RBTree::rbTreePredecessor(Node* node)
{
  Node* temp;
  if(node->left!=nil)
    return rbTreeMaximum(node->left);
  temp=node->parent;
  while(temp!=nil && node==temp->left)
  {
    node=temp;
    temp=temp->parent;
  }
  return temp;
}

/**
* Returns the minimum node of the tree
* @param Node* node
*/
RBTree::Node* RBTree::rbTreeMinimum(Node* node)
{
  while(node->left!=nil)
  {
    node=node->left;
  }
  return node;
}

/**
* Returns the maximum node of the tree
* @param Node* node
*/
RBTree::Node* RBTree::rbTreeMaximum(Node* node)
{
  while(node->right!=nil)
  {
    node=node->right;
  }
  return node;
}

/**
* Delete helper function. Searches the node and pushes in a vector
* Call rbDelete function to delete node in the RBTree
*/
void RBTree::rbDelete(const string& key, const string& value)
{
  Node* node;
  Node* successor;
  Node* predecessor;
  Node* temp;
  node=rbTreeSearch(root, key);
  if(node==nil)
  {
    return;
  }
  vector<Node* >nodesToBeDeleted;
  if(node!=nil && *(node->key)==key && *(node->value)==value)
  {
    nodesToBeDeleted.push_back(node);
  }
  if(node->left!=nil && node->right!=nil)
  {
    successor=rbTreeSuccessor(node);
    while(successor!=nil && *(successor->key)==key)
    {
      if(*(successor->value)==value)
      {
        nodesToBeDeleted.push_back(successor);
      }
      successor=rbTreeSuccessor(successor);
    }
    predecessor=rbTreePredecessor(node);
    while(predecessor!=nil && *(predecessor->key)==key)
    {
      if(*(predecessor->value)==value)
      {
        nodesToBeDeleted.push_back(predecessor);
      }
      predecessor=rbTreePredecessor(predecessor);
    }
  }
  else if(node->right!=nil && node->left==nil)
  {
    successor=rbTreeSuccessor(node);
    while(successor!=nil && *(successor->key)==key)
    {
      if(*(successor->value)==value)
      {
        nodesToBeDeleted.push_back(successor);
      }
      successor=rbTreeSuccessor(successor);
    }
  }
  else if(node->left!=nil && node->right==nil)
  {
    predecessor=rbTreePredecessor(node);
    while(predecessor!=nil && *(predecessor->key)==key)
    {
      if(*(predecessor->value)==value)
      {
        nodesToBeDeleted.push_back(predecessor);
      }
      predecessor=rbTreePredecessor(predecessor);
    }
  }
  vector<Node* >::iterator iter;
  iter=nodesToBeDeleted.begin();
  while(iter!=nodesToBeDeleted.end())
  {
    temp=*iter;
    rbDelete(temp);
    delete temp;
    iter++;
  }
}

/**
* rbDelete function to delete node from the tree
*/
void RBTree::rbDelete(Node* node)
{
  Node *temp;
  Node* curr;
  curr=node;
  char curr_original_color=curr->color;
  if(node->left==nil)
  {
    temp=node->right;
    rbTransplant(node,node->right);
  }
  else if(node->right==nil)
  {
    temp=node->left;
    rbTransplant(node,node->left);
  }
  else
  {
    curr=rbTreeMaximum(node->left);
    curr_original_color=curr->color;
    temp=curr->left;
    if(curr->parent==node)
    {
      temp->parent=curr;
    }
    else
    {
      rbTransplant(curr,curr->left);
      curr->left=node->left;
      curr->left->parent=curr;
    }
    rbTransplant(node,curr);
    curr->right=node->right;
    curr->right->parent=curr;
    curr->color=node->color;
  }
  if(curr_original_color=='B')
  {
    rbDeleteFixup(temp);
  }
}

/**
* rbDeleteFixup function to fixup the tree after deletion
* @param Node* node
*/
void RBTree::rbDeleteFixup(Node* node)
{
  Node* temp;
  while(node!=root && node->color=='B')
  {
    if(node==node->parent->left)
    {
      temp=node->parent->right;
      if(temp->color=='R')
      {
        temp->color='B';
        node->parent->color='R';
        leftRotate(node->parent);
        temp=node->parent->right;
      }
      if(temp->left->color=='B' && temp->right->color=='B')
      {
        temp->color='R';
        node=node->parent;
      }
      else if(temp->right->color=='B')
      {
        temp->left->color='B';
        temp->color='R';
        rightRotate(temp);
        temp=node->parent->right;
      }
      else
      {
        temp->color=node->parent->color;
        node->parent->color='B';
        temp->right->color='B';
        leftRotate(node->parent);
        node=root;
      }
    }
    else
    {
      temp=node->parent->left;
      if(temp->color=='R')
      {
        temp->color='B';
        node->parent->color='R';
        rightRotate(node->parent);
        temp=node->parent->left;
      }
      if(temp->left->color=='B' && temp->right->color=='B')
      {
        temp->color='R';
        node=node->parent;
      }
      else if(temp->left->color=='B')
      {
        temp->right->color='B';
        temp->color='R';
        leftRotate(temp);
        temp=node->parent->left;
      }
      else
      {
        temp->color=node->parent->color;
        node->parent->color ='B';
        temp->left->color ='B';
        rightRotate(node->parent);
        node = root;
      }
    }
  }
  node->color='B';
 }
 
/**
* rbTransplant function to connect nodes after deletion
* @param Node* node
* @param Node* temp
*/
void RBTree::rbTransplant(Node* node, Node* temp)
{
  if(node->parent==nil)
  {
    root=temp;
  }
  else if(node==node->parent->left)
  {
    node->parent->left=temp;
  }
  else
  {
    node->parent->right=temp;
  }
  temp->parent=node->parent;
}