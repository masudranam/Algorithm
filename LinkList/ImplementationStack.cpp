#include<iostream>
using namespace std;

#define N 5
int stack[N];
int top = -1;

void push(){
int x;
cout<<"Enter the data\n";
cin>>x;
 if(top == N-1){
 cout<<"Overflow condition\n";
 }else{
 top ++;
 stack[top] = x;
 }
}

void pop(){
int item;
if(top == -1){
cout<<"Empty\n";
item = stack[top];
top--;
cout<<item;
}
cout<<endl;
}

void peek(){
if(top == -1){
cout<<"Stack is empty\n";
}else{
cout<<stack[top];
}
cout<<endl;
}

void display(){
int i;
for(i=top; i>-1; i--){
cout<<stack[i]<<" ";
}
cout<<endl;
}


int  main(){
int choice;

do{
cout<<"press 1 for push 2 for pop 3 for peek 4 display\n";
cin>>choice;
switch(choice){
case 1: push();break;
case 2: pop();break;
case 3: peek();break;
case 4: display();break;
default : cout<<"Invalid choice\n";
}
}while(choice != 0);

}