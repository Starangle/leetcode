class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int m = s1.size(),n = s2.size();
        int sum = 0,counter = 1,pos = 0;
        vector<int> Cnt(n1 + 1,0); // 第n个s1片段覆盖的s2的个数
        vector<int> next(n1 + 1,0); // 第n个s1片段对应的第一个s2的index
        while(counter <= n1){
            for(int i = 0 ; i < m ; i++){
                if(s1[i] == s2[pos]){
                    if(pos == n - 1){
                        pos = 0;
                        sum++;
                    }else
                        pos++;
                }
            }
            
            Cnt[counter] = sum; // start of a new s2
            next[counter] = pos; 
            for(int begin = 0 ; begin < counter ; ++begin){
                if(next[begin] == pos){
                    int interval = counter - begin;
                    int N = (n1 - begin)/interval;
                    cout  << interval << "  " << Cnt[counter] - Cnt[begin] << endl;
                    int intervalCNT = N * (Cnt[counter] - Cnt[begin]);
                    int leftCNT = Cnt[begin + (n1 - begin) % interval];
                    return (intervalCNT + leftCNT)/n2;
                }
            }
            counter++;
        }
        return Cnt[n1] / n2;
    }
};

/*
another aolution:
doubling dp
*/

const int maxn=100+1,INF=1e+9;
long long int dp[maxn][30];

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        memset(dp,0,sizeof(dp));
        int len1=s1.length(),len2=s2.length();
        int l1=0,l2=0;

        /*
        以index = i(from s1)开始拼接一个s2所需的字符。
        */
        for (int i = 0; i < len1; i++)
        {
            int pos = i;
            dp[i][0] = 0;
            for (int j = 0; j < len2; j++)
            {
                int cnt = 0;
                while (s1[pos] != s2[j])
                {
                    pos = (pos + 1) % len1;
                    if (++cnt >= len1) return 0;
                }
                pos = (pos + 1) % len1;
                dp[i][0] += cnt + 1;
            }
        }

        for(int k=1;k<30;k++)
            for(int i=0;i<len1;i++)
            {
                dp[i][k]=dp[i][k-1]+dp[(i+dp[i][k-1])%len1][k-1];
            }
        long long int ans=0;
        int begin=0;
        for(int k=29;k>=0;k--)
            while((begin+dp[(begin%len1)][k])<=n1*len1)
            {ans+=(1<<k);begin+=dp[(begin%len1)][k];}
        return ans/n2;

    }
};
