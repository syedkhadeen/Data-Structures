#include<iostream>
using namespace std;
class AVL{
    private:
        class Node{  
            public: 
                string word;
                int frequency;  
                Node *left;  
                Node *right;  
                int height;
                Node(string word,int f):word(word),frequency(f),height(1),left(NULL),right(NULL){}
                friend class AVL;  
                friend int main();
        }; 
        Node*root;
    public:
        AVL():root(NULL){}
        void insert(string word,int freq){
            root=insert(root,word,freq);
        }
        void prefixSearch(string prefix){
            bool wordFound=false;
            prefixSearch(root,prefix,wordFound);
            if(!wordFound) cout<<"Word not found."<<endl;
        }
        Node* insert(Node* node,string word,int frequency){  
            if(node==NULL) return new Node(word,frequency);  
            if (word<node->word) node->left=insert(node->left,word,frequency);  
            else if(word>node->word) node->right=insert(node->right,word,frequency);  
            else return node;  
            node->height=1+max(height(node->left),height(node->right));  
            int balance=getBalance(node);   
            if(balance>1 && word<node->left->word) return rightRotate(node);   
            if(balance<-1 && word>node->right->word) return leftRotate(node);  
            if(balance>1 && word>node->left->word){  
                node->left=leftRotate(node->left);  
                return rightRotate(node);  
            }  
            if(balance<-1 && word<node->right->word){  
                node->right=rightRotate(node->right);  
                return leftRotate(node);  
            }  
            return node;  
        }  
        int max(int a,int b){  
            return(a>b)?a:b;  
        }   
        Node *rightRotate(Node *y){  
            Node *x=y->left;  
            Node *T2=x->right;   
            x->right=y;  
            y->left=T2;   
            y->height=max(height(y->left),height(y->right))+1;  
            x->height=max(height(x->left),height(x->right))+1;  
            return x;  
        }   
        Node *leftRotate(Node *x){  
            Node *y=x->right;  
            Node *T2=y->left;   
            y->left=x;  
            x->right=T2;  
            x->height=max(height(x->left),height(x->right))+1;  
            y->height=max(height(y->left),height(y->right))+1;  
            return y;  
        }  
        int height(Node *p){  
            if(p==NULL) return 0;  
            return p->height;  
        }   
        int getBalance(Node *p){  
            if(p==NULL) return 0;  
            return height(p->left)-height(p->right);  
        }    
        void prefixSearch(Node* p,string prefix,bool& wordFound){
            if(p==NULL) return;
            bool match=true;
            for(int i=0;i<prefix.length();i++){
                if(prefix[i]!=p->word[i]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<p->word<<endl;
                wordFound=true;
            }
            if(prefix<=p->word) prefixSearch(p->left,prefix,wordFound);
            else prefixSearch(p->right,prefix,wordFound);
        }
        friend int main(); 
};
int main() {
    AVL avl;
    string prefix;
    avl.insert("car", 50);
    avl.insert("cat", 30);
    avl.insert("calendar", 20);
    avl.insert("apple", 40);
    int choice;
    do{
    cout<<"1. Run the program."<<endl;
    cout<<"2. Exit the program."<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Auto-completion system :" << endl;
            cout<<"Enter word : ";
            cin>>prefix;
            avl.prefixSearch(prefix);
            break;
        case 2:
            break;
        default:
            break;
        }
    }while(choice!=2);
}