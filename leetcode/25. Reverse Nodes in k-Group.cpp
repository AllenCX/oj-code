// iterative solution
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tail = dummy, *slow = dummy;
        ListNode *start = NULL;
        while(tail){
            int i = k;
            while(i && tail){
                tail = tail->next;                
                --i;
            }
            if(tail == NULL) break;
            start = slow->next;
            slow->next = reverse(start, tail->next);
            slow = start;
            tail = start;
        }
        return dummy->next;
    }
    ListNode *reverse(ListNode *head, ListNode* tail){
        ListNode *p = head;
        while(p->next != tail){
            ListNode *tmp = p->next;
            p->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};

// recursive solution
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        ListNode *node = head;
        int i = k;
        while(i){
            if(!node) return head;
            node = node->next;
            --i;
        }
        ListNode *new_head = reverse(head, node);
        head->next = reverseKGroup(node, k);
        return new_head;
    }
    ListNode *reverse(ListNode *head, ListNode* tail){
        ListNode *p = head;
        while(p->next != tail){
            ListNode *tmp = p->next;
            p->next = tmp->next;
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};