#include <iostream>
#include <cstdlib>

using namespace std;


// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        else {
            return max(maxDepth(root->left), maxDepth(root->right))+1;
        }
    }
};

TreeNode *BuildTree(const int arr[], int arr_size, int cur_index) {
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    if (cur_index>arr_size) {
        // printf("current build: NULL1\n");
        return NULL;
    }
    int val = arr[cur_index-1];
    if ((val>=(10^4)) || (val<=-(10^4))) {
        // printf("current build: NULL2\n");
        return NULL;
    }
    else {
        root->val = val;
    }
    // printf("current build: %d\n", root->val);
    root->right = BuildTree(arr, arr_size, cur_index*2+1);
    root->left = BuildTree(arr, arr_size, cur_index*2);

    return root;
}

int main() {
    Solution s;
    // [3,9,20,null,null,15,7]
    int arr[] = {1,2,2,3,3,10^5,10^5,4,4};
    TreeNode *root = BuildTree(arr, sizeof(arr)/sizeof(int), 1);

    cout << "Tree Depth:" << s.maxDepth(root) << endl;

    return 0;
}
