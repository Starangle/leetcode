class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        s,p=list(haystack),list(needle)
        if len(p)==0:return 0
        if len(s)==0:return -1
        kmp,i,k=[0 for i in range(len(p))],0,-1
        kmp[0]=-1
        while i<len(p):
            if k==-1 or p[i]==p[k]:
                k+=1
                i+=1
                if i<len(p):kmp[i]=k
            else:
                k=kmp[k]
        
        i,j=0,0
        while i<len(s):
            if j==len(p):break
            if s[i]==p[j]:
                j+=1
                i+=1
            elif j!=-1:
                j=kmp[j]
            else:
                i+=1
                j=0
        return i-j if j==len(p) else -1