#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>nums={2,7,11,15};
    vector<int>ans;
    int target=9;
    int start=0,end=nums.size()-1;
    while(start<end){
        if(nums[start]+nums[end]==target){
            ans.push_back(start),ans.push_back(end);
            break;
        }
        else if(nums[start]+nums[end]<target){
            start++;
        }
        else{
            end--;
        }
    }
    for(int i:ans){
        cout<<i<<" ";
    }
}