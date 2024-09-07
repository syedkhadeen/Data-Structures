#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n; 
    cout << fixed << setprecision(6);
    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input; 
        double value;
        if (input == "Inf") {
            value = INFINITY;
        } else if (input == "-Inf") {
            value = -INFINITY;
        } else if (input == "nan" || input == "NaN") {
            value = NAN;
        } else {
            value=stod(input); 
        }
        double reciprocal=1.0/value;
        cout<<reciprocal<<endl;
    }
    return 0;
}
