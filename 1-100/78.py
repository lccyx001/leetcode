class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ars = []
        n = len(nums)
        def dfs(idx,arr):
            ars.append(arr)
            for j in range(idx,n):
                dfs(j+1,arr+[nums[j]])
        dfs(0,[])
        return ars