#include<cstdio>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/*两次通过，还好，20分，关键是平方探测法只需要检验从0到length-1范围内的数据是否可被填入*/


/*查找大于等于n的最小的质数*/
int findminPrime(int n);
/*将n插入长度为length的hash表中,插入成功返回插入位置，否则返回-1*/
int insert(int hash[], int length, int n);
/*检测数字n是否是质数,是则返回true， 否则返回false*/
bool isPrime(int n);
int main(void){
    int m, n;
    int temp;
    int *hash;
    int index;
    scanf("%d %d", &m, &n);
    m = findminPrime(m);
    hash = (int*)malloc(sizeof(int)*m);
    memset(hash, -1, sizeof(int)*m);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        index = insert(hash, m, temp);
        if(index == -1){
            printf("-");
        }
        else{
            printf("%d", index);
        }
        if(i == n - 1){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    free(hash);
    return 0;
}


/*查找大于等于n的最小的质数*/
int findminPrime(int n){
    while(!isPrime(n)){
        n++;
    }
    return n;
}

/*检测数字n是否是质数,是则返回true， 否则返回false*/
bool isPrime(int n){
    if(n == 1){
        return false;
    }
    else{
        for(int i = 2; i <= (int)sqrt(n); i++){
            if(n % i == 0){
                return false;
            }
        }
    }
    return true;
}

int insert(int hash[], int length, int n){
    for(int i = 0; i < length; i++){
        if(hash[(n+i*i)%length] == -1){
            hash[(n+i*i)%length] = n;
            return (n+i*i)%length;
        }
    }
    return -1;
}