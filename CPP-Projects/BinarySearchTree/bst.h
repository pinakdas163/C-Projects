// bst.h
// Das, Pinak
// pdas

#ifndef BST_H_
#define BST_H_
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class BST{
  public:
    bool insert(string str) { return insert(str, m_root);}
    bool find(string target) { return find(target, m_root); }
    void dft(vector<string> &value) { dft(value, m_root); }
    void bft(vector<string> &value);
    double distance();
    int countNodes(){ return countNodes(m_root);}
    bool balanced();
    void rebalance();
    string smallest(){ return smallestprivate(m_root); }
  private:
    class Node{
      public:
        Node(string str)
        {
          m_str=str;
          m_left=NULL;
          m_right=NULL;
        }
        string m_str;
        Node* m_left;
        Node* m_right;
    };
    Node* m_root=NULL;
    queue<Node*> que;
    bool insert(string str, Node* &cur_root);
    bool find(string target, Node* cur_root);
    void dft(vector<string> &value, Node* cur_root);
    int distance(Node* cur_root, int dist);
    int countNodes(Node* cur_root);
    int balanced(Node *cur_root);
    void deleteNodes(Node* cur_root);
    void insert_from_vector(vector <string> &elements, int start_index, int end_index);
    string smallestprivate(Node* cur_root);
};

#endif
