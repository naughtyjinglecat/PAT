#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int main(){
    string beedsOnSell;
    string beedsTobeBought;
    /*记录待销售的珠串各种珠子各有多少颗,欲购买各种珠子多少颗*/
    int onSell[128];
    int toBeBought[128];
    /*多了或者少了多少颗珠子*/
    int redundancy = 0;
    int dificit = 0;
    cin >> beedsOnSell;
    cin >> beedsTobeBought;
    memset(onSell, 0, sizeof(onSell));
    memset(toBeBought, 0, sizeof(toBeBought));
    for(int i = 0; i < beedsOnSell.size(); i++){
        onSell[beedsOnSell[i]]++;
    }
    for(int i = 0; i < beedsTobeBought.size(); i++){
        toBeBought[beedsTobeBought[i]]++;
    }
    for(int i = 0; i < 128; i++){
        if(onSell[i] - toBeBought[i] > 0){
            redundancy += onSell[i] - toBeBought[i];
        }
        else{
            dificit += toBeBought[i] - onSell[i];
        }
    }
    if(dificit != 0){
        cout << "No " << dificit << endl;
    }
    else{
        cout << "Yes " << redundancy << endl;
    }
    return 0;
}