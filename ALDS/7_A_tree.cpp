#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cstring>


using namespace std;

const int N_MAX = 1000000;

/*
struct Node{
  int id;
  int parent;
  int d;
  string type;
  Node* child_nodes;
};

class Tree{
  Node tmp_root;
public:
  Node search_node_by_num(int);
  void add_child_from_ids(int, int);
};


Node Tree::search_node_by_num(int id){
  
  // iterate through tmp_root.child_nodes  
  tmp_root.child_nodes;

  // if found, return that node
  // else, return null
    
}

void Tree::add_child_from_ids(Node parent, Node child){
  // search whether id exists, if exists, return the node
  
  // add child to child_nodes
  parent.child_nodes
}
*/

void dfs(vector<int>* G, int node_id, int depth, int* dp, int* parent){
  dp[node_id] = depth;
  for(int i=0; i<(int)G[node_id].size(); i++){
    parent[G[node_id][i]] = node_id;
    dfs(G,G[node_id][i],  depth+1, dp, parent);
  }
}

int main(){
  int n; cin >> n;
  vector<int>* G = new vector<int>[n];
  int* depth = new int[n];
  int* parent = new int[n];
  int* used = new int[n];
  memset(parent, -1, n*sizeof(parent[0]));
  
  for(int i=0; i<n; i++){
    int id, k;
    cin >> id >> k;
    // int* ids = new int[k];
    G[i].resize(k);
    for(int j=0; j<k; j++){
      int tmp;
      cin >> tmp;
      G[i][j] = tmp;
      used[tmp] = 1;
    }
  }
  
  for(int i=0; i<n; i++){
    if(used[i] != 1) dfs(G, i, 0, depth, parent);
  }

  delete[] G;
  delete[] depth;
  delete[] parent;
  delete[] used;
  
  return 0;
}
