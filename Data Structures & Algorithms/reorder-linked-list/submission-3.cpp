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

    ListNode* reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *succ = NULL;
        ListNode *curr = head;

        while (curr) {
            succ = curr->next;
            curr->next = prev;

            prev = curr;
            curr = succ;
        }

        return prev;
    }

    void printList(ListNode *head) {
        while (head) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << '\n';
    }

    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        // Find mid point
        ListNode *fast = head;
        ListNode *slow = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *midPoint = slow;

        // Split into 2 lists at the midpoint
        ListNode *l = head;
        while (l->next != midPoint) l = l->next;
        l->next = NULL;

        ListNode *l1 = head;
        ListNode *l2 = reverseList(midPoint); // reverse the second list

        ListNode *temp1, *temp2;
        // Interweave l1 and l2
        while (l1) {
            temp1 = l1->next;
            temp2 = l2->next;

            l1->next = l2;
            if (temp1) l2->next = temp1;

            l1 = temp1;
            l2 = temp2;

        }
    }
};
