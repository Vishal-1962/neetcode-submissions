/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "";

        string result = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr == nullptr) {
                result += "null,";
                continue;
            }

            result += to_string(curr->val) + ",";

            q.push(curr->left);
            q.push(curr->right);
        }

        return result;
    }

    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        stringstream ss(data);
        string value;

        getline(ss, value, ',');
        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            getline(ss, value, ',');
            if (value != "null") {
                curr->left = new TreeNode(stoi(value));
                q.push(curr->left);
            }

            getline(ss, value, ',');
            if (value != "null") {
                curr->right = new TreeNode(stoi(value));
                q.push(curr->right);
            }
        }

        return root;
    }
};