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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* s = NULL;
        ListNode* head;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
            
        if(l1->val <= l2->val) {
            s = l1;
            head = l1;
            p = p->next;
        }
        else if(l1->val > l2->val) {
            s = l2;
            head = l2;
            q = q->next;
        }
        
        while(true) {
            if(p==NULL) {
                s->next = q;
                break;
            }
            if(q==NULL) {
                s->next = p;
                break;
            }
            if(p->val <= q->val) {
                s->next = p;
                p = p->next;
            }
            else {
                s->next = q;
                q = q->next;
            }
            s = s->next;
        }
        
        return head;
    }
};