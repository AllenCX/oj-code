/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode *pnew = NULL, *pold = head;
        RandomListNode *tmp = NULL;
        // create new nodes
        while(pold){
            pnew = new RandomListNode(pold->label);
            tmp = pold->next;
            pold->next = pnew;
            pnew->next = tmp;
            pold = tmp;
        }
        // copy random pointers to new nodes
        pold = head;
        while(pold){
            if(pold->random) pold->next->random = pold->random->next;
            pold = pold->next->next;
        }
        // split the two identical lists
        pold = head;
        pnew = head->next;
        RandomListNode *new_head = pnew;
        while(pnew->next){
            pold->next = pnew->next;
            pold = pold->next;
            pnew->next = pold->next;
            pnew = pnew->next;
        }
        pold->next = NULL;
        pnew->next = NULL;
        return new_head;
    }
};