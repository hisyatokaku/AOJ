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

int main(){
    int n;
    cin >> n;
    int* S = new int[n];
    
    for(int i=0;i<n;i++){
        cin >> S[i];
    }
    
    int q;
    cin >> q;
    int* T = new int[n];
    for(int i=0; i<n; i++){
        cin >> T[i];
    }
    
    int ans = 0;
    
    for(int i=0; i<q; i++){
        for(int j=0; j<n; j++){
            if(T[i] == S[j]){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    
    delete[] S;
    delete[] T;
    return 0;
}
