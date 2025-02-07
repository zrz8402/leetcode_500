#include <iostream>
#include <unordered_set>
#include <unordered_map>
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

    int lengthOfLongestSubstring2(string s) {
        unordered_map<char, int> charmap;
        int left = 0;
        int maxLen = 0;
        int n = s.length();
    
        for (int right = 0; right < n; right++) {
            if (charmap.find(s[right]) != charmap.end()) {
                left = max(left, charmap[s[right]] + 1);
            }
            charmap[s[right]] = right;
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

    assert(sol.lengthOfLongestSubstring2("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring2("bbbbb") == 1);
    assert(sol.lengthOfLongestSubstring2("pwwkew") == 3);
    assert(sol.lengthOfLongestSubstring2("") == 0);
    assert(sol.lengthOfLongestSubstring2("a") == 1);

    cout << "All tests passed!" << endl;
    return 0;
}