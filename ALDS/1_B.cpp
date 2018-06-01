#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int N_MAX = 1000000;

int main(){
  int x, y;
  cin >> x;
  cin >> y;

  int residue = -1;
  int ans;
  while(residue != 0){
    residue = max(x, y)%min(x, y);
    ans = min(x, y);
    if(x>y) x = residue;
    else y = residue;
  }

  cout << ans << endl;
    
  return 0;
}
