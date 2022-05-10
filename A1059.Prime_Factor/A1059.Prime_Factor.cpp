#include<cstdio>
#include<string.h>

/*题目关于1的描述语义不详，原本23分，专门处理了1之后25分*/


/*初始化质数表,false代表质数，true代表非质数*/
void initPrime(bool prime[], int n);
/*查找n的下一个质数*/
int nextPrime(bool prime[], int n);

int main(void){
    int n;
    bool prime[1000004];
    int temp = 2;
    int count;
    memset(prime, 0, sizeof(prime));
    scanf("%d", &n);
    printf("%d=", n);
        if(n == 1){
            printf("1\n");
        }
    initPrime(prime, 1000004);
    for(int i = 2; i <= n; i = nextPrime(prime, i)){
        count = 0;
        while (n % i == 0){
            count++;
            n /= i;
        }
        if(count > 0){
            printf("%d", i);
            if(count > 1){
                printf("^%d", count);
            }
            if(n == 1){
                printf("\n");
                break;
            }
            else{
                printf("*");
            }
        }
    }
    return 0;
}

void initPrime(bool prime[], int n){
    prime[0] = true;
    prime[1] = true;
    for(int i = 2; i <= n; i++){
        if(prime[i] == false){
            for(int j = 2; i*j <= n; j++){
                prime[i*j] = true;
            }
        }
    }
}

int nextPrime(bool prime[], int n){
    while(prime[n + 1] != false){
        n++;
    }
    return n + 1;
}