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
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)return false;
        vector<int>temp;
        inorder(root,temp);
        int i=0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]+temp[j]==k){return true;}
            else if (temp[i]+temp[j]>k){j--;}
            else{i++;}
        }
        return false;
    }
};
