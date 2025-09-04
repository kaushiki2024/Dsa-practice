//TC:O(N)
#include<iostream>
using namespace std;
int main(){
    int A[5]={0,0,0,1,1};
    int n = 5;

    // ---- Find first index of 1 ----
    int firstOne = -1;
    for(int i=0; i<n; i++){
        if(A[i]==1){
            firstOne = i;
            break;   // stop at the first 1
        }
    }
    cout << firstOne << " ";   // if not found, stays -1

    // ---- Find last index of 0 ----
    int lastZero = n;
    for(int j=n-1; j>=0; j--){
        if(A[j]==0){
            lastZero = j;
            break;   // stop at the last 0
        }
    }
    cout << lastZero << " ";   // if not found, stays n
}
