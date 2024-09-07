#include <iostream>
#include <string>
using namespace std;
class Node{
public:
    string rollnumber;
    string name;
    string fatherName;
    string department;
    string degree;
    Node* next;
    Node(string rollnumber,string name,string fatherName,string department,string degree):
    rollnumber(rollnumber),name(name),fatherName(fatherName),department(department),degree(degree),next(NULL){}
};
class HashTable{
public:
    static const int size=100;
    Node* arr[size];
    HashTable(){
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }
    int extractYear(string rollnumber){
        int year=0;
        int multiplier=1;
        for (int i=rollnumber.length()-1;i>=0;i--){
            if (isdigit(rollnumber[i])){
                year+=(rollnumber[i]-'0')*multiplier;
                multiplier*=10;
            } 
            else break;
        }
        return year;
    }
    int hashFunction(string rollnumber){
        int year=extractYear(rollnumber);
        return year % size;
    }
    void insert(string rollnumber,string name,string fatherName,string department,string degree){
        int index = hashFunction(rollnumber);
        if(arr[index]==NULL) arr[index]=new Node(rollnumber,name,fatherName,department,degree);
        else{
            Node* newNode=new Node(rollnumber,name,fatherName,department,degree);
            Node* current=arr[index];
            while(current->next!=NULL) current=current->next;
            current->next=newNode;
        }
    }
    Node* retrieve(string rollnumber){
        int index=hashFunction(rollnumber);
        if(arr[index]!=NULL){
            Node* current=arr[index];
            while(current!=NULL){
                if(current->rollnumber==rollnumber) return current;
                current = current->next;
            }
        }
        return NULL;
    }
    void print(Node* p){
        cout<<"Roll Number: "<<p->rollnumber<<endl;
        cout<<"Name: " << p->name<<endl;
        cout<<"Father's Name: "<<p->fatherName<<endl;
        cout<<"Department: "<<p->department<<endl;
        cout<<"Degree: "<<p->degree<<endl;
    }
};
int main(){
    HashTable HT;
    HT.insert("22P-9150", "Khadeen", "Azmat", "Software Engineering", "BSc");
    HT.insert("23P-1567", "Ali", "Shah", "Physics", "BSc");
    HT.insert("21P-9166", "Shahid", "Ali", "AI", "MSc");
    HT.insert("19P-9199", "Sameer", "Ahmad", "Biology", "BSc");
    HT.insert("23P-2934", "Rayyan", "Ali", "Data Science", "BSc");
    HT.insert("18P-5589", "Rehan", "Nawaz", "Computer Science", "Phd");
    HT.insert("20P-5993", "Bilal", "Khan", "Medicine", "MBBS");
    char choice;
    do{
        cout<<"Do you want to search for student records ?(y/n): ";
        cin>>choice;
        if(choice=='Y'||choice=='y'){
            string rollnumber;
            cout<<"Enter the roll number of the student: ";
            cin>>rollnumber;
            Node* p=HT.retrieve(rollnumber);
            if(p!=NULL){
                HT.print(p);
                cout<<endl;
            } 
            else cout<<"Student record not found."<<endl;
        }
    }while(choice=='Y'||choice=='y');
}