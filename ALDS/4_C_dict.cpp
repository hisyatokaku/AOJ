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
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1000000;

unordered_set<string> dict;

void solve(string operation, string word){
  if(operation=="insert"){
    dict.insert(word);
  }
  else{
    dict.find(word) != dict.end() ? cout << "yes" << endl : cout <<"no" << endl;
  }
}

int main(){
  int n;
  cin >> n;
  vector<string> operations;
  vector<string> words;
  
  for(int i=0; i<n; i++){
    string operation, word;
    cin >> operation >> word;
    operations.push_back(operation); words.push_back(word);
  }

  for(int i=0; i<n; i++){
    solve(operations[i], words[i]);
  }
  
  return 0;
}
