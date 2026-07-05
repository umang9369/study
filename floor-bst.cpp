/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int floor=-1;
        while(root){
            if(root->data==k){
                floor=root->data;
                return floor;
            }
            if(root->data>k){
                root=root->left;
            }
            else{
                floor=root->data;
                root=root->right;
            }
        }
        return floor;
    }
};
