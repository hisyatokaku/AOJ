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
/*
 pre: 4 2 3 1 5
 in:  3 2 4 5 1

*/
struct Node{
  int data;
  Node* left = NULL;
  Node* right = NULL;
};

int ans[N_MAX];
int ans_ix = 0 ;
void append_to_answer(int n){
  ans[ans_ix] = n;
  ans_ix++;
}

void postorder(Node* root){

  if(root == NULL) return;
  postorder(root->left);
  postorder(root->right);

  append_to_answer(root->data);
  // ans += (to_string(root->data) + " ");
}


void print_array(int* arr, int len){
  rep(i, 0, len){
    cout << arr[i];
    if(i==len-1) cout << endl;
    else cout << " ";
  }
}

Node* solve(int* inorder, int* preorder, int len){


  // find root
  int root_data = preorder[0];
  Node* root_node = new Node;
  root_node->data = root_data;
  if(len==1) return root_node;
  
  // count all the num left
  int left_num=0;
  while(inorder[left_num] != root_data) left_num++;
  int right_num = len - left_num - 1;
  
  int* left_inorder = new int[left_num];
  int* right_inorder = new int[right_num];
  
  int* left_preorder = new int[left_num];
  int* right_preorder = new int[right_num];

  int ix=0;
  int l_ix=0, r_ix=0;

  rep(ix, 0, len){
    if(inorder[ix] == root_data) continue;
    if(l_ix<left_num){
      left_inorder[l_ix] = inorder[ix];
      l_ix++;
    }
    else if(r_ix<right_num){
      right_inorder[r_ix] = inorder[ix];
      r_ix++;
    }
  }
  
  ix = 0; l_ix = 0; r_ix = 0;
  
  rep(ix, 1, len){
    if(l_ix < left_num){
      left_preorder[l_ix] = preorder[ix];
      l_ix++;
    }
    else if(r_ix < right_num){
      right_preorder[r_ix] = preorder[ix];
      r_ix++;
    }
  }

  if(left_num>0) root_node->left = solve(left_inorder, left_preorder, left_num);
  if(right_num>0) root_node->right = solve(right_inorder, right_preorder, right_num);
  
  delete[] left_inorder;
  delete[] right_inorder;
  delete[] left_preorder;
  delete[] right_preorder;
  
  return root_node;
  
}

int main(){
  int n; cin >> n;
  int* inorder = new int[n];
  int* preorder = new int[n];
  
  int tmp;
  rep(i, 0, n){
    cin >> tmp;
    preorder[i] = tmp;
  }
  rep(i, 0, n){
    cin >> tmp;
    inorder[i] = tmp;
  }

  Node* root = NULL;
  root = solve(inorder, preorder, n);
  postorder(root);
  //rep(i, 0, 2*n-1) cout << ans[i];
  rep(i, 0, n){
    cout << ans[i];
    if(i==n-1) cout << endl;
    else cout << " ";
  }

  delete[] inorder;
  delete[] preorder;
  delete root;
  
  return 0;
}
