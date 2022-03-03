#include <vector>
#include <cstdio>

using namespace std;

int numberOfArithmeticSlices1(vector<int>& nums) {
    if (nums.size()<=2) {
        return 0;
    }
    int ans = 0;
    int cnt = 1;
    int prev_diff = nums[1] - nums[0];
    for (int i=2; i<nums.size(); i++) {
        if ((nums[i] - nums[i-1]) == prev_diff) {
            cnt += 1;
        }
        else {
            if (cnt>=2) {
                
                ans += cnt*(cnt-1)/2;
            }
            cnt = 1;
        }
        prev_diff = nums[i] - nums[i-1];
    }
    if (cnt>=2) {
        ans += cnt*(cnt-1)/2;
    }
    return ans;
}

int numberOfArithmeticSlices2(vector<int>& nums) {
    int n = nums.size();
    if (n<=2) {
        return 0;
    }
    int prev_diff = nums[1] - nums[0];
    int ans = 0;
    int cnt = 1;
    for (int i=2; i<n; i++) {
        int cur_diff = nums[i] - nums[i-1];
        if (cur_diff == prev_diff) {
            ans += cnt++;
        }
        else {
            cnt = 1;
            prev_diff = cur_diff;
        }
    }
    return ans;
}

 int numberOfArithmeticSlices3(vector<int>& nums) {
    int n=nums.size();
    if(n<3)
    return 0;
    int s1=0,ans=0;
    for(int i=2;i<n;i++)
    {
        if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]) 
        {
            ans+=++s1;
        }
        else
        { 
            s1=0;
        }
        
        
    }
    return ans;
}

int main() {
    vector <vector <int>> testcase_nums = {{1,2,3,4}, {1}};
    for (int i=0; i<testcase_nums.size(); i++) {
        // Method 1
        printf("[");
        for (int n: testcase_nums[i]) {
            printf("%d, ", n);
        }
        printf("] -> %d\n", numberOfArithmeticSlices1(testcase_nums[i]));

        // Method 2: Modified from Method 1
        printf("[");
        for (int n: testcase_nums[i]) {
            printf("%d, ", n);
        }
        printf("] -> %d\n", numberOfArithmeticSlices2(testcase_nums[i]));

        // Method 3: Solution
        printf("[");
        for (int n: testcase_nums[i]) {
            printf("%d, ", n);
        }
        printf("] -> %d\n", numberOfArithmeticSlices3(testcase_nums[i]));
    }
    return 0;
}