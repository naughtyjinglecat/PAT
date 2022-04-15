/*需要考虑特殊情况，大多数特殊情况是由于0引起的，需要额外注意*/


#include<cstdio>
#include<string.h>
/*计算整数a有多少位*/


int main(void){
    int a, b;
    int sum;
    scanf("%d %d", &a, &b);
    int num[7];
    int i = 6;
    sum = a + b;
    if(sum == 0){
        printf("0");
    }
    if(sum < 0){
        printf("-");
        sum = -sum;
    }
    memset(num, 0, sizeof(num));
    while(sum != 0){
        num[i] = sum % 10;
        sum /= 10;
        i--;
    }
    i++;//让i指向第一个有效数位
    for(int j = i; j < 7; j++){
        printf("%d", num[j]);
        if(j == 0 || j == 3){
            printf(",");
        }
    }
    printf("\n");
    return 0;
}