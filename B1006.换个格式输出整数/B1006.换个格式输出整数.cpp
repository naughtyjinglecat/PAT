/* 完美运行 */
#include<cstdio>

int main(void){
    int n;
    int digit[3];
    scanf("%d", &n);
    digit[2] = n % 10;
    n = n/10;
    digit[1] = n % 10;
    n = n/10;
    digit[0] = n % 10;
    for(int i = 0; i < digit[0]; i++){
        printf("B");
    }
    for(int i = 0; i < digit[1]; i++){
        printf("S");
    }
    for(int i = 0; i < digit[2]; i++){
        printf("%d", i + 1);
    }
    printf("\n");
    return 0;
}