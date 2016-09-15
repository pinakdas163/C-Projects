/**
 * @file hash.cpp
 * 
 * @brief Implements functions print, processFile, search, remove, 
 * output and printStats to perform dictionary operations.
 *
 * @author Pinak Das
 * @date 3/30/16
 */

#include <string>
#include <list>
#include <fstream>
#include <fstream>
#include "hash.h"
#include<iostream>
using std::string;
using std::list;
using std::cout;
using std::endl;

/**
 * Constructor to initialize the member variables.
 */
Hash::Hash()
{
  collisions=0;
  longestList=0;
  runningAvgListLength=0;
}

/**
 * Iterate through the hash table to print words.
 */
void Hash::print()
{
  for(int i=0; i<HASH_TABLE_SIZE;i++)
  {
    cout<<i<<":"<<'\t';
    list<string>::iterator iter=hashTable[i].begin();
    while(iter!=hashTable[i].end())
    {
      cout<<*iter<<", ";
      iter++;
    }
    cout<<endl;
  }
}

/**
 * @brief Read from the file and insert in the hash table.
 *
 * @param filename
 */
void Hash::processFile(string filename)
{
  string word;
  std::ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {
    while(inFile>>word)
    {
      int index= hf(word);
      if(hashTable[index].empty())
      {
        hashTable[index].push_back(word);
        longestList=getlongestList();
        runningAvgListLength=getRunningAvgListLength();
      }
      else
      {
        hashTable[index].push_back(word);
        collisions++;
        longestList=getlongestList();
        runningAvgListLength=getRunningAvgListLength();
      }
    }
    inFile.close();
  }
}

/**
 * @brief Search the word in the hash table. Return true if found
 * else false.
 *
 * @param word
 * @return boolean
 */
bool Hash::search(string word)
{
  int index=hf(word);
  list<string>::iterator it=hashTable[index].begin();
  while(it!=hashTable[index].end())
  {
    if(*it==word)
    {
      return true;
    }
    it++;
  }
  return false;
}

/**
 * @brief Remove the word from the hash table
 *
 * @param word
 */
void Hash::remove(string word)
{
  int index=hf(word);
  list<string>::iterator it=hashTable[index].begin();
  while(it!=hashTable[index].end())
  {
    if(*it==word)
    {
      hashTable[index].remove(*it);
      runningAvgListLength=getRunningAvgListLength();
      return;
    }
    it++;
  }
}

/**
 * @brief Print hash table words to the specified filename.
 *
 * @param filename
 */
void Hash::output(string filename)
{
  std::ofstream outFile;
  outFile.open(filename);
  if(outFile.is_open())
  {
    for(int i=0; i<HASH_TABLE_SIZE;i++)
    {
      outFile<<i<<":"<<'\t';
      list<string>::iterator iter=hashTable[i].begin();
      while(iter!=hashTable[i].end())
      {
        outFile<<*iter<<", ";
        iter++;
      }
      outFile<<endl;
    }
    outFile.close();
  }
}

/**
 * @brief Print the number of collisions, longest list,
 * average list length.
 */
void Hash::printStats()
{
  cout<<"Total Collisions = "<<collisions<< endl;

  cout<<"Longest List Ever = "<<longestList<< endl;

  cout<<"Average List Length Over Time = "<< runningAvgListLength<< endl;
  
  cout<<"Load Factor = "<<getLoadFactor()<<endl;    
}

/** 
 * @brief Iterate through the hash table and
 * find the longest list and return it.
 *
 * @return int
 */
int Hash::getlongestList()
{
  int finalMax=0;
  for(int i=0;i<HASH_TABLE_SIZE;i++)
  {
    int count=0;
    count=hashTable[i].size();
    if(count>finalMax)
    {
      finalMax=count;
    }
  }
  return finalMax;
}

/**
 * @brief Keep track of the current average list length.
 * Calculate and running average list length.
 *
 * @return double
 */
double Hash::getRunningAvgListLength()
{
  double currentAvgListLength=0;
  int noNonEmptyList=0;
  int noItems=0;
  for(int i=0;i<HASH_TABLE_SIZE;i++)
  {
    if(!hashTable[i].empty())
    {
      noNonEmptyList++;
      noItems+=hashTable[i].size();
    }
  }
  if(noNonEmptyList==0)
  {
    return 0;
  }
  currentAvgListLength=(double) noItems/noNonEmptyList;
  runningAvgListLength= (currentAvgListLength+runningAvgListLength)/2.0;
  return runningAvgListLength;
}

/**
 * @brief Calculate the load factor of the hash table
 * and return the value.
 *
 * @return double
 */
double Hash::getLoadFactor()
{
  double loadFactor=0;
  int noElements=0;
  for(int i=0;i<HASH_TABLE_SIZE;i++)
  {
    noElements+=hashTable[i].size();
  }
  loadFactor= (double) noElements/HASH_TABLE_SIZE;
  return loadFactor;
}