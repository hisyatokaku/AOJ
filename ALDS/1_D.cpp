#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int N_MAX = numeric_limits<int>::max();

int maxprofit(vector<int> arr){
  int tmp_min = arr[0];
  int max_profit = -N_MAX;
  for(int i=1; i<arr.size(); i++){
    max_profit = max(max_profit, arr[i] - tmp_min);
    if(arr[i] <= tmp_min) tmp_min = arr[i];
  }
  return max_profit;
  
}

int main(){
  int n;
  int x;
  vector<int> arr;

  cin >> n;

  for(int i=0; i<n; i++){
    cin >> x;
    arr.push_back(x);
  }
  cout << maxprofit(arr) << endl;
  return 0;
}
