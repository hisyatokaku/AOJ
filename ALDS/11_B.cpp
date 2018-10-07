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
bool update_num_to_visit(int st, int en, int* arr){
  if(st==-1) return false;
  arr[st]--;
  return arr[st]==0;
  }*/

int main(){
  int n;
  cin >> n;
  stack<pair<int, int> > edges;
  stack<pair<int, int> > paths;
  
  int** adjl = new int*[n];
  int* d = new int[n];
  int* f = new int[n];
  
  for(int i=0; i<n; i++){
    adjl[i] = new int[n];
    memset(adjl[i], -1, n * sizeof(adjl[i][0]));
  }
  
  memset(d, -1, n*sizeof(d[0]));
  memset(f, -1, n*sizeof(f[0]));

  for(int i=0; i<n; i++){
    int row_num, k;
    cin >> row_num >> k; row_num--;
    
    for(int j=0; j<k; j++){
      int node_num;
      cin >> node_num; node_num--;
      adjl[row_num][j] = node_num; // [[3, 5, -1 , ...], [1, 3, -1, ...], [1, 2], ...]
    }
  }

  for(int row_num=n-1; row_num>=0; row_num--){
      pair<int, int> p;
      p.first = -1; p.second = row_num; // visited from nowhere
      cout << "<" << p.first << ", " << p.second << "> pushed into queue." << endl;
      edges.push(p);

    }

  int time = 1;
  while(!edges.empty()){
    //    cout << "time: " << time << endl;
    
    pair<int, int> edge;
    edge = edges.top(); edges.pop();
    int st, en; st = edge.first; en = edge.second;
    cout << "visiting: " << en << " from: " << st << endl;
    
    pair<int, int> path; 
    // record path to go back
    if(st > -1){ // exclude (-1, node)
      path.first = en; path.second = st;
      // avoid inf loop: if the node is not finished, have to go back at some point
      if(f[path.second] == -1){
	paths.push(path);
	cout << "<" << path.first << ", " << path.second << "> pushed as a path." << endl;
      }
    }    
    
    // if first time visit, mark as visited
    if(d[en] == -1) d[en] = time;
    
    // if not first time, check if it was finished.
    // if it was already finished, continue
    if(f[en] != -1){
      continue;
    }
    
    // counter for opened nodes
    int unvisited_node_num = 0;

    // open node (reverse order)
    for(int i=n-1; i>=0; i--){
      int next_node = adjl[en][i];
      // cout << "next_node: " << next_node << endl;
      // undefined dest or visited, continue
      if(next_node == -1) continue;
      if(d[next_node] != -1){
	// if num_to_visit[en] > 0;
	continue;
      }
      // if unvisited, push into stack
      unvisited_node_num++;
      pair<int, int> next_edge; next_edge.first = en; next_edge.second = next_node;
      edges.push(next_edge);
      cout << "<" << next_edge.first << ", " << next_edge.second << "> pushed." << endl;
    }

    // if there are no unvisited linked nodes anymore, mark the node finished
    if(unvisited_node_num == 0){
      // cout << "going back..." << endl;
      // cout << "f[" << en << "]: " << f[en] << endl;
      f[en] = time+1;      
      // way to go back
      if(!paths.empty()){
	path = paths.top(); paths.pop();
	edges.push(path);
	cout << "path pushed." << endl;

      }
    }
    time++;
  }

  // print 'i+1, d[i], f[i]'
  
  for(int i=0; i<n; i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
  
  for(int i=0; i<n; i++){
    delete[] adjl[i];
  }
  delete[] adjl;
  delete[] d;
  delete[] f;
  
  return 0;
}
