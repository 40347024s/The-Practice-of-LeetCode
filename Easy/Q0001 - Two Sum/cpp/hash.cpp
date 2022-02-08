#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> ans;
        auto iter = seen.end();
        for (int i = 0; i < nums.size(); i++)
        {
            iter = seen.find(target-nums[i]);
            if (iter!=seen.end()) {
                ans.push_back(iter->second);
                ans.push_back(i);
                return ans;
            }
            seen[nums[i]] = i;
        }
        return ans;   
    }
};

int main() {
    // c language
    int nums[4] = {15, 11, 7, 2};
    int returnSize = -1;
    int numsSize = sizeof(nums)/sizeof(int);
    // int *ans = twoSum(nums, numsSize, 9, &returnSize);
    // printf("%d %d\n", ans[0], ans[1]);

    // c++ 
    vector<int> nums2(&nums[0], &nums[numsSize]);
    Solution sol;
    vector<int> ans2 = sol.twoSum(nums2, 9);
    cout << ans2[0] << " " << ans2[1] << endl;
    return 0;
}