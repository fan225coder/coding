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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            auto cmp=[](const ListNode* a, const ListNode* b) { return a->val>b->val; };
            priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
            for (auto ln:lists) {
                if (ln) pq.push(ln);
            }
            auto cur=new ListNode(0);
            auto head(cur);
            while (!pq.empty()) {
                cur->next=new ListNode(0);
                cur=cur->next;
                auto t=pq.top();
                pq.pop();
                if (t->next) pq.push(t->next);
                cur->val=t->val;
            }
            return head->next;

        }
};
