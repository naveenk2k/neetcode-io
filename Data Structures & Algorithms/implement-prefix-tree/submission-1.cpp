class Node {
public:
    vector<Node*> next{26, NULL};
    bool isFinal = false;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }

    int idx(char c) {
        return c - 'a';
    }
    
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->next[idx(c)] == NULL) {
                node->next[idx(c)] = new Node();
            }
            node = node->next[idx(c)];
        }
        node->isFinal = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for (char c : word) {
            int index = idx(c);
            if (node->next[index] != NULL) {
                node = node->next[index];
            } else {
                return false;
            }
        }

        return node->isFinal == true;
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for (char c : prefix) {
            int index = idx(c);
            if (node->next[index] != NULL) {
                node = node->next[index];
            } else {
                return false;
            }
        }

        return true;
    }
};
