/*重点关注字符串数组怎么输入*/

#include<cstdio>


int main(void){
    char a[][10]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char num[105];
    int sum = 0;
    int digit[3];
    int j = 0;
    scanf("%s", num);
    for(int i = 0; i < 105 && num[i] != '\0'; i++){
        sum += num[i] - '0';
    }
    digit[2] = sum%10;
    sum/=10;
    digit[1] = sum%10;
    sum/=10;
    digit[0] = sum%10;
    for(j = 0; j < 2; j++){
        if(digit[j] != 0){
            break;
        }
    }
    for(; j < 3; j++){
        if(j != 2){
            printf("%s ", a[digit[j]]);
        }
        else{
            printf("%s\n", a[digit[j]]);
        }
    }
    return 0;
}