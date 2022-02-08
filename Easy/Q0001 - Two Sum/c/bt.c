#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(const int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *)malloc(sizeof(int)*2);
    int i, j;
    for (i=0; i<numsSize-1;i+=1) {
        int remind = target-nums[i];
        for (j=i+1; j<numsSize; j+=1) {
            if (remind==nums[j]) {
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;

                return ans;
            }
        }
        
    }
    return ans;
}

int main() {
    FILE *fp = fopen("../testcase.txt", "r");
    if (fp==NULL) {
        printf("Cannot load test case file!!!\n");
        return -1;
    }
    while (feof(fp)==0) {
        int i;
        int numsSize = 4;
        fscanf(fp, "%d", &numsSize);
        int nums[numsSize];
        printf("array: [");
        for (i = 0; i < numsSize; i++) {
            fscanf(fp, "%d", &nums[i]);
            printf("%d ", nums[i]);
        }
        printf("]\n");
        int target;
        fscanf(fp, "%d", &target);
        printf("numSize=%d, target=%d\n", numsSize, target);
        int ans[2];
        int returnSize;
        memcpy(ans, twoSum(nums, numsSize, target, &returnSize), sizeof(int)*2);
        printf("[%d,%d]\n", ans[0], ans[1]);
        printf("------------------------------\n");

    }
    fclose(fp);
    return 0;
}