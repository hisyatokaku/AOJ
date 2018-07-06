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

int calc_area(int st_ix, int en_ix){
  return (en_ix - st_ix - 1) + 1;
}

int main(){
  string S;
  cin >> S;
  
  int ans = 0;
  int tmp_area = 0;

  typedef pair<int, int> P;
  
  stack<int> s;
  stack<P> s_ix_area;
  stack<P> rev_s_ix_area;
  rep(i, 0, S.length()){
    if(S[i] == '\\'){
      s.push(i);
    }
    else if(S[i] == '/' && !s.empty()){
      int st_ix = s.top(); s.pop();
      int area = calc_area(st_ix, i);
      int tmp_area = area;
      while(!s_ix_area.empty() && st_ix < s_ix_area.top().first){
	tmp_area += s_ix_area.top().second; s_ix_area.pop();
      }
      ans += area;
      s_ix_area.push(make_pair(i, tmp_area));
    }
  }
  while(!s_ix_area.empty()){
    rev_s_ix_area.push(s_ix_area.top());
    s_ix_area.pop();
  }
  
  cout << ans << endl;
  cout << rev_s_ix_area.size();
  while(!rev_s_ix_area.empty()){
    cout << " " << rev_s_ix_area.top().second;
    rev_s_ix_area.pop();
  }
  cout << endl;
  return 0;
}
