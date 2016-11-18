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
    struct cmp{
        bool operator() (const ListNode *a, const ListNode *b){
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        ListNode node(0), *res = &node;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i]) q.push(lists[i]);
        }
        while(!q.empty()){
            ListNode *tmp = q.top();
            q.pop();
            res -> next = tmp;
            res = res -> next;
            if(tmp -> next) q.push(tmp->next);
        }
        return node.next;
    }
};