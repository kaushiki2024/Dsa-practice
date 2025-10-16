#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;
    int findMin(vector<int>& nums) {
           int low=0,high=nums.size()-1;
           int ans=INT_MAX;
           while(low<=high){
               int mid=low+(high-low)/2;

               if(nums[low]<=nums[mid]){
                      ans=min(ans,nums[low]);
                      low=mid+1;
               }
               else{
                  ans=min(ans,nums[mid]);
                  high=mid-1;
               }
           }
           return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
         
    }
    cout<<findMin(nums);

}