#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int N_MAX = 1000000;

void round_robin_scheduling(vector<pair<string, int> > arr, int quantum){
  queue<pair<string, int> > q;
  int cur_time = 0;
  pair<string, int> p_i;
  
  for(int i=0; i<arr.size(); i++){
    q.push(arr[i]);
  }
  
  while(!q.empty()){
    p_i = q.front(); q.pop();
    
    int timediff = p_i.second - quantum;
    
    if(timediff <= 0){
      p_i.second -= quantum;
      q.push(p_i);
      cur_time += quantum;
    }
    else{
      cur_time += p_i.second;
      cout << p_i.first << " " << cur_time << cout;
    }
    
  }
}

int main(){
  int n, quantum;
  cin >> n >> quantum;
  pair<string, int> p_t;
  vector<pair<string, int> > arr;
  
  for(int i=0; i<n; i++){
    cin >> p_t.first >>p_t.second;
    arr.push_back(p_t);
  }
  round_robin_scheduling(arr, quantum);
  return 0;
}
