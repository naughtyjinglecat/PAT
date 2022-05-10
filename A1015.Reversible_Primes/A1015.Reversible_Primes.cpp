#include<math.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

/*不晓得错哪里了，总之就是错了。。。。12分*/

/*检测数字n是否是质数*/
bool isPrime(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(void){
    int n, d;
    int num[20];
    int i = 0;
    int temp;
    int digit;
    while(true){
        memset(num, -1, sizeof(num));
        scanf("%d", &n);
        if(n < 0) break;
        scanf("%d", &d);
        if(!isPrime(n)){
            printf("No\n");
        }
        while(n != 0){
            num[i] = n % d;
            n /= d;
            i++;
        }
        i--;
        digit = i;
        while(i >= 0){
            temp = (int)pow((double)d, (double)(digit - i));
            n += num[i]*temp;
            i--;
        }
        if(!isPrime(n)){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
        i++;
    }

    return 0;
}