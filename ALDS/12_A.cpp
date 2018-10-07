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

bool is_safe(char f[][8], int r, int c){
  rep(col, 0, 8){
    if(f[r][col] == 'x') return false;
  }
  rep(row, 0, 8){
    if(f[row][c] == 'x') return false;
  }


  for(int i = -8, j = -8;
      r+i < 8 & c+j < 8;
      i++, j++){
    if(!((0<=r+i) && (r+i<8) && (0<=c+j) && (c+j<8))) continue;
    if(f[r+i][c+j] == 'x') return false;
  }

  for(int i = -8, j = 8;
      r+i < 8 & 0 <= c+j;
      i++, j--){
    if(!((0<=r+i) && (r+i<8) && (0<=c+j) && (c+j<8))) continue;
    if(f[r+i][c+j] == 'x') return false;
  }


  for(int i = 8, j = 8;
      r+i >= 0 && c+j >= 0;
      i--, j--){
    if(!((0<=r+i) && (r+i<8) && (0<=c+j) && (c+j<8))) continue;
    if(f[r+i][c+j] == 'x') return false;
    }

  for(int i = 8, j = -8;
      r+i >= 0 && c+j < 8;
      i--, j++){
    if(!((0<=r+i) && (r+i<8) && (0<=c+j) && (c+j<8))) continue;
    if(f[r+i][c+j] == 'x') return false;
    }

  
  return true;
}

/*char** fill(char** f, int r, int c){
  f[r][c] = 'x';
  return f;
  }*/

bool solve(char f[][8], int col){
  // return true or false
  // base case
  if(col >= 8) return true;
  
  rep(row, 0, 8){
    // already filled
    if(f[row][col] == 'x'){
      if(solve(f, col+1)) return true;
    }
    
    if(is_safe(f, row, col)){
      f[row][col] = 'x';
      if(solve(f, col+1)) return true;
      f[row][col] = 'o';
    }
  }
  return false;
  // put queen
  //   if collision, not put
  //   else
  //      if further fails, not put
  // cannot put queen
  //   return false
  //   back, put away last queen
}

int main(){
  char f[8][8];
  rep(i, 0, 8){
    rep(j, 0, 8){
      f[i][j] = 'o';
    }
  }
  int k;
  cin >> k;
  rep(i, 0, k){
    int r, c;
    cin >> r >> c;
    f[r][c] = 'x';
  }

  solve(f, 0);
  
  rep(r, 0, 8){
    rep(c, 0, 8){
      if(f[r][c]=='x') cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
  return 0;
}
