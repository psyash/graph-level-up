//Cycle detetection directed graph
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
  int V;
  list<int> *l;

public:
        Graph(int v){
          this->V = v;
          l = new list<int>[V];
        }

        //undirected graph
        void addEdge(int x, int y){
          l[x].push_back(y);
          l[y].push_back(x);
        }

        bool dfs(int node, vector<bool> &visited, int parent){
          //arrive at node
          visited[node] = true;

          for(auto nbr : l[node]){
            if(!visited[nbr]){
              bool nbrFoundCycle = dfs(nbr,visited,node);
              if(nbrFoundCycle){
                return true;
              }
            }
            else if (nbr!=parent){
              return true;
            }
          }
          return false;
          
        }

        bool contain_cycle(){
          //Graph is single component
          vector<bool> visited(V,false);
          return dfs(0,visited,-1);
        }
};


