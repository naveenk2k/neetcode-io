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

        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        ListNode* smallest;

        while (!pq.empty()) {
            smallest = pq.top();
            // cout << x->val << "\n";
            pq.pop();

            if (smallest->next) {
                pq.push(smallest->next);
            }

            curr->next = smallest;
            curr = curr->next;
        }

        return head->next;
    }
};
