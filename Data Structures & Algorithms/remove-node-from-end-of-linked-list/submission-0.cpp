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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // nth from end = (k-n+1)st from beginning
        ListNode *l = head;
        int k=0;
        while (l != NULL) { 
            l = l->next;
            ++k;
        }

        if (k == n) return head->next;

        ListNode *prev = head;
        int i = 0;
        while (i < k-n-1) {
            ++i;
            prev = prev->next;
        }

        cout << prev->val << '\n';
        ListNode *succ = prev->next->next;
        // free(prev->next);
        prev->next = succ;

        return head;
    }
};
