#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node *next;
};

node *head;
void Insert(int data,int n){
 node *nnode=new node;
 nnode->data=data;
 nnode->next=NULL;
 if(n==1){
    nnode->next=head;
    head=nnode;
    return ;
}
node *temp=head;
int cnt = 1;
while(temp != NULL)temp = temp->next, cnt++;
if(cnt < n){
	cout <<"Invalid length\n";
	return;
}
temp = head;
for(int i=0; i<n-2; i++){
      temp=temp->next;
}
nnode->next=temp->next;
temp->next=nnode;
}
print(){
  node *temp=head;
  cout<<"List is : ";
  while(temp){
    cout<<temp->data<<" ";
    temp=temp->next;

  }
  cout<<endl;
}

int main(){
   head=NULL;
   int num;
   cout<<" How many num want to add ?: ";
   cin>>num;

   while(num--){
    int x,n;
    cout<<"value pos : ";
    cin>>x>>n;
    Insert(x,n);
    print();

   }

 return 0;
}

