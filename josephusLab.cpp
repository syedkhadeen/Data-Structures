#include<iostream>
using namespace std;
class DoublyList{
    private:
        class Node{
            public:
                string name;
                Node*next;
                Node*prev;
            Node(string name):name(name),next(NULL),prev(NULL){}
        };
        Node*head;
        int N=0;
        public:
            DoublyList():head(NULL){}
            void insert(string n){
                Node *newNode= new Node(n);
                if(!head){
                    head=newNode;
                    head->next=head;
                    head->prev=head;
                }
                else{
                    Node *curr=head->prev;
                    curr->next=newNode;
                    newNode->prev=curr;
                    newNode->next=head;
                    head->prev=newNode;
                }
                N++;
            }
            string JosephusClockwise(int M,int s){    //clockwise
                Node *curr=head;
                Node *back=NULL;
                for(int i=1;i<s-1;i++){
                    back=curr;
                    curr=curr->next;
                }
                int count=0;
                while(curr->next!=curr){
                    count++;
                    if(count==M){
                    back->next=curr->next;
                    curr->next->prev=back;
                    delete curr;
                    curr=back->next;
                    count=0;
                    }
                    else{
                        back=curr;
                        curr=curr->next;
                    }
                }
                return curr->name;
            }
            string JosephusAnticlockwise(int M,int s){    //Anticlockwise
                Node*curr2=head;
                Node*back2=NULL;
                for(int i=1;i<s-1;i++){
                    back2=curr2;
                    curr2=curr2->prev;
                }
                int count=0;
                while(curr2->prev!=curr2){
                    count++;
                    if(count==M){
                        back2->prev=curr2->prev;
                        curr2->prev->next=back2;
                        delete curr2;
                        curr2=back2->prev;
                        count=0;
                    }
                    else{
                        back2=curr2;
                        curr2=curr2->prev;
                    }
                }
                return curr2->name;
            }
            void Display() {
                Node* temp=head;
                do{
                    cout<<temp->name<<",";
                    temp=temp->next;
                } while(temp!=head);
                cout<<endl;  
            }
            int findNode(string s){
                Node*curr=head;
                int i=1;
                while(curr){
                    if(curr->name==s) return i;
                    curr=curr->next;
                    i++;
                }
                return 0; 
            }
};
int main(){
    DoublyList l1;
    int choice,m,elimination,pos;
    string name,starting;
    do{
        cout<<"1.Add person"<<endl;
        cout<<"2.Elimination"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter the name : "<<endl;
                cin>>name;
                l1.insert(name);
                cout<<"Person "<<name<<" added to the circle"<<endl;
                cout<<endl;
                cout<<"Current persons in the circle : ";
                l1.Display();
                cout<<endl;
                break;
            case 2:
                cout<<"Enter the skips you want?"<<endl;
                cin>>m;
                cout<<"Enter the starting point : ";
                cin>>starting;
                pos=l1.findNode(starting);
                cout<<"In what direction do you want?(1.Clock-wise 2.Anticlockwise) : ";
                cin>>elimination;
                if(elimination==1)
                    cout<<"The survivor is : "<<l1.JosephusClockwise(m,pos)<<endl;
                if(elimination==2)
                    cout<<"The survivor is : "<<l1.JosephusAnticlockwise(m,pos)<<endl;
                break;
            case 3:
                break;
        }
    }while(choice!=3);  
}