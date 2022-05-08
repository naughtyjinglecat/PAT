#include<cstdio>
// #include<malloc.h>

/*不知道错哪里了，就酱紫把，17分*/

int main(void){
    int n;
    double num;
    double ans= 0;
    scanf("%d", &n);
//     num = (double*)malloc(sizeof(double)*n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &num);
        ans += num*(i + 1)*(n - i);
    }
    printf("%.2lf", ans);
//     free(num);
    return 0;
}