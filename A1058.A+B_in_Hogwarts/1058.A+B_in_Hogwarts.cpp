/*得分18，扣两分是因为。。。。运算的时候计算纳特溢出了。。。。*/
#include<cstdio>

int main(void){
    long long yingfu_knut, you_nut;
    long long fu_Galleon, fu_Sickle, fu_Knut;
    long long you_Galleon, you_Sickle, you_Knut;
    /*找零暂时以纳特计数，以加仑西可纳特输出*/
    long long zhaoling;
    long long zl_Galleon, zl_Sickle, zl_Knut;
    scanf("%ld.%ld.%ld %ld.%ld.%ld",&fu_Galleon, &fu_Sickle, &fu_Knut, &you_Galleon, &you_Sickle, &you_Knut);
    yingfu_knut = fu_Galleon*17*29 + fu_Sickle*29 + fu_Knut;
    you_nut = you_Galleon*17*29 + you_Sickle*29 + you_Knut;
    zhaoling = you_nut + yingfu_knut;
    if(zhaoling < 0){
        printf("%c", '-');
        zhaoling = -zhaoling;
    }
    zl_Galleon = zhaoling/(17*29);
    zhaoling = zhaoling - zl_Galleon*17*29;
    zl_Sickle = zhaoling/29;
    zhaoling = zhaoling - zl_Sickle*29;
    zl_Knut = zhaoling;
    printf("%ld.%ld.%ld\n", zl_Galleon, zl_Sickle, zl_Knut);
    return 0;
}