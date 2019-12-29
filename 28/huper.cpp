class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        int lh = haystack.size();
        int ln = needle.size();
        vector<int> next(needle.size(), 0);
        
        next[0] = -1;
        i = 0, j = -1;
        while(i < needle.size()) {
            if(j == -1 || needle[i] == needle[j]) {
                i++;
                j++;
                next[i] = j;
            } else {
                j = next[j];
            }
        }

        for(int i = 0; i < next.size(); ++i) {
            cout << next[i] << endl;
        }
        
        i = 0, j = 0;
        while(i < lh && j < ln) {
            if(j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }

        if(j == needle.size()) return i - j;
        else return -1;
    }
};