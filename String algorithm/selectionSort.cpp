#include<bits/stdc++.h>
using namespace std;

int main(){
  int n[] = {6,4,5,3,2,1,7,8,9};
    int i,j,m=9,f,k;
    for(i=0; i<m; i++){
        int temp = n[i];
        k=0;
        for(j=i+1; j<m; j++){
            if(n[j]<temp){
                temp = n[j];
                f=j;
                k++;
            }
        }
        if(k != 0){
        n[f]=n[i];
        n[i] = temp;
        }
    }
    cout<<"Ascending order"<<endl;


    for(i=0; i<m; i++)
        cout<<n[i]<<" ";

     for(i=0; i<m; i++){
        int temp = n[i];
        k=0;
        for(j=i+1; j<m; j++){
            if(n[j]>temp){
                temp = n[j];
                f=j;
                k++;
            }
        }
        if(k != 0){
        n[f]=n[i];
        n[i] = temp;
        }
    }

    cout<<endl;
    cout<<"Descending order"<<endl;
    for(i=0; i<m; i++)
        cout<<n[i]<<" ";
     return 0;
}