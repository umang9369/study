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
    int count=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr)return -1;
        if(root->left){
            int leftr=kthSmallest(root->left,k);
            if(leftr !=-1){return leftr;}
        }
        if(count+1==k)return root->val;
        count++;
        if(root->right){
            int rightr=kthSmallest(root->right,k);
            if(rightr !=-1){return rightr;}
        }
        return -1;
    }
};
