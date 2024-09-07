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
        void Inorder(Node *p){
            if(p){
                Inorder(p->left);
                cout<<p->data<<" ";
                Inorder(p->right);
            }
        }
        void PreOrder(Node*p){
            if(p){
                cout<<p->data<<" ";
                PreOrder(p->left);
                PreOrder(p->right);
            }
        }
        void Postorder(Node*p){
            if(p){
                Postorder(p->left);
                Postorder(p->right);
                cout<<p->data<<" ";
            }
        }
        Node *search(Node *p,int key){
            if(p==NULL) return NULL;
            if(key==p->data) return p;
            else if(key<p->data) return search(p->left,key);
            else if(key>p->data)return search(p->right,key);
            return NULL;
        }
        Node* Delete(Node*p,int key){
            Node*q;
            if(p==NULL) return NULL;
            if(p->left==NULL && p->right ==NULL){
                if(p==root) root=NULL;
                delete p;
                return NULL;
            }
            if(key<p->data){
                p->left=Delete(p->left,key);
            }
            else if(key>p->data){
                p->right=Delete(p->right,key);
            }
            else{
                if(Height(p->left)>Height(p->right)){
                    q=InPre(p->left);
                    p->data=q->data;
                    p->left=Delete(p->left,q->data);
                }
                else{
                    q=InSucc(p->right);
                    p->data=q->data;
                    p->right=Delete(p->right,q->data);
                }
            }
            return p;
        }
        int Height(Node*p){
            int x,y;
            if(p==NULL) return 0;
            x=Height(p->left);
            y=Height(p->right);
            return x>y?x+1:y+1;
        }
        Node*InSucc(Node*p){
            while(p && p->left!=NULL){
                p=p->left;
            }
            return p;
        }
        Node*InPre(Node*p){
            while(p && p->right!=NULL){
                p=p->right;
            }
            return p;
        }
        friend int main();
};
int main(){
    BST bst;
    int choice,data,key;
    BST::Node *res=NULL;
    char ch;
    do{
        cout<<"\n1. Insert in a BST."<<endl;
        cout<<"2. Delete from BST."<<endl;
        cout<<"3. Display BST."<<endl;
        cout<<"0. End program."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Ending program."<<endl;
                break;
            case 1:
                do{
                    cout<<"Enter data to insert: ";
                    cin>>data;
                    bst.root = bst.insert(bst.root, data);
                    cout<<"Do you want to insert another value? (Y/N): ";
                    cin>>ch;
                }while(ch=='Y'||ch=='y');
                break;
            case 2:
                cout<<"Enter the key you want to delete: "<<endl;
                cin>>key;
                bst.root = bst.Delete(bst.root, key);
                break;
            case 3:
                if(bst.root==nullptr){
                    cout<<"BST is empty."<<endl;
                } 
                else{
                    cout<<"Inorder Traversal : ";
                    bst.Inorder(bst.root);
                    cout<<endl;
                }
                break;
            default:
                cout<<"Invalid choice. Please enter again."<<endl;
                break;
        }
    }while(choice!=0);
    return 0;
}