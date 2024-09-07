#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
        Node*prev;
        Node(int data){
            this->data=data;
            prev=next=NULL;
        }
};
class List{
    private:
        Node*head;
        int length;
    public:
        List(){
            head=NULL;
            length=0;
        }
        void insert(int val,int pos){
            if(pos<1 || pos>length+1) return ;
            Node*n=new Node(val);
            if(pos==1){
                n->next=head;
                if(head){
                    head->prev=n;
                }
                head=n;
            }
            else{
                Node*curr=head;
                for(int i=1;i<pos-1;i++){
                    curr=curr->next;
                }
                n->next=curr->next;
                n->prev=curr;
                if(n->next){
                    curr->next->prev=n;
                }
                curr->next=n;
            }
            length++;
        }
        void remove(int pos){
            if(length==0) return;
            if(pos<0 || pos>length) return;
            Node*curr=head;
            if(pos==1){
                head=head->next;
                delete curr;
                if(head){
                    head->prev=NULL;
                }
            }
            else{
                for(int i=1;i<pos;i++){
                    curr=curr->next;
                }
                curr->prev->next=curr->next;
                if(curr->next){
                    curr->next->prev=curr->prev;
                }
                delete curr;
            }
            length--;   
        }
        void reverse(){
            Node*p=head;
            Node*temp=NULL;
            while(p){
                temp=p->next;
                p->next=p->prev;
                p->prev=temp;
                p=p->prev;
                if(p!=NULL && p->next==NULL){
                    head=p;
                }
                p=temp;
            }
        }
        void display(){
            Node*p=head;
            while(p){
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
};
int main(){
    List l1;
    l1.insert(3,1);
    l1.insert(4,2);
    l1.insert(5,3);
    l1.insert(7,4);
    l1.insert(6,4);
    l1.remove(3);
    //l1.reverse();
    l1.display();
    
}