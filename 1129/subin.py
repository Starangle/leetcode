class Solution:
    '''
    there maybe circle path with different color
    '''
    def shortestAlternatingPaths(self, n: int, red_edges: List[List[int]], blue_edges: List[List[int]]) -> List[int]:

        red_rouds=[[] for i in range(n)]
        for x,y in red_edges:
            red_rouds[x].append(y)

        blue_rouds=[[] for i in range(n)]
        for x,y in blue_edges:
            blue_rouds[x].append(y)

        inf=10000

        dis=[[inf,inf] for i in range(n)]
        vis=[[False,False] for i in range(n)]

        # init 
        dis[0]=[0,0]
        
        while True:
            x,c,d=None,None,inf # x:begin c:color(0/1) d:distance
            for i,ods in enumerate(dis):
                if d>ods[0] and not vis[i][0]:
                    x,c,d=i,0,ods[0]
                if d>ods[1] and not vis[i][1]:
                    x,c,d=i,1,ods[1]
            if x is None:
                break
            vis[x][c]=True

            # update path
            ups=blue_rouds[x] if c==0 else red_rouds[x]
            nc=1-c

            for y in ups:
                if dis[y][nc]>dis[x][c]+1:
                    dis[y][nc]=dis[x][c]+1
        merge=lambda x: min(x) if min(x)<inf else -1
        ans=list(map(merge,dis))
        return ans