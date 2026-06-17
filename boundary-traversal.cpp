/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void traverseleft(Node *root ,vector<int>&res ){
        if((root==NULL)|| (root->left==NULL && root->right==NULL))return;
        res.push_back(root->data);
        if(root->left){
            traverseleft(root->left,res);
        }else{
            traverseleft(root->right,res);
        }
        
    }
    void traverseleaf(Node *root ,vector<int>&res){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            res.push_back(root->data);
            return ;
        }
        traverseleaf(root->left,res);
        traverseleaf(root->right,res);
    }
    void traverseright(Node *root ,vector<int>&res ){
        if((root==NULL)|| (root->left==NULL && root->right==NULL))return;
        if(root->right){
            traverseright(root->right,res);
        }else{
            traverseright(root->left,res);
        }
        res.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        vector<int>res;
        if(root==NULL)return res;
        res.push_back(root->data);
        traverseleft(root->left,res);
        traverseleaf(root->left,res);
        traverseleaf(root->right,res);
        traverseright(root->right,res);
        return res;
    }
};
