/* This assignment originated at UC Riverside.*/

/**
 * @file hash_function.cpp
 *
 * @brief This hash function utilizes the multiplication method.
 * Advantage of multiplication method is table size is not
 * critical. This method for calculating hash value is formulated
 * by going through Hash Tables chapter in CLRS book & tutorials
 * about hash function in "http://saurabhschool.org/"
 * This hash function uniformly distributes the words in the table
 * with longest list & avg list length size very small compared to
 * the provided hash function.
 * the computation requires O(1) run time
 * sum of all the characters are obtained by multiplying the ascii values
 * with word size 32 to the power of i and adding them up.
 *
 * @author Pinak Das
 * @date 3/30/16
 */

#include <string>
#include <math.h>
#include "hash.h"
#include <iostream>
using namespace std;
using std::string;

/* hash function to compute the index in the hash table
 * for storing the element
 */
int Hash::hf ( string ins ) {
  int hash;
  int sum=0;
  double A=0.6180339887;
  double B;
  for(unsigned int i=0;i<ins.length();i++)
  {
    sum=sum+ ((int) ins[(ins.length()-1)-i]*pow(32, i));
  }
  B=(sum*A)- floor(sum*A);
  hash=floor(B*HASH_TABLE_SIZE);
  return hash;
}
