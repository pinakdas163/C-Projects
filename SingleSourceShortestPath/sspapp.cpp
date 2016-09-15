/**
 * @file sspapp.cpp Process input for building graph
 * 
 * @author Pinak Das
 * @date 5/16/2016
 */
#include "sspapp.h"
#include <iostream>
using namespace std;

/**
 * @brief read input and call graph functions to
 * to add new vertices and edges to the graph
 */
void SSPapp::readGraph()
{
  int noOfVertices, noOfEdges, weight;
  string vertexIdentifier;
  string fromVertex, toVertex;
  cin>>noOfVertices;
  for(int i=0;i<noOfVertices;i++)
  {
    cin>>vertexIdentifier;
    myGraph.addVertex(vertexIdentifier);
  }
  cin>>noOfEdges;
  for(int i=0;i<noOfEdges;i++)
  {
    cin>>fromVertex;
    cin.ignore();
    cin>>toVertex;
    cin.ignore();
    cin>>weight;
    myGraph.addEdge(fromVertex, toVertex, weight);
  }
}

/**
 * @brief Function to process the queries
 * and print path from source to destination
 */
void SSPapp::processQueries()
{
  string source, destination;
  string output;
  while(cin>>source)
  {
    cin.ignore();
    cin>>destination;
    output=myGraph.getShortestPath(source, destination);
    cout<<output<<endl;
  }
}

/**
 * main function to instantiate SSPapp object and
 * call function
 */
int main()
{
  SSPapp ssp;
  ssp.readGraph();
  ssp.processQueries();
  return 0;
}
