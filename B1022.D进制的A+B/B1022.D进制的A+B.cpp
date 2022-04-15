#include<cstdio>
#include<string.h>
int main(void){
    int digit[40];
    unsigned int a, b, d, he;
    int yushu = 0, shang = 0;
    int i = 0;
    memset(digit, -1, sizeof(digit));
    scanf("%d %d %d", &a, &b, &d);
    he = a + b;
    do{
        shang = he/d;
        yushu = he%d;
        digit[i] = yushu;
        i++;
        he = shang;
    }while(he != 0);
    i--;
    /*注意不要越界*/
    if(digit[i] == 0 && i > 0){
        i--;
    }
    for(; i >=0; i--){
        printf("%d", digit[i]);
    }
    printf("\n");
    return 0;
}