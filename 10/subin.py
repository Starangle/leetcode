class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if s==p:return True
        self.s,self.p=list(s),list(p)
        return self.check(len(self.s)-1,len(self.p)-1)
    
    def zero(self,j):
        if j%2==0:return False
        for k in range(1,j+1,2):
            if self.p[k]!='*':return False
        return True

    def check(self,i,j):
        if i==-1:
            if j==-1 or self.zero(j):return True
            else:return False
        if j==-1:return False
        

        if self.s[i]==self.p[j] or self.p[j]=='.':
            if self.check(i-1,j-1): return True
        if self.p[j]=='*':
            if self.check(i,j-2):return True
            if self.s[i]==self.p[j-1] or self.p[j-1]=='.':
                if self.check(i-1,j-2) or self.check(i-1,j):return True

        return False