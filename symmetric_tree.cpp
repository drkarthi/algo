/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p==NULL && q==NULL)
            return true;
        if(p==NULL || q==NULL)
            return false;
        // recursive case
        if(p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right))
            return true;
        return false;
    }
    
    // create a copy of a binary tree
    TreeNode* copyTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
        p->val = root->val;
        p->left = copyTree(root->left);
        p->right = copyTree(root->right);
        return p;
    }
    
    void invertTree(TreeNode* root) {
        if(root == NULL)
            return;
        // swap the two subtrees
        TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
    }

    bool isSymmetric(TreeNode* root) {
        TreeNode *p = copyTree(root);
        invertTree(p);
        return isSameTree(root,p);
    }
};