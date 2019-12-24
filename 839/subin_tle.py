import itertools
import math
import time
class Solution:
    def similar(self,x:str,y:str) -> bool:
        l,dc=len(x),0
        swap_record=None

        if l==0:
            return False

        for i in range(l):
            if x[i]!=y[i]:
                if dc==0:
                    swap_record=x[i],y[i]
                    dc+=1
                elif dc==1:
                    a,b=swap_record
                    if not (a==y[i] and b==x[i]):
                        return False
                    dc+=1
                else:
                    return False
        if dc!=2:
            return False
        return True


    def numSimilarGroups(self, A: List[str]) -> int:
        A=list(set(A))
        n=len(A)
        if n==0:
            return 0
        
        m=len(A[0])
        
        bt=time.time()
        if n**2*m<n*m**2*math.log2(n):
            # Build graph method 1: n<m
            link=[[self.similar(A[i],A[j]) if i<j else False for i in range(n)]\
                for j in range(n)] # n^2*m
        else:
            # Build graph method 2: n>m
            tab=dict(zip(A,range(n))) # n*logn
            link=[[False for i in range(n)] for j in range(n)]
            for strx in A: # n
                inode=tab[strx]
                x=list(strx)
                for i,j in itertools.product(range(m),range(m)): # m^2*logn
                    x[i],x[j]=x[j],x[i]
                    new_str_x=''.join(x)
                    if new_str_x in tab:
                        jnode=tab[new_str_x]
                        link[inode][jnode]=True
                    x[i],x[j]=x[j],x[i]
        print(time.time()-bt)

        # BFS
        vis=[0 for i in range(n)]
        count=0
        while min(vis)==0:
            x=-1
            for i,v in enumerate(vis):
                if v==0:
                    x=i
                    break
            
            count+=1
            q=[x,]
            vis[x]=1
            while len(q)!=0:
                i=q.pop(0)
                for j in range(n):
                    if vis[j]==0 and (link[i][j] or link[j][i]):
                        q.append(j)
                        vis[j]=1
        return count