class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }

        flag = false;
    }
};

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(curr->links[index] == NULL) {
                curr->links[index] = new Node();
            }

            curr = curr->links[index];
        }

        curr->flag = true;
    }
    
    bool search(string word) {
        Node* curr = root;

        for(char ch : word) {
            int index = ch - 'a';

            if(curr->links[index] == NULL) {
                return false;
            }

            curr = curr->links[index];
        }

        return curr->flag;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;

        for(char ch : prefix) {
            int index = ch - 'a';

            if(curr->links[index] == NULL) {
                return false;
            }

            curr = curr->links[index];
        }

        return true;
    }
};