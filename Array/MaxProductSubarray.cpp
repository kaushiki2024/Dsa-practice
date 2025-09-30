#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
            int forward=1,backward=1,maxi=INT_MIN;
            int n=nums.size();
            for(int i=0;i<n;i++){
                if(forward==0) forward=1;
                if(backward==0) backward=1;
                forward=forward*nums[i];
                backward=backward*nums[n-i-1];
                maxi=max(maxi,max(forward,backward));

            }
            return maxi;
    }
}; 
int main(){
    Solution obj;   
    vector<int>nums={-1,4,-4,5,-2,-1,-1,-2,-3};
    cout<<obj.maxProduct(nums);
}