#include<iostream>
using namespace std;
class List{
    private:
        int *arr,capacity,length,*curr;
    public:
        List(int size){
            arr=new int[size];
            capacity=size;
            length=0;
            curr=NULL;
        }
        void start(){curr=arr;}
        void tail(){
            curr=arr+length-1;                    //Faster method
            // for(int i=0;i<length;i++){        //We can also use this method to move the curr pointer,but it is slower method.
            //     curr++;
            // }
        }
        void next(){curr++;}
        void back(){curr--;}
        void insert(int pos,int val){
            if(length==capacity){
                return;
            }
            if(pos<1 || pos>length+1){
                return;
            }
            tail();
            for(int i=length;i>=pos;i--){
                *(curr+1)=*curr;
                 back();
            }
            *(curr+1)=val;
            length++;
        }
        void remove(int pos){
            if(length==0) return;
            if(pos<1 || pos>length) return;
            curr=arr+pos-1;
            for(int i=pos;i<length;i++){
                *curr=*(curr+1);
                next();
            }
            length--;
        }
        void display(){
            for(int i=0;i<length;i++){
                cout<<" "<<arr[i];
            }
        }
        int get(int pos){
            if(length==0) return -1;
            if(pos<1||pos>length)return -1;
            curr=arr+pos-1;
            return *curr;
        }
        void update(int val,int pos){
            if(length==capacity){
                return;
            }
            if(pos<1 || pos>length+1){
                return;
            }
            curr=arr+pos-1;
            *curr=val;
        }
        bool find(int val){
            start();
            for(int i=1;i<length;i++){
                if(*curr==val) return true;
                next();
            }
            return false;
        }
        int lengthOfList(){
            return length;
        }
        void createList(){
            delete []arr;
            length=0;
            curr=NULL;
        }
        void copy(List &other){
            delete []arr;
            arr=new int[other.capacity];
            int *newptr = other.arr;
            int *oldptr = arr;
            for(int i=0;i<other.length;i++){
                *oldptr=*newptr;
                oldptr++;
                newptr++;
            }
            capacity=other.capacity;
            length=other.length;
            curr=arr+length-1;
        }
        void clear(){
            delete []arr;
            length=0;
            curr=NULL;
        }
        void reverseList() {
        if (length > 1) {
            int *start = arr;
            int *end = arr + length - 1;

            while (start < end) {
                swap(*start, *end);
                start++;
                end--;
            }
        }
    }
    void sort() {
        for (int i = 0; i < length - 1; i++) {
            for (int j = 0; j < length - i - 1; j++) {
                if (*(arr + j) > *(arr + j + 1)) {
                    swap(*(arr + j), *(arr + j + 1));
                }
            }
        }
    }
    bool isFull() {
        return length == capacity;
    }
    bool isEmpty() {
        return length == 0;
    }
};
int main(){
     int size;
    cout << "Enter the size of the list: ";
    cin >> size;

    List lis(size);
    List otherList(size); // Create another list for testing copy operation

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Copy List\n";
        cout << "3. Clear List\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert at Position\n";
        cout << "6. Remove at Position\n";
        cout << "7. Get Element at Position\n";
        cout << "8. Update Element at Position\n";
        cout << "9. Find Element\n";
        cout << "10. Length of List\n";
        cout << "11. Print List\n";
        cout << "12. Reverse List\n";
        cout << "13. Sort List\n";
        cout << "14. Check if List is Full\n";
        cout << "15. Check if List is Empty\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lis.createList();
                cout << "List created.\n";
                break;

            case 2:
                otherList.copy(lis);
                cout << "List copied.\n";
                break;

            case 3:
                lis.clear();
                cout << "List cleared.\n";
                break;

              case 4:
                int val;
                cout << "Enter value to insert: ";
                cin >> val;
                lis.insert(val,1);
                break;

            case 5:
                int posX, valX;
                cout << "Enter value to insert: ";
                cin >> valX;
                cout << "Enter position to insert: ";
                cin >> posX;
                lis.insert(posX, valX);
                break;

            case 6:
                int posRemove;
                cout << "Enter position to remove: ";
                cin >> posRemove;
                lis.remove(posRemove);
                break;

            case 7:
                int posGet;
                cout << "Enter position to get element: ";
                cin >> posGet;
                cout << "Element at position " << posGet << ": " << lis.get(posGet) << endl;
                break;

            case 8:
                int posUpdate, valUpdate;
                cout << "Enter position to update: ";
                cin >> posUpdate;
                cout << "Enter new value: ";
                cin >> valUpdate;
                lis.update(valUpdate, posUpdate);
                break;

            case 9:
                int valFind;
                cout << "Enter value to find: ";
                cin >> valFind;
                cout << (lis.find(valFind) ? "Found" : "Not Found") << endl;
                break;

            case 10:
                cout << "Length of List: " << lis.lengthOfList() << endl;
                break;

            case 11:
                cout << "List: ";
                lis.display();
                cout << endl;
                break;

            case 12:
                lis.reverseList();
                cout << "List reversed.\n";
                break;

            case 13:
                lis.sort();
                cout << "List sorted.\n";
                break;

            case 14:
                cout << (lis.isFull() ? "List is Full" : "List is not Full") << endl;
                break;

            case 15:
                cout << (lis.isEmpty() ? "List is Empty" : "List is not Empty") << endl;
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 0);

    return 0;
}