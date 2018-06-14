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


int allocation(vector<int> arr, k){
  int* track = new int[k];
  memset(track, 0, k*sizeof(track[0]));
  
  for(int i=0; i<arr.size(); i++){
    for(int j=0; j<k; j++){
      if(track[k])arr[i];
    }
  }
 
  delete[] track;
  return 1;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> W;
  for(int i=0;i<n;i++){
    int w;
    cin >> w;
    W.push_back(w);
  }
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  
  allocation(W, k);
  
  return 0;
}
