#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

struct node* Node(int data){
    node* new_node= new node;
    new_node->data= data;
    new_node->next= NULL;
    return new_node;
}

//INSERTION
void insert_start(struct node** head_ref, int data)
{
    node* newNode=Node(data);
    if(*head_ref==NULL){
        *head_ref =newNode;
        return;
    }
    newNode->next= *head_ref;
    *head_ref= newNode;
}
void insert_middle(struct node* head, int key, int data)
{
    if(head==NULL) return;
    node* newNode= Node(data);
    node *temp=NULL, *current=NULL;
    current = head;
    temp=current->next;
    while(current->data !=key)
    {
        current=current->next;
        temp=current->next;
    }
    current->next=newNode;
    newNode->next=temp;
}

void insert_end(struct node** head, int data){
    node* newNode = Node(data);

    if(*head==NULL){
        *head=newNode;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void printLL(struct node* head){
    if(head==NULL){
        cout<<"Linkled list is empty";
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(void)
{
    node* head=NULL;
    int data;
    cin>>data;
    insert_start(&head,data);
    insert_start(&head,5);
    insert_start(&head,6);
    insert_start(&head,9);
    insert_start(&head,3);
    insert_start(&head,1);
    insert_start(&head,0);
    insert_start(&head,4);
    insert_middle(head,9,16);
    insert_end(&head,99);
    insert_end(&head,98);
    insert_end(&head,92);
    insert_end(&head,90);

    printLL(head);
    return 0;

}
