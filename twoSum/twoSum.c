/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return (result);
            }
        }
    }
    *returnSize = 0;
    return (NULL);
}

int main(void) {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);
    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }
    else {
        printf("No solution found\n");
    }

    int nums1[] = {3, 2, 4};
    int target1 = 6;
    int returnSize1;
    int *result1 = twoSum(nums1, 3, target1, &returnSize1);
    if (result1 != NULL) {
        printf("[%d, %d]\n", result1[0], result1[1]);
        free(result1);
    }
    else {
        printf("No solution found\n");
    }
}
