/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        int carry = 0;

        while(l1 || l2){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;

            int sum = carry + num1 + num2;
            carry = sum/10;

            ListNode* next = new ListNode(sum%10);
            tail->next = next;
            tail = tail->next;

            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        if(carry){
            ListNode* next = new ListNode(carry);
            tail->next = next;
            tail = tail->next;
        }
        return dummyHead->next;
    }
};