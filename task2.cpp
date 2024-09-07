#include <iostream>
#include <cstring>
using namespace std;
char* get(const char* str,int start,int stop) {
    if(start<0||stop<start){
        return nullptr;
    }
    const char* startPtr=str+start;
    int length=stop-start+1;
    char* result=new char[length+1];  
    char* resultPtr=result;
    while(length-- >0){
        *resultPtr++ =*startPtr++;
    }
    *resultPtr='\0'; 
    return result;
}
int main() {
    const char* inputString="My name is Ali";
    int startIndex=3;
    int stopIndex=6;

    char* substring=get(inputString,startIndex,stopIndex);
    if(substring!=nullptr){
        cout<<"Return String : "<<substring<<endl;
        delete[] substring;
    } 
    else{
       cout<<"Invalid."<<endl;
    }
}
