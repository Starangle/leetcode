class Solution:
    def trap(self, height: List[int]) -> int:
        hmax,hmax_idx=0,0
        for i,h in enumerate(height):
            if h>hmax:hmax,hmax_idx=h,i
        r1,hb=0,0
        for i,h in enumerate(height[:hmax_idx]):
            if h>hb:hb=h
            else:r1+=hb-h
        r2,hb=0,0
        for i,h in enumerate(height[-1:hmax_idx:-1]):
            if h>hb:hb=h
            else:r2+=hb-h
        return r1+r2