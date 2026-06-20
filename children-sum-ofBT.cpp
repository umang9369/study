/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if((root==NULL)||(root->left==NULL && root->right==NULL)){
            return true;
        }
        int lsum=0;
        int rsum=0;
        if(root->left!=NULL){
            lsum=root->left->data;
        }
        if(root->right!=NULL){
            rsum=root->right->data;
        }
        if((root->data==(lsum+rsum))&&isSumProperty(root->left)&&isSumProperty(root->right)){
            return true;
        }else{
            return false;
        }
    }
};
