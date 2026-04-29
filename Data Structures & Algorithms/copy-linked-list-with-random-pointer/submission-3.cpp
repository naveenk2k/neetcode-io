/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> mp;

        Node *h = head;
        while (h) {
            // check if we have a copy of this node
            if (!mp[h]) {
                mp[h] = new Node(h->val);
            }

            // check if we have a copy of next node
            if (h->next && !mp[h->next]) {
                mp[h->next] = new Node(h->next->val);
            }

            // check if we have a copy of random node
            if (h->random && !mp[h->random]) {
                mp[h->random] = new Node(h->random->val);
            }

            h = h->next;

        }

        h = head;
        while (h) {
            if (h->next) {
                mp[h]->next = mp[h->next];
            }

            if (h->random) {
                mp[h]->random = mp[h->random];
            }

            h = h->next;
        }

        return mp[head];
    }
};
