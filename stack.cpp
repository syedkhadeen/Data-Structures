#include<iostream>
#include<string>
using namespace std;
template<typename T>
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
        if (top==size-1){
            cout<<"Stack Overflow";
            return;
        }
        else{
            top++;
            arr[top]=x; //arr[top++]=x;
        }
    }
    T pop(){
        if (top==-1){
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
        if(top==-1) return 1;
        else return 0;
    }
    int isFull(){
        if(top==size-1) return 1;
        else return 0;
    }
    void Display(){
        int i;
        for(i=top;i>=0;i--){
            cout<<" "<<arr[i];
        }
    }
    void navigateTo(const T& url){
        push(url);
        cout << "Navigated to: " << url << endl;
    }
    void goBack(Stack<T>& forwardStack){
        if (Empty()){
            cout<<"Error: No more pages to go back to." << endl;
            return;
        }
        forwardStack.push(stackTop());
        pop();
        cout << "Navigated back to: " << stackTop() << endl;
    }
    void goForward(Stack<T>& backStack) {
        if (backStack.Empty()) {
            cout << "Error: No more pages to go forward to." << endl;
            return;
        }
        push(backStack.pop());
        cout << "Navigated forward to: " << stackTop() << endl;
    }
};

int main() {
    Stack<string> backstack(10);
    Stack<string> forwardstack(10);
    backstack.navigateTo("https://www.khadeen.com/page1");
    backstack.navigateTo("https://www.khadeen.com/page2");
    backstack.goBack(forwardstack);
    backstack.goForward(forwardstack);
    backstack.goForward(forwardstack);
    backstack.goBack(forwardstack);
    backstack.goBack(forwardstack);
    return 0;
}

// #include<iostream>
// #include<string>
// using namespace std;
// template <typename T>
// class Stack{
//     private:
//         T *arr;
//         int size;
//         int top;
//     public:
//         Stack(int s){
//             size=s;
//             arr=new T[size];
//             top=-1;
//         }
//         void push(T x){
//             if(top==size-1){
//                 cout<<"Stack Overflow";
//                 return;
//             }
//             else{
//                 top++;
//                 arr[top]=x; //arr[top++]=x;
//             }
//         } 
//         T pop(){
//             if(top==-1){
//                 cout<<"Underflow";
//                 return T();
//             }
//             return arr[top--];
//         }
//         T stackTop(){
//             if(Empty()){
//                 cout<<"Stack is empty";
//                 return T();
//             }
//             return arr[top];
//         }
//         T peek(T pos){
//             int x=-1;
//             if(top-pos+1<0){ 
//             cout<<"invalid pos";
//              return T();
//             }
//             else{
//                 x=arr[top-pos+1];
//                 return x;
//             }
//         }

//         int Empty(){
//             if(top==-1)return 1;
//             else return 0;
//         }
//         int isFull(){
//             if(top==size-1)return 1;
//             else return 0;
//         }
//         void Display(struct Stack st){
//             int i;
//             for(i=top;i>=0;i--){
//                 cout<<" "<<arr[i];
//             }
//         }
//         int isBalaned(string &exp) {
//             for (int i = 0; i < exp.length(); i++) {
//                 if (exp[i] == '(') {
//                     push(exp[i]);
//                 }
//                 else if (exp[i] == ')') {
//                     if (Empty()) return 0;
//                     pop();
//                 }
//             }
//             return Empty() ? 1 : 0;
//         }
//         int pre(char x){
//             if(x=='+' || x=='-')
//             return 1;
//             else if(x=='*' || x=='/')
//             return 2;
//             return 0;
//         }
//         int isOperand(char x){
//             if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^')
//             return 0;
//             else
//             return 1;
//         }

//         char * InToPost(char *infix){
//         int i=0,j=0;
//         char *postfix;
//         int len=strlen(infix);
//         postfix=(char *)malloc((len+2)*sizeof(char));

//         while(infix[i]!='\0')
//         {
//         if(isOperand(infix[i]))
//         postfix[j++]=infix[i++];
//         else
//         {
//         if(pre(infix[i])>pre(top->data))
//         push(infix[i++]);
//         else
//         {
//         postfix[j++]=pop();
//         }
//         }
//         }
//         while(top!=NULL)
//         postfix[j++]=pop();
//         postfix[j]='\0';
//         return postfix;
//         }


//         ~Stack(){delete []arr;}
// };
// int main(){
//      //Stack<char> st(5);
// //     st.push(5);
// //     st.push(4);
// //     st.push(7);
// //     st.push(3);
// //    // st.pop();
// //    // cout<<st.peek(2);
// //     //cout<<st.stackTop();
// //     st.Display(st);
//      //string exp="((a+b)*(c-d))";
//     //  cout<<st.isBalaned(exp);
// //     char *infix="a+b*c-d/e";
// //  push('#');

// //  char *postfix=InToPost(infix);

// //  printf("%s ",postfix);


//  return 0;

// }
// #include<iostream>
// #include<string>
// using namespace std;
// class Stack{
//     private:
//         T *arr;
//         int size;
//         int top;
//     public:
//         Stack(int s){
//             size=s;
//             arr=new T[size];
//             top=-1;
//         }
//         void push(T x){
//             if(top==size-1){
//                 cout<<"Stack Overflow";
//                 return;
//             }
//             else{
//                 top++;
//                 arr[top]=x; //arr[top++]=x;
//             }
//         } 
//         T pop(){
//             if(top==-1){
//                 cout<<"Underflow";
//                 return T();
//             }
//             return arr[top--];
//         }
//         T stackTop(){
//             if(Empty()){
//                 cout<<"Stack is empty";
//                 return T();
//             }
//             return arr[top];
//         }
//         T peek(T pos){
//             int x=-1;
//             if(top-pos+1<0){ 
//             cout<<"invalid pos";
//              return T();
//             }
//             else{
//                 x=arr[top-pos+1];
//                 return x;
//             }
//         }

//         int Empty(){
//             if(top==-1)return 1;
//             else return 0;
//         }
//         int isFull(){
//             if(top==size-1)return 1;
//             else return 0;
//         }
//         void Display(struct Stack st){
//             int i;
//             for(i=top;i>=0;i--){
//                 cout<<" "<<arr[i];
//             }
//         }
//         void navigateTo(const string& url){
//             push(url);
//             while (!empty()){
//             pop();
//             }
//             cout<<"Navigated to: "<<url<<endl;
//             }
//             void goBack(){
//             if(empty()){
//             cout<<"Error: No more pages to go back to."<<endl;
//             return;
//             }
//             string currentPage=top();
//             pop();
//             push(currentPage);
//             cout<<"Navigated back to: "<<currentPage<<endl;
//             }
//             void goForward(){
//             if(empty()){
//             cout << "Error: No more pages to go forward to." << endl;
//             return;
//             }
//             string nextPage=top();
//             pop();
//             push(nextPage);
//             cout<<"Navigated forward to: "<<nextPage<<endl;
//             }
// };

// int main(){
//     Stack backstack;
//     Stack forwardstack;
//     backstack.navigateTo("https://www.khadeen.com/page1");
//     navigateTo("https://www.khadeen.com/page2");
//     goBack();
//     goForward();

//     goForward();
//     goBack();
//     goBack();
// }
