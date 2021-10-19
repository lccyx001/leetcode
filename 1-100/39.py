class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        def dfs(sums,path):
            if sums == 0 and sorted(path) not in res:
                res.append(sorted(path[:]))
                return
            for ca in candidates:
                if ca > sums:
                    continue
                dfs(sums-ca,path + [ca])

        dfs(target,[])
        return res