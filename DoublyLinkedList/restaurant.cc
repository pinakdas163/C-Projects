/**
 * @file restaurant.cc   Source code of a restaurant.
 *
 * @brief
 *    Simulates seating diners in a restaurant.
 *
 * @author Pinak Das
 * @date 2/9/16
 */
#include <string>
#include <map>
#include "doublylinkedlist.h"
#include "table.h"
#include "party.h"
#include "restaurant.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief  function to take inputs and insert in the lists
 *
 * take inputs from command 
 * create Table object and put on available list
 * create Party object and put on waiting list
 */
void Restaurant::getInput()
{
  string command, tableId, serverName, reservationName;
  int noOfSeats, noOfGuests, timeNeed;
  Table* table;
  Party* party;
  while(cin>>command){
    if(command=="table")
    {
      cin>> tableId >>noOfSeats >>serverName;
      table=new Table(tableId, noOfSeats, serverName);
      servers[serverName]=0;
      available.append(table);
    }
    if(command=="party")
    {
      cin>> noOfGuests >> reservationName >> timeNeed;
      party=new Party(reservationName, noOfGuests, timeNeed);
      waiting.append(party);
    }
    if(command=="end")
    {
      break;
    }
  }
}

/**
 * @brief  function to perform simulation of diners
 * 
 * print number of diners served by servers
 */
void Restaurant::serveParties()
{
  bool open=true;
  while(open==true)
  {
    Table* table=occupied.first();
    while( table!=nullptr)                              // for each occupied table
    {
      table->decrementTimer();
      if(table->getTimer()==0)
      {
        cout<<*(table->getParty()->getReservationName())
										<<" finished at "<<*(table->getTableID())<<endl;
        table->clearTable();
        available.append(table);
        table=occupied.remove();
        waiting.remove();
      }
      else{
        table=occupied.next();
      }
    }
    
    Party* party=waiting.first();
    while(party!=nullptr)                            // for each waiting party
    {
      Table* table=available.first();
      while(table!=nullptr && party!=nullptr)      // iterate through available
			{																						                    // tables for each party
        if(party->getNumDiners()<=table->getNumSeats())
        {
          cout<<*(party->getReservationName())<<" seated at "
									    <<*(table->getTableID())<<endl;
          table->seatParty(party);
          int timeNeed= table->getParty()->getTimeRequired();
          table->setTimer(timeNeed);
          string title=*(table->getServerName());
          servers[title]+= table->getParty()->getNumDiners();
          occupied.append(table);
          table=available.remove();
          table=available.first();
          party=waiting.remove();
        }
        else{
          table=available.next();
        }
      }
      party=waiting.next();
    }
    if(waiting.first()==nullptr && occupied.first()==nullptr)
    {
      for(std::map<string,int>::iterator iter=servers.begin(); 
										iter!=servers.end();iter++)
      {
        cout<< iter->first <<" served "<<iter->second<<endl;
      }
      open=false;
    }
  }
}

/**
 *@brief  main function to instantiate Restaurant object and call functions
 */
int main()
{
  Restaurant myDiner;
  myDiner.getInput(); 
  myDiner.serveParties();
  
  return 0;
}