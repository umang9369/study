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
    int getlh(TreeNode* root){
        TreeNode* temp=root;
        int l=0;
        while(temp){
            temp=temp->left;
            l++;
        }
        return l;
    }
    int getrh(TreeNode* root){
        TreeNode* temp=root;
        int r=0;
        while(temp){
            temp=temp->right;
            r++;
        }
        return r;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=getlh(root);
        int rh=getrh(root);
        if(lh==rh){
            return (pow(2,rh)-1);
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
