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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        TreeNode* temp;
        queue<TreeNode*> oldq,newq;
        oldq.push(root);
        while(true)
        {
            temp = oldq.front();
            v.push_back(temp->val);
            while(oldq.empty() == false)
            {
                temp = oldq.front();
                oldq.pop();
                if(temp->right != NULL)
                    newq.push(temp->right);
                if(temp->left != NULL)
                    newq.push(temp->left);
            }
            if(newq.empty() == true)
                break;
            oldq = newq;
            newq = queue<TreeNode*>();
        }
        return v;
    }
};
