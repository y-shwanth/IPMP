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
    int findMax(int x,int y)
    {
        if(x > y)
            return x;
        return y;
    }
    int findDiff(int x,int y)
    {
        if(x > y)
            return x-y;
        return y-x;
    }
    int checkBalanced(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int ls = checkBalanced(root->left);
        int rs = checkBalanced(root->right);
        
        int max = findMax(ls,rs);
        int diff = findDiff(ls,rs);
        if(diff > 1 || ls == -1 || rs == -1)
            max = -1;
        
        if(max == -1)
            return -1;
        return max+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int res = checkBalanced(root);
        if(res == -1)
            return false;
        
        return true;
    }
};
