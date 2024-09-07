// #include<iostream>
// using namespace std;
// class Queue{
//     private:
//         class Node{
//             public:
//                 int data;
//                 double price;
//                 Node*next;
//         };
//     Node *front,*rear;
//     public:
//         Queue():front(NULL),rear(NULL){}
//         void enqueue(int x,int p){
//             Node*t=new Node;
//             if(t==NULL){
//                 cout<<"Queue  is full!";
//                 return;
//             }
//             else{
//                 t->price=p;
//                 t->data=x;
//                 t->next=NULL;
//                 if(front==NULL){
//                     front=rear=t;
//                 }
//                 else{
//                     rear->next=t;
//                     rear=t;
//                 }
//             }
//         }
//         int dequeue(){
//             int x;
//             Node*temp;
//             if(front==NULL){
//                 cout<<"Queue is Empty";
//                 return -1;
//             }
//             else{
//                 temp=front;
//                 x=front->data;
//                 front=front->next;
//                 delete temp;
//             }
//             return x;
//         }
//         void display(){
//             Node *p=front;
//             while(p){
//                 if(p->data==1) cout<<" Burger "<<p->price;
//                 else if(p->data==2) cout<<" Pizza "<<p->price;
//                 else if(p->data==3) cout<<" Cold Drink "<<p->price;
//                 else if(p->data==4) cout<<" Biryani "<<p->price;
//                 else if(p->data==5) cout<<" Pasta "<<p->price;
//                 p=p->next;
//             }
//             cout<<endl;
//         }
// };
// void displayOrder(){
//     cout<<"Enter 0 for end."<<endl;
//     cout<<"1. Burger(Rs. 300)."<<endl;
//     cout<<"2. Pizza(Rs. 1000)."<<endl;
//     cout<<"3. Cold Drink(Rs. 100)."<<endl;
//     cout<<"4. Biryani(Rs. 200)."<<endl;
//     cout<<"5. Pasta(Rs. 500)."<<endl;
// }
// int main(){
//     Queue q;
//     int choice, order,price;
//     do{
//         cout<<"Select the following:" << endl;
//         cout<<"1. Add Order." << endl;
//         cout<<"2. Remove processed orders." << endl;
//         cout<<"3. Display current orders in the queue." << endl;
//         cin>>choice;
//         switch(choice){
//             case 1:
//                 do{
//                     displayOrder();
//                     cin>>order;
//                     if(order == 0) break;
//                     else if(order==1) price=300; else if(order==2) price = 1000;
//                      else if(order==3) price=100; else if(order==4) price =200; else if(order==5) price=500;
//                     if(order!=0)
//                         q.enqueue(order,price);
//                 }while(order!=0);
//                 break;
//             case 2:
//                 cout<<"Processing orders..."<<endl;
//                 q.dequeue();
//                 q.display();
//                 break;
//             case 3:
//                 cout<<"Current orders in the queue: ";
//                 q.display();
//                 break;
//             default:
//                 cout<<"Exiting!"<<endl;
//         }
//     }while(choice!=0);
// }
#include <iostream>
using namespace std;
class Queue{
private:
    class Node{
    public:
        int data;
        Node *next;
    };
    Node *front, *rear;
    public:
        Queue() : front(NULL), rear(NULL) {}
        void enqueue(int x){
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "Queue is full!";
            return;
        }
        else
        {
            t->data = x;
            t->next = NULL;
            if (front == NULL)
            {
                front = rear = t;
            }
            else
            {
                rear->next = t;
                rear = t;
            }
        }
    }
    int dequeue()
    {
        int x;
        Node *temp;
        if (front == NULL)
        {
            cout << "Queue is Empty";
            return -1;
        }
        else
        {
            temp = front;
            x = front->data;
            front = front->next;
            delete temp;
        }
        return x;
    }
    void duplicate(Queue &second)
    {
        Node *temp = front;
        while (temp)
        {
            for (int i = 0; i < temp->data; i++)
            {
                second.enqueue(temp->data);
            }
            temp = temp->next;
        }
    }

    void Display()
    {
        Node *p = front;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
};
int main()
{
    Queue q, q2;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.duplicate(q2);
    cout << "Input Queue : " << endl;
    q.Display();
    cout << "Output Queue : " << endl;
    q2.Display();
}