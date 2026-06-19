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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxi=0;
        while(!q.empty()){
            ll l=q.front().second;
            ll r=q.back().second;
            maxi=max(maxi,r-l+1);
            ll n=q.size();
            while(n--){
                TreeNode* temp=q.front().first;
                ll idx=q.front().second;
                q.pop();
                if(temp->left){
                    q.push({temp->left,2*idx+1});
                }
                if(temp->right){
                    q.push({temp->right,2*idx+2});
                }
            }
        }
        return maxi;
    }
};
