int liss(Node* root)
{
	if(root==NULL) return 0;
	int ex=liss(root->right)+liss(root->left);
	int incl=1;
	if(root->left) incl+=liss(root->left->left)+liss(root->left->right);
	if(root->right) incl+=liss(root->right->left)+liss(root->right->right);
	
	return max(ex,incl);
}