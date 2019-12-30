class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        s,t=list(s),list(t)
        if len(s)==0:return int(len(t)==0)
        dp=[[0 for j in range(len(s))] for i in range(len(t))]
        for i,a in enumerate(t):
            for j,b in enumerate(s):
                if i==0 and a==b:dp[i][j]=1
                if j>0: dp[i][j]+=dp[i][j-1]
                if i>0 and j>0 and a==b:dp[i][j]+=dp[i-1][j-1]
        return dp[-1][-1]