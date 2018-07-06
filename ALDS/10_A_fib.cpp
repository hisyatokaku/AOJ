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
int dp[N_MAX];

int fib(int n, int* dp){
  if(n==0) dp[n] = 1;
  if(n==1) dp[n] = 1;

  if(dp[n] >= 0) return dp[n];
  else dp[n] = fib(n-2, dp) + fib(n-1, dp);
  return dp[n];
}

int main(){
  int n;
  cin >> n;
  memset(dp, -1, N_MAX * sizeof(dp[0]));
  // cout << fib(n, dp) << endl;
  dp[0] = dp[1] = 1;
  rep(i, 2, n+1) dp[i] = dp[i-1] + dp[i-2];
  cout << dp[n] << endl;
  return 0;
}
