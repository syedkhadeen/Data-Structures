#include<iostream>
using namespace std;
int main(){
    int n,elements;
    bool check;
    bool array[];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>elements;
        for(int i=0;i<elements;i++){
            cin>>array[i];
            if(i==0) array[i]=true;
            else if(i==elements-1) array[i]=false;
        }
        cin>>check;
    }
    
}