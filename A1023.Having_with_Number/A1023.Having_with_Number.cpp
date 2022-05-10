#include<cstdio>
#include<string.h>
/*测试一把通过，但是处理字符串真的有毒毒。。。25分，调试了三小时*/


/* 高精度数乘以低精度数,用num2数组返回计算结果*/
void multiple(char num1[], int n, char num2[]);

int main(void){
    char num1[22];
    char num2[22];
    int hashtable[10];
    int i;
    memset(num2, '\0', sizeof(num2));
    memset(hashtable, 0, sizeof(hashtable));
    scanf("%s", num1);
    multiple(num1, 2, num2);
    for(i = 0; i < strlen(num1); i++){
        hashtable[num1[i] - '0']++;
    }
    for(i = 0; i < strlen(num2); i++){
        hashtable[num2[i] - '0']--;
    }
    for(i = 0; i < 10; i++){
        if(hashtable[i] != 0){
            printf("No\n");
            break;
        }
    }
    if(i == 10){
        printf("Yes\n");
    }
    printf("%s\n", num2);
    return 0;
}

/* 高精度数乘以低精度数,用num2数组返回计算结果*/
void multiple(char num1[], int n, char num2[]){
    int num1Int[21];
    int nInt[21];
    int i, j = 20;
    int temp = 0;//储存进位是多少
    memset(num1Int, 0, sizeof(num1Int));
    memset(nInt, 0, sizeof(nInt));
    for(i = strlen(num1) - 1; i >= 0; i--){
        num1Int[j] = num1[i] - '0';
        j--;
    }
    j = 21;
    num2[21] = '\0';
    for(j = 20; j >= 0; j--){
        num2[j] = (num1Int[j]*n + temp)%10;
        temp = (num1Int[j]*n + temp)/10;
    }
    for(i = 0; i < 21; i++){
        num2[i] += '0';
    }
    for(i = 0; i < 21; i++){
        if(num2[i] != '0'){
            break;
        }
    }
    i--;
    j = -1;
    do{
        j++;
        i++;
        num2[j] = num2[i];
    }while(num2[i] != '\0');
}