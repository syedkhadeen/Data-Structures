#include<iostream>
using namespace std;
class Node{
    public:
        Node*left;
        int data;
        Node*right;
};
class BST{
    public:
        Node*root;
        void Inorder(){Inorder(root);}
        Node*Delete(int key){Delete(root,key);}
        BST():root(NULL){}
        Node*Rinsert(int key){Rinsert(root,key);}
        Node* Rinsert(Node*p,int key){
            Node*t=NULL;
            if(p==NULL){
                t=new Node;
                t->data=key;
                t->left=t->right=NULL;
                return t;
            }
            if(key<p->data){
                p->left=Rinsert(p->left,key);
            }
            else if(key>p->data){
                p->right=Rinsert(p->right,key);
            }
            return p;
        }
        void Insert(int key){
            Node*t=root;
            Node*r,*p;
            if(root==NULL){
                p=new Node;
                p->data=key;
                p->left=p->right=NULL;
                root=p;
                return;
            }
            while(t!=NULL){
                r=t;
                if(key<t->data){
                    t=t->left;
                }
                else if(key>t->data){
                    t=t->right;
                }
                else return;
            }
            p=new Node;
            p->data=key;
            p->left=p->right=NULL;
            if(key<r->data){
                r->left=p;
            }
            else{
                r->right=p;
            }
        }
        void Inorder(Node*p){
            if(p){
                Inorder(p->left);
                cout<<p->data<<" ";
                Inorder(p->right);
            }
        }
      
        bool pairSum(Node *p, int sum){
            if(p==NULL) return false;
            if (p->data+p->left->data==sum){
                cout<<p->data<<" "<<p->left->data<<endl;
                return true;
            }
            if(p->data+p->right->data==sum){
                cout<<p->data<<" "<<p->right->data<<endl;
                return true;
            }
            return pairSum(p->left,sum)||pairSum(p->right,sum);
        }
      
};
int main(){
    BST obj;
    obj.root=obj.Rinsert(15);
    obj.Rinsert(10);
    obj.Rinsert(25);
    obj.Rinsert(8);
    obj.Rinsert(12);
    obj.Rinsert(20);
    obj.Rinsert(30);
    obj.Rinsert(6);
    obj.Rinsert(9);
    obj.Rinsert(18);
    obj.Rinsert(22);
    obj.Inorder();
    cout<<endl;
    cout<<"The pairs are : "<<obj.pairSum(obj.root,16);
}