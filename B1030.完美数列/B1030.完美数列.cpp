/*喜闻乐见没有满分TVT，21分，下次尝试二分查找来完成这个题目*/

#include<cstdio>
#include<algorithm>
using namespace std;


/*线性查找*/
int main(void){
    int n;
    long long p;
    int maxCount = 1;
    long long *num;
    long long m = 0, M = 0;
    scanf("%d %lld", &n, &p);
    num = new long long[n];
    for(int i = 0; i < n; i++){
        scanf("%lld", num + i);
    }
    sort(num, num + n);
    for(M = 0; M < n; M++){
        if(num[M] > num[m]*p){
            maxCount = (M - m) > maxCount ? (M - m) : maxCount;
            while(num[M] > num[m]*p && m <= M){
                m++;
            }
        }
    }
    printf("%d\n", maxCount);
    return 0;
}