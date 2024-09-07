#include<iostream>
using namespace std;
/*int binarysearch(int *a,int key,int size){
    int l,mid,h;
    l=0;
    h=size-1;
    while(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            h=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return -1;
}
*/
int RbinSearch(int *a,int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            return RbinSearch(a,l,mid-1,key);
        else
            return RbinSearch(a,mid+1,h,key);
    }
    return -1;
}
int main(){
    int a[] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43};
    int key=41;
    int size=sizeof(a)/sizeof(a[0]);
   // cout<<"Element found at : "<<binarysearch(a,key,size);
    cout<<"Element found at : "<<RbinSearch(a,0,size-1,key);
}