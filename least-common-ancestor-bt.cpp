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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)return NULL;
        if(root==p || root==q) return root;
        TreeNode* leftnode=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightnode=lowestCommonAncestor(root->right,p,q);
        if(leftnode!=NULL && rightnode!=NULL)return root;
        if(leftnode != NULL)return leftnode;
        return rightnode;
    }
};
