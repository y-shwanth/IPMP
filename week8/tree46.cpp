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
    void func(TreeNode* root, int targetSum, int sum, bool &res)
    {
        if(res == true)
            return;
        
        if(root == NULL)
            return;
        
        sum = sum + root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
                res = true;
            return;
        }
        
        func(root->left,targetSum,sum,res);
        func(root->right,targetSum,sum,res);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        
        int sum=0;
        bool res = false;
        func(root, targetSum, sum, res);
        
        return res;
    }
};
