/*
dp 问题的核心：
1. 问题规模（从小到大）
2. 规模转移（大规模 = 小规模 + 当前问题）
3. 状态
4. action (如何构造状态转移)

此题中四个要素分别为：
1. 两个字符串的长度
2. dp[i][j] dp[i - 1][j - 1] s[i - 1] j[i - 1]
3. 无额外状态
4. 删除或者不删除
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size();
        int len2 = t.size();
        vector<vector<long>> dp(len1 + 1, vector<long>(len2 + 1, 0));

        for(int i = 0; i <= len1; ++i) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp.back().back();
    }
};