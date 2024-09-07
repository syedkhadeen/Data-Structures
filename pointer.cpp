#include<iostream>
using namespace std;
// void sum(int a,int b){
//     cout<<a+b;
// }
// void(*ptrSum)(int,int);
// int main(){
//     ptrSum=&sum;
//     ptrSum(3,3);
//     cout<<endl;
//     int age=19;
//     int *ptr=&age;
//     int **ptr1=&ptr;
//     cout<<ptr<<endl;
//     cout<<&ptr<<endl;
//     cout<<*ptr<<endl;
//     cout<<ptr1<<endl;
//     cout<<&ptr1<<endl;
//     cout<<**ptr1<<endl;
// }
void print(int *arr,int size){
    int *p;
    for(p=arr;p<arr+size;p++){
        cout<<*p<<" ";
    }
}
bool checkSum(int *arr,int size,int a){
    int *p;
    int sum=0;
    for(p=arr;p<arr+size;p++){
        //cout<<*p<<" ";
        sum+=*p;
    }
    if(sum==a)return true;
    else return false;

}
void swap(int *arr,int size){
    int *p,temp,*q;
    for(p=arr,q=arr+1;p<arr+size-1;p+=2,q+=2){
        temp=*p;
        *p=*q;
        *q=temp;
        //q++;
    }  
    print(arr,size); 

}
void rearrange(int *arr,int size){
    int *even,*odd,temp;
    for(even=arr,odd=arr+1;even<arr+size-1;even+=2,odd+=2){
        if(*even%2!=0 && *odd%2==0){
            temp=*even;
            *even=*odd;
            *odd=temp;
        }
    }
        print(arr,size);
}
int main(){
    int arr[]={5,2,9,4,7,6,1,3,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    cout<<endl;
//     cout<<endl;
//    cout<< checkSum(arr,size,10)<<endl;
//    swap(arr,size);
    rearrange(arr,size);
   
}
