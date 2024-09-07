#include <iostream>
using namespace std;

class CircularList {
private:
    class Node {
    public:
        int data;
        Node *next;
        Node(int data):data(data),next(NULL){}
    };
    Node *head;
    int length=0;

public:
    CircularList() : head(nullptr),length(0) {}

    void Display() {
        Node *h = head;
        do {
            cout << " " << h->data;
            h = h->next;
        } while (h != head);
        cout << endl;
    }

    int Length() {
        Node *p = head;
        int len = 0;
        do {
            len++;
            p = p->next;
        } while (p != head);
        return len;
    }

    void RDisplay(Node *p){
        static int flag=0;
        if(p!=head || flag==0){
            flag=1;
            cout<<p->data<<" ";
            RDisplay(p->next);
        }
        flag=0;
    }

void insertFirst(int value) {
        Node *newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void insertEnd(int value) {
        Node *newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node *temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        length++;
    }

    void Insert(int value,int position) {
        if (position > length) {
            std::cout << "Invalid position" << std::endl;
            return;
        }

        if (position == 0) {
            insertFirst(value);
        } else if (position == length) {
            insertEnd(value);
        } else {
            Node *newNode = new Node(value);
            Node *temp = head;
            for (int i = 0; i < position - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }


    int Delete(int index) {
        Node *p = head, *q;
        int i, x;
        if (index < 0 || index >= Length()) {
            return -1;
        }
        if (index == 0) {
            while (p->next != head)
                p = p->next;
            x = head->data;
            if (head == p) {
                delete head;
                head = nullptr;
            } else {
                p->next = head->next;
                delete head;
                head = p->next;
            }
        } else {
            for (i = 0; i < index - 1; i++) {
                p = p->next;
            }
            q = p->next;
            p->next = q->next;
            x = q->data;
            delete q;
        }
        return x;
    }
    friend int main();
};

int main() {
    CircularList c;
    c.Insert(1, 0);
    c.Insert(2, 1);
    c.Insert(3, 2);
    c.Insert(4, 3);
    c.Display();
    c.RDisplay(c.head);
    return 0;
}
