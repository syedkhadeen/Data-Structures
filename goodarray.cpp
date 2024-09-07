#include <iostream>
#include <vector>
using namespace std;
int min_operations_to_form_good_array(const vector<int>& a){
    int operations=0;
    int n=a.size();
    for(int i=0;i<n-1;++i){
        if(a[i]%2==a[i+1]%2) operations++;
    }
    return operations;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        
        int result=min_operations_to_form_good_array(a);
        cout<<result<<endl;
    }
}
