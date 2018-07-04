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
#include <unordered_map>

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;

const int N_MAX = 999999999;

int arr[100001];
char suite[100001];

int prev_arr[100001];
char prev_suite[100001];


void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int l, int r){
  // rearrange array and return pivot index
  // [3, 5, 2, 1, 4] -> [3, 2, 1, 5, 4] and return 4(index)
  int cur_ix=l;
  int piv = arr[r];
  
  rep(i, l, r){
    if(arr[i] <= piv){
      //swap(arr[i], arr[cur_ix])
      
      int tmp=arr[i]; char tmp2 = suite[i];
      arr[i] = arr[cur_ix]; suite[i] = suite[cur_ix];
      arr[cur_ix] = tmp; suite[cur_ix] = tmp2;
      cur_ix++;
      // swap(&arr[i], &arr[cur_ix]);
    }
  }
  int tmp=arr[cur_ix]; char tmp2 = suite[cur_ix];
  arr[cur_ix] = arr[r]; suite[cur_ix] = suite[r];
  arr[r] = tmp; suite[r] = tmp2;
  /*
  cout << "piv: " << piv << endl;
  cout << "l: " << l << ", r: " << r << endl;
  rep(i, l, r+1) cout << arr[i] << " ";
  cout << endl << endl;*/
  return cur_ix;
}

void quicksort(int l, int r){
  if(l>=r) return;
  int mid_ix = partition(l, r);
  quicksort(l, mid_ix-1);
  quicksort(mid_ix+1, r);
}

void check_stable(int n){
  
  unordered_map<int, int> num2id;
  int id = 0;
  int cur_val = -1;
  string order_suite[100000];
  
  rep(i, 0, n) order_suite[i] = "";
  rep(i, 0, n){
    if(cur_val != arr[i]){
      num2id[arr[i]] = id;
      cur_val = arr[i];
      id++;
    }
    order_suite[num2id[arr[i]]] += suite[i];
  }

  rep(i, 0, n){
    //cout << prev_suite[i] << endl;
    //cout << order_suite[num2id[prev_arr[i]]][0] << endl;
    //cout << endl;
    
    if(order_suite[num2id[prev_arr[i]]][0] != prev_suite[i]){
      cout << "Not stable" << endl;
      return;
    }
    else{
      order_suite[num2id[prev_arr[i]]].erase(0, 1);
    }
  }
  cout << "Stable" << endl;
}

int main(){
  int n;
  cin >> n;
  
  rep(i, 0, n){
    cin >> suite[i]; prev_suite[i] = suite[i];
    cin >> arr[i];   prev_arr[i] = arr[i];
  }
  quicksort(0, n-1);
  check_stable(n);
  rep(i, 0, n) cout << suite[i] << " "<< arr[i] << endl;
  return 0;
}
