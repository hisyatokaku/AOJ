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

int pque[2000000001];
int ele_counter = 0;


void insert(int data){
  pque[ele_counter] = data;
  int cur_ix = ele_counter;
  int parent_ix = (cur_ix - 1)/2;
  while(parent_ix >= 0 && pque[parent_ix] < pque[cur_ix]){
    swap(pque[parent_ix], pque[cur_ix]);
    cur_ix = parent_ix;
    parent_ix = (cur_ix - 1)/2;
  }
}


void heapify_topdown(int cur_ix){
  int left_ix = 2*cur_ix + 1;
  int right_ix = 2*cur_ix + 2;
  // minus 1 because element is popped but counter not decreased
  if(left_ix <= ele_counter-2 && right_ix <= ele_counter-2){
    // swap whichever bigger
    if(pque[left_ix] <= pque[right_ix] && pque[cur_ix] < pque[right_ix]){
      swap(pque[right_ix], pque[cur_ix]);
      heapify_topdown(right_ix);
    }
    else if(pque[left_ix] > pque[right_ix] && pque[cur_ix] < pque[left_ix]){
      swap(pque[left_ix], pque[cur_ix]);
      heapify_topdown(left_ix);
    }
    // else: do nothing
  }
  else if(left_ix == ele_counter-2){
    // compare with left
    if(pque[cur_ix] < pque[left_ix]) swap(pque[cur_ix], pque[left_ix]);
  }
  // else: do nothing
}

int extract(){
  //  if(ele_counter <= 0) return;
  int extracted = pque[0];
  pque[0] = pque[ele_counter - 1];
  int cur_ix = 0;
  // swap with whichever bigger
  heapify_topdown(cur_ix);
  
  return extracted;
}

int main(){
  string order;
  vector<int> ans;
  while(cin >> order){
    int data;
    if(order == "end") break;
    if(order == "insert"){
      cin >> data;
      insert(data);

      ele_counter++;

    }
    else{
      ans.push_back(extract());
      ele_counter--;

    }
  }
  rep(i, 0, ans.size()) cout << ans[i] << endl;
  return 0;
}
