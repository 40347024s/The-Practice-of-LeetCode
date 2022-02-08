#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> ans;
        for (int i = 0; i < nums.size()-1; i++)
        {
            int remind = target-nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if (remind==nums[j]) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
            
        }
        return ans;
    }
};

int main() {
    fstream file;
    file.open("../testcase.txt", fstream::in);
    if (!file.is_open()) {
        cout << "Cannot open test case file!!!" << endl;
        return -1;
    }
    while (!file.eof())
    {
        int numsSize;
        file >> numsSize;
        int nums[numsSize];
        for (int i=0;i<numsSize;i+=1) {
            file >> nums[i];
        }
        int target;
        file >> target;
        vector<int> nums2(&nums[0], &nums[numsSize]);
        Solution sol;
        cout << "array = [";
        for (int i=0;i<numsSize;i+=1) {
            cout << nums[i] << " ";
        }
        cout << "]" << endl;
        cout << "numsSize=" << numsSize << ", ";
        cout << "target=" << target << endl;

        vector<int> ans2 = sol.twoSum(nums2, target);
        cout << "[" << ans2[0] << "," << ans2[1] << "]" << endl;
        cout << "------------------------------" << endl;
    }

    T t;
    return 0;
}