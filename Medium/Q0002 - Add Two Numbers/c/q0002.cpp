#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(){
    int arr1[1] = {5};
    int arr2[2] = {5, 9};

    struct ListNode *l1, *l2;
    for (int i = sizeof(arr1)/sizeof(int)-1; i >= 0; i--)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = arr1[i];
        node->next = l1;
        l1 = node;
    }
    for (int i = sizeof(arr2)/sizeof(int)-1; i >= 0; i--)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = arr2[i];
        node->next = l2;
        l2 = node;
    }

    struct ListNode *ans = addTwoNumbers(l1, l2);
    printf("l1: ");
    for (int i=0; i<sizeof(arr1)/sizeof(int); i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("l2: ");
    for (int i=0; i<sizeof(arr2)/sizeof(int); i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("output: ");
    while (ans!=NULL)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }
    printf("\n");
    
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL, *cur = NULL;
    struct ListNode *curl1 = l1, *curl2 = l2;
    
    int prev_sum = 0;
    while (curl1!=NULL || curl2!=NULL || prev_sum/10>0) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        int val1 = curl1!=NULL ? curl1->val : 0;
        int val2 = curl2!=NULL ? curl2->val : 0;
        prev_sum = val1 + val2 + prev_sum/10;
        node->val = prev_sum%10;
        if (head==NULL) head = node;
        else cur->next = node;
        
        node->next = NULL;
        cur = node;
        curl1 = curl1==NULL ? NULL : curl1->next;
        curl2 = curl2==NULL ? NULL : curl2->next;
    }

    return head;
}
