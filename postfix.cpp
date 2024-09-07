#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
template <typename T>
class Stack{
    private:
        T *arr;
        int size;
        int top;
    public:
        Stack(int s){
            size=s;
            arr=new T[size];
            top=-1;
        }
        void push(T x){
            if(top==size-1){
                cout<<"Stack Overflow";
                return;
            }
            else{
                top++;
                arr[top]=x; //arr[top++]=x;
            }
        } 
        T pop(){
            if(top==-1){
                cout<<"Underflow";
                return T();
            }
            return arr[top--];
        }
        T stackTop(){
            if(Empty()){
                cout<<"Stack is empty";
                return T();
            }
            return arr[top];
        }
        T peek(T pos){
            int x=-1;
            if(top-pos+1<0){ 
            cout<<"invalid pos";
             return T();
            }
            else{
                x=arr[top-pos+1];
                return x;
            }
        }
        int Empty(){
            if(top==-1)return 1;
            else return 0;
        }
        int isFull(){
            if(top==size-1)return 1;
            else return 0;
        }
        int isOperand(char x){
            if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
            return 0;
            else
            return 1;
        }
        int convert(string &postfix){
            int res=0,val1,val2;
            for(int i=0;i<postfix.length();i++){
                if(isOperand(postfix[i])){
                    push(postfix[i]-'0');
                }
                else{
                    val1=pop();
                    val2=pop();
                    switch(postfix[i]){
                        case '+':
                            push(val2+val1);
                            break;
                        case '-':
                            push(val2-val1);
                            break;
                        case '*':
                            push(val2*val1);
                            break;
                        case '/':
                            push(val2/val1);
                            break;
                        case '^':
                            push(pow(val2, val1));
                            break;
                    }
                }
            }
                return stackTop();
        }
};
int main(){
    Stack<char> st1(10);
    char choice;
    do{
    string postfix;
    cout<<"Enter the postfix expression : ";
    getline(cin,postfix);
    cout<<"Result of this Expression is : "<<st1.convert(postfix)<<endl;
    cout<<"Do you want to continue?(y/n) ";
    cin>>choice;
    }while(choice!='n' && choice!='N');
}