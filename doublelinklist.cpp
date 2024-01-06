#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
struct node{
    int data;
    Node *next;
    Node *prev;

};
/*****Insert a node into front*****/
void pushdouble(Node **head_ref,int data){
    Node *new_node=new Node();
    new_node->data=data;
    new_node->next=*head_ref;
    new_node->prev=NULL;
    if(*head_ref!=NULL){
        (*head_ref)->prev=new_node;
    }
    (*head_ref)=new_node;
}
/****Insert a node after a node*****/
void insertafter(Node *prev,int data){

    if(prev==NULL){
        cout<<"Given prev node can't be null"<<endl;
    }
    Node *current_node=new Node();

    current_node->data=data;
    current_node->next=prev->next;
    prev->next=current_node;
    current_node->prev=prev;

    if(current_node!=NULL){
        current_node->next->prev=current_node;

    }
    return;
}
/***Insert a node at last Position****/
void append(Node **head_ref,int data){
    Node *newnode=new Node();
    newnode->data=data;
    newnode->next=NULL;
    node *last=*head_ref;
    if(*head_ref==NULL){
        newnode->prev=NULL;
        *head_ref=newnode;
        return;
    }
    while(last->next!=NULL){
        last=last->next;

    }
    last->next=newnode;
    newnode->prev=last;

    return;
}
/**print Double Linklist***/
void printdoublelist(Node *n){
    while(n!=NULL){cout<<n->data<<" ";
    n=n->next;
    }
}
int main(){
   Node *head=NULL;
   pushdouble(&head,234);
   pushdouble(&head,2321);
   pushdouble(&head,2356);

   insertafter(head->next,10);
   printdoublelist(head);
   cout<<endl;
   append(&head,8777);
   printdoublelist(head);


}