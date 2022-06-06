#include<cstdio>
#include<map>
#include<string>
#include<iostream>
using namespace std;
/*将大写字符转化为小写字符*/
char lower(char a){
    char ans = a;
    if(a >= 'A' && a <= 'Z'){
        ans = a - 'A' + 'a';
    }
    return ans;
}

int main(void){
    map<string, int> count;
    string paragraph;
    string currentWord;
    string dominantWord = "";
    int maxtimes = 0;
    char tmp;
    bool sign1 = false;
    do{
        tmp = getchar();
        tmp = lower(tmp);
        if((tmp >= 'a' && tmp <= 'z') || (tmp >= '0' && tmp <= '9')){
            sign1 = true;
        }
        if(sign1 == true){
            if((tmp >= 'a' && tmp <= 'z') || (tmp >= '0' && tmp <= '9')){
                currentWord.push_back(tmp);
            }
            else{
                if(currentWord.size() > 0){
                    if(count.find(currentWord) == count.end()){
                        count[currentWord] = 0;
                    }
                    count[currentWord]++;
                    if(maxtimes < count[currentWord]){
                        maxtimes = count[currentWord];
                        dominantWord = currentWord;
                    }
                }
                //统计了该单词，则清除当前单词
                currentWord.clear();
            }
        }
    }while(tmp != '\n');
    
    cout << dominantWord + " " << maxtimes << endl;
    return 0;
}