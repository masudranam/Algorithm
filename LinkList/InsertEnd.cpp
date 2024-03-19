#include<iostream>
using namespace std;

int main(){
 struct node{
 int data;
 node *next;
 };

 node *head,*newnode, *temp;

 newnode = new node();
 cout<<"Enter a data you want to insert: \n";
 cin>>(newnode -> data);
 newnode -> next = NULL;
 head = newnode;
cout<<head->data<<endl;

return 0;
}