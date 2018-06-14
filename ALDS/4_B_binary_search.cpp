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

int binarysearch(int target, int* arr, int arr_size){
  int l_ix = 0;
  int r_ix = arr_size;
  int mid_ix = l_ix + (r_ix - l_ix)/2;

  // improved
  while(l_ix <= r_ix){
    mid_ix = l_ix + (r_ix - l_ix)/2;
    if(arr[mid_ix] == target) return 1;
    if(arr[mid_ix] < target) l_ix = ++mid_ix;
    if(arr[mid_ix] > target) r_ix = --mid_ix;
  }

  /* shit
  while(l_ix < r_ix){
    mid_ix = l_ix + (r_ix - l_ix)/2;

    if(l_ix == r_ix - 1){
      if(arr[l_ix] == target || arr[r_ix] == target ) return 1;
      else break;
    }
    
    if(arr[mid_ix] == target) return 1;
    if(arr[mid_ix] < target) l_ix = mid_ix;
    if(arr[mid_ix] > target) r_ix = mid_ix;
    }*/

  
  return 0;
}


int main(){
  int n;
  cin >> n;
  int* S = new int[n];
  
  for(int i=0;i<n;i++){
    cin >> S[i];
  }
  
  int q;
  cin >> q;

  int ans = 0;
  
  int* T = new int[n];
  for(int i=0; i<q; i++){
    cin >> T[i];
    ans += binarysearch(T[i], S, n-1);
  }
  cout << ans << endl;

  return 0;
}
