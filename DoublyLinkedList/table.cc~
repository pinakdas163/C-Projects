/**
 * @file table.cc
 *
 * @brief
 *    Definition of a class to represent a restaurant table.
 *
 * @author Pinak Das
 * @date 2/9/16
 */

#include <string>
#include "table.h"

Table::Table(const string& tableID, int numSeats, const string& serverName)
{
	this->tableID=new string(tableID);
	this->numSeats=numSeats;
	this->serverName=new string(serverName);
}

void Table::seatParty(const Party* newParty)
{
	this->party=newParty;
}

Table::~Table() 
{
  delete this->tableID;
  delete this->serverName;
}
