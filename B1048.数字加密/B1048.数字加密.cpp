#include<cstdio>
#include<string.h>
/*得分16，不知道哪里出问题了。。。*/
int main(void){
    char a[101], b[101];
    char temp[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    int i = 0, j = 0;
    int sign = 0;//0 为奇数位， 1 为偶数位
    scanf("%s %s", a, b);
    j = strlen(b) - 1;
    i  = strlen(a) - 1;
    while(i >= 0 && j >= 0){
        if(sign == 0){
            b[j] = temp[((int)(b[j]+a[i]) - (int)('0'+'0'))%13];
            sign = 1;
        }
        else{
            b[j] = temp[(b[j] - a[i] + 10) % 10];
            sign = 0;
        }
        i--;
        j--;
    }
    for(int k = 0; k < strlen(b); k++){
        printf("%c", b[k]);
    }
    printf("\n");
    return 0;
}