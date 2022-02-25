#include <vector>
#include <string>
#include <cstdio>
#include <unistd.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *GenerateList(vector <int> list) {
    ListNode *head = nullptr;
    while (list.size()) {
        ListNode *node = new ListNode;
        node->val = list.back();
        node->next = head;
        head = node;
        list.pop_back();
    }
    return head;
}

ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
    ListNode *head = nullptr;
    ListNode *cur = nullptr;
    while (list1!=nullptr || list2!=nullptr) {
        int val1 = list1 ? list1->val : 101;
        int val2 = list2 ? list2->val : 101;
        if (val1 <= val2) {
            if (!head) {
                head = list1;
            }
            else {
                cur->next = list1;
            }
            cur = list1;
            list1 = list1->next;
        }
        else {
            if (!head) {
                head = list2;
            }
            else {
                cur->next = list2;
            }
            cur = list2;
            list2 = list2->next;
        }
    }
    return head;
}

void merge(ListNode *major, ListNode *minor) {
    ListNode *head = major, *cur = head;
    while (major && minor) {
        if (major->val <= minor->val) {
            if (cur!=major) {
                cur->next = major;
            }
            cur = major;
            major = major->next;
        }
        else {
            if (cur!=minor) {
                cur->next = minor;
            }
            cur = minor;
            minor = minor->next;
        }
    }
    if (minor) {
        cur->next = minor;
    }
    if (major) {
        cur->next = major;
    }
    major = head;
}

ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    if (list1->val <= list2->val) {
        merge(list1, list2);
        return list1;
    }
    else {
        merge(list2, list1);
        return list2;
    }
}

string List2String(ListNode *head) {
    ListNode *cur = head;
    string str("[");
    while (cur) {
        str += to_string(cur->val) + ", ";
        cur = cur->next;
    }
    str = str.substr(0, str.length()-2);
    str += "]";
    return str;
}

int main() {
    vector <vector <int>> testcase_list1 = {{1,2,4}, {}, {}, {2}};
    vector <vector <int>> testcase_list2 = {{1,2,4}, {}, {0}, {1}};
    for (int i=0; i<testcase_list1.size(); i++) {
        // Method 1
        printf("%s + %s = %s\n", List2String(GenerateList(testcase_list1[i])).c_str(), List2String(GenerateList(testcase_list2[i])).c_str(), List2String(mergeTwoLists1(GenerateList(testcase_list1[i]), GenerateList(testcase_list2[i]))).c_str());
        
        // Method 2: Solution
        printf("%s + %s = %s\n", List2String(GenerateList(testcase_list1[i])).c_str(), List2String(GenerateList(testcase_list2[i])).c_str(), List2String(mergeTwoLists2(GenerateList(testcase_list1[i]), GenerateList(testcase_list2[i]))).c_str());
    }
    return 0;
}