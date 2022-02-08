#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int foo (const vector<int> &nums, int divisor) {
    int sum = 0;
    for (int i=0;i<nums.size();i+=1) {
        sum += ceil((double)nums[i]/divisor);
    }

    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = 1e6;

    while (low<high) {
        int mid = (low+high)/2;
        if (foo(nums, mid) <= threshold) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }

    return low ;
}

int main() {
    int arr[] = {962551,933661,905225,923035,990560};
    vector<int> nums(begin(arr), end(arr));
    int threshold = 10;

    printf("ans: %d\n", smallestDivisor(nums, threshold));
    return 0;
}