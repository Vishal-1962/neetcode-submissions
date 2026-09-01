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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        findSmallest(root,k,count,ans);
        return ans;
    }

    void findSmallest(TreeNode* root,int k,int &count,int &ans){
        if(root == nullptr) return;

        findSmallest(root->left,k,count,ans);
        count++;
        if(count == k) ans = root->val;

        findSmallest(root->right,k,count,ans);
    }
};
