#include<iostream>
using namespace std;
int binarysearch(int *a,int key,int size,int start,int end){
    while(start<=end){
        int mid=(start+end)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
            end=mid-1;
        else 
            start=mid+1;
    }
    return -1;
}
int ans(int *a,int target,int start,int end){
        int start=0;
        int end=start+1;
        while(target>a[end]){
            int temp=end+1;
            end=end+(end-start+1)*2;
            start=temp;
        }
        return binarysearch(a,target,start,end);
}
int main(){
   int a[] = {4, 8, 10, 15, 18, 21, 24, 27, 29, 33, 34, 37, 39, 41, 43};
   int target=10;
   cout<<ans(a,target);
}