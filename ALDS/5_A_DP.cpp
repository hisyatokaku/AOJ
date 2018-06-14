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

const int n_MAX = 21;
const int q_MAX = 20*2000+1;

int main(){
  int n;
  cin >> n;
  vector<int> A;
  int tmp;
  for(int i=0; i<n; i++){
    scanf("%d", &tmp);
    A.push_back(tmp);
  }

  int q;
  cin >> q;
  vector<int> m;
  for(int i=0;i<q; i++){
    scanf("%d", &tmp);
    m.push_back(tmp);
  }
  
  bool** dp = new bool*[n_MAX];
  for(int i=0; i<n_MAX; i++){
    dp[i] = new bool[q_MAX];
  }
  /*
  for(int row=0; row<n_MAX; row++){
    for(int col=0; col<q_MAX; col++){
      dp[row][col] = false;
    }
    }*/
  
  for(int col=0; col<q_MAX; col++){
    dp[0][col] = false;
  }

  for(int row=0; row<n_MAX; row++){
    dp[row][0] = true;
  }
  
  
  for(int row=1; row<=A.size(); row++){
    for(int col=0; col<q_MAX; col++){
      if(col-A[row-1] >= 0){
	dp[row][col] = dp[row-1][col-A[row-1]] || dp[row-1][col];
	//if(dp[row][col]) cout << "row: " << row << ", col: " << col << endl;
      }
      else dp[row][col] = dp[row-1][col];
    }
  }
  for(int i=0; i<m.size(); i++){
    int m_i = m[i];
    if(dp[n][m_i]) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  
  for(int i=0; i<n_MAX; i++){
    delete[]  dp[i];
  }      
  delete[] dp;
  
  return 0;
}
