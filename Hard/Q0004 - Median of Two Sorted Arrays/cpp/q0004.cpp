#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;
    int it1 = 0, it2 = 0;
    while (it1 < nums1.size() && it2 < nums2.size()) {
        if (nums1[it1] <= nums2[it2]) {
            nums.push_back(nums1[it1]);
            it1 += 1;
        }
        else {
            nums.push_back(nums2[it2]);
            it2 += 1;
        }
    }
    while (it1 < nums1.size()) {
        nums.push_back(nums1[it1]);
        it1 += 1;
    }
    while (it2 < nums2.size()) {
        nums.push_back(nums2[it2]);
        it2 += 1;
    }
    int mid_it = (nums.size() - 1)/2;
    double ans = nums.size()%2==0 ? (nums[mid_it] + nums[mid_it+1])/2.0 : nums[mid_it];
    return ans;
}
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        int it1 = 0, it2 = 0;
        int i = 0;
        int last1 = 0, last2 = 0;
        while (i < (nums1.size()+nums2.size())/2 + 1) {
            last1 = last2;
            if (it1 < nums1.size() && it2 < nums2.size()) {
                if (nums1[it1] <= nums2[it2]) {
                    last2 = nums1[it1];
                    it1 += 1;
                    i += 1;
                }
                else {
                    last2 = nums2[it2];
                    it2 += 1;
                    i += 1;
                }
            }
            else if (it1 < nums1.size()) {
                last2 = nums1[it1];
                it1 += 1;
                i += 1;
            }
            else if (it2 < nums2.size()) {
                last2 = nums2[it2];
                it2 += 1;
                i += 1;
            }
        }
        if ((nums1.size() + nums2.size())%2==0) {
            return (last1 + last2)/2.0;
        }
        else {
            return last2;
        }
    }
int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    // Method1: Merge two vector into a new vector, waste memory
    cout << "ans:" << findMedianSortedArrays1(nums1, nums2) << endl;

    // Method2: O(n) solution without create a new vector
    cout << "ans:" << findMedianSortedArrays2(nums1, nums2) << endl;
    return 0;
}