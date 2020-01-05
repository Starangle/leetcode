class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        s,h,ns,p=list(s),dict(),[],dict()
        for i,a in enumerate(s):h[a]=i
        for i,a in enumerate(s):
            if a in p and p[a]==True:continue
            while len(ns)>0 and h[s[ns[-1]]]>i and s[ns[-1]]>a:
                x=ns.pop()
                p[s[x]]=False
            if a not in p or p[a]==False:
                ns.append(i)
                p[a]=True
        ns=[s[i] for i in ns]
        return ''.join(ns)