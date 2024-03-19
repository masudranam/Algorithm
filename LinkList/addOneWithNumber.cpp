#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *next;
};

 //function to reverse the link list
 node* Reverse(node *head){
    node *prev = NULL;
    node *current = head;
    node *next ;
    while(current != NULL){
        next = current->next;
        current ->next = prev;
        prev = current;
        current = next;
    }
    return prev;
 }


 //create a new node with given data
 node *newNode(int data){
 node *new_node = new node();
 new_node ->data = data;
 new_node -> next = NULL;
 return new_node;
 }


  //add one with a link list and return the head list
 node* addOneUtil(node *head){
    node* res = head;
    node* temp,*prev = NULL;
    int carry =1, sum;

    while(head != 0){
        sum = carry + (head? head ->data:0);
        carry = (sum>=10)?1:0;
        sum = sum%10;
        head -> data = sum;
        temp = head;
        head = head -> next;
    }
    if(carry>0)
        temp ->next = newNode(carry);
    return res;
 }


//This function mainly use addOneutil
node* addOne(node *head){
//Reverse the list
head = Reverse(head);
//add one from left to right
 head = addOneUtil(head);
return Reverse(head);
}

 int addWithCarry(node *head){
    if(head == NULL){
        return 1;
    }
    int res = head -> data+ addWithCarry(head ->next);
    head ->data = (res) %10;
    return (res)/10;
 }

 // A utility function to print a list
 void printList(node *head){
    while(head != NULL){
        cout<<(head -> data);
        head = head->next;
    }
    cout<<endl;
 }


int main() {
    node *head = newNode(1);
    head -> next = newNode(9);
    head ->next -> next = newNode(9);
    head ->next -> next -> next = newNode(9);
    cout<<"List is : ";
    printList(head);

    head = addOne(head);
    cout<<"Result list is : ";
    printList(head);

    return 0;
}
