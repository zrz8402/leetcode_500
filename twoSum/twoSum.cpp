#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> num_map;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};
        }

        num_map[nums[i]] = i;
    }

    return vector<int>{};
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    assert((result1 == vector<int>{0, 1}) || (result1 == vector<int>{1, 0}));

    vector<int> nums5 = {1, 2, 3};
    int target5 = 6;
    vector<int> result5 = twoSum(nums5, target5);
    assert(result5.empty());

    cout << "All test cases passed!" << endl;
    return 0;
}