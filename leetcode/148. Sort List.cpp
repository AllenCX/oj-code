/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Linked list version of Mergesort.
class Solution {
public:
    ListNode* merge(ListNode* l_head, ListNode* r_head){
        ListNode *res_head = new ListNode(0);
        ListNode *d = res_head;
        while(l_head || r_head){
            if(l_head && (!r_head || l_head->val <= r_head->val)){
                d->next = l_head;
                d = d->next;
                l_head = l_head->next;
            }
            if(r_head && (!l_head || r_head->val < l_head->val)){
                d->next = r_head;
                d = d->next;
                r_head = r_head->next;
            }
        }
        d->next = NULL;
        return res_head->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(head2));
    }
};