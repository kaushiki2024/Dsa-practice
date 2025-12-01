#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int direction = 1;
        int currRow = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            rows[currRow] += c;

            if (currRow == 0) {
                direction = 1;
            } else if (currRow == numRows - 1) {
                direction = -1;
            }

            currRow += direction;
        }

        string result;
        for (int i = 0; i < rows.size(); i++) {
            result += rows[i];
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s;
    int numRows;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of rows: ";
    cin >> numRows;

    string ans = sol.convert(s, numRows);
    cout << "Zigzag Conversion: " << ans << endl;

    return 0;
}
