/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp != NULL){
            if(temp->data==x){
                if(temp==*head_ref){
                    *head_ref=temp->next;
                }else{
                    Node* nextnode=temp->next;
                    Node* prevnode=temp->prev;
                    if(nextnode !=NULL)nextnode->prev=prevnode;
                    if(prevnode !=NULL)prevnode->next=nextnode;
                    free(temp);
                    temp=nextnode;
                }
            }else{
                temp=temp->next;
            }
        }
        
    }
};
