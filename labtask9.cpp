#include<iostream>
using namespace std;
class BST{
    private:
        class Node{
            Node*left;
            int ID;
            string name;
            string department;
            Node*right;
            Node():ID(0),left(NULL),right(NULL){}
            Node(int ID,string name,string department):ID(ID),name(name),department(department),(NULL),right(NULL){}
            friend  class BST;
        };
        Node*root;
    public:
        BST():root(NULL){}
        Node* insert(Node*p,int ID){
            Node*t=NULL;
            if(p==NULL){
                t=new Node;
                t->ID=ID;
                t->name=name;
                t->department=department;
                t->left=t->right=NULL;
                return t;
            }
            if(ID<p->ID) p->left=insert(p->left,ID,name,department);
            else if(ID>p->ID) p->right=insert(p->right,ID,name,department);
            return p;
        }
         Node *search(Node *p,int ID){
            if(p==NULL) return NULL;
            if(ID==p->ID) return p;
            else if(ID<p->ID) return search(p->left,ID);
            else if(ID>p->ID)return search(p->right,ID);
            return NULL;
        }
        int depth(Node* p){
            if(p==NULL)
                return 0;
            int leftDepth=depth(p->left);
            int rightDepth=depth(p->right);
            return 1+max(leftDepth,rightDepth);
        }
        Node *parent(Node *curr, Node *p, Node *par){
            if(curr==NULL) return NULL;
            if(curr==p) return par;
            else{
                Node *t=NULL;
                t=parent(curr->left,p,curr);
                if(t!=NULL) return t;
                else{
                    t=parent(curr->right,p,curr);
                    return t;
                }
            }
        }
        Node *sibling(Node *root, Node *p){
            Node *par=parent(root,p,NULL);
            if(par->left==p) return par->right;
            else return par->left;
        }
        void Inorder(Node *p){
            if(p){
                Inorder(p->left);
                cout<<"ID: "<<p->ID<< ", Name: "<<p->name<<", Department: "<<p->department<<endl;
                Inorder(p->right);
            }
        }
        void PreOrder(Node*p){
            if(p){
                cout<<p->ID<<" ";
                PreOrder(p->left);
                PreOrder(p->right);
            }
        }
        void Postorder(Node*p){
            if(p){
                Postorder(p->left);
                Postorder(p->right);
                cout<<p->ID<<" ";
            }
        }
        int count(Node *p){
            if(p==NULL) return 0;
            return count(p->left)+count(p->right)+1;
        }
        int minimum(Node *p){
            if(p->left==NULL) return p->ID;
            return minimum(p->left);
        }
        friend int main();
};
int main(){
    BST bst;
    int choice, ID;
    string name, department;
    do{
        cout<<"\n1. Insert Employee. "<<endl;
        cout<<"2. Search Employee. "<<endl;
        cout<<"3. Find Employees with same level of authority. "<<endl;
        cout<<"4. Total Depth of the Employee Hierarchy."<<endl;
        cout<<"5. Find Subordinates of an Employee."<<endl;
        cout<<"6. View All Employees. "<<endl;
        cout<<"0. Exit. "<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:
                cout << "Exiting program." << endl;
                break;
            case 1:
                cout << "Enter Employee ID: ";
                cin >> ID;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Department: ";
                cin >> department;
                bst.insert(bst.root,ID,name,department);
                break;
            case 2:
                cout << "Enter Employee ID to search: ";
                cin >> ID;
                BST::Node* result = bst.search(bst.root,ID);
                if (result)
                    cout<< "Employee found: " << result->name << ", " << result->department << endl;
                else
                    cout<< "Employee not found." << endl;
                break;
            case 3:
                cout<< "Enter Employee ID to find same level of authority : ";
                cin>> ID;
                BST::Node* s=bst.search(bst.root,ID);
                if(!s) return 0;
                BST::Node *p=bst.parent(s)
                break;
            case 4:
                cout<< "Total Depth of the Hierarchy: " << bst.depth(bst.root) << endl;
                break;
             case 5:
                cout << "Enter Employee ID to find subordinates: ";
                cin >> ID;
                bst.findSubordinates(bst.root, ID);
                break;
            case 6:
                cout << "All Employees:" << endl;
                bst.viewAllEmployees(bst.root);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
How can you identify a pair within a BST that adds up to specified sum? For example in this BST if the sum is 18 the pair would be (10,8)