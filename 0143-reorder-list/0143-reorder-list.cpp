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
    ListNode* reverseList(ListNode* root){
        ListNode* p = root;
        ListNode* q = root;
        ListNode* r;

        while(p){
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }
        return q;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHead = reverseList(slow->next);
        slow->next = NULL;

        ListNode* firstHead = head;

        
        while(firstHead && secondHead){
            ListNode* temp1 = firstHead->next;
            ListNode* temp2 = secondHead->next;

            firstHead->next = secondHead;

            if(!temp1)
                break;
            secondHead->next = temp1;

            firstHead = temp1;
            secondHead = temp2;
        }
    }
};