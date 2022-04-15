/*满分代码*/

#include<cstdio>
#include<string.h>

int main(void){
    double an_a[1001], an_b[1001];
    int zhishu = 0;
    double xishu = 0;
    int count = 0;
    memset(an_a, 0, sizeof(an_a));
    memset(an_b, 0, sizeof(an_b));
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        scanf("%d %lf", &zhishu, &xishu);
        an_a[zhishu] = xishu;
    }
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        scanf("%d %lf", &zhishu, &xishu);
        an_b[zhishu] = xishu;
    }
    count = 0;
    for(int i = 0; i <= 1000; i++){
        an_a[i] += an_b[i];
        if(an_a[i] != 0){
            count++;
        }
    }
    printf("%d", count);
    for(int i = 1000; i >=0; i--){
        if(an_a[i] != 0){
            printf(" %d %.1lf",i ,an_a[i]);
        }
    }
    printf("\n");
    return 0;
}