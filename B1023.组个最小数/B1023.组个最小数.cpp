#include<cstdio>

/*题目不难，读懂题意*/

int main(void){
    int num[10];
    /*标记输出的第一位数字*/
    int firstDigit = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", num + i);
    }
    for(firstDigit = 1; firstDigit < 10; firstDigit++){
        if(num[firstDigit] != 0){
            num[firstDigit]--;
            break;
        }
    }
    if(firstDigit == 10){
        printf("0\n");
    }
    else{
        printf("%d", firstDigit);
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < num[i]; j++){
                printf("%d", i);
            }
        }
        printf("\n");
    }
    return 0;
}