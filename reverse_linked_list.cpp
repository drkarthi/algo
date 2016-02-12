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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* p = head;
        ListNode* q;
        while(p!=NULL){
            q = p->next;
            p->next = prev;
            prev = p;
            p = q;
        }
        return prev;
    }
};