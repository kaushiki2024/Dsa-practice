//WAP to find and return the num which occurs the max times in the given input.
//If two or more elements contend for the max freq, return the element which occurs in the array first i.e whose index is lowest
//Implementation

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int  maximumFrequency(vector<int> &arr ,int n){
    unordered_map<int,int> m;
    int maxFreq = 0;
    int maxAns = 0;
    for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        maxFreq = max(maxFreq , m[arr[i]]);
    }
    for(int i=0;i<arr.size();i++){
        if(maxFreq == m[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
     vector<int> arr = {2,3,5,2,2,2,5,5,5,5};
     cout<<maximumFrequency(arr,arr.size());
}