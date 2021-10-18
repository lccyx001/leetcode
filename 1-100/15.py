class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums_dict = {}
        for num in nums:
            if nums_dict.get(num):
                nums_dict[num] += 1
            else:
                nums_dict[num] = 1
        if nums_dict.get(0)>2:
            result = [[0,0,0]]
        else:
            result = []
        positives = [p for p in nums_dict.keys() if p >0]
        negatives = [q for q in nums_dict.keys() if q <0]
        for p in positives:
            for q in negatives:
                s = -(p+q)
                if not nums_dict.get(s):
                    continue
                if s == 0:
                    result.append([p,q,s])
                elif s==p and nums_dict.get(p) > 1:
                    result.append([p,q,s])
                elif s == q and nums_dict.get(q) > 1:
                    result.append([p,q,s])
                elif s > p or s < q:
                    result.append([p,q,s])
        return result