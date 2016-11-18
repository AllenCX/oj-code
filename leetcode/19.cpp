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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode *p, *q;
        p = head;
        q = head;
        // p is in front of q
        int i = 0;
        while(i < n + 1 && p != NULL){
            p = p -> next;
            ++i;
        }
        while(p){
            p = p -> next;
            q = q -> next;
        }
        // when we need to delete the first item of the list;
        if(i == n && p == NULL){
            q = q -> next;
            head -> next = NULL;
            delete head;
            return q;
        }
        
        ListNode *tmp = q -> next;
        q -> next = tmp -> next;
        tmp -> next = NULL;
        delete tmp;
        
        return head;
    }
};