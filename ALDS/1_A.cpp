#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int N_MAX = 1000000;

void print_vector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i];
	if(i!=arr.suze()-1) cout << " ";
    }
    cout << endl;
}

void solve(vector<int> arr){
    int key;
    for(int i=0; i<arr.size(); i++){
        key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        print_vector(arr);
    }
}

int main(){
    int N;
    vector<int> arr;    

    cin >> N;
    int x;
    for(int i=0; i<N; i++){
      cin >> x;
      arr.push_back(x);
    }
    solve(arr);
    return 0;
}  
