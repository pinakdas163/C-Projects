/**
 * @file party.cc
 *
 * @brief
 *    Definition of a party of diners in a restaurant.
 *
 * @author Pinak Das
 * @date 2/9/16
 */

#include <string>
#include "party.h"
using std::string;

Party::Party(const string& reservationName, int numDiners, int timeRequired)
{
	this->reservationName=new string(reservationName);
  this->numDiners=numDiners; 
  this->timeRequired=timeRequired;
}

Party::~Party() {
 delete this->reservationName;
}




