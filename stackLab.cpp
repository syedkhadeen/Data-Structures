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
        void Display(struct Stack st){
            int i;
            for(i=top;i>=0;i--){
                cout<<" "<<arr[i];
            }
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
        string infixToPostfix(string infix){
            Stack<char> st(size);
            string postfix;
            for(char& c:infix){
                if(isalnum(c)){
                    postfix+=c;
                }else if(c=='('){
                    st.push(c);
                }else if(c==')'){
                    while(!st.Empty() && st.stackTop()!='('){
                        postfix+=st.stackTop();
                        st.pop();
                    }
                    st.pop(); 
                }else{
                    while(!st.Empty() && pre(c)<=pre(st.stackTop())){
                        postfix+=st.stackTop();
                        st.pop();
                    }
                    st.push(c);
                }
            }
            while(!st.Empty()){
                postfix+=st.stackTop();
                st.pop();
            }
            return postfix;
        }
          int pre(char x){
            if(x=='^') return 3;
            else if(x=='*'||x=='/') return 2;
            else if(x=='+'|| x=='-') return 1;
            return 0;
        }
};
int main(){
    Stack <char>st(10);
    string s,postfix;
    int choice;
    do{
    cout<<"Choose 1 or 2 (0 to end the program): "<<endl;
    cout<<"1. To check valid parentheses."<<endl;
    cout<<"2. Find the result of Postix expression."<<endl;
    cin>>choice;
    cin.ignore();
    switch(choice){
        case 1:
            cout<<"Enter the bracket : ";
            cin>>s;
            if(st.isBalaned(s)){
                cout<<"Valid"<<endl<<endl;
            }
            else
                cout<<"Invalid"<<endl<<endl;
            break;
        case 2:
            cout<<"Enter postfix  expression : ";
            getline(cin,postfix);
            cout<<"The output of Postfix Expression "<<postfix<<" is : "<<st.convert(postfix);
            cout<<endl<<endl;
            break;
        default:
            break;
        }
    }while(choice!=0);
}