int maxSubArray(int *nums, int numSize) {
    int max_sum = nums[0];
    int max_cur = nums[0];

    for (int i = 1; i < numSize; i++) {
        max_cur = (max_cur + nums[i] > nums[i]) ?  max_cur + nums[i] : nums[i];
        max_sum = (max_sum > max_cur) ? max_sum : max_cur;
    }
    return (max_sum);
}
