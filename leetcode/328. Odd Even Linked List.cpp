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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        //if(!head->next->next) return head;
        ListNode *p = head, *q = head->next;
        ListNode *second = head->next;
        int i = 0;
        while(q != NULL){
            p->next = q->next;
            ++i;
            if(q->next != NULL){
                p = q;
                q = q->next;
            }else if(i % 2 == 0){
                q->next = second;
                p->next = NULL;
                return head;
            }else if(i % 2 == 1){
                q->next = NULL;
                p->next = second;
                return head;
            }
        }
        return head;
    }
};

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;
        ListNode *p = head, *q = head->next; // p for odd, q for even
        ListNode *even_head = head->next;
        while(q && q->next){
            p->next = p->next->next;
            q->next = q->next->next;
            p = p->next;
            q = q->next;
        }
        p->next = even_head;
        return head;
    }
};