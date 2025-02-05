class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        charset = set()
        left = 0
        max_len = 0
    
        for right in range(len(s)):
            while s[right] in charset:
                charset.remove(s[left])
                left += 1
            charset.add(s[right])
            max_len = max(max_len, right - left + 1)

        return max_len

sol = Solution()
print(sol.lengthOfLongestSubstring("abcabcbb"))

import unittest

class TestLengthOfLongestSubstring(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()

    def test_cases(self):
        self.assertEqual(self.solution.lengthOfLongestSubstring("abcabcbb"), 3)  # "abc"
        self.assertEqual(self.solution.lengthOfLongestSubstring("bbbbb"), 1)  # "b"
        self.assertEqual(self.solution.lengthOfLongestSubstring("pwwkew"), 3)  # "wke"
        self.assertEqual(self.solution.lengthOfLongestSubstring(""), 0)  # empty string
        self.assertEqual(self.solution.lengthOfLongestSubstring("au"), 2)  # "au"
        self.assertEqual(self.solution.lengthOfLongestSubstring("dvdf"), 3)  # "vdf"

if __name__ == "__main__":
    unittest.main()