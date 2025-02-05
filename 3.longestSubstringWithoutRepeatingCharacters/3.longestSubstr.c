#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int charset[128] = {0};
    int left = 0;
    int max_len = 0;
    int n = strlen(s);

    for (int right = 0; right < n; right++) {
        while (charset[s[right]] > 0) {
            charset[s[left]]--;
            left++;
        }
        charset[s[right]]++;
        max_len = (right - left + 1) > max_len ? (right - left + 1) : max_len;
    }
    return (max_len);
}

void test(char* input, int expected) {
    int result = lengthOfLongestSubstring(input);
    printf("Input: %-10s | Expected: %2d | Output: %2d | %-4s\n", 
           input, expected, result, (result == expected) ? "PASS" : "FAIL");
}

int main(void) {
    printf("------------------------------------------------------\n");
    printf("Input             | Expected     | Output     | Result\n");
    printf("------------------------------------------------------\n");

    test("abcabcbb", 3);
    test("bbbbb", 1);
    test("pwwkew", 3);
    test("", 0);
    test("abcdef", 6);
    test("aabbcc", 2);
    test(" ", 1);
    test("abba", 2);
    test("dvdf", 3);

    printf("------------------------------------------------------\n");

    return 0;
}