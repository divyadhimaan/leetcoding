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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;

       ListNode* p = head;
       ListNode* q = head->next;
       ListNode* qHead = q;

       while(q && q->next){
        p->next = q->next;
        p = p->next;
        
        q->next = p->next;
        q = q->next;
       }
       p->next = qHead;

       return head;

    }
};