/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = (int)lists.size();
        
        auto cmp = [](const ListNode* a, const ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

        for (int i = 0; i < k; ++i) {
            pq.push(lists[i]);
        }

        // 1, 1, 3

        ListNode* node = new ListNode(-1);
        ListNode* n = node;
        ListNode* x;

        while (!pq.empty()) {
            x = pq.top();
            // cout << x->val << "\n";
            pq.pop();

            if (x->next) {
                pq.push(x->next);
            }

            n->next = x;
            n = n->next;
        }

        return node->next;
    }
};
