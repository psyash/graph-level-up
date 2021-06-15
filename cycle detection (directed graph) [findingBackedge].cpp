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

        void addEdge(int x, int y){
          l[x].push_back(y);
        }

        bool dfs(int node, vector<bool> &visited, vector<bool> &stack){
          //arrive at node
          visited[node] = true;
          stack[node] = true;

          //do some work at node, return true if backedge is found here itself
          for(int nbr : l[node]){
            if(stack[nbr]==true){
              return true;
            }
            else if(visited[nbr]==false){
              bool nbrFoundCycle = dfs(nbr,visited,stack);
              if(nbrFoundCycle){
                return true;
              }
            }
          }
          //going back
          stack[node] = false;
          return false;
        }
}

//wrapper function
bool containCycle(){
  vector<bool> visited(V,false);
  vector<bool> stack(V,false);

  for(int i=0;i<V;i++){
    if(!visited[i]){
      if(dfs(i,visited,stack)){
        return true;
      }
    }
    
  }
  return false;
}
};

