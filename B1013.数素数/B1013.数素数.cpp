#include<cstdio>
#include<string.h>

/*对齐格式就好了，其实很好做，20分*/

/*检测n以内的质数*/
void isPrime(bool prime[], int n);

int main(void){
    int m, n;
    /*如果没有输出过，标记为false，否则为true*/
    bool sign = false;
    int count = 0;
    int output = 0;
    scanf("%d %d", &m, &n);
    bool prime[1000000];
    /*假定所有的数都是质数，标记为false*/
    memset(prime, 0, sizeof(prime));
    /*从质数中筛选和数*/
    isPrime(prime, 1000000);

    for(int i = 0; i < 1000000; i++){
        if(prime[i] == false){
            count++;
            if(count >= m){
                if(sign == false){
                    sign = true;                    
                }
                else{
                    if(output%10 == 0){
                        printf("\n");
                    }
                    else{
                        printf(" ");
                    }
                }
                printf("%d", i);
                output++;
            }
            if(count == n){
                break;
            }
        }
    }
    printf("\n");
    return 0;
}

void isPrime(bool prime[], int n){
    /*i指向除0和1之外的第一个未标记为质数的数*/
    int i = 3;
    prime[0] = true;
    prime[1] = true;
    /*从2开始，假定第一个标记为false的数是质数，这个数的倍数都是和数*/
    for(int i = 2; i <= n; i++){
        if(prime[i] == false){
            for(int j = 2; i*j <= n; j++){
                prime[i*j] = true;
            }
        }
    }
}