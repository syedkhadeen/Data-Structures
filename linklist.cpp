#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class LinkedList{
    private:
        Node*head;
        int length;
    public:
        LinkedList(){
            head=NULL;
            length=0;
        }
        void insert(int pos,int data){
            if(pos< 1|| pos>length+1) return;
            Node*t=new Node(data);
            if(pos==1){
                t->next=head;
                head=t;
            }
            else{
                Node*curr=head;
                for(int i=1;i<pos-1;i++){
                    curr=curr->next;
                }
                t->next=curr->next;
                curr->next=t;
            }
            length++;
        }
        void Delete(int pos){
            if(length==0) return;
            if(pos<1 || pos>length) return;
            Node *curr=head;
            if(pos==1){
                head=head->next;
                delete curr;
            }
            else{
                Node*slow=head;
                for(int i=1;i<pos;i++){
                    slow=curr;
                    curr=curr->next;
                }
                slow->next=curr->next;
                delete curr;
            }
            length--;
        }
        void display(){
            Node *p=head;
            while(p){
                cout<<p->data<<" ";
                p=p->next;
            }
        }
        void update(int pos,int val){
            Node*curr=head;
            for(int i=1;i<pos;i++){
                curr=curr->next;
            }
            curr->data=val;
        }
        int find(int val){
            Node*curr=head;
            int i=1;
            while(curr){
                if(curr->data==val) return i;
                curr=curr->next;
                i++;
            }
            return 0;
        }
        void sortedInsert(int val){
            Node*t=new Node(val);
            Node*p,*q;
            q=NULL;
            p=head;
            while(p&&p->data<t->data){
                q=p;
                p=p->next;
            }
            q->next=t;
            t->next=p;
        }
        int findMid(){
            Node*fast=head;
            Node*slow=head;
            while(fast&&fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            return slow->data;
        }
        void reverse(){
            Node*p=head;
            Node*q=NULL;
            Node*r=NULL;
            while(p){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            head=q;
        }
        bool hasCycle(){
            Node*fast=head;
            Node*slow=head;
            while(fast&&fast->next){
                fast=fast->next->next;
                slow=slow->next;
                if(fast==slow) return true;
            }
            return false;
        }
};
int main(){
    LinkedList l1;
    // l1.Insert(0,1);
    // l1.Insert(1,2);
    // l1.Insert(2,3);
    // l1.Insert(3,5);
    // l1.Insert(2,7);

   // l1.insert(0,1);
    l1.insert(1,2);
    l1.insert(2,3);
    l1.insert(3,5);
   // l1.insert(2,7);
    // l1.Delete(3);
    // l1.Delete(1);
    l1.insert(4,7);
    l1.insert(5,9);
    l1.sortedInsert(4);
    //cout<<l1.findMid();
    //cout<<endl;
    //l1.reverse();
    //cout<<l1.hasCycle();
    //cout<<l1.find(9)<<endl;
    l1.display();
}