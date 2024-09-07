#include<iostream>
using namespace std;
class BST{
    class Node{
    public:
        Node*left;
        int data;
        Node*right;
        friend class BST;
        friend int main();
    };
    public:
        Node*root;
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
        Node* lca(Node* root,int p,int q){
            if(root==NULL)return NULL;
            if(root->data>p && root->data>q) return lca(root->left,p,q);
            if(root->data<p && root->data<q) return lca(root->right,p,q);
            return root;
        }
        friend int main();
};
int main(){
    BST obj;
    obj.root=obj.Rinsert(6);
    obj.Rinsert(2);
    obj.Rinsert(9);
    obj.Rinsert(1);
    obj.Rinsert(5);
    obj.Rinsert(8);
    obj.Rinsert(4);
    obj.Rinsert(7);
    obj.Rinsert(10);
    cout<<obj.lca(obj.root,7,10)->data;
}
 