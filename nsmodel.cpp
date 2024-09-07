#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
const int roadlength=100;
const int numCars=10;
const int maxSpeed=5;
const double slowdownProb=0.2;
void initializeRoad(int road[],int length){
    for(int i=0;i<numCars;++i){
        int pos=rand()%length;
        road[pos]=maxSpeed;
    }
}
void updateRoad(int road[],int length){
    for(int i=0;i<length;++i){
        if(road[i]>0){
            if(road[i]<maxSpeed){
                road[i]++;
            }
            if(static_cast<double>(rand())/RAND_MAX<slowdownProb){
                road[i]--;
            }
        }
        int newPos=(i+road[i])%length;
        if(road[newPos]>0 && road[i]>road[newPos]){
            road[i]=road[newPos]-1;
        }
        else{
            road[newPos]=road[i];
            road[i]=0;
        }
    }
}
void printRoad(const int road[],int length){
    for(int i=0;i<length;++i){
        if(road[i]==0){
            cout<<"-";
        }
        else{
            cout<<road[i];
        }
    }
    cout<<endl;
}
int main(){
    srand(time(0));
    int road[roadlength]={0};
    initializeRoad(road,roadlength);
    for(int step=0;step<10;++step){
        updateRoad(road,roadlength);
        printRoad(road,roadlength);
    }
}