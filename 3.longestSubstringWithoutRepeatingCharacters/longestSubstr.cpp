#include <iostream>
#include <unordered_set>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charset;
        int left = 0;
        int maxLen = 0;
        int n = s.length();
    
        for (int right = 0; right < n; right++) {
            while (charset.find(s[right]) != charset.end()) {
                charset.erase(s[left]);
                left++;
            }
            charset.insert(s[right]);
            maxLen = max(maxLen, right - left + 1); 
        }
        
        return maxLen;
    }
};

int main( void ) {
    Solution sol;
    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring("bbbbb") == 1);
    assert(sol.lengthOfLongestSubstring("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstring("") == 0);
    assert(sol.lengthOfLongestSubstring("a") == 1);
    
    cout << "All tests passed!" << endl;
    return 0;
}