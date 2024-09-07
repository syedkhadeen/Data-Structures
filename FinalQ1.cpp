#include <iostream>
using namespace std;
class SparseMatrix{
    public:
    class Node{
    public:             //SIR, if had done this private,there was error
        int row;
        int col;
        int val;
        Node* next;
        Node* down;
        Node():val(0),col(0),row(0),next(NULL),down(NULL){}
        Node(int val,int row,int col):val(val),row(row),col(col),next(NULL),down(NULL){}
        friend int main();
        friend class SparseMatrix;
    };
    Node* matrix;
public:
    SparseMatrix():matrix(NULL){}
    void insert(Node* p){
        if(p->val!=0){
            if(matrix==NULL) matrix=p;
            else{
                Node* temp=matrix;
                while(temp->down) temp=temp->down;
                temp->down=p;
            }
        }
    }
    void display(int rows,int cols){
        for(int i=0;i<rows; i++){
            for(int j=0;j<cols; ++j){
                Node* temp=matrix;
                bool found=false;
                while(temp){
                    if(temp->row==i&&temp->col==j){
                        cout<<temp->val<<" ";
                        found=true;
                        break;
                    }
                    temp=temp->down;
                }
                if(!found) cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
int main(){
    SparseMatrix matrix;
    int rows, cols;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter columns: ";
    cin>>cols;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int val;
            cout<<"Enter value at position("<<i<<", "<<j<<"): ";
            cin>>val;
            SparseMatrix::Node* newNode=new SparseMatrix::Node(val,i,j);    //SIR, I used scope res operator to access class Node,without that it wasnt working
            matrix.insert(newNode);
        }
    }
    cout<<"Sparse Matrix:\n";
    matrix.display(rows,cols);
}
