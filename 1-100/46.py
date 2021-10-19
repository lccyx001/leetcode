class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # 需要考虑的问题有, 如何对结果树进行搜索 dfs？wfs？
        # 找到结果如何退出递归？
        size = len(nums)
        res = []
        path = []
        used = [False for _ in range(size)]
        self.dfs(res,path,used,size,nums)
        return res
    
    def dfs(self,res,path,used,size,nums):
        if len(path) == size:
            res.append(path[:])
            return 
        
        for i in range(size):
            if not used[i]:
                path.append(nums[i])
                used[i] = True
                self.dfs(res,path,used,size,nums)
                used[i] = False
                path.pop()



    

        
            

