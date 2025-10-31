#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> NextSmallestElement(vector<int>&arr){
    stack<int> s;
    vector<int> ans(arr.size());
    s.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
        
    }
    return ans;
}
int main(){
    vector<int> arr={2,1,4,3};
     vector<int>result=NextSmallestElement(arr);
     for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
     }
}