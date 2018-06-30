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

Node* insert(Node* root, int data){
  if(root==NULL){
    Node* new_node = new Node;
    new_node->data = data;
    return new_node;
  }  
  if(root->data > data) root->left = insert(root->left, data);
  if(root->data < data) root->right = insert(root->right, data);
  
  return root;
  
  // if root == NULL, return new node
  // root->data > data --> insert(root->right, data)
  // root->data < data --> insert(root->left,  data)  
}

void print_inorder(Node* root){
  if(root == NULL) return;
  print_inorder(root->left);
  cout << " " << root->data;
  print_inorder(root->right);
}

void print_preorder(Node* root){
  if(root == NULL) return;
  cout << " " << root->data;
  print_preorder(root->left);
  print_preorder(root->right);
}

int main(){
  int n;
  cin >> n;
  Node* root = NULL;
  
  rep(i, 0, n){
    string order;
    int data;
    cin >> order;
    if(order == "insert") cin >> data;

    if(order=="insert"){
      root = insert(root, data);
    }
    else{
      print_inorder(root);
      cout << endl;
      print_preorder(root);
      cout << endl;
    }
  }

  return 0;
}
