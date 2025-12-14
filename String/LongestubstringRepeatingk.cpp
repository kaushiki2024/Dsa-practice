#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, k);
    }

private:
    int helper(const string& s, int k) {
        if (s.size() < k) return 0;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // find a bad character
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] > 0 && freq[s[i] - 'a'] < k) {
                // split string
                int left = helper(s.substr(0, i), k);
                int right = helper(s.substr(i + 1), k);
                return max(left, right);
            }
        }

        return s.size();
    }
};

int main() {
    Solution sol;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int result = sol.longestSubstring(s, k);

    cout << "Longest substring length where every character appears at least k times: " 
         << result << endl;

    return 0;
}
