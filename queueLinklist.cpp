#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
};
class Queue{
    private:
        Node*front,*rear;
    public:
        Queue(){front=NULL; rear=NULL;}
        void enQueue(int x){
            Node *t=new Node;
            if(t==NULL){
                cout<<"Queue is full";
            }
            else{
                t->data=x;
                t->next=NULL;
                if(front==NULL){
                    front=rear=t;
                }
                else{
                    rear->next=t;
                    rear=t;
                }
            }
        } 
        int deQueue(){
            int x=-1;
            Node*p;
            if(front==NULL){
                cout<<"Queue is empty";
            }
            else{
                p=front;
                front=front->next;
                x=p->data;
                delete p;
            }
            return x;
        }
        void Display(){
            Node *p=front;
            while(p){
               cout<<p->data<<" ";
               p=p->next;
            }
        }
};
int main(){
    Queue  q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    q.Display();
}
