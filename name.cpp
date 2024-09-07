#include <iostream>
#include <vector>
//#include <clib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    vector<string> names={"Pumair", "Pahad", "Khadeen", "Ali Naveed","Ahmad P"};
    int randomIndex=rand()%names.size();
    cout<<"THE WIINER OF GIVEAWAY IS : "<<names[randomIndex]<<endl;
    return 0;
}
