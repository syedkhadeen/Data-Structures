#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int elements;
    int size;

public:
    Queue(int s) {
        arr = new int[s];
        size = s;
        elements = 0;
        rear = -1;
        front = 0;
    }

    void enqueue(int val) {
        if (elements == size) {
            cout << "Overflow";
            return;
        }
        if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
        elements++;
    }

    int dequeue() {
        if (front == rear) {
            cout << "Underflow";
            return -1;
        }
        int val = arr[front];
        if (front == size - 1) {    //if front is at the last send it to 0
            front = 0;
        } else {
            front++;
        }
        elements--;
        return val;
    }

    void Display() {
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }

    void reverseEven() {
        int i = front;
        int j = rear;
        int temp;
        while (i <= j) {
            if ((i + 1) % 2 == 0) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            i++;
            j--;
        }
    }
    void reverseOdd(){
        int i=front;
        int j=rear;
        int temp;
        while(i<j){
            if(arr[i]%2!=0 && arr[j]%2!=0){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else{
                i++;
                j--;
            }
        }
    //      if (i == j) {
    //     front = i;
    //     rear = j;
    // }
    }
};
class Queue2{
    private:
        int *arr;
        int *front;
        int *rear;
        int size;
    public:
        Queue(int s) : size(s) {
            arr = new int[size];
            front = nullptr;
            rear = nullptr;
        }
        ~Queue() {
            delete[] arr;
        }
        bool isEmpty() {
            return (front == nullptr && rear == nullptr);
        }
        bool isFull() {
            // Check if next position of rear is the front (circular condition)
            return (front == arr && rear == arr + size - 1) ||
                (rear == front - 1);
        }
        void enqueue(int val) {
            if (isFull()) {
                cout << "Queue is full. Cannot enqueue." << endl;
                return;
            }
            if (isEmpty()) {
                front = arr;
                rear = arr;
            }
            else{
                if (rear == arr + size - 1) {
                    rear = arr; // Wrap around to the beginning
                } else {
                    rear++;
                }
            }
            *rear = val;
            cout << "Enqueued " << val << endl;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return -1; // Assuming -1 is not a valid queue element
            }

            int dequeuedValue = *front;

            if (front == rear) {
                front = nullptr;
                rear = nullptr;
            } else {
                if (front == arr + size - 1) {
                    front = arr; // Wrap around to the beginning
                } else {
                    front++;
                }
            }

            cout << "Dequeued " << dequeuedValue << endl;
            return dequeuedValue;
        }
};
int main() {
    Queue q(11);
    q.enqueue(14);
    q.enqueue(13);
    q.enqueue(17);
    q.enqueue(8);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(4);
    q.enqueue(15);
    q.enqueue(18);
    q.enqueue(19);
    
    cout << "Original Queue: ";
    q.Display();

    q.reverseEven();
    cout << "Queue after reversing even-indexed elements: ";
    q.Display();

    q.reverseOdd();
    cout << "Queue after reversing odd-valued elements: ";
    q.Display();

    return 0;
}
//    createQueue(&q,5);
//     enqueue(&q, 1);
//     enqueue(&q, 2);
//     enqueue(&q, 3);

//     cout << "Queue elements: ";
//     Display(q);

//     // Example: Dequeue and Display
//     int removedElement = dequeue(&q);
//     cout << "Removed element: " << removedElement << endl;

//     cout << "Queue elements after dequeue: ";
//     Display(q);

//     return 0;
// class circularQueue{
//     private:
//         int size;
//         int front;
//         int rear;
//         int *Q;
//     public:
//         circularQueue(){front=rear=0;size=10; Q = new int[size];}
//         circularQueue(int size){front=rear=0;this->size=size; Q = new int[this->size];}
//         void enqueue(int x){
//             if((rear+1)%size==front){
//                 cout<<"Queue Full";
//             }
//             else{
//                 rear=(rear+1)%size;
//                 Q[rear]=x;
//             }
//         }
//         int dequeue(){
//             int x=-1;
//             if(front==rear){
//                 cout<<"Queue empty";
//             }
//             else{
//                 front=(front+1)%size;
//                 x=Q[front];
//             }
//             return x;
//         }
//         void Display(){
//             int i=front+1;
//             do{
//                 cout<<Q[i]<<" ";
//                 i=(i+1)%size;
//             }while(i!=(rear+1)%size);
//         }
// };
// void createQueue(Queue *q,int size){
//     q->size=size;
//     q->front=q->rear=-1;
//     q->Q=new int[q->size];
// }
// void enqueue(Queue *q,int x){
//     if(q->rear==q->size-1){
//         cout<<"Queue is full";
//     }
//     else{
//         q->rear++;
//         q->Q[q->rear]=x;
//     }
// }
// int dequeue(Queue *q){
//     int x=-1;
//     if(q->front==q->rear){
//         cout<<"Queue is empty";
//     }
//     else{
//         q->front++;
//         x=q->Q[q->front];
//     }
//     return x;
// }
// void Display(Queue q){
//     for(int i=q.front+1;i<=q.rear;i++){
//         cout<<q.Q[i]<<" " ;
//     }
// } 
// class Queue2{
//     private:
//         int size;
//         int front;
//         int rear;
//         int *Q;
//     public:
//         Queue(){front=rear=-1;size=10; Q = new int[size];}
//         Queue(int size){front=rear=-1;this->size=size; Q = new int[this->size];}
//         void enqueue(int x){
//             if(rear==size-1){
//                 cout<<"Queue Full";
//             }
//             else{
//                 rear++;
//                 Q[rear]=x;
//             }
//         }
//         int dequeue(){
//             int x=-1;
//             if(front==rear){
//                 cout<<"Queue empty";
//             }
//             else{
//                 x=Q[front++];
//                 front++;
//             }
//             return x;
//         }
//         void Display(){
//             for(int i=front+1;i<=rear;i++){
//                 cout<<Q[i]<<" ";
//             }
//         }
// };