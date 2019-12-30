class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:return 1
        for i in range(n):
            if nums[i]>n or nums[i]<=0: nums[i]=0
        for i in range(n):
            v=nums[i]%(n+1)
            if v!=0:nums[v-1]=(v)*(n+1)+nums[v-1]
        for i in range(n):
            nums[i]=nums[i]//(n+1)
            if nums[i]==0:
                return i+1
        return n+1