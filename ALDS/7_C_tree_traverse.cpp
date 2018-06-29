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
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

const int N_MAX = 1000000;

struct Node{
  int data;
  Node* left = NULL;
  Node* right = NULL;
};

Node** nodes = new Node*[N_MAX];
int* used = new int[N_MAX];
int* parent = new int[N_MAX];

void preorder(Node* root){
  if(root != NULL){
    cout << " " << root->data;
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node* root){
  if(root == NULL) return;
  inorder(root->left);
  cout << " " << root->data;
  
  inorder(root->right);
}

void postorder(Node* root){
  // cout << "id: " << root->data << ", obj:" << root << endl;
  // cout << root->left << endl;
  // cout << root->right << endl;
  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);
  cout << " " << root->data ;
}

int main(){
  int n;
  cin >> n;
  memset(used, 0, N_MAX*sizeof(used[0]));
  memset(parent, -1, N_MAX*sizeof(parent[0]));
  
  rep(i, 0, n){
    int node, left, right;
    cin >> node >> left >> right;
      
    Node* cur_node = NULL;
    Node* left_node = NULL;
    Node* right_node = NULL;
    
    if(!used[node]){
      cur_node = new Node;
      cur_node->data = node;
      nodes[node] = cur_node;
      used[node] = 1;
    }
    else{
      cur_node = nodes[node];
    }
    
    if(left != -1){
      if(!used[left]) left_node = new Node;
      else left_node = nodes[left];
      
      left_node->data = left;
      cur_node->left = left_node;
      nodes[left] = left_node;

      used[left] = 1;
      parent[left] = node;
    }
    
    if(right != -1){
      if(!used[right]) right_node = new Node;
      else right_node = nodes[right];
      
      right_node->data = right;
      cur_node->right = right_node;
      nodes[right] = right_node;

      used[right] = 1;
      parent[right] = node;
    }
  }
  int root_id = -1;
  rep(i, 0, n) root_id = parent[i] == -1 ? i : root_id;
  Node* root_node = nodes[root_id];
  
  cout << "Preorder" << endl;  
  preorder(root_node);
  cout << endl;
  /*rep(i, 0, n){
    cout << pre[i];
    if(i!=n-1) cout << " ";
    else cout << endl;
    }*/
  
  cout << "Inorder" << endl;
  inorder(root_node);
  cout << endl;
    /*rep(i, 0, n){
    cout << in[i];
    if(i!=n-1) cout << " ";
    else cout << endl;
    }*/

  
  cout << "Postorder" << endl;
  postorder(root_node);
  cout << endl;
  /*rep(i, 0, n){
    cout << post[i];
    if(i!=n-1) cout << " ";
    else cout << endl;
    }*/
  
  delete[] nodes;
  return 0;
}
