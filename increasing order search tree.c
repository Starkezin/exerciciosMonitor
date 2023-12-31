struct TreeNode* increasingBST(struct TreeNode* root){
    if(root == NULL || (root->left==NULL && root->right==NULL))
        return root;
    
    struct TreeNode* Ltree = root->left;
    struct TreeNode* Rtree = root->right;
    root->left = NULL;
    root->right = NULL;
    struct TreeNode* leftTree = increasingBST(Ltree);
    struct TreeNode* rightTree = increasingBST(Rtree);

    if(leftTree == NULL){
        root->right = rightTree;
    }
    else{
        struct TreeNode* temp = leftTree;
        while(temp->right != NULL){
            temp = temp->right;
        }
        temp->right = root;
        root->right = rightTree;
        return leftTree;
    }
    
    return root;
           
}