#include<iostream>
using namespace std;
/*int fun(int n){
    static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int main(){
    int a=5;
    cout<<fun(a);
}
int main(){
    int fact=1,n;
    cin>>n;
    for(int i=n;i>=1;i--){
        fact*=i;
    }
    cout<<fact;
}
*/
int fun(int n){
    static int i=1;
    if(n>=5) return n;
    n=n+i;
    i++;
    return fun(n);
}
int main(){
    cout<<fun(1);
}