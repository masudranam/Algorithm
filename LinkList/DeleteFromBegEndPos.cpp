#include<iostream>
using namespace std;
 struct node{
 int data;
 node *next;
 };
 
 node create(node *head){
	 node *newnode,*temp;
	 head=0;
	 int choice=1;
	 while(choice!=0){
	 newnode=new node();
	 
	 cout<<"data: ";
	 cin>>(newnode->data);
	 newnode->next=0;
	 if(head==0){
		 temp =head=newnode;
	 }else{
		 temp->next=newnode;
		 temp =newnode;
	 }
	 cout<<"0 for stop:";
	 cin>>choice;
	 }
	 
	// temp =head;
	// while(temp!=0){
	//	 cout<<(temp->data)<<" ";
	//	 temp =temp->next;
	// 
	return *head;
 }
 
 
 void display(node *head){
node *temp;
	 temp =head;
	 cout<<"list is: ";
	 while(temp!=0){
		 cout<<(temp->data)<<" ";
		 temp =temp->next;
	 }
	 cout<<endl;
 }

  void DFB(node *head){
 node *temp;
 temp  = head;
 head = head -> next;
 free(temp);

 }


 void DeleteFromEnd(){
  node *temp, *head, *prevnode;
  temp = head;

  while(temp -> next != 0){
    prevnode = temp;
    temp = temp -> next;

  }

  if(temp == head){
  head = 0;
  }else{
  prevnode -> next = 0;
  }
  free(temp);

 }
 
 
int main(){
	
node *head,*temp;
int choice=1;

while(choice!=0){
	cout<<"1 for new num 2 for print 0 for stop\n";
	cin>>choice;
	switch(choice){
		case 1: create(head);break;
		//case 2: DFB(head);break;
		case 2: display(head);
		default: cout<<"enter correct number";
	}
}

return 0;
}