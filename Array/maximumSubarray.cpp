#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int MaxSub(vector<int>&arr){
    int maxi = INT_MIN, prefix =0, n= arr.size();
    for(int i=0;i<n;i++){
        prefix+=arr[i];
        maxi=max(maxi,prefix);
        if(prefix<0) prefix=0;
    }
    return maxi;
}
int main(){
    int n;
    cout<<"Enter the total number of elements in the array:";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter elements in the array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<MaxSub(arr);
}