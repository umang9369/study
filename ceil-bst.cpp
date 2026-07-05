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
    int findCeil(Node* root, int x) {
        int ceil=-1;
        while(root){
            if(root->data==x){
                ceil=root->data;
                return ceil;
            }
            if(root->data>x){
                ceil=root->data;
                root=root->left;
            }else{
                root=root->right;
            }
        }
        return ceil;
    }
};
