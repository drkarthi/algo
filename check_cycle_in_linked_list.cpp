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
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode *p=head,*q=head;
        while(q!=NULL && q->next!=NULL) {
            q = q->next->next;
            p = p->next;
            if(p==q)
                return true;
        }
        return false;
    }
};