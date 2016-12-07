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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode *dummy1 = new ListNode(0);
        ListNode *dummy2 = new ListNode(0);
        ListNode *a = dummy1, *b = dummy2;
        while(head){
            if(head->val < x){
                a->next = head;
                a = a->next;
            }else{
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }
        b->next = NULL;
        a->next = dummy2->next;
        return dummy1->next;
    }
};