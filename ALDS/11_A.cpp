#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>
#include <stdio.h>
#include<cstdio>

#include<string>
#include<cmath>
#include<map>
#include<cstdlib>
#include<deque>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

const int N_MAX = 1000000;

int main(){
  int N;
  cin >> N;

  // table
  int** table = new int*[N];
  for(int i=0; i<N; i++){
    table[i] = new int[N];
    memset(&table[i][0], 0, N*sizeof(table[i][0]));
    // &table[i][0] can be table[i] because it only needs head address.
    
    //[..., [int, int,int], ...]
    // memset(start_addr, 0, delta_arr) fills
    // start_addr to (start_addr + delta_arr) by 0.
    // table[i] refers to the first addr of table[i],
    // for each integer to be filled by 0, size of the element
    // (not table[i]) should be given.
  }
  
  for(int i=0; i<N; i++){
    int row_num, k;
    cin >> row_num >> k;

    row_num--;
    
    for(int j=0; j<k; j++){
      int col_num;
      cin >> col_num;
      col_num--;
      table[row_num][col_num] = 1;
    }
  }

  //print table
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << table[i][j];
      if(j!=N-1) cout << " ";
      else cout << endl;
    }
  }
  
  for(int i=0; i<N; i++){
    delete[] table[i];
  }
  delete[] table;
  
  return 0;
}
