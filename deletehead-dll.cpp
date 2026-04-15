// User function Template for C++

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
Node *deleteHead(Node *head) {
    Node* temp=head;
    while(temp != NULL){
        if(head==NULL) return NULL;
        if(head->next==NULL){
            delete head;
            return NULL;
        }else{
            head=head->next;
            head->prev=NULL;
            delete temp;
            return head;
            
        }
    }
}
