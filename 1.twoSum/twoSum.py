from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i, num in enumerate(nums):
            complement = target - num
            if (complement) in num_map:
                return [num_map[complement], i]
            num_map[num] = i
        return []

# sol = Solution()
# print(sol.twoSum([2, 7, 11, 15], 9))

import unittest

class TestTwoSum(unittest.TestCase):
    def test_two_sum(self):
        sol = Solution()
        self.assertEqual(sol.twoSum([2, 7, 11, 15], 9), [0, 1])
        self.assertEqual(sol.twoSum([3, 2, 4], 6), [1, 2])
        self.assertEqual(sol.twoSum([3, 3], 6), [0, 1])

if __name__ == "__main__":
    unittest.main()