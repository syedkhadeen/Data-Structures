#include<iostream>
using namespace std;
class Node{
public:
    string sensorID;
    int timeStamp;
    int value;
    Node* next;
    Node(string sensorID,int timeStamp,int val):sensorID(sensorID),timeStamp(timeStamp),val(val),next(NULL){}
};
class HashTable{
    const int size=100;
    Node *arr[size];
    HashTable(){
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }
    void addDataPoint(string sensorID,int timestamp,int val){
        int index=sensorID;
        if(arr[index]==NULL) arr[index]=new Node(sensorID,name,fatherName,department,degree);
        else{
            Node* newNode=new Node(sensorID,timestamp,val);
            Node* current=arr[index];
            while(current->next!=NULL) current=current->next;
            current->next=newNode;
        }
    }
    Node* retrieve(string sensorID){
        int index=sensorID;
        if(arr[index]!=NULL){
            Node* current=arr[index];
            while(current!=NULL){
                if(current->sensorID==sensorID) return current;
                current=current->next;
            }
        }
        return NULL;
    }
    void update(){
        
    }

}