/**
 * @file rbapp.cpp   Functions to assist the RBTree Implementation
 *
 * @author Pinak Das
 * @date 04/28/16
 */

#include<iostream>
#include "rbapp.h"
#include "rbtree.h"

using std::cout;
using std::cin;
using std::endl;

/** 
* Read input until end of file
*/
void RBapp::mainLoop()
{
  processCommand();
}

/**
* Process commands given by user and call appropriate functions
*/
void RBapp::processCommand()
{
  string line, key, data;
  while(getline(cin,line))
	{
  	if(line.substr(0,6)=="insert")
  	{
      data=line.substr(7);
    	processInsert(data);
  	}
    else if(line.substr(0,5)=="print")
    {
      processPrint();
    }
    else if(line.substr(0,4)=="find")
    {
      key=line.substr(5);
      processFind(key);
    }
    else if(line.substr(0,6)=="delete")
    {
      data=line.substr(7);
      processDelete(data);
    }
   else if(line.substr(0,4)=="quit")
    { 
      processQuit();
      return;
    }
  }
}

/**
* Process string and assign to key and value. Call RBTree insert
* @param string key
*/
void RBapp::processInsert(string& data)
{
  string key, value;
  int pos;
  pos=data.find(' ',0);
  key=data.substr(0,pos);
  value=data.substr(pos+1);
  myRBT.rbInsert(key, value);
}

/**
* Call RBTree print function
*/
void RBapp::processPrint()
{
  myRBT.rbPrintTree();
}

/**
* Call RBTree find function. A vector containing the value and key
* is returned which is then printed out.
* @param string key
*/
void RBapp::processFind(string& key)
{
  vector<const string*> output;
  
  output = myRBT.rbFind(key);
  vector<const string*>::iterator iter= output.begin(); 
  while(iter != output.end())
  {
    cout << key << " " << *(*iter) << endl;
    iter++;
  }
}

/**
* Call RBTree delete function passing the key and value
* @param string key
*/
void RBapp::processDelete(string& data)
{
  string key, value;
  int pos;
  pos=data.find(' ',0);
  key=data.substr(0,pos);
  value=data.substr(pos+1);
  myRBT.rbDelete(key, value);
}

/**
* Function to exit the program
*/
void RBapp::processQuit()
{
  done=true;
  return;
}

/**
* Constructor to initialize RBapp member variable
*/
RBapp::RBapp()
{
  done=false;
}   

/**
* Initialize RBapp object and call mainLoop()
*/
int main()
{
  RBapp rbapp;
  rbapp.mainLoop();
  return 0;
}