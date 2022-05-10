#include<cstdio>

/*不晓得错哪里了。。。总之就是离谱， 17分*/


/*查找从start开始的最长因式串的长度*/
long long maxLength(long long n, long long start){
    long long temp = start;
    long long length = 0;
    long long i = 0;
    while(n % temp == 0){
        length++;
        i++;
        temp *= start + i;
    }
    return length;
}

int main(void){
    long long n;
    long long curLength;
    long long maxCount = 0;
    long long start = 1;
    scanf("%lld", &n);
    for(long long i = 2; i <= n; i++){
        curLength = maxLength(n, i);
        if(curLength > maxCount){
            maxCount = curLength;
            start = i;
            i += maxCount - 1;
        }
    }
    printf("%lld\n", maxCount);
    for(long long i = 0; i < maxCount; i++){
        printf("%lld", start + i);
        if(i == maxCount - 1){
            printf("\n");
        }
        else{
            printf("*");
        }
    }
    return 0;
}