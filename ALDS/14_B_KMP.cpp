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

  int size_T = T.length();
  int size_P = P.length();

  // longest proper prefix which is also suffix
  int* lps = new int[size_P];
  memset(lps, 0, size_P * sizeof(lps[0]));
  
  // build lps
  int l_ix=0;
  int r_ix=1;

  while(r_ix < size_P){ // aabaabaaa
    if(P[l_ix] == P[r_ix]){
      lps[r_ix] = lps[r_ix-1] + 1;
      l_ix++; r_ix++;
    }    
    else{
      //while(l_ix!=0){
      if(l_ix != 0){
	l_ix = lps[l_ix-1];
      }
      if(l_ix==0) lps[r_ix] = 0;
      r_ix++;
    }
  }

  // compare T and P
  int T_ix = 0;
  int P_ix = 0;

  //aaaaaa
  //aaaa
  while(T_ix < size_T){
    //    cout << "T_ix: " << T_ix << endl;
    
    if(T[T_ix] == P[P_ix]){
      T_ix++; P_ix++;
      if(P_ix == size_P){
	cout << T_ix - P_ix << endl;
	P_ix = lps[P_ix-1];
      }
    }
    else{
      if(P_ix==0) T_ix++;
      else{
	P_ix = lps[P_ix-1];
      }
    }
  } 

  delete[] lps;  
  return 0;
}
