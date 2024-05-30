struct Node {
    Node* arr[26];
    bool flag = false;
};
class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }
    void insert(string s) {
        int n = s.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (node->arr[s[i] - 'a'] == NULL) {
                node->arr[s[i] - 'a'] = new Node();
            }
            node = node->arr[s[i] - 'a'];
        }
        node->flag = true;
    }
    bool search(string s) {
        int n = s.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (node->arr[s[i] - 'a'] == NULL) {
                return false;
            }
            node = node->arr[s[i] - 'a'];
        }
        return node->flag;
    }
    bool startsWith(string s) {
        int n = s.size();
        Node* node = root;
        for (int i = 0; i < n; i++) {
            if (node->arr[s[i] - 'a'] == NULL) {
                return false;
            }
            node = node->arr[s[i] - 'a'];
        }
        return true;
    }
};