#include<iostream>
using namespace std;
class Node{
    public:
        Node*lchild;
        int data;
        Node*rchild;
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
                t->lchild=t->rchild=NULL;
                return t;
            }
            if(key<p->data){
                p->lchild=Rinsert(p->lchild,key);
            }
            else if(key>p->data){
                p->rchild=Rinsert(p->rchild,key);
            }
            return p;
        }
        void Insert(int key){
            Node*t=root;
            Node*r,*p;
            if(root==NULL){
                p=new Node;
                p->data=key;
                p->lchild=p->rchild=NULL;
                root=p;
                return;
            }
            while(t!=NULL){
                r=t;
                if(key<t->data){
                    t=t->lchild;
                }
                else if(key>t->data){
                    t=t->rchild;
                }
                else return;
            }
            p=new Node;
            p->data=key;
            p->lchild=p->rchild=NULL;
            if(key<r->data){
                r->lchild=p;
            }
            else{
                r->rchild=p;
            }
        }
        void Inorder(Node*p){
            if(p){
                Inorder(p->lchild);
                cout<<p->data<<" ";
                Inorder(p->rchild);
            }
        }
        Node* search(int key){
            Node*t=root;
            while(t){
                if(key==t->data) return t;
                else if(key<t->data){
                    t=t->lchild;
                }
                else{
                    t=t->rchild;
                }
            }
            return NULL;
        }
//         class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node(int val) : val(val), left(nullptr), right(nullptr) {}
// };

// void inorder(Node* root, std::vector<int>& vec) {
//     if (!root) return;
//     inorder(root->left, vec);
//     vec.push_back(root->val);
//     inorder(root->right, vec);
// }

// bool findPair(Node* root, int sum) {
//     std::vector<int> vec;
//     inorder(root, vec);

//     std::unordered_set<int> set;
//     for (int i = 0; i < vec.size(); i++) {
//         int complement = sum - vec[i];
//         if (set.find(complement)!= set.end()) {
//             return true;
//         }
//         set.insert(vec[i]);
//     }

//     return false;
// }
        // void pairSum(Node *p,int sum){
        //     if(p==NULL) return;
        //     int val=p->data;
        //     if(val+p->left==sum) cout<<val<<" "<<p->left;
        //     else pair(p->left,sum);
        //     if(val+p->right==sum)cout<<val<<" "<<p->right;
        //     else pair(p->right,sum);
        // }
        

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
        int Height(Node*p){
            int x,y;
            if(p==NULL) return 0;
            x=Height(p->lchild);
            y=Height(p->rchild);
            return x>y?x+1:y+1;
        }
        Node*InPre(Node*p){
            while(p && p->rchild!=NULL){
                p=p->rchild;
            }
            return p;
        }
        Node*InSucc(Node*p){
            while(p && p->lchild!=NULL){
                p=p->lchild;
            }
            return p;
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
};
int main(){
    BST obj;
    obj.root=obj.Rinsert(10);
    obj.Rinsert(5);
    obj.Rinsert(20);
    obj.Rinsert(8);
    obj.Rinsert(30);
    obj.Delete(20);
    obj.Inorder();
    Node*temp=obj.search(5);
    cout<<endl;
    if(temp!=NULL){
        cout<<"Element "<<temp->data<<" found.";
    }
    else{
        cout<<"Not found!";
    }
}