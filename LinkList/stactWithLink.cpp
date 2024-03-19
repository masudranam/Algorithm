#include<iostream>
using namespace std;


void add(int *a,int b[],int n) {
    int carry=0;
    for(int i=n; i>=0; i--) {
        a[i]=(a[i]+b[i]+carry);
        if(a[i]>1) {
            a[i]%=2;
            carry=1;
        } else {
            carry=0;
        }
    }
}

void complement(int *a,int n) {
    int x[n+1]= {0};
    x[n-1]=1;
    for(int i=n-1; i>=0; i--) {
        a[i]=(a[i]+1)%2;
    }
    add(a,x,n);
}

void rightShift(int *a,int *b,int n,int m) {
    for(int i=m-1; i>0; i--) {
        b[i]=b[i-1];
    }
    b[0]=a[n-1];
    for(int i=n-1; i>0; i--)a[i]=a[i-1];
    a[0]=0;
}

void show(int *a,int *b,int n,int m) {
    for(int i=0; i<n; i++)cout<<a[i];
    cout<<"\t\t";
    for(int i=0; i<m; i++)cout<<b[i];

}



int main() {
    int a[32]= {0},b[32]= {0},c[32]= {0},carry=0;

    int n;
    cout<<"Enter the number of multiplicant bits: ";
    cin>>n;


    cout<<"Enter multiplicant: \n";
    for(int i=0; i<n; i++)cin>>b[i];
    cout<<"Ener number of multiplier bits:\n";
    int m;
    cin>>m;
    cout<<"Enter multiplier :\n";
    for(int i=0; i<m; i++)cin>>c[i];

    for(int i=m-1; i>=0; i--) {
        if(c[m-1]==1) {
            add(a,b,30);
        }
        rightShift(a,c,n,m);
    }

    for(int i=0; i<n; i++)cout<<a[i];
    for(int i=0; i<m; i++)cout<<c[i];
    cout<<endl;

    return 0;
}
