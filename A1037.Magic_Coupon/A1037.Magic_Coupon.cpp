#include<cstdio>
#include<algorithm>
using namespace std;

int main(void){
    long long coupon[100005], product[100005];
    int nc, np;
    int cp = 0, pp = 0;
    long long money = 0;
    scanf("%d", &nc);
    for(int i = 0; i < nc; i++){
        scanf("%lld", coupon + i);
    }
    scanf("%d", &np);
    for(int i = 0; i < np; i++){
        scanf("%lld", product + i);
    }
    sort(coupon, coupon + nc);
    sort(product, product + np);
    while(cp < nc && pp < np){
        if(coupon[cp] >=0 || product[pp] >= 0){
            break;
        }
        money += coupon[cp]*product[pp];
        cp++;
        pp++;
    }
    cp = nc - 1;
    pp = np - 1;
    while(cp >= 0 && pp >= 0){
        if(coupon[cp] <= 0 || product[pp] <= 0){
            break;
        }
        money += coupon[cp]*product[pp];
        cp--;
        pp--;
    }
    printf("%lld", money);
    return  0;
}