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
    bool contains(TreeNode* p, TreeNode* q){
        if(p==NULL)
            return false;
        if(p->val==q->val)
            return true;
        else if(p->val>q->val)
            return(contains(p->left,q));
        else
            return(contains(p->right,q));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( contains(root->left,p) && contains(root->left,q) )
            return lowestCommonAncestor(root->left,p,q);
        else if( contains(root->right,p) && contains(root->right,q) )
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};