#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> threeSum1(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map <int, unordered_map<int, int>> seen;
    sort(nums.begin(), nums.end());
    for (int i=0; i<nums.size(); i++) {
        for (int j=i+1; j<nums.size(); j++) {
            for (int k=j+1; k<nums.size(); k++) {
                if (nums[i]+nums[j]+nums[k]==0) {
                    if (seen.find(nums[i])!=seen.end()) {
                        if (seen[nums[i]].find(nums[j])!=seen[nums[i]].end()) {
                            continue;
                        }
                    }
                    seen[nums[i]][nums[j]] = nums[k];
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSum2(vector<int>& nums) {
    vector<vector<int>> ans;
    unordered_map <int, bool> layer1_seen;
    sort(nums.begin(), nums.end());
    for (int i=0; i<nums.size(); i++) {
        if (layer1_seen.find(nums[i])!=layer1_seen.end()) {
            continue;
        }
        unordered_map <int, bool> layer2_seen;
        for (int j=i+1; j<nums.size(); j++) {
            if (layer2_seen.find(nums[j])!=layer2_seen.end()) {
                continue;
            }
            unordered_map <int, bool> layer3_seen;
            for (int k=j+1; k<nums.size(); k++) {
                if (layer3_seen.find(nums[k])!=layer3_seen.end()) {
                    continue;
                }
                if (nums[i]+nums[j]+nums[k]==0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
                layer3_seen[nums[k]] = 1;
            }
            layer2_seen[nums[j]] = 1;
        }
        layer1_seen[nums[i]] = 1;
    }

    return ans;
}

vector<vector<int>> threeSum3(vector<int>& nums) {
    vector<vector<int>> ans;
    if (!nums.size()) {
        return ans;
    }
    sort(nums.begin(), nums.end());
    int prev = nums[0] - 1;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]==prev) {
            continue;
        }
        prev = nums[i];
        int target = -1 * nums[i];
        int key_thresh = INT32_MIN;
        unordered_map <int, int> seen;
        for (int j=i+1; j<nums.size(); j++) {
            if (seen.find(nums[j])!=seen.end() && nums[j]>key_thresh) {
                ans.push_back({nums[i], nums[seen[nums[j]]], nums[j]});
                key_thresh = nums[j];
            }
            else {
                seen[target - nums[j]] = j;
            }
        }
    }
    return ans;
}

vector<vector<int>> threeSum4(vector<int>& nums) {
    vector<vector<int>> ans;
    return ans;
}

int main() {
    vector <vector<int>> testcase_nums = {{-1,0,1,2,-1,-4}, {}, {0}, {-1,0,1,2,-1,-4, -1,0,1,2,-1,-4}};
    for (int i=0; i<testcase_nums.size(); i++) {
        printf("===========================\n");
        printf("testcase %d\n", i+1);
        printf("Input: [");
        for (int j=0; j<testcase_nums[i].size(); j++) {
            printf("%d, ", testcase_nums[i][j]);
        }
        printf("]\n");
        // Method 1: Brute force, timeout
        printf("Output1: ");
        for (vector<int> ans: threeSum1(testcase_nums[i])) {
            printf("[");
            for (int j=0; j<ans.size(); j++) {
                printf("%d, ", ans[j]);
            }
            printf("], ");
        }
        printf("\n");

        // Method 2: Timeout
        printf("Output2: ");
        for (vector<int> ans: threeSum2(testcase_nums[i])) {
            printf("[");
            for (int j=0; j<ans.size(); j++) {
                printf("%d, ", ans[j]);
            }
            printf("], ");
        }
        printf("\n");

        // Method 3: Accepted
        printf("Output3: ");
        for (vector<int> ans: threeSum3(testcase_nums[i])) {
            printf("[");
            for (int j=0; j<ans.size(); j++) {
                printf("%d, ", ans[j]);
            }
            printf("], ");
        }
        printf("\n");

        // // Method 4: Accepted
        // printf("Output4: ");
        // for (vector<int> ans: threeSum4(testcase_nums[i])) {
        //     printf("[");
        //     for (int j=0; j<ans.size(); j++) {
        //         printf("%d, ", ans[j]);
        //     }
        //     printf("], ");
        // }
        // printf("\n");
    }
    return 0;
}