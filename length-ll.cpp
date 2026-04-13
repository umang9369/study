/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int length(Node* slow,Node* fast){
        int count=1;
        fast=fast->next;
        while(slow !=fast){
            count++;
            fast=fast->next;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return length(slow,fast);
        }
        return 0;
    }
};
