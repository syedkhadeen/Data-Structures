#include<iostream>
using namespace std;
class BST{
    private:
        class Node{
            Node*left;
            int data;
            Node*right;
            Node():data(0),left(NULL),right(NULL){}
            Node(int data):data(data),left(NULL),right(NULL){}
            friend  class BST;
            friend int main();
        };
        Node*root;
    public:
        BST():root(NULL){}
        Node* insert(Node*p,int data){
            Node*t=NULL;
            if(p==NULL){
                t=new Node;
                t->data=data;
                t->left=t->right=NULL;
                return t;
            }
            if(data<p->data) p->left=insert(p->left,data);
            else if(data>p->data) p->right=insert(p->right,data);
            return p;
        }
        Node* mirror(Node *root){
            if(root==NULL) return NULL;
            Node* left=mirror(root->left);
            Node* right=mirror(root->right);
            root->left=right;
            root->right=left;
            return root;
        }
        void Inorder(Node *p){
            if(p){
                Inorder(p->left);
                cout<<p->data<<" ";
                Inorder(p->right);
            }
        }
        friend int main();
};
int main(){
    BST bst;
    int choice,data,key;
    BST res;
    char ch;
    do{
        cout<<"\n0. To end program."<<endl;
        cout<<"1. Insert in a BST."<<endl;
        cout<<"2. Mirror of tree."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                break;
            case 1:
                do{
                    cout<<"Enter data to insert: ";
                    cin>>data;
                    bst.root=bst.insert(bst.root,data);
                    cout<<"Do you want to insert another value? (Y/N): ";
                    cin>>ch;
                }while(ch=='Y'||ch=='y');
                break;
            case 2:
                cout<<"Inorder of Normal tree : "<<endl;
                bst.Inorder(bst.root);
                res.root=bst.mirror(bst.root);
                cout<<"\nInorder of Mirror Tree : "<<endl;
                res.Inorder(res.root);
                break;
            default:
                cout<<"Invalid choice. Please enter again."<<endl;
                break;
        }
    }while(choice!=0);
}