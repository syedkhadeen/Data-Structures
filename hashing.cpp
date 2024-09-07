#include<iostream>
using namespace std;
class HashTable{
    private:
        int *table;
        int size;
        int min;
        int max;
        int elements;
        void rehashing(){
            int new_size=size*2;
            int *new_table=new int[new_size]();
            for(int i=0;i<size;i++){
                if(table[i]!=0){
                    int key=table[i];
                    int index=hash_function(key);
                    if(new_table[index]!=0) index=probe(key);  
                    new_table[index]=key;
                }
            }
            delete[] table;
            table=new_table;
            size=new_size;
        }
    public:
        HashTable(int size,int min,int max):size(size),min(min),max(max),elements(0){
            table=new int[size]();
        }
        int hash_function(int key){
            return key%size;
        }
        void insert(int key){
            if(key<min || key>max) return;
            if(10*elements>=7*size){
                cout<<"Hash table is 70 % full.Rehashing..."<<endl;
                rehashing();
            }
            int index=hash_function(key);
            if(table[index]!=0) index=probe(key);
            table[index]=key;
            elements++;
            printTable();
        }
        int probe(int key){
            int index=hash_function(key);
            int i=0;
            while(table[(index+i)%size]!=0) i++;
            return (index+i)%size;
        }
        int search(int key){
            if(key<min || key>max) return -1;
            int index=hash_function(key);
            int i=0;
            while(table[(index+i%size)]!=key){
                if(table[(index+i)%size]==0) return -1;
                i++;
            }
            return (index+i)%size;
        }
        void printTable(){
            cout<<"Hash Table: ";
            for(int i = 0; i < size; i++){
                cout<<table[i]<< " ";
            }
            cout<<endl;
        }
        ~HashTable(){
            delete[] table;
        }
        
};
int main(){
    HashTable HT(10, 0, 99);
    int key,search;
    while(1){
        cout<<"\nEnter a number to insert into the hash table (-1 to quit): ";
        cin>>key;
        if(key==-1) break;
        HT.insert(key);
    }
    while (true){
        cout<<"\nSearch for a number in the hash table (-1 to quit): ";
        cin>>search;
        if(search==-1) break;
        int index=HT.search(search);
        if (index!=-1){
            cout<<"\nValue "<<search<<" found at index "<<index<<endl;
        } 
        else{
            cout<<"Value "<<search<<" not found in the hash table."<<endl;
        }
        HT.printTable();
    }
}