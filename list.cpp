#include<iostream>
using namespace std;
class List{
    private:
        int *arr,capacity,length,*curr;
    public:
        List(int size){
            arr=new int[size];
            capacity=size;
            length=0;
            curr=NULL;
        }
        void start(){curr=arr;}
        void tail(){
            curr=arr+length-1;                    //Faster method
            // for(int i=0;i<length;i++){        //We can also use this method to move the curr pointer,but it is slower method.
            //     curr++;
            // }
        }
        void next(){curr++;}
        void back(){curr--;}
        void insert(int pos,int val){
            if(length==capacity){
                return;
            }
            if(pos<1 || pos>length+1){
                return;
            }
            tail();
            for(int i=length;i>=pos;i--){
                *(curr+1)=*curr;
                 back();
            }
            *(curr+1)=val;
            length++;
        }
        void remove(int pos){
            if(length==0) return;
            if(pos<1 || pos>length) return;
            curr=arr+pos-1;
            for(int i=pos;i<length;i++){
                *curr=*(curr+1);
                next();
            }
            length--;
        }
        void display(){
            for(int i=0;i<length;i++){
                cout<<" "<<arr[i];
            }
            cout<<endl;
        }
        int get(int pos){
            if(length==0) return -1;
            if(pos<1||pos>length)return -1;
            curr=arr+pos-1;
            return *curr;
        }
        void update(int val,int pos){
            if(length==capacity){
                return;
            }
            if(pos<1 || pos>length+1){
                return;
            }
            curr=arr+pos-1;
            *curr=val;
        }
        bool find(int val){
            start();
            for(int i=1;i<length;i++){
                if(*curr==val) return true;
                next();
            }
            return false;
        }
        int lengthOfList(){
            return length;
        }
        void createList(){
            delete []arr;
            length=0;
            curr=NULL;
        }
        void copy(List l1){
            for(int i=1;i<=l1.length;i++){
                insert(i,l1.get(i));
            }
        }
        void clear(){
            delete []arr;
            length=0;
            curr=NULL;
        }
};
void reverseArray(int *a,int size){
    int *start=a;
    int *end=a+size-1;
    int temp;
    // for(int i=1;i<size;i++){
    //     end++;
    // }
    while(start<=end){
        temp=*start;
        *start=*end;
        *end=temp;
        end--;
        start++;
    }
    for(int *i=a;i<a+size;i++){
        cout<<" "<<*i;
    }
}
int main(){
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    cout<<size<<endl;
    reverseArray(a,size);
    // List lis(5);
    // lis.insert(1,2);
    // lis.insert(2,3);
    // lis.insert(3,4);
    // lis.insert(4,5);
    // cout<<"List 1 before insertion : "<<endl;
    // lis.display();
    // cout<<endl;
    // cout<<"List1 after  inserting the value 7 at index 3 : "<<endl;
    // lis.insert(3,7);
    // lis.display();
    // cout<<endl;
    // cout<<"Getting the index of element 4 in the list : "<<lis.get(4)<<endl<<endl;
    // cout<<"List1 after removing at position 2 : "<<endl;
    // lis.remove(2);
    // lis.display();
    // cout<<endl;
    // lis.update(8,3);
    // cout<<"After updating 3 position to 8 value in the list: "<<endl;
    // lis.display();
    // cout<<endl;
    // cout<<"Finding element 8 in the list True(1) and False(0) : "<<lis.find(8)<<endl<<endl;
    // cout<<"The length of list is : "<<lis.lengthOfList()<<endl<<endl;
   
    // List lis2(5);
    // lis2.createList();
    // cout<<endl;
    // cout<<"Copying elements of list 1 in list 2 : "<<endl;
    // lis2.copy(lis);

    // // Display the contents of lis2
    // lis2.display();
    // cout<<endl;
    // // Clear the contents of lis2
    // lis2.clear();
    // lis.clear();
    // // Display the contents of lists after clearing
    // cout<<"List 1 after clearing : "<<endl;
    // lis.display();

    // cout<<"List 2 after clearing : "<<endl;
    // lis2.display();
}