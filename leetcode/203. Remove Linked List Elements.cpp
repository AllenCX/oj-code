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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        while(head !=NULL && head->val == val){
            head = head->next;
        }
        if(!head) return head;
        ListNode *p = head;
        while(p->next){
            if(p->next->val == val){
                //ListNode *tmp = p->next;
                p->next = p->next->next;
                continue;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};