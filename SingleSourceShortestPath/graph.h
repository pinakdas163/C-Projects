/**
 * @file graph.h Header file to implement graph
 * and build SSP tree
 * @author Pinak Das
 * @date 5/16/2016
 */

#ifndef CSCI_311_GRAPH_H
#define CSCI_311_GRAPH_H

#include<iostream>
#include<stdio.h>
#include<list>
#include <map>
#include <vector>
#include "minpriority.h"
using namespace std;

class Graph
{
  private:
    class Vertex
    {
      public:
        Vertex(){};
        string pi;
        int key;
    };
    class Neighbor
    {
      public:
        Neighbor(){};
        string name;
        int weight;
    };
    struct Compare
    {
      bool operator()(Neighbor first , Neighbor second)
      {
        return (first.name < second.name);
      }
    } compare;
    
    void getParents(list<string> *path, string vertex);
    string currentSource;
    map<string, Vertex> vertices;
    map<string,vector<Neighbor>> adjList;
    MinPriorityQ minQ;
    void sortAdjacentList();
    void initializeSingleSource(string source);
    void relax(string u, string v, int weight);
    void buildSSPTree(string source);
  public:
    Graph() {};
    ~Graph(){};
    void addVertex(string name);
    void addEdge(string from, string to, int weight);
    string getShortestPath(string from, string to);
};

#endif