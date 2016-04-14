/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // base case
        if(head==NULL || head->next==NULL)
            return head;
        // recursive case
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* nexthead = q->next;
        
        q->next = p;
        head = q;
        p->next = swapPairs(nexthead);
        return head;
    }
};