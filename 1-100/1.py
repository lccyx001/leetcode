class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return []
        
        arr_len = len(nums) 
        for i in range(arr_len):
            for j in range(arr_len - 1, i, -1):
                if nums[i] + nums[j] == target and i != j:
                    return [i, j]