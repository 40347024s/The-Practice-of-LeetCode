#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNode *GenerateList (vector<int> arr, int pos) {
    ListNode *head = nullptr, *tail = nullptr;
    while (arr.size()) {
        ListNode *node = new ListNode(arr.back());
        node->next = nullptr;
        if (head) {
            node->next = head;
        }
        else {
            tail = node;
        }
        head = node;
        arr.pop_back();
    }
    ListNode *cur = head;
    for (int i=0; i<pos; i++) {
        if (!cur) {
            cur = cur->next;
        }
    }
    if (pos >=0 ) {
        tail->next = cur;
    }
    
    return head;
}

bool hasCycle(ListNode *head) {
    unordered_map<ListNode *, bool> seen;
    cout << "[ ";
    while (head) {
        cout << head->val << ", ";
        if (seen.find(head)!=seen.end()) {
            cout << "] -> ";
            return true;
       }
        seen[head] = true;
        head = head->next;
    }
    cout << "] -> ";
    return false;
}

int main()
{
    vector <vector<int>> testcase_arr = {{3, 2, 0, -4}, {1, 2}, {1}};
    vector <int> testcase_pos = {1, 0, -1};
    for (int i=0; i<testcase_pos.size(); i++) {
        ListNode *ll = GenerateList(testcase_arr[i], testcase_pos[i]);
        cout << hasCycle(ll) << endl;
    }
    return 0;
}