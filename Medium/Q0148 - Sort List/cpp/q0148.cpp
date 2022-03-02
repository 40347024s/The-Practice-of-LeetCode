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

ListNode* sortList1(ListNode* head) {
    vector <int> list_val;
    while (head) {
        list_val.push_back(head->val);
        head = head->next;
    }
    sort(list_val.begin(), list_val.end());
    ListNode *ans = GenerateList(list_val);
    return ans;
}

// =============== method 2 ======================

ListNode* merge2(ListNode* list1, ListNode* list2) {
    ListNode dummyHead(0);
    ListNode* ptr = &dummyHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            ptr->next = list1;
            list1 = list1->next;
        } else {
            ptr->next = list2;
            list2 = list2->next;
        }
        ptr = ptr->next;
    }
    if(list1) ptr->next = list1;
    else ptr->next = list2;

    return dummyHead.next;
}

ListNode* getMid(ListNode* head) {
    ListNode* midPrev = nullptr;
    while (head && head->next) {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode* mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}

ListNode* sortList2(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList2(head);
    ListNode* right = sortList2(mid);
    return merge2(left, right);
}

// =============== method 3 ======================
ListNode* tail = new ListNode();
ListNode* nextSubList = new ListNode();

ListNode* split(ListNode* start, int size) {
    ListNode* midPrev = start;
    ListNode* end = start->next;
    //use fast and slow approach to find middle and end of second linked list
    for (int index = 1; index < size && (midPrev->next || end->next); index++) {
        if (end->next) {
            end = (end->next->next) ? end->next->next : end->next;
        }
        if (midPrev->next) {
            midPrev = midPrev->next;
        }
    }
    ListNode* mid = midPrev->next;
    nextSubList = end->next;
    midPrev->next = nullptr;
    end->next = nullptr;
    // return the start of second linked list
    return mid;
}

void merge3(ListNode* list1, ListNode* list2) {
    ListNode dummyHead(0);
    ListNode* newTail = &dummyHead;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            newTail->next = list1;
            list1 = list1->next;
            newTail = newTail->next;
        } else {
            newTail->next = list2;
            list2 = list2->next;
            newTail = newTail->next;
        }
    }
    newTail->next = (list1) ? list1 : list2;
    // traverse till the end of merged list to get the newTail
    while (newTail->next) {
        newTail = newTail->next;
    }
    // link the old tail with the head of merged list
    tail->next = dummyHead.next;
    // update the old tail with the new tail of merged list
    tail = newTail;
}

int getCount(ListNode* head) {
    int cnt = 0;
    ListNode* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        cnt++;
    }
    return cnt;
}

ListNode* sortList3(ListNode* head) {
    if (!head || !head -> next)
        return head;
    int n = getCount(head);
    ListNode* start = head;
    ListNode dummyHead(0);
    for (int size = 1; size < n; size = size * 2) {
        tail = &dummyHead;
        while (start) {
            if (!start->next) {
                tail->next = start;
                break;
            }
            ListNode* mid = split(start, size);
            merge3(start, mid);
            start = nextSubList;
        }
        start = dummyHead.next;
    }
    return dummyHead.next;
}

// ============================================

int main () {
    vector <vector <int>> testcase_heads = {{4,2,1,3}, {-1,5,3,4,0}, {}};
    for (int i=0; i<testcase_heads.size(); i++) {
        printf("====== Testcase %d ======\n", i);
        // Method 1: Accepted, Time Complexity: O(nlogn), space complexity: O(n)
        printf("Method 1:\n");
        PrintList(GenerateList(testcase_heads[i]));
        PrintList(sortList1(GenerateList(testcase_heads[i])));

        // Method 2: Solution, Top Down Merge Sort, Time Complexity: O(nlogn), space complexity: O(logn)
        printf("Method 2:\n");
        PrintList(GenerateList(testcase_heads[i]));
        PrintList(sortList2(GenerateList(testcase_heads[i])));

        // Method 3: Solution, Bottom Up Merge Sort, Time Complexity: O(nlogn), space complexity: O(1)
        printf("Method 3:\n");
        PrintList(GenerateList(testcase_heads[i]));
        PrintList(sortList3(GenerateList(testcase_heads[i])));
    }

    return 0;
}