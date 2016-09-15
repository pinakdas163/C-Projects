/**
 * @file main.cpp Huffman code implementation
 *
 * @author Pinak Das
 * @date 5/14/2016
 */

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include"trie.h"
#include"dlist.h"
#include"priority_queue.h"
#include"node.h"
using namespace std; 

// Function to build Trie
// @input PriorityQueue<Trie> *pQue
// @retur`n Trie
void mergeTries(Trie* statTrie1,PriorityQueue<Trie> *pQue)
{
  while(pQue->size()!=0)
  {
    Trie firstCopy=pQue->front();
    pQue->dequeue();
    if(pQue->size()!=0)
    {
      Trie secondCopy=pQue->front();
      pQue->dequeue();
      int prior=firstCopy.getPriority() + secondCopy.getPriority();
      Node<char> *node= new Node<char>('*', firstCopy.getRoot(), 
                                        secondCopy.getRoot(),prior);
      firstCopy.setRoot(node);
      firstCopy.setPriority(prior);
      pQue->enqueue(firstCopy, prior);
      delete node;
    }
    else
    {
      *statTrie1=firstCopy;
    }
  }
}

// main function to implement huffman encoding
int main(int argc, char* argv[])
{
  map<char,int> characters;
  PriorityQueue<Trie> *pQue=new PriorityQueue<Trie>();
  ifstream infile(argv[1]);
  if(infile.is_open())
  {
    string input;
    getline(infile,input);
    for(unsigned int i=0;i<input.length();i++)
    {
      char ch=toupper(input.substr(i,1)[0]);
      if(characters.count(ch)>0)
      {
        characters.find(ch)->second++;
      }
      else
      {
        if(isprint(ch))
        {
          characters.insert(pair<char,int>(ch,1));
        }
      }
    }
    infile.close();
  }
  
  for(map<char,int>::iterator it=characters.begin();
              it!=characters.end();it++)
  {
    Node<char> *node=new Node<char>(it->first,NULL,NULL,it->second);
    Trie tempTrie(node, node->priority);
    pQue->enqueue(tempTrie, tempTrie.getPriority());
  }
  Trie *statTrie1=new Trie();
  mergeTries(statTrie1, pQue);
  map<char,string> huffEncode;
  if(statTrie1->getRoot()!=NULL)
  {
    statTrie1->traverseTrie(statTrie1->getRoot(),huffEncode,"");
  }
  int newBits=0;
  int oldBits=0;
  for(map<char,string>::iterator it=huffEncode.begin();
    it!=huffEncode.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
    if(characters.count(it->first) > 0){
      newBits=newBits +
        ((characters.find(it->first)->second)*((it->second).length()));
    }
  }
  for(map<char,int>::iterator it=characters.begin();
              it!=characters.end();it++){
    oldBits= oldBits + ((it->second)*8);
  }
  cout<<newBits<<endl;
  cout<<oldBits<<endl;
  delete pQue;
  delete statTrie1;
  return 0;
}
