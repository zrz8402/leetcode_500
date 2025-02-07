#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int maxCur = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxCur = max(maxCur + nums[i], nums[i]);
            maxSum = max(maxSum, maxCur);
        }
        return maxSum;
    }
};
