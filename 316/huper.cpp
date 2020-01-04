/*
solution: 
1. 使用单调栈来实现字典序的需求（vector一类的数据结构也可以实现栈的功能）。
2. 使用位运算和一个int来实现set的功能。
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int ch[26];
        memset(ch, 0, sizeof ch);
        for (auto &i : s) {
            ++ch[i - 'a'];
        }
        // 当前结果中有没有某个字母
        int bitmap = 0;
        string ans;
        for (auto &i : s) {
            int c = i - 'a';
            --ch[c];
            if ((1 << c) & bitmap) continue; //
            while (!ans.empty() && i <= ans.back() && ch[ans.back() - 'a']) {
                bitmap ^= 1 << (ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(i);
            bitmap |= 1 << c;
        }
        return ans;
    }
};