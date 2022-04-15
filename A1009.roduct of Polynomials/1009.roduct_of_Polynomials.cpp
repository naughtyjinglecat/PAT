#include<cstdio>
#include<string.h>

typedef struct polynomial{
    int zhishu;
    float xishu;
}polynomial;

int main(void){
    int count = 0;
    polynomial a[11];
    polynomial b[11];
    polynomial c[121];
    polynomial d[121];
    int i = 0, j = 0;
    int zhi = 0, zhi_2 = 0;
    float xi = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    scanf("%d", &count);
    for(i = 0; i < count; i++){
        scanf("%d %f", &a[i].zhishu, &a[i].xishu);
    }
    scanf("%d", &count);
    for(i = 0; i < count; i++){
        scanf("%d %f", &b[i].zhishu, &b[i].xishu);
    }
    for(i = 0; i < 11; i++){
        for(j = 0; j < 11; j++){
            c[i*11+j].zhishu = a[i].zhishu + b[j].zhishu;
            c[i*11+j].xishu = a[i].xishu * b[j].xishu;
        }
    }
    zhi = c[0].zhishu;
    zhi_2 = 0;
    count = 0;
    for(i = 0; i < 121; i++){
        for(j = 0; j < 121; j++){
            if(c[j].zhishu == zhi){
                d[i].zhishu = zhi;
                d[i].xishu += c[j].xishu;
                c[j].zhishu = 0;
                c[j].xishu = 0;
            }
            else{
                zhi_2 = (zhi_2 > c[j].zhishu) ? zhi_2 : c[j].zhishu;
            }
        }
        zhi = zhi_2;
        zhi_2 = 0;
        // if(zhi == c[i].zhishu){
        //     d[i].zhishu = zhi;
        //     d[i].xishu += c[i].xishu;
        //     c[i].xishu = 0;
        //     c[i].zhishu = 0;
        // }
        if(d[i].xishu != 0){
            count++;
        }
    }
    printf("%d", count);
    return 0;
}