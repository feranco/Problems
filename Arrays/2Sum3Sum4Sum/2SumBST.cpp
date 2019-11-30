void getInorder(TreeNode* root, vector<int>& inorder) {        
    if(!root) return;
    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
}

bool existSum(vector<int> const& inorder, int k) {

    size_t i = 0, j = inorder.size()-1;
    while (i < j) {
        int sum = inorder[i]+inorder[j];
        if (sum == k) return true;
        else if (sum < k) i++;
        else j--;
    }
    return false;
}

bool findTarget(TreeNode* root, int k) {

    vector<int> inorder;
    getInorder(root, inorder);
    return existSum(inorder,k);
}
