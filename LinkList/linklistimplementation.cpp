#include<bits/stdc++.h>
using namespace std;
#define pb push_back

 class node{
 public:
     int data;
     node *next;
 }*head,*tail;

 void add(int value){
    node* newnode=new node;
    newnode->data=value;
    newnode->next=NULL;
        if(!head){
            head=tail=newnode;
        }else{
        tail->next=newnode;
        tail=tail->next;
        }
 }

 void print(node *n){
 tail=n;
 while(tail){
    cout<<tail->data<<" ";
    tail=tail->next;
 }
 }

 void addFront(int value){
    node *newnode=new node;
    newnode->data=value;
    newnode->next=head;
    head=newnode;
 }

 void addLast(int value){
 node *newnode=new node;
 newnode->data=value;
 newnode->next=NULL;
 tail->next=newnode;
 }

 void addPos(int value,int pos){
    node *newnode=new node;
    newnode->data=value;
    node *temp;
    temp=head;
    pos--;
   while(pos--){
    temp=temp->next;
   }
   newnode->next=temp->next;
   temp->next=newnode;
 }


void revers(node *head){
    if(!head){
        cout<<"empty";
        return ;
    }
node *cur,*nex,*prev;
cur=head;
next=prev=NULL;
while(cur){
    nex=cur->next;
}

}


 int main(){
   for(int i=0; i<10; i++)
    add(i);

    print(head);
    rever(head);
    print(head);
 return 0;
 }
