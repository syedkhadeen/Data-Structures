#include<iostream>
#include<string>
#include<cmath>
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
        int isBalaned(string &exp) {
            for (int i=0;i<exp.length();i++){
                if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
                    push(exp[i]);
                }
                else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                    if(Empty()) return 0;
                    char c=pop();
                    if((exp[i]==')' && c!= '(') || (exp[i]=='}' && c!= '{') || (exp[i]==']' && c!= '[')) return 0;
                }
            }
            return Empty()?1:0;
        }
};
int main(){
    Stack <char>st(10);
    char choice;
    string s;
    do{
        cout<<"Enter the parentheses : ";
        cin>>s;
        if(st.isBalaned(s)) cout<<"The parentheses "<<s<<" is balanced/Valid."<<endl;
        else cout<<"The parentheses "<<s<<" is not balanced/Valid."<<endl;
        cout<<"\nDo you want to continue?(y/n): ";
        cin>>choice;
    }while(choice!='n' && choice!='N');
}