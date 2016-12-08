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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *pa = headA, *pb = headB;
        while(pa){
            pa = pa->next;
            ++lenA;
        }
        while(pb){
            pb = pb->next;
            ++lenB;
        }
        if(lenA >= lenB){
            pa = headA;
            pb = headB;
            int step = lenA - lenB;
            while(step > 0){
                pa = pa->next;
                --step;
            }
        }else{
            pa = headA;
            pb = headB;
            int step = lenB - lenA;
            while(step > 0){
                pb = pb->next;
                --step;
            }
        }
        if(pa == pb) return pa;
        while(pa != pb){
            pa = pa->next;
            pb = pb->next;
        }
        return pa;
    }
};