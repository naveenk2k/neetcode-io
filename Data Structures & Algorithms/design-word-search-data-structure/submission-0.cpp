class Node {
public:
    vector<Node*> next{26, NULL};
    bool isFinal{false};
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                node->next[idx] = new Node();
            }
            node = node->next[idx];
        }
        node->isFinal = true;
    }

    bool recurse(string word, int wordIndex, Node* node) {
        // check if node->next contains word[index]
        if (wordIndex == word.size()) {
            return node->isFinal == true;
        }

        int trieIdx = word[wordIndex] - 'a';

        if (word[wordIndex] == '.') {
            // loop through all possible next chars and dfs further

            bool acc = false;
            for (int i = 0; i < node->next.size(); ++i) {
                if (node->next[i]) {
                    acc = acc || recurse(word, wordIndex + 1, node->next[i]);
                    if (acc) return true;
                }
            }

            if (!acc) return false;         

        } else {
            if (node->next[trieIdx]) {
                return recurse(word, wordIndex + 1, node->next[trieIdx]);
            } else {
                return false;
            }
        }
    }
    
    bool search(string word) {
        Node* node = root;
        return recurse(word, 0, node);
    }
};
