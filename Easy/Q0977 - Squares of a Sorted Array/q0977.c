#include <stdlib.h>
#include <stdio.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int *outputs = (int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int from = 0, end = numsSize-1;
    int count = numsSize-1;
    while (end>=from)
    {
        int rval = nums[from]*nums[from];
        int lval = nums[end]*nums[end];
        if (rval >= lval) {
            outputs[count--]=rval;
            from++;
            // rval = nums[from]*nums[from];
        }
        else {
            outputs[count--]=lval;
            end--;
            // lval = nums[end]*nums[end];
        }
    }
    
    return outputs;
}
int main() {
    int nums[] = {-4,-1,0,3,10};
    int return_size = -1;
    int *outputs = sortedSquares(nums, sizeof(nums)/sizeof(int), &return_size);
    int i = 0;
    for (i = 0; i < sizeof(nums)/sizeof(int); i++)
    {
        printf("%d ", outputs[i]);
    }
    printf("\n");
    return 0;
}
