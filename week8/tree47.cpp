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
    void func(TreeNode* root, int sum, int &maxSum)
    {
        
        if(root == NULL)
            return;
        
        sum = sum + root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(sum > maxSum)
                maxSum = sum;
            return;
        }
        
        func(root->left,sum,maxSum);
        func(root->right,sum,maxSum);
    }
    int maxPathSum(TreeNode* root) {
        int sum = 0, maxSum = 0;
        func(root, sum, maxSum);
        return maxSum;
    }
};
