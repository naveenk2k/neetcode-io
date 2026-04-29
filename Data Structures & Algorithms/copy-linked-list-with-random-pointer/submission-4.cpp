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
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        // 1st pass: create all required nodes
        Node* node = head;
        while (node) {
            if (!mp.contains(node)) {
                mp[node] = new Node(node->val);
            }

            if (node->random && !mp.contains(node->random)) {
                mp[node->random] = new Node(node->random->val);
            }

            node = node->next;
        }

        // 2nd pass: create all required links
        node = head;
        while (node) {
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
            node = node->next;
        }

        return mp[head];
    }
};
