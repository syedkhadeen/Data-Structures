#include<iostream>
using namespace std;
class AVL{
    private:
        class Node{  
            public: 
                int key;  
                Node *left;  
                Node *right;  
                int height;  
                friend  class AVL;  
                friend int main();
        }; 
        Node*root;
    public:
        AVL():root(NULL){}
        void insert(int key){
            root=insert(root,key);
        }
        void displayPreOrder(){
            cout<<"Preorder traversal of the constructed AVL tree is:" << endl;
            preOrder(root);
            cout<<endl;
        }
        Node* insert(Node* node,int key){  
            if(node==NULL) return(newNode(key));  
            if (key<node->key) node->left=insert(node->left, key);  
            else if(key>node->key) node->right=insert(node->right,key);  
            else return node;  
            node->height=1+max(height(node->left),height(node->right));  
            int balance=getBalance(node);   
            if(balance>1&&key<node->left->key) return rightRotate(node);   
            if(balance<-1&&key>node->right->key) return leftRotate(node);  
            if(balance>1&&key>node->left->key){  
                node->left=leftRotate(node->left);  
                return rightRotate(node);  
            }  
            if(balance<-1&&key<node->right->key){  
                node->right=rightRotate(node->right);  
                return leftRotate(node);  
            }  
            return node;  
        }  
        int height(Node *p){  
            if(p==NULL) return 0;  
            return p->height;  
        }   
        int max(int a,int b){  
            return(a>b)?a:b;  
        }  
        Node* newNode(int key){  
            Node* node = new Node(); 
            node->key = key;  
            node->left = NULL;  
            node->right = NULL;  
            node->height = 1;  
            return(node);  
        }  
        Node *rightRotate(Node *y){  
            Node *x = y->left;  
            Node *T2 = x->right;   
            x->right = y;  
            y->left = T2;   
            y->height = max(height(y->left),height(y->right))+1;  
            x->height = max(height(x->left),height(x->right))+1;  
            return x;  
        }   
        Node *leftRotate(Node *x){  
            Node *y = x->right;  
            Node *T2 = y->left;   
            y->left = x;  
            x->right = T2;  
            x->height=max(height(x->left),height(x->right))+1;  
            y->height=max(height(y->left),height(y->right))+1;  
            return y;  
        }  

        int getBalance(Node *p){  
            if(p == NULL)  return 0;  
            return height(p->left)-height(p->right);  
        }   
        void preOrder(Node *root){  
            if(root){  
                cout<<root->key<<" ";  
                preOrder(root->left);  
                preOrder(root->right);  
            }  
        } 
        friend int main(); 
};
int main(){  
    AVL avl;
    int key;
    char choice;
    do{
        cout<<"Enter a value to insert into AVL tree: ";
        cin>>key;
        avl.insert(key);
        cout<<"Do you want to insert another value?(y/n): ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    avl.displayPreOrder();
    return 0;
}  