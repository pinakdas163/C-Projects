// main.cpp
// Das, Pinak
// pdas

#include "bst.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void skip_space()
{
  while(isspace(cin.peek()))
  {
    cin.ignore();
  }
}
    
int main()
{
  BST bst;
  string command;
  while(cin>> command)
  {  

    if(command == "smallest")
    {
      string small= bst.smallest();
      cout<<"smallest "<<small<<endl;
    }
    
    else if(command == "insert")
    {
      skip_space();
      string str;
      getline(cin,str);
      if(bst.insert(str)==false)
      {
        cerr<<"insert <"<<str<<"> failed. String already in tree."<<endl;
      }
    }

    else if(command == "print")
    {
      vector<string> strings;
      bst.dft(strings);
      cout<<"{";
      for(unsigned int i=0;i<strings.size();i++)
      {
        cout<<strings[i];
        if(i != strings.size()-1)
        {
          cout<<", ";
        }
      }
      cout<<"}"<<endl;
    }
    
    else if(command == "breadth")
    {
      vector<string> strings;
      bst.bft(strings);
      cout<<"{";
      for(unsigned int i=0;i<strings.size();i++)
      {
        cout<<strings[i];
        if(i != strings.size()-1)
        {
          cout<<", ";
        }
      }
      cout<<"}"<<endl;
    }
    
    else if(command == "size")
    {
      int size=bst.countNodes();
      cout<<size<<endl;
    }
    
    else if(command == "find")
    {
      skip_space();
      string target;
      getline(cin,target);
      if(bst.find(target)==true)
      {
        cout<<"<"<<target<<"> is in tree."<<endl;
      }
      else
      {
        cout<<"<"<<target<<"> is not in tree."<<endl;
      }
    }
    
    else if(command == "distance")
    {
      double avg=bst.distance();
      cout<<"Average distance of nodes to root = "<<avg<<endl;
    }
    
    else if(command == "balanced")
    {
      if(bst.balanced()==false)
      {
        cout<<"Tree is not balanced."<<endl;
      }
      else
      {
        cout<<"Tree is balanced."<<endl;
      }
    }
    
    else if(command == "rebalance")
    {
      bst.rebalance();
    }
    
    else if(command == "echo")
    {
      skip_space();
      string sentence;
      getline(cin,sentence);
      if(sentence.length()!=0)
      {
        cout<<sentence<<endl;
      }
    }

    else
    {
      cerr<<"Illegal command <"<<command<<">."<<endl;
      while(cin.peek()!='\n')
      {
        cin.ignore();
      }
    }
  }
  return 0;
}