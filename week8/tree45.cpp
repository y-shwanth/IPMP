/** NOT THE SAME QUES YET SIMILAR
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
    void func(TreeNode* root, int targetSum, int sum, vector<vector<int>> &res, vector<int> v)
    {
        if(root == NULL)
            return;
        
        sum = sum + root->val;
        v.push_back(root->val);
        
        
        if(root->left == NULL && root->right == NULL)
        {
            if(sum == targetSum)
            {
                res.push_back(v);
                return;
            }
        }
        
        func(root->left, targetSum, sum, res, v);
        func(root->right, targetSum, sum, res, v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        int sum = 0;
        
        func(root, targetSum, sum, res, v);
        return res;
    }
};
