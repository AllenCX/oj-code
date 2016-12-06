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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* fast = head, *slow = head;
        int i = 0;
        while(i < k){
            fast = fast->next;
            ++i;
            if(!fast){
                if(k % i == 0) return head;
                else{
                    fast = head;
                    k = k % i;
                    i = 0;
                }
            }
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next; // find the last node of first half list
        }
        if(!fast) return head;
        ListNode *tmp = slow->next;
        fast->next = head;
        slow->next = NULL;
        head = tmp;
        return head;
    }
};