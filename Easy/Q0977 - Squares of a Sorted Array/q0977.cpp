#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> outputs(nums.size(), 0);
        int from = 0, end = nums.size()-1;
        int count = nums.size()-1;
        while (end>=from)
        {
            int rval = nums[from]*nums[from];
            int lval = nums[end]*nums[end];
            if (rval >= lval) {
                outputs[count--]=rval;
                from++;
                // rval = nums[from]*nums[from];
            }
            else {
                outputs[count--]=lval;
                end--;
                // lval = nums[end]*nums[end];
            }
        }
        
        return outputs;
        
    }
};

int main() {
    vector<int> nums{-3, -1, 0, 1, 1, 2, 4, 8, 100};
    Solution s;
    vector<int> outputs = s.sortedSquares(nums);
    // for (int i=0;i<nums.size();i+=1) {
    //     outputs[i] = nums[i]*nums[i];
    // }
    // sort(outputs.begin(), outputs.end());
    for (auto &e: outputs){
        cout << e << " ";
    }
    cout << endl;
    return 0;
}
