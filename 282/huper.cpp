/*
思路：
传统的回溯，直观的思想是不断parse新的数字并尝试不同的运算，在深搜栈保留已经计算的数字。
终止条件是无剩余问题并且栈内数字等于目标值。

但是由于乘法优先级高，所以需要在深搜栈中保存上一次parse出来的数字。

parse数字中一个常见的问题是以0开头的数字不能超过一位。
*/

#define ll long long

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        search(num, target, 0, 1, 0, "");
        return res;
    }

    void search(const string& num, int target, int index, ll pre, ll sum, string temp) {
        if(index == num.size()) {
            if(sum == target) res.push_back(temp);
        }
        
        int len = temp.size();

        for(int i = index; i < num.size(); ++i) {
            string sn = num.substr(index, i - index + 1);
            ll n = stol(sn);

            if(index == 0) {
                temp += sn;
                search(num, target, i + 1, n, n, temp);
                temp.resize(len);
            }
            else {
                temp += "+" + sn;
                search(num, target, i + 1, n, sum + n, temp);
                temp.resize(len);

                temp += "-" + sn;
                search(num, target, i + 1, -n, sum - n, temp);
                temp.resize(len);

                temp += "*" + sn;
                search(num, target, i + 1, pre * n, sum - pre + pre * n, temp);
                temp.resize(len);
            }
            if(n == 0) return;
        }
    }

private:
    vector<string> res;
};