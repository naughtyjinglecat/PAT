#include<cstdio>
#include<string.h>
#include<stdlib.h>

/*答案正确，只是回想起筛法想了蛮长时间，20分满分*/

/*检测n以内的质数*/
void isPrime(bool prime[], int n);

int main(void){
    int n;
    scanf("%d", &n);
    bool *prime = (bool*)malloc(sizeof(bool)*(n+1));
    int count = 0;
    /*假定所有的数都是质数，标记为false*/
    memset(prime, 0, sizeof(bool)*(n+1));
    /*从质数中筛选和数*/
    isPrime(prime, n+1);
    for(int i = 3; i + 2 <= n; i++){
        if(prime[i] == false && prime[i + 2] == false){
            count++;
        }
    }
    printf("%d\n", count);

    free(prime);
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