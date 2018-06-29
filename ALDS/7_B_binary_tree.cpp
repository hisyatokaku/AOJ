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
#include <boost/format.hpp>

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

const int N_MAX = 1000000;

vector<int> tree[N_MAX];

int parent[N_MAX];
int sibl[N_MAX];
int deg[N_MAX];
int dep[N_MAX];
int height[N_MAX];
string type[N_MAX];

int find_depth(int node_id){
  if(node_id == -1) return 0;
  return 1 + max(find_depth(tree[node_id][0]),
		 find_depth(tree[node_id][1]));
}

void _height_dfs(int node_id, int h){
  if(node_id == -1) return;
  height[node_id] = max(h, height[node_id]);
  _height_dfs(parent[node_id], h+1);
}

void fill_height(int n){
  // find children
  rep(i, 0, n){
    if(type[i] == "leaf") _height_dfs(i, 0);
  }
}

void dfs(int node_id, int depth){
    int left_id = tree[node_id][0];
    int right_id = tree[node_id][1];

    deg[node_id] = (left_id != -1) + (right_id != -1);
    dep[node_id] = depth;

    // root
    if(depth==0){
      parent[node_id] = -1;
      sibl[node_id] = -1;
      type[node_id] = "root";
    }
    
    // if both children
    if(left_id != -1 && right_id != -1){
      parent[left_id] = node_id;
      parent[right_id] = node_id;
      sibl[left_id] = right_id;
      sibl[right_id] = left_id;
      if(depth > 0) type[node_id] = "internal node";

      dfs(left_id, depth+1);
      dfs(right_id, depth+1);
      
    }
    else if(left_id * right_id <= 0){
      int single_id = left_id < right_id ? right_id : left_id;
      parent[single_id] = node_id;
      sibl[single_id] = -1;
      if(depth > 0) type[node_id] = "internal node";
      dfs(single_id, depth+1);
    }
    
    else{
      if(depth != 0) type[node_id] = "leaf";
    }
    
}

int main(){
  int n;
  cin >> n;
  
  memset(parent, -1, N_MAX*sizeof(parent[0]));
  memset(height, 0, N_MAX*sizeof(height[0]));
  
  rep(i, 0, n){
    int node, left, right;
    cin >> node >> left >> right; 
    tree[node].push_back(left);
    tree[node].push_back(right);
    /*
    if(left >= 0) used[left] = 1;
    if(right >= 0) used[right] = 1;
    */
    if(left != -1 && right != -1){
      parent[left] = node;
      parent[right] = node;
      sibl[left] = right;
      sibl[right] = left;
    }
    else if(left != -1 && right == -1){
      parent[left] = node;
      sibl[left] = right;
    }
    else if(left == -1 && right != -1){
      parent[right] = node;
      sibl[right] = left;
    }    
    
  }
  
  int root_id = -1;
  rep(i, 0, n){
    root_id = (parent[i] == -1 ? i : root_id);
  }

  // find depth
  // int t_height = find_depth(root_id);

  // fill infos
  dfs(root_id, 0);

  // fill height
  fill_height(n);

  // print array
  rep(i, 0, n){
    cout << boost::format("node %1%: parent = %2%, sibling = %3%, degree = %4%, depth = %5%, height = %6%, %7%")% i % parent[i] % sibl[i] % deg[i] % dep[i] % height[i] % type[i] << endl;
    
  }

  // node {}: parent = {}, sibling = {}, degree = {}, depth = {}, height = {}, {type}
  
  return 0;
}
