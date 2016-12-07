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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* sec_half = reverse(slow->next);
        slow->next = NULL;
        while(head && sec_half){
            ListNode *tmp = head->next;
            head->next = sec_half;
            head = tmp;
            
            ListNode *tmp2 = sec_half->next;
            sec_half->next = tmp;
            sec_half = tmp2;
        }
        return;
    }
    ListNode* reverse(ListNode* head){
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