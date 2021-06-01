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
    int sum = 0;
    void inorder_tra(TreeNode* root)
    {
        if(root == NULL)
            return;
        inorder_tra(root->right);
        sum  = root->val + sum;
        root->val = sum;
        inorder_tra(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        inorder_tra(root);
        return root;
    }
};
