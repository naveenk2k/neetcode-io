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
    bool hasCycle(ListNode* head) {
        ListNode *tortoise = head;
        ListNode *hare = (head ? head->next : NULL);

        while (tortoise && hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;

            if (tortoise == hare) return true;
        }

        return false;
    }
};
