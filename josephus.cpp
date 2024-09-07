#include<iostream>
using namespace std;
class LinkedList{
    private:
    class Node{
        public:
            int data;
            Node* next;
            Node(int data):data(data),next(NULL){}
    };
    Node*head;
    public:
        LinkedList():head(NULL){}
        int josephus(int N,int M){
            for(int i=1;i<=N;i++){  //Loop for creating circular linked list
                Node*newNode= new Node(i);
                if(!head){
                    head=newNode;
                    head->next=head;
                }
                else{
                    Node*curr=head;
                    while(curr->next!=head){
                        curr=curr->next;
                    }
                    curr->next=newNode;
                    newNode->next=head;
                }
            }   
            Node*curr=head;
            Node*prev=NULL;
            int count=0;
            while(curr->next!=curr){    //Loop for leader
                count++;
                if(count==M){
                    prev->next=curr->next;
                    delete curr;
                    curr=prev->next;
                    count=0;
                }
                else{
                    prev=curr;
                    curr=curr->next;
                }
            }   
            return curr->data;
        }
};
int main(){
    LinkedList l1;
    int N,M;
    cout<<"Enter the  number of people in circle : ";
    cin>>N;
    cout<<"Enter the skips you want? : ";
    cin>>M;
    cout<<"Leader is : "<<l1.josephus(N,M);
}