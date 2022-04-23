#include<cstdio>
#include<algorithm>
using namespace std;

/*把储存量的int改为double型，应该是数据发生了溢出，做计算的时候还是对应数据类型直接计算比较好，自动类型转化可能会出现新的问题*/

typedef struct moonCake{
    double stored;
    double totalPrice;
    double DanJia;
}moonCake;

bool compare(moonCake a, moonCake b){
    return a.DanJia > b.DanJia;
}

int main(void){
    int n, d;
    double profile = 0;
    moonCake moonCakes[1005];
    scanf("%d %d", &n,&d);
    for(int i = 0; i < n; i++){
        scanf("%lf", &moonCakes[i].stored);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &moonCakes[i].totalPrice);
        moonCakes[i].DanJia = moonCakes[i].totalPrice/moonCakes[i].stored;
    }
    sort(moonCakes, moonCakes + n, compare);
    for(int i = 0; i < n && d > 0; i++){
        if(d >= moonCakes[i].stored){
            profile += moonCakes[i].totalPrice;
            d -= moonCakes[i].stored;
        }
        else{
            profile += moonCakes[i].DanJia*d;
            d -= moonCakes[i].stored;
            break;
        }
    }
    printf("%.2lf\n", profile);
    return 0;
}