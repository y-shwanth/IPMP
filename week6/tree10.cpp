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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      vector<vector<int>> res;
        if(root == NULL)
            return res;
        vector<int> v;
        
        stack<TreeNode*> oldq,newq;
        TreeNode* temp = NULL;
        oldq.push(root);
        int x=2,count=0,flag=1;
        while(true)
        {
           TreeNode* temp = oldq.top();
            v.push_back(temp->val);
            oldq.pop();
            if(flag == 1)
            {
                if(temp->left != NULL)
                newq.push(temp->left);
                if(temp->right != NULL)
                newq.push(temp->right);
            }
            else
            {
                if(temp->right != NULL)
                newq.push(temp->right);
                if(temp->left != NULL)
                newq.push(temp->left);
            }
            if(oldq.empty() == true)
            {
                res.push_back(v);
                v.clear();
                flag = flag * -1;
                if(newq.empty() == true)
                    return res;
                swap(oldq,newq);
                newq = stack<TreeNode*>();
            }
            
        }
        if(v.empty() == false)
            res.push_back(v);
        return res;  
    }
};
