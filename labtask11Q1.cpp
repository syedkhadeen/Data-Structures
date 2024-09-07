#include<iostream>
#include<algorithm>
#include<cmath>
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
        int height(Node *p){
            if(p==NULL) return 0;
            int left=height(p->left);
            int right=height(p->right);
            return max(left,right)+1;
        }
        bool isBalanced(Node *p){
            if(p==NULL) return true;
            int left=height(p->left);
            int right=height(p->right);
            if(abs(left-right)<=1 && isBalanced(p->left) && isBalanced(p->right)) return  true;
            return false;
        }
        bool isAVL(Node *root){
            if(root==NULL) return false;
            else{
                return isBalanced(root);
            }
        }
        friend int main();
};
int main(){
    BST bst;
    int choice,data;
    char ch;
    do{
        cout<<"\n1. Insert in a BST."<<endl;
        cout<<"2. Check if its AVL or not."<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 0:
                cout<<"Ending program."<<endl;
                break;
            case 1:
                do{
                    cout<<"Enter data to insert: ";
                    cin>>data;
                    bst.root=bst.insert(bst.root,data);
                    cout<<"Do you want to insert another value? (Y/N): ";
                    cin>>ch;
                } while(ch=='Y'||ch=='y');
                break;
            case 2:
                if(bst.isAVL(bst.root)) cout<<"The tree is AVL."<<endl;
                else  cout<<"The tree is not AVL."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please enter again."<<endl;
                break;
        }
    }while(choice!=0);
}