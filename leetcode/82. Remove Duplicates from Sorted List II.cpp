//recursive
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head->next;
        int val = head->val;
        if(val != p->val){
            head->next = deleteDuplicates(p);
            return head;
        }else{
            while(p && val == p->val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};
// iterative
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        //if there are duplicate nodes at the head
        ListNode *dummy = new ListNode(INT_MIN); // safeguard
        dummy->next = head;
        ListNode *p = dummy, *q = head;// p is in front of q
        while(q){
            bool flag = false;
            while(q->next && q->next->val == q->val){
                flag = true;
                q = q->next;
            }
            if(flag){
                q = q->next;
                continue;
            }
            p->next = q;
            q = q->next;
            p = p->next;
        }
        p->next = q;
        return dummy->next;
    }
};