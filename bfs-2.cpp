
void bfs(int src){
  queue<int> q;
  bool *visited = new bool[V]{0};

  queue.push(src);
  visited[src] = true;

  while(!q.empty()){
    int f = q.front();
    cout<<f<<endl;
    q.pop();

    //Push nbrs
    for(auto nbr : l[f]){
      if(!visited[nbr]){
        q.push(nbr);
        visited[nbr] = true;
      }
    }

  }

}