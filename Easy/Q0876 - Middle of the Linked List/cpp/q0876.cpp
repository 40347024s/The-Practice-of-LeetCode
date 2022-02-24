#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *GenerateList(vector<int> testcase) {
    ListNode *head = nullptr;
    while (testcase.size()) {
        ListNode *node = new ListNode;
        node->val = testcase.back();
        node->next = head;
        head = node;
        testcase.pop_back();        
    }
    return head;
}

ListNode* middleNode1(ListNode* head) {
    int cur_idx = 0;
    int len = 0;
    ListNode *ans = head;
    while (head) {
        len++;
        if (len/2!=cur_idx) {
            ans = ans->next;
            cur_idx++;
        }
        head = head->next;
    }
    return ans;
}

ListNode* middleNode2(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

using namespace std;

int main() {
    vector <vector<int>> testcase_heads = {{1,2,3,4,5}, {1,2,3,4,5,6}};
    for (int i=0; i<testcase_heads.size(); i++) {
        // Method 1
        printf("method 1, mid = %d\n", middleNode1(GenerateList(testcase_heads[i]))->val);

        // Method 2: Solution, Fast and Slow pointer
        printf("method 2, mid = %d\n", middleNode2(GenerateList(testcase_heads[i]))->val);
    }
    return 0;
}