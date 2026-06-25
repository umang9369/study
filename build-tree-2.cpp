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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder ,int &idx,int start,int end){
        if(start>end)return NULL;
        int rootval=postorder[idx];
        int i=end;
        for(;i>=start;i--){
            if(inorder[i]==rootval)break;
        }
        idx--;
        TreeNode* root=new TreeNode(rootval);
        root->right = solve(inorder, postorder, idx, i + 1, end);
        root->left = solve(inorder, postorder, idx, start, i - 1);   
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int idx=n-1;
        return solve(inorder,postorder,idx,0,n-1);
    }
};
