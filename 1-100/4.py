from math import ceil
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        array = nums1
        array.extend(nums2)
        array.sort()
        if len(array) % 2 == 0:
            return float((array[len(array) / 2 -1] + array[len(array) / 2])) / 2
        else:
            return array[int(ceil(len(array) / 2))]