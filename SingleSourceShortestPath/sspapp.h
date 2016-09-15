/**
 * @file sspapp.h Process data to build graph
 *
 *@brief Class to create graph object and read inputs
 * 
 * @author Pinak Das
 * @date 5/16/2016
 */
#ifndef CSCI_311_SSPAPP_H
#define CSCI_311_SSPAPP_H
#include "graph.h"

class SSPapp
{
  private:
    Graph myGraph;
  public:
    void readGraph();
    void processQueries();
};

#endif