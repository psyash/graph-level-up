#include <iostream>
#include<list>
using namespace std;

//Implementation of adjacency list

class Graph{
  list<int> *l;
  int V;
public:
  Graph(int v){
    V = v;
    l = new list<int>[V];
  }

  void addEdge(int i, int j, bool undir=true){
    l[i].push_back(j);
    if(undir){
        l[j].push_back(i);
    }
}

    void printAdjList(){
      //iterate over all row
      for(int i=0;i<V;i++){
        cout<<i<<"---->";
        for(auto node: l[i]){
          cout<<node<<" ";
        }
        cout<<endl;
      }
    }
  };

int main(){
  Graph g(6);
  g.addEdge(0,1);
  g.addEdge(0,4);
  g.addEdge(2,1);
  g.addEdge(3,4);
  g.addEdge(4,5);
  g.addEdge(2,3);
  g.addEdge(3,5);
  g.printAdjList();
  return 0;
}

