from typing import List

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = max_cur = nums[0]
        for i in range(1, len(nums)):
            max_cur = max(nums[i], max_cur + nums[i])
            max_sum = max(max_sum, max_cur)
        return max_sum

sol = Solution()
print(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))

import unittest

class TestMaxSubArray(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
    
    def test_cases(self):
        self.assertEqual(self.solution.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]), 6)
        self.assertEqual(self.solution.maxSubArray([1]), 1)
        self.assertEqual(self.solution.maxSubArray([5,4,-1,7,8]), 23)
        
if __name__ == "__main__":
    unittest.main()