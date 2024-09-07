#include<iostream>
#include<string>
using namespace std;
class Node{
public:
    char data;
    Node* next;
    Node(char val):data(val),next(nullptr){}
};
class LinkedList{
public:
    Node* head;
    int count;
    LinkedList():head(nullptr),count(1){}
    void insertAtEnd(char value){
        Node* newNode=new Node(value);
        if(!head){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void display(){
        Node* current=head;
        while(current){
            cout<<current->data;
            current=current->next;
        }
        cout<<endl;
    }

    bool isVowel(char ch){
        return(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    void processWord(const string& word){
        for(char ch:word){
            if(isVowel(ch)){
                insertAtEnd(ch);
                for(int i=0;i<count;++i){
                    insertAtEnd('Y');
                }
            } 
            else if(isalpha(ch)){
                insertAtEnd(ch);
                insertAtEnd('X');
                insertAtEnd(count+'0');
            } 
            else if(isdigit(ch)){
                int squaredDigit=(ch-'0')*(ch-'0');
                string reversedDigits;
                while(squaredDigit>0){
                    reversedDigits+='0'+(squaredDigit%10);
                    squaredDigit/=10;
                }
                for (int i=reversedDigits.size()-1;i>=0;--i) {
                    insertAtEnd(reversedDigits[i]);
                }
            }
            ++count;
        }
    }
};
int main(){
    LinkedList l1;
    string word;
    cout<<"Enter the string : ";
    cin>>word;
    cout<<"Encrypted string would be : ";
    l1.processWord(word);
    l1.display();
}
