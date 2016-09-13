// bst.cpp
// Das, Pinak
// pdas

#include "bst.h"
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

string BST::smallestprivate(Node* cur_root)
{
  if(cur_root==NULL)
  {
    return "empty";
  }
  
  else{
    if(cur_root->m_left!=NULL)
    {
      return smallestprivate(cur_root->m_left);
    }
    else
    {
      return cur_root->m_str;
    }
  }
}
  

bool BST::insert(string str, Node* &cur_root)
{
  if(cur_root==NULL)
  {
    cur_root=new Node(str);
    return true;
  }
  if(str == cur_root->m_str)
  {
    return false;
  }
  if(str < cur_root->m_str)
  {
    return insert(str, cur_root->m_left);
  }
  else
  {
    return insert(str, cur_root->m_right);
  }
}

bool BST::find(string target, Node* cur_root)
{
  if(cur_root==NULL)
  {
    return false;
  }
  if(cur_root->m_str==target)
  {
    return true;
  }
  if(target < cur_root->m_str)
  {
    return find(target, cur_root->m_left);
  }
  else
  {
    return find(target, cur_root->m_right);
  }
}

void BST::dft(vector<string> &value, Node* cur_root)
{
  if(cur_root!=NULL)
  {
    dft(value, cur_root->m_left);
    value.push_back(cur_root->m_str);
    dft(value, cur_root->m_right);
  }
}

void BST::bft(vector<string> &value)
{
  if(m_root!=NULL)
  {
    que.push(m_root);
  }
  while(que.empty()==false)
  {
    Node* tmp=que.front();
    que.pop();
    value.push_back(tmp->m_str);
    if(tmp->m_left!=NULL){
      que.push(tmp->m_left);
    }
    if(tmp->m_right!=NULL){
      que.push(tmp->m_right);
    }
  }
}

int BST::distance(Node* cur_root, int dist)
{
  if(cur_root== NULL)
    return 0;
  return dist + distance(cur_root->m_left, dist+1) +
  distance(cur_root->m_right, dist+1);
}

double BST::distance()
{
  int total=distance(m_root, 0);
  int nodes=countNodes(m_root);
  double avg=(double)total/nodes;
  return avg;
}

int BST::countNodes(Node* cur_root)
{
  if(cur_root==NULL)
  {
    return 0;
  }
  return 1+countNodes(cur_root->m_left) + countNodes(cur_root->m_right);
}

int BST::balanced(Node *cur_root)
{
  if(cur_root==NULL)
  {
    return 0;
  }
  int left=balanced(cur_root->m_left);
  int right=balanced(cur_root->m_right);
  if(left==-1 || right==-1)
  {
    return -1;
  }
  if(abs(left-right) > 1)
  {
    return -1;
  }
  else
    return 1+max(left, right);
}

bool BST::balanced()
{
  if(balanced(m_root)==-1)
  {
    return false;
  }
  else
    return true;
}

void BST::insert_from_vector(vector <string> &elements, int start_index, int end_index)
{
  if(start_index==end_index)
  {
    insert(elements[start_index]);
    return;
  }
  
  if(start_index > end_index)
  {
    return;
  }
  else
  {
    int middle_index= (start_index+end_index)/2;
    insert(elements[middle_index]); 
    insert_from_vector(elements, start_index, middle_index -1);
    insert_from_vector(elements, middle_index+1, end_index);
  }
}
void BST::deleteNodes(Node* cur_root)
{
  if (cur_root == NULL) 
    return;
  if(cur_root->m_left!=NULL)
    deleteNodes(cur_root->m_left);
  if(cur_root->m_right!=NULL)
    deleteNodes(cur_root->m_right);
  if(cur_root->m_right==NULL && cur_root->m_left==NULL) 
    delete cur_root;
}
void BST::rebalance()
{
  vector<string> strings;
  dft(strings);
  m_root=NULL;
  deleteNodes(m_root);
  insert_from_vector( strings, 0 , strings.size()-1);
}