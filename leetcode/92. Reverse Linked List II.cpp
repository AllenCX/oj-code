// my solution
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) return head;
        int dis = n - m;
        if(dis == 0) return head;
        ListNode *front = head, *last = head;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        while(dis){
            last = last->next;
            --dis;
        }
        m -= 2;
        ListNode* pre = NULL;
        if(m < 0){
            pre = dummy;
        }else{
            while(m > 0){
                front = front->next;
                last = last->next;
                --m;
            }
            pre = front;
            last = last->next;
            front = front->next;
        }
        pre->next = reverse(front, last->next);
        return dummy->next;
    }
    ListNode* reverse(ListNode *head, ListNode *tail){
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

// updated solution
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next) return head;
        if(m == n) return head;
        int dis = n - m;
        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *front = head, *last = head;
        ListNode *pre = dummy;
        --m;
        while(m){
            pre = last;
            last = last->next;
            --m;
        }
        --n;
        while(n){
            front = front->next;
            --n;
        }
        ListNode *tail = front->next;
        while(last->next != tail){
            ListNode *tmp = last->next;
            last->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        last->next = tail;
        return dummy->next;
    }
};