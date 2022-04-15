#include<cstdio>
#include<string.h>

int main(void){
    int digit[10];
    char n[1005];
    int i = 0;
    memset(digit, 0, sizeof(digit));
    scanf("%s", n);
    while (n[i] != '\0'){
        digit[n[i] - '0']++;
        i++;
    }
    for(int j = 0; j < 10; j++){
        if(digit[j] > 0){
            printf("%d:%d\n", j, digit[j]);
        }
    }
    return 0;
}