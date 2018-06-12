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

int main(){
  string T;
  string P;
  cin >> T;
  cin >> P;

  int t_ix = 0;
  int p_ix = 0;

  vector<int> ans;
  /*
  while(t_ix < T.length()){
    // cout << "t_ix: " << t_ix << endl;
    if(T[t_ix] == P[p_ix]){
      
      int tmp_t_ix = t_ix;
      while(T[tmp_t_ix] == P[p_ix] && tmp_t_ix < T.length() && p_ix < P.length()){
	// cout << "tmp_t_ix: " << tmp_t_ix << endl;
	tmp_t_ix++;
	p_ix++;
      }
      if(p_ix == P.length()) ans.push_back(t_ix);
      p_ix = 0;
    }
    t_ix++;
  }
  */
  
  // smart answer
  for(int i=0; i<T.length(); i++){
    if(T.substr(i, P.length()) == P) cout << i << endl;
  }
  /*
  for(int i=0; i<ans.size(); i++){
    cout << ans[i] << endl;
    }*/
  return 0;
}
