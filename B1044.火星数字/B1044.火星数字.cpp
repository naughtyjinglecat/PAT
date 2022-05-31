#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

/*看着答案一遍过，满分20分*/


string intToStrLow[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string intToStrHigh[13] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> strToInt;

int numToInt(string num){
    int ans = 0;
    for(int i = 0; i < num.size(); i++){
        ans = ans*10 + num[i] - '0';
    }
    return ans;
}

int main(void){
    int n;
    string temp;
    int realvalue;
    cin >> n;
    getchar();
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            if(i == 0){
                temp = intToStrLow[j];
            }
            else{
                temp = intToStrHigh[i];
                if(j != 0){
                    temp += (" "+intToStrLow[j]);
                }
            }
            strToInt[temp] = i*13 + j;
        }
    }
    for(int i = 0; i < n; i++){
        temp.clear();
        getline(cin, temp);
        if(temp[0] >= '0' && temp[0] <= '9'){
            realvalue = numToInt(temp);
            temp.clear();
            if(realvalue == 0){
                temp = "tret";
            }
            else{
                if(realvalue <= 12){
                    temp += intToStrLow[realvalue];
                }
                else{
                    temp += intToStrHigh[realvalue/13];
                    if(realvalue%13 != 0){
                        temp = temp +" "+intToStrLow[realvalue%13];
                    }
                }
            }
            cout << temp << endl;
        }
        else{
            cout << strToInt.find(temp)->second << endl;
        }
    }
    return 0;
}