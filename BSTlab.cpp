#include<iostream>
using namespace std;
class Node{
    private:
        int data;
        Node* left;
        Node* right;
    public:
        Node():data(0),left(NULL),right(NULL){}
        Node(int data):data(data),left(NULL),right(NULL){}
};
class BST{
    private:
        Node*root;
    public:
        BST():root(NULL){}
        void insert(Node *p,int data){
            if(p==NULL){
                Node*temp=new Node(val);
                if(root==NULL) root=temp;
                return temp;
            }
            if(p->val==val) cout<<"EXISTS";
            else if(val>p->val) insert(p->right,val);
            else insert(p->left,val);
        }
};
int main(){
    
}