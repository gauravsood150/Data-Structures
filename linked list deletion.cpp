#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct node* Node(int data){
    node* newNode =new node;
    newNode->data= data;
    newNode->next = NULL;
}

//INSERTION
void push(struct node** head_ref, int data)
{
    node* newNode=Node(data);
    if(*head_ref==NULL){
        *head_ref =newNode;
        return;
    }
    newNode->next= *head_ref;
    *head_ref= newNode;
}
// DELETION
void deletion_start(struct node **head_ref)
{
    if(*head_ref==NULL)
    {
        cout<<"Linked List is already empty"<<endl;
        return;
    }
    node* temp=*head_ref;
    *head_ref= temp->next;
    delete(temp);
}

void deletion_middle(struct node **head, int key)
{
    if(*head==NULL)
    {
        cout<<"Linked List is already empty"<<endl;
        return;
    }
    node *current= *head, *prev;
    if(current->data ==key){
        *head=current->next;
        delete(current);
        return;
    }
    while(current->data!= key){
        prev=current;
        current= current->next;
    }
    if(current->data!=key){
        cout<<"Key is not present in LL"<<endl;
        return;
    }
    prev->next=current->next;
    delete(current);
}

void deletion_end(struct node* head){
    if(head==NULL)
    {
        cout<<"Linked List is already empty"<<endl;
        return;
    }
    node *temp=head;
    node *prev;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    delete(temp);
}

void printLL(struct node* head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(void){
    node* head= NULL;
    push(&head,59);
    push(&head,66);
    push(&head,69);
    push(&head,79);
    push(&head,89);
    push(&head,99);
    push(&head,49);
    push(&head,59);
    push(&head,29);
    push(&head,39);
    printLL(head);
    cout<<endl;
    deletion_start(&head);
    cout<<endl;printLL(head);
    deletion_start(&head);
    cout<<endl;printLL(head);
    deletion_end(head);
    cout<<endl;printLL(head);
    deletion_end(head);
    cout<<endl;
    printLL(head);
    deletion_end(head);
    cout<<endl;
    printLL(head);
    deletion_middle(&head,99);
    cout<<endl;
    printLL(head);
    deletion_middle(&head,59);
    cout<<endl;
    printLL(head);

}
