#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int subarraySum1(vector<int>& nums, int k) {
    int ans = 0;
    for (int len=1; len<=nums.size(); len++) {
        for (int i=0; i<=nums.size()-len; i++) {
            int sum = 0;
            // printf("len=%d, i=%d\n", len, i);
            for (int j=i; j<i+len; j++) {
                sum += nums[j];
            }
            if (sum==k) {
                ans ++;
            }
        }
    }
    return ans;
}

int subarraySum2(vector<int>& nums, int k) {
    int ans = 0;
    map <pair<int, int>, int> prev_sums;
    map <pair<int, int>, int> cur_sums;
    for (int len=0; len<nums.size(); len++) {
        prev_sums.clear();
        prev_sums = cur_sums;
        cur_sums.clear();
        for (int i=0; i<nums.size()-len; i++) {
            auto iter = prev_sums.find({i, i+len-1});
            if (iter==prev_sums.end()) {
                cur_sums[{i, i+len}] = nums[i+len];
            }
            else {
                cur_sums[{i, i+len}] = iter->second + nums[i+len];
            }
            if (cur_sums[{i, i+len}]==k) {
                ans += 1;
            }
        }
    }
    return ans;
}

int subarraySum3(vector<int>& nums, int k) {
    int res = 0, sum = 0, n = nums.size();
    map<int, int> m{{0, 1}};
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        res += m[sum - k];
        m[sum]++;
    }
    return res;
}

int main() {
    // vector<int> testcase_nums[] = {{1,1,1}, {1,2,3}, {1, -1, 0}, {1, -1, 0, 1, -1, 0}, {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
    // vector<int> testcase_k = {2, 3, 0, 0, 2};
    vector<int> testcase_nums[] = {{1}, {1, 2}, {1, 2, 1}, {1, 2, 1, 3}, {-1, -1, 1, 2, 1, 3}};
    vector<int> testcase_k = {3, 3, 3, 3, 3};
    for (int i=0; i< testcase_k.size(); i++) {
        // Method1: Naive (Timeout)
        cout << subarraySum1(testcase_nums[i], testcase_k[i]) << " ";

        // Method2: Save history in std::map (Timeout)
        cout << subarraySum2(testcase_nums[i], testcase_k[i]) << " ";

        // Method3: O(N)
        cout << subarraySum3(testcase_nums[i], testcase_k[i]) << endl;
    }
    return 0;
}
