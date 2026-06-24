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
    int res=INT_MIN;
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return res;
    }
    int solve(TreeNode* root, int start) {
        if(root==NULL)return 0;
        int lh=solve(root->left,start);
        int rh=solve(root->right,start);
        if(root->val==start){
            res=max(lh,rh);
            return -1;
        }else if(lh>=0 && rh>=0){
            return max(lh,rh)+1;
        }else{
            int d=abs(lh)+abs(rh);
            res=max(res,d);
            return min(lh,rh)-1;
        }
    }
};
