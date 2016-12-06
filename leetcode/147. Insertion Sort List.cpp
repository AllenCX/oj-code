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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *p = head;
        while(p && p->next){
            if(p->val <= p->next->val){
                p = p->next;
                continue;
            }
            if(p->next->val <= head->val){
                ListNode *tmp = p->next;
                p->next = p->next->next;
                tmp->next = head;
                head = tmp;
            }else if(p->next->val > head->val){
                ListNode *tmp = p->next;
                ListNode *cur = head;
                while(cur->next){
                    if(cur->next->val > tmp->val){
                        p->next = p->next->next;
                        tmp->next = cur->next;
                        cur->next = tmp;
                        break;
                    }
                    cur = cur->next;
                }
            }else{
                p = p->next;
            }
        }
        return head;
    }
};