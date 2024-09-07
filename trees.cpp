#include<iostream>
//#include<stack.cpp>
using namespace std;
class Node{
    public:
        Node*lchild;
        int data;
        Node*rchild;
};
class Queue{
    private:
        int size;
        int front;
        int rear;
        Node **Q;
    public:
        Queue(){front=rear=-1;size=10; Q = new Node*[size];}
        Queue(int size){front=rear=-1;this->size=size; Q = new Node*[this->size];}
        void enqueue(Node* x){
            if(rear==size-1){
                cout<<"Queue Full";
            }
            else{
                rear++;
                Q[rear]=x;
            }
        }
        Node* dequeue(){
            Node* x=NULL;
            if(front==rear){
                cout<<"Queue empty";
            }
            else{
                x=Q[++front];
            }
            return x;
        }
        void Display(){
            for(int i=front+1;i<=rear;i++){
                cout<<Q[i]<<" ";
            }
        }
        int isEmpty(){return front==rear;}
};
class Tree{
        Node*root;
    public:
        Tree():root(NULL){}
        void CreateTree(){
            Node*p,*t;
            int x;
            Queue q(100);
            cout<<"Enter root value : ";
            cin>>x;
            root=new Node;
            root->data=x;
            root->lchild=root->rchild=NULL;
            q.enqueue(root);
            while(!q.isEmpty()){
                p=q.dequeue();
                cout<<"Enter the lchild child of  "<<p->data<<" : ";
                cin>>x;
                if(x!=-1){
                    t=new Node;
                    t->data=x;
                    t->lchild=t->rchild=NULL;
                    p->lchild=t;
                    q.enqueue(t);
                }
                cout<<"Enter the rchild child of  "<<p->data<<" : ";
                cin>>x;
                if(x!=-1){
                    t=new Node;
                    t->data=x;
                    t->lchild=t->rchild=NULL;
                    p->rchild=t;
                    q.enqueue(t);
                }
            }
        }
        void PreOrder(){PreOrder(root);}
        void Postorder(){Postorder(root);}
        void Inorder(){Inorder(root);}
        void Levelorder(){Levelorder(root);}
        int Height(){return Height(root);}
        int count(){return count(root);}
        int countSum(){return count(root);}
        void PreOrder(Node*p){
            if(p){
                cout<<p->data<<" ";
                PreOrder(p->lchild);
                PreOrder(p->rchild);
            }
        }
        void Postorder(Node*p){
            if(p){
                Postorder(p->lchild);
                Postorder(p->rchild);
                cout<<p->data<<" ";
            }
        }
        void Inorder(Node*p){
            if(p){
                Inorder(p->lchild);
                cout<<p->data<<" ";
                Inorder(p->rchild);
            }
        }
        void Levelorder(Node *root){
            Queue q(100);
            cout<<root->data<<" ";
            q.enqueue(root);
            while(!q.isEmpty()){
                root=q.dequeue();
                if(root->lchild){
                    cout<<root->lchild->data<<" ";
                    q.enqueue(root->lchild);
                }
                if(root->rchild){
                    cout<<root->rchild->data<<" ";
                    q.enqueue(root->rchild);
                }
            }
        }
        int count(Node* root){
            if(root){
                return count(root->lchild)+count(root->rchild)+1;  
            }
            else{
                return 0;
            }
        }
        int countSum(Node *p){
            if(p==NULL) return 0;
            if(p->lchild->data+p->rchild->data==p->data) return countSum(p->lchild)+countSum(p->rchild)+1;
            else return countSum(p->lchild)+countSum(p->rchild);
        }
        int Height(Node*root){
            int x=0,y=0;
            if(root==0) return 0;
            x=Height(root->lchild);
            y=Height(root->rchild);
            if(x>y) return x+1;
            else  return y+1;
        }
};
int main(){
    Tree t;
    t.CreateTree();
    // cout<<"Pre Order : "<<endl;
    // t.PreOrder();
    // cout<<endl;
    // cout<<"Inorder : "<<endl;
    // t.Inorder();
    // cout<<endl;
    // cout<<"PostOrder : "<<endl;
    // t.Postorder();
    // cout<<endl;
    // cout<<"Level Order : "<<endl;
    // t.Levelorder();
    cout<<"Count : "<<t.countSum()<<endl;
    cout<<"Height : "<<t.Height()<<endl;
    return 0;
}