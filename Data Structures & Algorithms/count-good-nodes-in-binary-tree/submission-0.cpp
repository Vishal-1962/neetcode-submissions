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
    int goodNodes(TreeNode* root) {
        int ans = 0 ;
        findCount(root,root->val,ans);
        return ans;
    }

    void findCount(TreeNode* root,int maxValue,int &count){
        if(root == nullptr) return;

        if(root->val >= maxValue){
            count++;
        }
        maxValue = max(maxValue,root->val);

        findCount(root->left,maxValue,count);
        findCount(root->right,maxValue,count);
    }
};
