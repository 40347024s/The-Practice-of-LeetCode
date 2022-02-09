#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

int findPairs1(vector<int>& nums, int k) {
    map<pair<int, int>, bool> seen;
    int ans = 0;
    for (int i=0; i<nums.size(); i++) {
        for (int j=i+1; j<nums.size(); j++) {
            int val1 = min(nums[i], nums[j]), val2 = nums[i] + nums[j] - val1;
            auto iter = seen.find({val1, val2});
            if (iter!=seen.end()) {
                continue;
            }
            if (val2-val1==k) {
                ans += 1;
                seen[{val1, val2}] = true;
            }
        }
    }
    return ans;
}

int findPairs2(vector<int>& nums, int k) {
    map<int, int> seen;
    int ans = 0;
    for (int i=0; i<nums.size(); i++) {
        auto iter = seen.find(nums[i]);
        if (iter==seen.end()) {
            seen[nums[i]] = 1;
        }
        else {
            iter->second += 1;
        }
    }
    for (auto iter=seen.begin(); iter!=seen.end(); iter++) {
        if (k==0 && iter->second>=2) {
            ans += 1;
        }
        else if (k>0 && seen.find(iter->first+k)!=seen.end()) {
            ans += 1;
        }
    }
    return ans;
}
int main() {
    vector<int> testcase_arr[4] = {{3,1,4,1,5}, {1,2,3,4,5}, {1,3,1,5,4}, {1,2,4,4,3,3,0,9,2,3}};
    int testcase_int[4] = {2, 1, 0, 3};
    for (int i=0; i< 4; i++) {
        // Method1: Naive 
        cout << findPairs1(testcase_arr[i], testcase_int[i]) << endl;

        // Method2: O(N)
        cout << findPairs2(testcase_arr[i], testcase_int[i]) << endl;
    }
    return 0;
}
