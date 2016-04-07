import operator

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = {}
        for num in nums:
            if num not in count:
                count[num] = 0
            count[num] += 1
        return max(count.iteritems(), key=operator.itemgetter(1))[0]
            
        