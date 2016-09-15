#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
  private:
    int vertices, edges;
    int firstCore, secondCore;
  public:
    Graph(int vertices, int edges);
    ~Graph() {};
    int getFirstCore() { return firstCore; }
    int getSecondCore() { return secondCore; }
    int BFS(int source, std::vector<std::list<int> > adjacency, int *parentVertexArray);
    int findDiameter(int firstNode, int lastNode, int *parentVertexArray);
  
};

Graph::Graph(int vertices, int edges) 
{ 
  this->vertices=vertices;
  this->edges=edges;
}

int Graph::BFS(int source, std::vector<std::list<int> > adjacency, int *parentVertexArray)
{
  bool *visited=new bool[vertices];
  for(int i=0;i<vertices;i++)
  {
    visited[i]=false;
  }
  visited[source]=true;
  list<int> queue;
  queue.push_back(source);
  parentVertexArray[source]=source;
  list<int>:: iterator iter;
  while(!queue.empty())
  {
    source=queue.front();
    queue.pop_front();
    
    for(iter=adjacency[source].begin(); iter!=adjacency[source].end(); iter++)
    {
      if(visited[*iter]==false)
      {
        visited[*iter]=true;
        queue.push_back(*iter);
        parentVertexArray[*iter]=source;
      }
    }
  }
  delete[] visited;
  return source;
}

int Graph::findDiameter(int firstNode, int lastNode, int *parentVertexArray)
{
  list<int> diameter;
  int current;
  diameter.push_back(firstNode);
  while(firstNode != lastNode)
  {
    current= parentVertexArray[firstNode];
    diameter.push_back(current);
    firstNode=current;
  }
  unsigned int i=0;
  for (list<int>::iterator it = diameter.begin(); it != diameter.end(); it++)
  {
    if(i == (diameter.size()/2) -1){
      firstCore = *it;
    }
    if(i == (diameter.size()/2)){
      secondCore = *it;
    }
    i++;
  }
  return diameter.size();    
}

int main()
{
  int vertices, edges;
  cin>>vertices;
  std::vector <std::list<int> > adjList(vertices);
  int j=0;
  int dest;
  while(cin >> edges)
  {
    for(int i=0; i< edges; i++)
    {
      cin>>dest; 
      adjList[j].push_back(dest);
    }
    j++;
  }
  
  Graph *g=new Graph(vertices, edges);
  int *parentVertexArray=new int[vertices];
  int oneEndofDiameter= g->BFS(0, adjList, parentVertexArray);
  int otherEndofDiameter= g->BFS(oneEndofDiameter, adjList, parentVertexArray);
  
  int diameterSize = g->findDiameter(otherEndofDiameter, oneEndofDiameter, parentVertexArray);
  int core1=g->getFirstCore();
  int core2=g->getSecondCore();
  
  if(diameterSize%2 == 0){
    if(core1 < core2){
      cout<<core1<<" "<<core2<<endl;
    }
    else{
      cout<<core2<<" "<<core1<<endl;
    }
  }
  else{
    cout<<core2<<endl;
  }
    
  delete[] parentVertexArray;
  delete g;
  
  return 0;
}