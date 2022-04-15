#include<cstdio>
#include<string.h>
int main(void){
    char num[105];
    int sum = 0;
    int digit[3];
    char word[10][6] = {"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int i = 0;
    scanf("%s", num);
    for(i = 0; num[i] != '\0'; i++){
        sum += num[i] - '0';
    }
    memset(digit, -1, sizeof(digit));
    i = 0;
    do{
        digit[i] = sum%10;
        sum /= 10;
        i++;
    }while(sum != 0);
    i--;
    for(; i >= 0; i--){
        printf("%s", word[digit[i]]);
        if(i != 0){
            printf(" ");
        }
        else{
            printf("\n");
        }
    }
    return 0;

}