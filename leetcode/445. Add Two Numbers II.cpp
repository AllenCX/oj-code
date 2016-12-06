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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(!l1 && !l2) return NULL;
        ListNode *head1 = reverse(l1), *head2 = reverse(l2);
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        int carry = 0;
        while(head1 || head2){
            if(head1){
                carry += head1->val;
                head1 = head1->next;
            }
            if(head2){
                carry += head2->val;
                head2 = head2->next;
            }
            p->next = new ListNode(carry%10);
            carry /= 10;
            p = p->next;
        }
        if(head1 == NULL && head2 == NULL){
            if(carry != 0){
                p->next = new ListNode(carry);
                p = p->next;
            }
        }
        p->next = NULL;
        return reverse(dummy->next);
    }
    ListNode* reverse(ListNode* head){
        ListNode* cur = head;
        while(cur->next){
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};