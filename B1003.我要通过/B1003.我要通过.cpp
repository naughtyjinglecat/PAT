#include<stdio.h>
#include<string.h>

/*看上去难，实则一把透过...*/

bool isCorrect(char str[]){
    int length = strlen(str);
    int countP = 0, countT = 0;
    /*以下几种情况直接判错*/
    for(int i = 0; i < length; i++){
        if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T'){
            return false;
        }
        if(str[i] == 'P'){
            countP++;
            if(countP > 1){
                return false;
            }
            if(countT != 0){
                return false;
            }
        }
        if(str[i] =='T'){
            countT++;
            if(countP != 1){
                return false;
            }
            if(countT > 1){
                return false;
            }
        }
    }
    /*若以上为判错，则该字符串形式为aPbTc,其中a，b，c为空数组或者全为A的字符数组*/
    int count1 = 0, count2 = 0, count3 = 0;//记录a,b,c字符串的长度
    for(int i = 0; i < length; i++){
        if(countP == 1 && str[i] == 'A'){
            count1++;
        }
        else if(str[i] == 'P'){
            countP--;
        }
        else if(countP == 0 && countT == 1 && str[i] == 'A'){
            count2++;
        }
        else if(str[i] == 'T'){
            countT--;
        }
        else if(countP == 0 && countT == 0 && str[i] == 'A'){
            count3++;
        }
    }
    /*显然count3应该大于等于count1,且count2应该大于等于1，如果不满足，则无法凑出xPATx,或者aPbATca形式*/
    if(count3 < count1 || count2 == 0){
        return false;
    }
    /*跑到这里该字符串一定满足aPbATca形式,记录a，b，c的长度*/
    int counta = count1, countb = count2 - 1, countc = count3 - counta;
    while(count2 > 1){
        count1 = counta;
        count2 = countb;
        count3 = countc;
        counta = count1;
        counta = count1;
        countb = count2 - 1;
        countc = count3 - counta;
    }
    if(count1 == count3){
        return true;
    }
    else{
        return false;
    }
}


int main(void){
    int n;
    char temp[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", temp);
        if(isCorrect(temp)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}