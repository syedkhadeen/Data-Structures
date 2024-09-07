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
class Stack{
    private:
        Node*top;
    public:
        Stack(){top=NULL;}
        void push(int x){
            Node*t=new Node(x);
            if(t==NULL){
                cout<<"Stack Overflow";
            }
            else{
                t->data=x;
                t->next=top;
                top=t;
            }
        }
        int pop(){
            Node*p;
            int x=-1;
            if(top==NULL){
                cout<<"Stack Underflow";
                return -111;
            }
            else{
                p=top;
                top=top->next;
                int x=p->data;
                delete p;
            }
            return x;
        }
        int peek(int pos){
            int x=-1;
            Node*p=top;
            for(int i=0;p&&i<pos-1;i++){
                p=p->next;
            }
            if(p){
                return p->data;
            }
            else return -1;
        }
        int stackTop(){
            if(top) return top->data;
            return -1;
        }
        int isEmpty(){
            return top == NULL; 
        }
        int isFull(){
            Node* temp=new Node(0);
            if(temp==NULL){
                delete temp;
                return 1; 
            }
            delete temp; 
            return 0; 
        }
        void display(){
            Node* p=top;
            while (p!=NULL){
                cout << p->data <<" ";
                p=p->next;
            }
            cout<<endl;
        }

};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.display();
}