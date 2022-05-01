#include<stdio.h>
#include<string.h>
/*之后一次循环跳出，temp做了相加但是还没有取余，25分，三十五分钟*/


typedef struct PAT{
    /*如果该字符是A，则标记为true，否则标记为false*/
    bool isA;
    /*A之前p的个数*/
    long long countOfP;
    /*A之后T的个数*/
    long long countOfT;
    PAT(){
        isA = false;
        countOfP = 0;
        countOfT = 0;
    }
}PAT;


int main(){
    char letter[100005];
    PAT infA[100005];
    /*暂存当前有多少个P或者A,病统计最后输出结果*/
    long long temp = 0;
    scanf("%s", letter);
    for(int i = 0; i < strlen(letter); i++){
        if(letter[i] == 'P'){
            temp++;
        }
        if(letter[i] == 'A'){
            infA[i].isA = true;
            infA[i].countOfP = temp;
        }
    }
    temp = 0;
    for(int i = strlen(letter) - 1; i >= 0; i--){
        if(letter[i] == 'T'){
            temp++;
        }
        if(letter[i] == 'A'){
            infA[i].countOfT = temp;
        }
    }
    temp = 0;
    for(int i = 0; i < strlen(letter); i++){
        if(infA[i].isA){
            temp += (infA[i].countOfP*infA[i].countOfT)%1000000007;
        }
    }
    temp %= 1000000007;
    printf("%lld\n", temp);
    return 0;
}