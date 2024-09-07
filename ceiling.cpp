#include<iostream>
using namespace std;
int ceiling(int *a,int key,int size){
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            end=mid-1;
        else 
            start=mid+1;
    }
    return start;

}
int main(){
    int a[] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43};
    int key=19;
    int size=sizeof(a)/sizeof(a[0]);
    cout<<"Ceiling is : "<<a[ceiling(a,key,size)];
}