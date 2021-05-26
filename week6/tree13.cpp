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
    int diffbtwoddeven(TreeNode* root) {
        if(root == NULL)
            return 0;
      
        queue<TreeNode*> oldq,newq;
        TreeNode* temp = NULL;
        oldq.push(root);
        int flag = -1,x = 0;
        while(true)
        {
           TreeNode* temp = oldq.front();
            x = x + flag*temp->val;
            oldq.pop();
            if(temp->left != NULL)
                newq.push(temp->left);
            if(temp->right != NULL)
                newq.push(temp->right);
            
            if(oldq.empty() == true)
            {
                flag = flag*-1;
                if(newq.empty() == true)
                    break;
                swap(oldq,newq);
                newq = queue<TreeNode*>();
            }
            
        }
        return x;
    }
};
