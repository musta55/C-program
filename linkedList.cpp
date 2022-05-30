#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;    
};

void push(Node** head_ref,int new_data)
{

    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    *head_ref=new_node;
}

void insertAfter(Node * prev_node,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=prev_node->next;
    prev_node->next=new_node;
}

void append(Node** head_ref,int new_data)
{
    Node *new_node=new Node();
    new_node->data=new_data;
    new_node->next=NULL;
    Node *last=*head_ref;

    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=new_node;
    return;

}

void deleteNode(Node** head_ref,int key)
{
    Node* temp=*head_ref;
    Node* prev=NULL;
    if(temp!=NULL && temp->data==key)
    {
        *head_ref=temp->next;
        delete temp;
        return;
    }

    else 
    {
        while(temp!=NULL && temp->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL)
        return;
        prev->next=temp->next;
        delete temp;
    }
}

void printList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

int main()
{
Node *head=NULL;
append(&head,2);
push(&head,24);
insertAfter(head->next,6);
insertAfter(head->next->next,543);
append(&head,324);
cout<<"Created Linked List is: ";
  deleteNode(&head, 6);
    puts("\nLinked List after Deletion of 6: ");
printList(head);
return 0;


}