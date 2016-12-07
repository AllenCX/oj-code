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
        if(!head || !head->next) return head;
        ListNode *p = head;
        while(p->next){
            ListNode* tmp = p->next;
            p->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};