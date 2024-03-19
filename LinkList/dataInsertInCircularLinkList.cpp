#include<iostream>
using namespace std;

struct node{
int data;
node *next;
};

int main(){
 node *newnode, *head, *temp, *tail;
   int choice;
 head = 0;
 cout<<"press 0 to stop\n";
 cin>>choice;
 while(choice != 0){
 newnode = new node();
 cout<<"Enter the data :\n";
 cin>>(newnode -> data);
 newnode -> next = 0;

 if(head == 0){
 head =temp = newnode;
 }else{
   temp -> next = newnode;
   temp = newnode;
 }
 cout<<"press 0 to stop \n";
 cin>>choice;
 }
   temp -> next = head;

   temp = head;
   if(head == 0){
   cout<<"\nLink list is empty\n";
   }else{
   while(temp -> next != head){
   cout<<(temp -> data)<<" ";
   temp = temp -> next;
   }
   }
 cout<<(temp -> data);
   tail = temp;

   newnode =new node();
   cout<<"\nEnter the data :\n";
   cin>>(newnode -> data);
   newnode -> next = 0;
   if(tail == 0){
   tail = newnode;
   tail -> next = newnode;
   }else{
     tail -> next = newnode ;
     newnode->next=head;

   }
temp =head;
  if(head == 0){
   cout<<"\nLink list is empty\n";
   }else{
   while(temp -> next != head){
   cout<<(temp -> data)<<" ";
   temp =temp -> next;
   }
   }
}