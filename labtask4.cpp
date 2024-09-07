#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class Student{
    private:
        int id;
        string name;
        float gpa;
    public:
        Student(int id,string name,float gpa):id(id),name(name),gpa(gpa){}
        void display()
        {
            cout<<"ID : "<<id<<"\nName : "<<name<<"\nGPA : "<<fixed<<setprecision(2)<<gpa<<endl;
        }
        int getId(){
            return id;
        }
        string getName(){return name;}
        float getGPA(){return gpa;}
};
class Node{
    public:
        Student data;
        Node*next;
        Node(const Student &student):data(student),next(NULL){}
};
class ListStudent{
    private:
        Node*head;
    public:
        ListStudent():head(NULL){}
        void add(const Student&student){
            Node*newNode=new Node(student);
            newNode->next=head;
            head=newNode;
        }
        void remove(int Id){
            Node*curr=head;
            Node*prev=NULL;
            while(curr!=NULL && curr->data.getId()!=Id){
                prev=curr;
                curr=curr->next;
            }
        if(curr!=NULL){
            if(prev!=NULL){
                prev->next=curr->next;
            }
            else{
                head=curr->next;
            }
            delete curr;
        }
        else{
            cout<<"Student not found"<<endl;
        } 
        }
    void display(){
        Node*curr=head;
        while(curr){
            curr->data.display();
            curr=curr->next;
        }
    }
    void search(int Id){
        Node*curr=head;
        while(curr){
            if(curr->data.getId()==Id){
                curr->data.display();
                return;
            }
            curr=curr->next;
        }
        cout<<"Student not found!"<<endl;
    }
    float calcAvgGpa(){
        if(head==NULL){
            return 0.0;
        }
        float total=0.0;
        int count=0;
        Node*curr=head;
        while(curr!=NULL){
            total+=curr->data.getGPA();
            count++;
            curr=curr->next;
        }
        return total/count;
    }
    ~ListStudent(){
        Node*curr=head;
        while(curr){
            Node*next=curr->next;
            delete curr;
            curr=next;
        }
    }
};
int main(){
    ListStudent stdlist;
    char c;
    do{
        cout<< "\n1. Add Student\n2. Remove Student\n3. Display All Students\n4. Search Student\n5. Calculate Average GPA\n6. Quit\n";
        cout<< "Enter your choice: ";
        cin>>c;

        switch (c) {
            case '1': {
                int id;
                string name;
                float gpa;

                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin.ignore(); // Clear the newline character from the buffer
                getline(cin, name);
                cout << "Enter student GPA: ";
                cin >> gpa;

                stdlist.add(Student(id, name, gpa));
                break;
            }
            case '2': {
                int id;
                cout << "Enter student ID to remove: ";
                cin >> id;
                stdlist.remove(id);
                break;
            }
            case '3':
                stdlist.display();
                break;
            case '4': {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                stdlist.search(id);
                break;
            }
            case '5':
                cout << "Average GPA: " << fixed << setprecision(2) << stdlist.calcAvgGpa() << endl;
                break;
            case '6':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (c != '6');
}
