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
int a[N_MAX];

int main(){
  int n;
  cin >> n;
  memset(a, -1, N_MAX * sizeof(a[0]));
  rep(i, 0, n) cin >> a[i];
  const int max = 2000000001;
  // node id: key = k, parent key = pk, left key = lk, right key = rk,
  rep(i, 0, n){
    int node_num = i+1;
    int key = a[i];
    int pk = a[(i-1)>>1];
    int lk = max;
    int rk = max;
    if(2*i+1 < n) lk = a[2*i+1];
    if(2*i+2 < n) rk = a[2*i+2];
    printf("node %d:", node_num);
    printf(" key = %d", key);
    if(i != 0) printf(", parent key = %d", pk);
    if(lk != max) printf(", left key = %d", lk);
    if(rk != max) printf(", right key = %d", rk);
    cout << ", " << endl;
  }
  return 0;
}
