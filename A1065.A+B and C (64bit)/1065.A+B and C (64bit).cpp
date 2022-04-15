#include<cstdio>
#include<climits>
/*我代码出现的问题：发生了溢出，可以使用大整数运算进行比较，也可以判断溢出的情况下怎么比较*/

int main(void){
    int count = 0;
    long long a = 0, b = 0, c = 0;
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        scanf("%lld %lld %lld", &a, &b ,&c);
        if((a == LLONG_MAX/2 + 1 && b == LLONG_MAX/2 + 1) || a + b > c){
            printf("Case #%d: true", i + 1);
        }else{
           printf("Case #%i: false", i + 1);
        }
        if(i != count - 1){
            printf("\n");
        }        
    }
    return 0;
}