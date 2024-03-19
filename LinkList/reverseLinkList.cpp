#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

int main() {
    node *head, *temp, *newnode;
    head = 0;
    int choice =1;
    while(choice != 0) {
        newnode = new node();
        cout<<"Enter the value :\n";
        cin>>(newnode ->data);
        newnode -> next = NULL;

        if(head == 0) {
            head = temp = newnode;
        } else {
            temp -> next = newnode;
            temp = newnode;
        }
        cout<<"press 0 to stop :\n";
        cin>>choice;
    }
    temp = head;
    cout<<"The link list is : \n";
    while(temp != 0) {
        cout<<(temp -> data)<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    node *prevnode, *currentnode, *nextnode;

    prevnode = 0;
    currentnode = nextnode = head;
    while(nextnode != 0) {
        nextnode = nextnode -> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }


    head = prevnode;
    cout<<"The reverse link list is : \n";
    while(prevnode != 0) {
        cout<<(prevnode -> data)<<" ";
        prevnode = prevnode -> next;
    }

    return 0;
}
