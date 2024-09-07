#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node * next;
}*first=NULL,*second=NULL,*third=NULL;
void create(int *a,int n){
    int i;
    struct Node*t,*last;
    first=new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void create2(int *a,int n){
    int i;
    struct Node*t,*last;
    second=new Node;
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node*p){
    while(p!=NULL){
        cout<<"  "<<p->data;
        p=p->next;
    }
}
int count(struct Node*p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
//sum using loop
int Add(struct Node*p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
//summ using recursion
int recurAdd(struct Node*p){
    if(p==NULL){
        return 0;
    }
    else{
        return recurAdd(p->next)+p->data;
    }
}
//max element using loop
int max(Node *p){
    int m=INT_MIN;
    while(p){
        if(p->data>m){
            m=p->data;
        }
        p=p->next;
    } 
    return m;
}
//using recursion
int recMax(Node*p){
    int x=0;
    if(p==NULL){
        return INT_MIN;
    }
    x=recMax(p->next);
    return x>p->data?x:p->data;
}
//Searching (linear search) using loop
Node* search(Node *p,int key){
    while(p!=NULL){
        if(p->data==key)
            return p;
        p=p->next;
    }
    return NULL;
}
//using recursion
Node* recSearch(Node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return recSearch(p->next,key);
} 
//insertion
void Insert(struct Node*p,int index,int x){
    struct Node*t;
    if(index<0 || index>count(p)){
        return;
    }
    t=new Node;
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}
void SortedInsert(struct Node*p,int x){
    struct Node*t,*q=NULL;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else{
        while(p&&p->data<x){
            q=p;
            p=p->next;
            if(p==first){
                t->next=first;
                first=t;
            }
            else{
                t->next=q->next;
                q->next=t;
            }
        }
    }

}
// Deleting in Linked List
int Delete(struct Node *p,int index){
    struct Node * q;
    int x=-1,i;
    if(index<1 || index>count(p))
        return -1;
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        delete p;
        return x; 
    }
    else{
        q=NULL;
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
         }
         q->next=p->next; 
         x=p->data;
         delete p;
         return x;
    }
}
//second way of deletion
int delete2(struct Node*p,int pos){
    Node *q;
    int x=-1,i;
    if(pos==1){
        x=first->data;
        p=first;
        first=first->next;
        delete p;
    }
    else{
        p=first;
        q=NULL;
        for(i=0;i<pos-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            delete p;
        }
    }
    return x;
}
// Check if linked list is sorted
bool isSorted(struct Node*p){
    int x=INT_MIN;
    while(p!=NULL){
        if(p->data<x){
            return false;
        }
        x=p->data;
        p=p->next; 
    }
    return true;
}
//Removing duplicate in a sorted linked list
void removeDupliacte(struct Node * p){
    struct Node*q=p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}
//Reversing a linked list
Node* reverse(struct Node *p){
    struct Node*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    return q;
}
//Using recursion
void reverse2(struct Node*q,struct Node *p){
    if(p!=NULL){
        reverse2(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
//Concatenation
void concatenation(struct Node*p,struct Node*q){
    third=p;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=q;
}
//Merging two sorted linked lists
void merge(struct Node*p,struct Node*q){
    struct Node*last;
     if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
     }
     else{
        third=last=q;
        q=q->next;
        third->next=NULL;
     }
     while(p&&q){
        if(p->data<=q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
        if(p){
            last->next=p;
        }
        else{
            last->next=q;
        }
    }
}    
int main(){
    int a[]={10,20,30,40,50};
    int b[]={5,15,25,35,45};
    create(a,5);
    create2(b,5);
    //Insert(first,5,10);
    // Display(first);
    // cout<<endl;
    // Display(second);
    //merge(first,second);
    //Display(third); 
    // delete2(first,4);
    // reverse2(NULL,first);
    // cout<<endl;
    // Display(first);
    // cout<<endl;
    // removeDupliacte(first);
    // Display(first);
    // Display(first);
    // if(isSorted(first)){
    //     cout<<"Linked List is Sorted\n";
    // }
    // else{
    //     cout<<"Linked List is not Sorted\n";
    // }
    //SortedInsert(first,8);
    //Display(first); 
    // cout<<count(first)<<endl;
    // cout<<Add(first)<<endl;
    // cout<<recurAdd(first)<<endl;
    // cout<<max(first)<<endl;
    // cout<<recMax(first)<<endl;
    // cout<<search(first,10)<<endl;
    // cout<<recSearch(first,15);


}