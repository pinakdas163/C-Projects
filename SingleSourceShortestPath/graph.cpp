/**
 * @file graph.cpp Implementation of graph to
 * add new vertices, edges, build graph and
 * find shortest path
 *
 * @author Pinak Das
 * @date 5/16/2016
 */

#include "graph.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
using namespace std;

/**
 * @brief Function to add vertices to the graph
 * @param string
 */
void Graph::addVertex(string name)
{
   if(vertices.find(name) == vertices.end())
   {
      Vertex vert;
      vert.pi="NIL";
      vert.key=150;
      vertices.insert(pair<string, Vertex>(name, vert));
   }
 }

/**
 * @brief Function to add edges to the graph
 * @param string from
 * @param string to
 * @param int weight
 */
void Graph::addEdge(string from, string to, int weight)
{
  if(vertices.find(from)!=vertices.end() 
    && vertices.find(to)!=vertices.end())
  {
    map<string,vector<Neighbor>>::iterator iter;
    iter=adjList.find(from);
    vector<Neighbor> neighbor;
    if(iter==adjList.end())
    {
      Neighbor neigh;
      neigh.name=to;
      neigh.weight=weight;
      neighbor.push_back(neigh);
      adjList[from]=neighbor;
    }
    else
    {
      neighbor=iter->second;
      Neighbor neigh;
      neigh.name=to;
      neigh.weight=weight;
      neighbor.push_back(neigh);
      adjList[from]=neighbor;
    }
  }
}

/**
 * @brief Function to sort Adjacency List
 * in alphabetical order
 */
void Graph::sortAdjacentList()
{
  map<string, vector<Neighbor>>::iterator iter=adjList.begin();
  while(iter!=adjList.end())
  {
    sort(iter->second.begin(), iter->second.end(), compare);
    adjList[iter->first]=iter->second;
    iter++;
  }
}

/**
 * @brief Function to initialize all the vertices
 */
void Graph::initializeSingleSource(string source)
{
  map<std::string, Vertex>::iterator v;
  for(v= vertices.begin();v!=vertices.end();v++)
  {
    v->second.pi="NIL";
    v->second.key=150;
  }
  vertices[source].key=0;
}

/**
 * @brief  function to update the weight of vertices 
 * and decrease key in the MinPriorityQ
 */
void Graph::relax(string vertex, string neighbor, int weight)
{
  map<string,Vertex>::iterator ite=vertices.find(vertex);
  int ud=ite->second.key;
  map<string,Vertex>::iterator it=vertices.find(neighbor);
  int vd=it->second.key;
  if(vd>(ud+weight))
  {
    vd=ud+weight;
    it->second.key=vd;
    it->second.pi=vertex;
    vertices[neighbor]=it->second;
    minQ.decreaseKey(neighbor, vd);
  }
}

/**
 * @brief  function to build SSP tree
 * @param string source
 */
void Graph::buildSSPTree(string source)
{
  sortAdjacentList();
  initializeSingleSource(source);
  map<std::string, Vertex>::iterator v;
  for(v= vertices.begin();v!=vertices.end();v++)
  {
    minQ.insert(v->first,v->second.key);
  }
  for(unsigned int i=0;i<vertices.size();i++)
  {
    string uVertex=minQ.extractMin();
    map<string,vector<Neighbor>>::iterator it;
    it=adjList.find(uVertex);
    if(it!=adjList.end())
    {
      vector<Neighbor> neighbor=it->second;
      vector<Neighbor>::iterator i=neighbor.begin();
      while(i!=neighbor.end())
      {
        relax(uVertex, i->name,i->weight);
        i++;
      }
    }
  }
}

/**
 * @brief Function to get the parent of the vertex
 * @param list
 * @param string
 */
void Graph::getParents(list<string> *path, string vertex)
{
  Vertex node=vertices[vertex];
  if(node.pi=="NIL")
  {
    return;
  }
  path->push_front(node.pi);
  getParents(path, node.pi);
}

/**
 * @brief  Function to obtain shortest path between
 * vertices in the graph
 * @param string from
 * @param string to
 * @return string
 */
string Graph::getShortestPath(string from, string to)
{
  if(currentSource!=from)
  {
    currentSource=from;
    buildSSPTree(from);
  }
  list<string> *path=new list<string>();
  if(!path->empty())
  {
    path->clear();
  }
  path->push_front(to);
  getParents(path, to);
  string output="";
  int size=path->size();
  for(int i=0;i<size;i++)
  {
    string start=path->front();
    path->pop_front();
    output=output+start;
    if(i!=size-1)
    {
      output=output+"->";
    }
  }
  output+=" with length ";
  int length= vertices[to].key;
  output+=std::to_string(length);
  delete path;
  return output;
}

