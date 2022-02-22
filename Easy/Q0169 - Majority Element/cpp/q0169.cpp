#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int majorityElement1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

int majorityElement2(vector<int>& nums) {
    int ans = nums[0];
    int cnt = 0;
    for (auto num: nums) {
        if (cnt==0) {
            ans = num;
            cnt = 1;
        }
        else if (num == ans) {
            cnt++;
        }
        else {
            cnt--;
        }
    }
    return ans;
}

int main() {
    vector<int> testcase_nums [2] = {{3,2,3}, {2,2,1,1,1,2,2}};
    for (int i=0; i<2; i++) {
        // Method 1: Sorting, Time complexity => O(nlogn),Space complexity => O(1)
        cout << majorityElement1(testcase_nums[i]) << endl;

        // Method 2: Boyer–Moore majority vote algorithm, Time complexity => O(n),Space complexity => O(1)
        cout << majorityElement2(testcase_nums[i]) << endl;
    }
    return 0;
}
