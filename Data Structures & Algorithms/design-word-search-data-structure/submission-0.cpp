class WordDictionary {
public:

    struct Node {
        Node* child[26];
        bool end;

        Node() {
            end = false;
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* cur = root;

        for (char ch : word) {
            int i = ch - 'a';

            if (cur->child[i] == NULL)
                cur->child[i] = new Node();

            cur = cur->child[i];
        }

        cur->end = true;
    }

    bool search(string word) {
        return dfs(0, root, word);
    }

    bool dfs(int pos, Node* cur, string& word) {

        if (pos == word.size())
            return cur->end;

        if (word[pos] != '.') {
            int i = word[pos] - 'a';

            if (cur->child[i] == NULL)
                return false;

            return dfs(pos + 1, cur->child[i], word);
        }

        // '.' -> try all 26 characters
        for (int i = 0; i < 26; i++) {
            if (cur->child[i] != NULL &&
                dfs(pos + 1, cur->child[i], word))
                return true;
        }

        return false;
    }
};