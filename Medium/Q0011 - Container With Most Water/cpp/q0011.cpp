#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int maxArea1(vector<int>& height) {
    int height_size = (int) height.size();
    int max_area = INT32_MIN;
    int cur_area;
    for (int i=0; i<height_size; i++) {
        for (int j=i+1; j<height_size; j++) {
            cur_area = min(height[i], height[j]) * (j - i);
            if (cur_area > max_area) {
                max_area = cur_area;
            }
        }
    }
    return max_area;
}

int maxArea2(vector<int>& height) {
    int height_size = (int) height.size();
    int max_area = INT32_MIN;
    int rhs = 0, lhs = height_size - 1;
    while (rhs < lhs) {
        max_area = max(max_area, (lhs-rhs)*min(height[rhs], height[lhs]));
        if (height[rhs] <= height[lhs]) {
            rhs++;
        }
        else {
            lhs--;
        }
    }
    return max_area;
}

int main () {
    vector<vector<int>> testcase_height = {{1,8,6,2,5,4,8,3,7}, {1,1}, {2,3,4,5,9,9,5,4,3,2}};
    
    for (int i=0; i<testcase_height.size(); i++) {
        // Method 1: Brute force, timeout
        printf("[");
        for (int num: testcase_height[i]) {
            printf("%d, ", num);
        }
        printf("] -> max area = %d\n", maxArea1(testcase_height[i]));

        // Method 2: Solution
        printf("[");
        for (int num: testcase_height[i]) {
            printf("%d, ", num);
        }
        printf("] -> max area = %d\n", maxArea2(testcase_height[i]));
    }
    return 0;
}