#include<iostream>
using namespace std;
struct node {
    int data;
    node *prev;
    node *next;
};
int main() {
    node *temp, *head, *newnode, *reserv;
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
    reserv = temp;
    temp = head;
    cout<<"The link list is :\n";
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;

    }
    temp = reserv;
    cout<<endl<<"The reverse link list is :\n";
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> prev;

    }

        return 0;
}
