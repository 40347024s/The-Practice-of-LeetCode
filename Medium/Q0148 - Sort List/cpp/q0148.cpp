#include <cstdio>
#include <vector> 
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList (ListNode* head) {
    ListNode *cur = head;
    while (cur) {
        printf("%d, ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

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

ListNode* sortList(ListNode* head) {
    vector <int> list_val;
    while (head) {
        list_val.push_back(head->val);
        head = head->next;
    }
    sort(list_val.begin(), list_val.end());
    ListNode *ans = GenerateList(list_val);
    return ans;
}

int main () {
    vector <vector <int>> testcase_heads = {{4,2,1,3}, {-1,5,3,4,0}, {}};
    
    for (int i=0; i<testcase_heads.size(); i++) {
        printf("====== Testcase %d ======\n", i);
        // Method 1: Accepted, Time Complexity: O(nlogn), space complexity: O(n)
        printf("Method 1:\n");
        PrintList(GenerateList(testcase_heads[i]));
        PrintList(sortList(GenerateList(testcase_heads[i])));
        // Method 2: Solution, Time Complexity: O(nlogn), space complexity: O(n)
        printf("Method 2:\n");
    }

    vector <int> arr = {0,6,4,7,3,8,2,9,1,5};
    QuickSort(arr, 0, arr.size());
    for (int num: arr) {
        printf("%d, ", num);
    }
    printf("\n");
    return 0;
}