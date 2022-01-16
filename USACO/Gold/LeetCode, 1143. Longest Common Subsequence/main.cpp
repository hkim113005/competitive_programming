#include <iostream>
#include <vector>

using namespace std;

string a, b;

class Solution {
public:
    static int longestCommonSubsequence(string t1, string t2) {
        int x = t1.size();
        int y = t2.size();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1));

        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (t1[i - 1] == t2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[x][y];
    }
};

int main() {
    cin >> a >> b;

    cout << Solution::longestCommonSubsequence(a, b);

    return 0;
}
