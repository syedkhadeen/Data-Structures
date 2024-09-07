#include<iostream>
#include<time.h>
//#include<clib>
using namespace std;
class Word{
    private:
        class Node{
            public:
                char data;
                Node*next;
                Node(char data):data(data),next(NULL){}
        };
        Node*head;
        int length;
    public:
        Word():head(NULL),length(0){}
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
            length++;
        }
        void processWord(string word){
            for(char ch:word){
                    insertAtEnd(ch);
            }
        }
        void displayHalf(Node*head,string word){
            Node*temp=head;
            int l=length/2;
            int skip=rand()%skip+1;
            int count=0;
            while(temp){
                if(count==skip){
                    cout<<"__";
                    temp=temp->next;
                    count=0;
                }
                else{
                    cout<<temp->data;
                    temp=temp->next;
                }
            }
            while(count<l){
                char c;
                int pos;
                cout<<"Enter the word : ";
                cin>>c;
                cout<<"Enter the Position : ";
                cin>>pos;
                for(int i=pos;i<length;i++){
                    if(word[i+1]==c){
                        cout<<"Correct";
                    }
                }

            }
        }

};
int main(){
    Word w;
    string str="Apple";
    //w.insert(str);
    char arr[5][10]={"Apple","Banana","Carrot","Dog","Elephant"};
    srand(time(NULL));
    int value=rand()%5+1;
    for(int i=0;i<5;i++){
        w.processWord(arr[value][i]);
    }


}


