#include<iostream>
using namespace std;
using ll=long long int;


class node {
public:
    int data;
    node *next;
    node *prev;

}*tail;


void push(node **hr,int v) {
    node *nnode=new node;
    nnode->data=v;
    nnode->next=NULL;
    nnode->prev=NULL;

    if(!(*hr)) {
        *hr=nnode;
    } else {
        node *last=*hr;
        while(last->next) {
            last=last->next;

        }
        last->next=nnode;
        nnode->prev=last;
        tail=nnode;

    }
}



void print(node *n) {
    n=tail;
    if(!n)cout<<"emnpty"<<endl;
    else {
        while(n) {
            cout<<n->data<<" ";
            n=n->prev;
        }
    }
}


void first(node **hr,int v) {
    node *nnode=new node;
    nnode->data=v;
    nnode->prev=NULL;
    nnode->next=NULL;
    if(!(*hr))(*hr)=nnode;
    else {
        nnode->next=*hr;
        (*hr)->prev=nnode;
        (*hr)=nnode;
    }
}


void Last(node **hr,int v) {
    node *nnode=new node;
    nnode->data=v;
    nnode->next=NULL;
    nnode->prev=NULL;
    if(!(*hr))(*hr)=nnode;
    else {
        tail->next=nnode;
        nnode->prev=tail;
    }
    tail=tail->next;
}


void delf(node **hr) {
    node *temp=(*hr);
    (*hr)=(*hr)->next;
    (*hr)->prev=NULL;
    free(temp);
}


int getcount(node *n) {
    int cnt=0;
    while(n) {
        cnt++;
        n=n->next;
    }
    return cnt;
}


int cnt(node *n) {
    if(!n)return 0;
    return 1+cnt(n->next);
}

bool srch(node *n,int v){
node *curr=n;
while(curr){
    if(curr->data==v){
        return true;
    }
    curr=curr->next;
}
return false;
}

int src(node *head,int x){
node *curr=head;
int cnt=1;
while(curr){
    if(curr->data==x){
      return cnt;
    }cnt++;
    curr=curr->next;
}
return -1;
}


int main() {
    node *head=NULL;
    print(head);
    for(int i=1; i<10; i++)push(&head,i);
//first(&head,100);
    Last(&head,200);
    print(head);

   cout<<endl<<src(head,16);
    return 0;
}
