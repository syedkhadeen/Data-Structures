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
            if(p->lchild==NULL && p->rchild ==NULL){
                if(p==root) root=NULL;
                delete p;
                return NULL;
            }
            if(key<p->data){
                p->lchild=Delete(p->lchild,key);
            }
            else if(key>p->data){
                p->rchild=Delete(p->rchild,key);
            }
            else{
                if(Height(p->lchild)>Height(p->rchild)){
                    q=InPre(p->lchild);
                    p->data=q->data;
                    p->lchild=Delete(p->lchild,q->data);
                }
                else{
                    q=InSucc(p->rchild);
                    p->data=q->data;
                    p->rchild=Delete(p->rchild,q->data);
                }
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
        cout<<"2. Search for a Node."<<endl;
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
                cout<<"Enter the key you want to search : "<<endl;
                cin>>key;
                res=bst.search(bst.root, key);
                if(res){
                    cout<<"Inorder Traversal : "<<endl;
                    bst.Inorder(res);
                    cout<<"\nPreorder Traversal : "<<endl;
                    bst.PreOrder(res);
                    cout<<"\nPostorder Traversal : "<<endl;
                    bst.Postorder(res);
                }
                else cout<<"The element is not present in the tree."<<endl;
                break;
            default:
                cout<<"Invalid choice. Please enter again."<<endl;
                break;
        }
    }while(choice!=0);
}

// class BST{
//     private:
//         class Node{
//             Node*left;
//             int data;
//             Node*right;
//             Node():data(0),left(NULL),right(NULL){}
//             Node(int data):data(data),left(NULL),right(NULL){}
//             friend  class BST;
//         };
//         Node*root;
//     public:
//         BST():root(NULL){}
//         Node* insert(Node*p,int data){
//             Node*t=NULL;
//             if(p==NULL){
//                 t=new Node;
//                 t->data=data;
//                 t->left=t->right=NULL;
//                 return t;
//             }
//             if(data<p->data) p->left=insert(p->left,data);
//             else if(data>p->data) p->right=insert(p->right,data);
//             return p;
//         }
//         void Inorder(Node *p){
//             if(p){
//                 Inorder(p->left);
//                 cout<<p->data<<" ";
//                 Inorder(p->right);
//             }
//         }
//         void PreOrder(Node*p){
//             if(p){
//                 cout<<p->data<<" ";
//                 PreOrder(p->left);
//                 PreOrder(p->right);
//             }
//         }
//         void Postorder(Node*p){
//             if(p){
//                 Postorder(p->left);
//                 Postorder(p->right);
//                 cout<<p->data<<" ";
//             }
//         }
//         int count(Node *p){
//             if(p==NULL) return 0;
//             return count(p->left)+count(p->right)+1;
//         }
//         int minimum(Node *p){
//             if(p->left==NULL) return p->data;
//             return minimum(p->left);
//         }
//         friend int main();
// };
// int main(){
//     BST bst;
//     int choice, data;
//     do{
//         cout<<"\n1. Insert in a BST."<<endl;
//         cout<<"2. InOrder Traversal."<<endl;
//         cout<<"3. PreOrder Traversal."<<endl;
//         cout<<"4. PostOrder Traversal."<<endl;
//         cout<<"5. Count Nodes."<<endl;
//         cout<<"6. Find Minimum Value."<<endl;
//         cout<<"0. To end program."<<endl;
//         cout<<"Enter your choice: ";
//         cin>>choice;
//         switch (choice){
//             case 0:
//                 cout<<"Ending program."<<endl;
//                 break;
//             case 1:
//                 char choice;
//                 do{
//                     cout<<"Enter data to insert: ";
//                     cin>>data;
//                     bst.root=bst.insert(bst.root,data);
//                     cout<<"Do you want to insert another value? (Y/N): ";
//                     cin>>choice;
//                 }while(choice=='Y'||choice=='y');
//                 break;
//             case 2:
//                 cout<<"InOrder Traversal: ";
//                 bst.Inorder(bst.root);
//                 cout<<endl;
//                 break;
//             case 3:
//                 cout<<"PreOrder Traversal: ";
//                 bst.PreOrder(bst.root);
//                 cout<<endl;
//                 break;
//             case 4:
//                 cout<<"PostOrder Traversal: ";
//                 bst.Postorder(bst.root);
//                 cout<<endl;
//                 break;
//             case 5:
//                 cout<<"Number of nodes in BST: "<<bst.count(bst.root)<<endl;
//                 break;
//             case 6:
//                 cout<<"Minimum value in BST: "<<bst.minimum(bst.root)<<endl;
//                 break;
//             default:
//                 cout<<"Invalid choice. Please enter again."<<endl;
//                 break;
//         }
//     }while(choice!=0);
//     return 0;
// }

// int multiply(int a,int b){
//     if(b==0) return 0;
//     else return a+multiply(a,b-1);
// }
// int main(){
//     int x=4,y=5;
//     cout<<"Multiplication of "<<x<<"  and "<<y<<" is : "<<multiply(4,5);
// }