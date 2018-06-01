#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

const int N_MAX = 1000000;

int is_prime(int n){
  if(n==1) return 0;
  int new_n = sqrt(n);
  for(int i=2; i<=new_n; i++){
    if(n%i == 0) return 0;
    
  }
  return 1; 
}

int main(){
  int n;
  cin >> n;
  int x;
  int ans=0;
  for(int i=0; i<n; i++){
    cin >> x;
    ans += is_prime(x);
  }
  cout << ans << endl;
  return 0;
}
