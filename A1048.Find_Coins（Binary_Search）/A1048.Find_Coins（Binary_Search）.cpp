#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*注意跳出循环的条件，25分*/

/*利用二分查找查询某金额的硬币,，若查询失败，则返回-1*/
int binarySearch(int coins[],int length, int value){
    int front = 0, rear = length - 1;
    int mid = front + (rear - front)/2;
    while(front <= rear){
        mid = front + (rear - front)/2;
        if(coins[mid] == value){
            return value;
        }
        else if(coins[mid] < value){
            front = mid + 1;
        }
        else{
            rear = mid -1;
        }
    }
    return -1;
}

int main(void){
    int i;
    int n ,m;
    int *coins;
    /*若查找到解决方案，则标志为true，未查找到则标志为false*/
    bool sign = false;
    /*待支付的两枚硬币*/
    int coin_1, coin_2;
    scanf("%d %d", &n, &m);
    coins = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", coins + i);
    }
    sort(coins, coins + n);
    for(i = 0; i < n && coins[i] <= m/2; i++){
        coin_1 = coins[i];
        coin_2 = binarySearch(coins + i + 1, n - i - 1, m - coin_1);
        if(coin_2 != -1){
            printf("%d %d\n", coin_1, coin_2);
            sign = true;
            break;
        }
    }
    if(sign == false){
        printf("No Solution\n");
    }
    return 0;
}