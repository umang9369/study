/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node * temp=head;
        while(temp!=NULL && temp->next !=NULL){
            Node * nextnode=temp->next;
            while(nextnode !=NULL && nextnode->data==temp->data){
                Node * nakli=nextnode;
                nextnode=nextnode->next;
                delete(nakli);
            }
            temp->next=nextnode;
            if(nextnode!=NULL)nextnode->prev=temp;
            temp=temp->next;
        }
        return head;
    }
};
