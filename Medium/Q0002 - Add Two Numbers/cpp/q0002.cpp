/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ans = nullptr, *cur;
    int isCarry = 0;
    while (isCarry || l1 || l2) {
        int val1 = 0, val2 = 0;
        if (l1) {
            val1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            val2 = l2->val;
            l2 = l2->next;
        }
        int val = val1 + val2 + isCarry;
        ListNode *node = new ListNode;
        node->val = val%10;
        isCarry = val/10;
        if (!ans) ans = node;
        else cur->next = node;
        node->next = nullptr;
        cur = node;
    }
    
    // if (isCarry) {
    //     ListNode *node = new ListNode;
    //     node->val = isCarry;
    //     node->next = nullptr;
    //     cur->next = node;
    // }
    return ans;
}

int main()
{
    fstream file;
    string str_buffer1, str_buffer2;
    file.open("testcase.txt", ios::in);
    while (getline(file, str_buffer1)) {
        if (str_buffer1.length() > 0) {
            getline(file, str_buffer2);
            istringstream iss(str_buffer1);
            ListNode *l1 = nullptr, *l2 = nullptr;
            int val;
            while (iss >> val) {
                ListNode *node = new ListNode;
                node->val = val;
                node->next = l1;
                l1 = node;
            }
            
            cout << "l1 : ";
            ListNode *cur = l1;
            while (cur!=nullptr) {
                cout << cur->val;
                cur = cur->next;
            }
            cout << endl;
            
            iss.clear();
            iss.str(str_buffer2);
            while (iss >> val) {
                ListNode *node = new ListNode;
                node->val = val;
                node->next = l2;
                l2 = node;
            }
            
            cout << "l2 : ";
            cur = l2;
            while (cur!=nullptr) {
                cout << cur->val;
                cur = cur->next;
            }
            cout << endl;
            
            ListNode *ans = addTwoNumbers(l1, l2);
            cout << "ans: ";
            while(ans) {
                cout << ans->val;
                ans = ans->next;
            }
            cout << endl;
        }
    }
    return 0;
}
