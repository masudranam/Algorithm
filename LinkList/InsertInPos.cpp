#include<iostream>
using namespace std;

int main(){
 struct node{
 int data;
 node *next;
 };

 node *head,*newnode, *temp;

  int pos,i=1;
 newnode = new node();
 cout<<"Enter the position you want to insert: \n";
 cin>>pos;
 int counter=Number_of_node;

 if(pos > counter){
 cout<<"Invalid position\n";
 }else{
 temp = head;
 while(i<pos){
 temp = temp -> next;
 i++;
 }
 cout<<"Enter the data :\n";
 cin>>(newnode -> data);
 newnode -> next = temp -> nxt;
 temp -> next = newnode;

 }

return 0;
}