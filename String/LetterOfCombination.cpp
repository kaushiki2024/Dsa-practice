#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> res;
        backtrack(0, digits, mp, "", res);
        return res;
    }

    // simplest backtracking function
    void backtrack(int i, string digits, vector<string>& mp,
                   string path, vector<string>& res) {

        if (i == digits.size()) {
            res.push_back(path);
            return;
        }

        string letters = mp[digits[i] - '0'];

        for (char ch : letters) {
            backtrack(i + 1, digits, mp, path + ch, res);
        }
    }
};

int main() {
    Solution s;

    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> ans = s.letterCombinations(digits);

    cout << "Letter Combinations:\n";
    for (string &str : ans) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}
