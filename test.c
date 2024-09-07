#include<stdio.h>
int fun(int);
int main(){
    int x;
    scanf("%d",&x);
    fun(x);
}
int fun(int x){
    int res;
    res=(x%2)?printf("even"):printf("odd");
}