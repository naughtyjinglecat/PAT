#include<stdio.h>
#include<algorithm>
using namespace std;

typedef struct student{
    int ID;
    int GE;
    int G1;
    int prefer[5];
    int rank;
    int total;
}student;

typedef struct college{
    /*打算录取人数*/
    int quota;
    /*实际录取人数*/
    int rolled;
    int admision[40005];
    int lastRank;
    college(){
        rolled = 0;
    }
}college;

int main(void){
    int n = 0, m = 0, k = 0;
    // college list[105];
    student applicants[40005];
    return 0;
}