/*要读懂题意喵喵喵*/

#include<cstdio>

int main(void){
    int xs = 0, zs = 0;
    int d_xs = 0, d_zs = 0;
    int sign = 0;
    int out_sign = 0;
    while(scanf("%d %d", &xs, &zs) != EOF){
        if(zs == 0){
            d_xs = 0;
            d_zs = 0;
        }
        else{
            d_xs = xs * zs;
            d_zs = zs - 1;
        }
        if(d_xs != 0 || d_zs != 0){
            if(sign == 0){
                sign = 1;
            }
            else{
                printf(" ");
            }
            printf("%d %d", d_xs, d_zs);
            out_sign = 1;
        }
    }
    if(out_sign == 0){
        printf("0 0");
    }
    return 0;
}