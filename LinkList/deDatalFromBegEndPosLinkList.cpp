#include<iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

int main() {
    node *temp, *head, *newnode, *tail;
    int choice = 1;

    head = 0;
    while(choice != 0) {
        newnode = new node();
        cout<<"Enter the data : \n";
        cin>>(newnode -> data);
        newnode -> prev = 0;
        newnode -> next = 0;

        if(head ==0 ) {
            head = temp = newnode;
        } else {
            temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
        }
        cout<<"press 0 to stop: \n";
        cin>>choice;
    }


    tail = temp;
    temp = head;
    cout<<"The link list is :\n";
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;
    }


    node *beg;

    beg = head;
    head = head -> next;
    head -> prev = 0;
    free(beg);

    cout<<endl<<"After delete the first data link list is :\n";
    temp = head;
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;
    }


    node *End;

    End = tail;
    tail = tail -> prev;
    tail -> next = 0;
    free(End);


    cout<<endl<<"After delete the last data the link list is :\n";
    temp = head;
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;
    }

    node *temp1;
    int pos,i=1;
    cout<<endl<<"Enter the deleting position :\n";
    cin>>pos;
    temp1 = head;

    while(i < pos) {
        temp1 = temp1 -> next;

        i++;
    }

    temp1 -> prev -> next = temp1 -> next;
    temp1 -> next -> prev = temp1 -> prev;
    free(temp1);

    temp = head;

    cout<<"After deleting "<<i<<" position data link list is :\n";

    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;

    }
	

    return 0;
}
