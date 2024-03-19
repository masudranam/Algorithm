#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
}*head, *temp;

int main() {
    node *newnode;
    int value = -1;
    head = 0;
    cout<<"press -1 to stop :\n";

    while(true) {
        newnode = new node();
        cout<<"Enter the data : ";
        cin >> value;
        if(value == -1)break;
        newnode -> data = value;
        newnode -> next = 0;

        if(head == 0)
            head =temp = newnode;

        else {
            temp -> next = newnode;
            temp = newnode;
        }
    }
     if(head == 0){
        cout<<"Link list is empty\n";
        return 0;
     }



    temp -> next = head;  //this is the circular link

    temp = head;

        while(temp -> next != head) {
            cout<<(temp -> data)<<" ";
            temp = temp -> next;
        }

    cout<<(temp -> data);

    return 0;
}
