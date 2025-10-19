#include <iostream>
#include <vector>
#include<set>
#include<Algorithm>
using namespace std;

vector<vector<int>> Sum(vector<int>& nums) {
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);                }
            }
        }
    }
     vector<vector<int>>result (st.begin(),st.end());
     return result;
}

int main() {
    vector<int> nums = {-1, 0, 2,1 , -1, -4};
    vector<vector<int>> ans = Sum(nums);
    for (int i = 0; i < ans.size(); i++) {
         cout << "[";
        for (int j = 0; j < 3; j++)
            cout << ans[i][j]<< " " ;
        cout << "]" << endl;
    }
    return 0;

}
