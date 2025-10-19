#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(int n, vector<int> &num) {
    vector<vector<int>> ans;
    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && num[i] == num[i - 1]) continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k) {
            int sum = num[i] + num[j] + num[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {num[i], num[j], num[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && num[j] == num[j - 1]) j++;
                while (j < k && num[k] == num[k + 1]) k--;
            }
        }
    }
    return ans;
}
int main(){
     vector<int> num = {-1, 0, 1, 2, -1, -4};
    int n = num.size();

    vector<vector<int>> result = threeSum(n, num);

    cout << "Triplets that sum to 0 are:\n";
    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
