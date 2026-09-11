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
    int findLength(ListNode* head){
        int count = 0;
        while(head){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int length = findLength(head);
        if(!head)
            return NULL;

        if(k >= length)
            k = k%length;

        if(k==0)
            return head;


        ListNode* p = head;
        ListNode* q;
        for(int i=0;i<length-k;i++){
            q = p;
            p=p->next;
        }

        while(p->next){
            p=p->next;
        }
        p->next = head;

        head = q->next;
        q->next = NULL;

        return head;
    }
};