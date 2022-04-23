#include<stdio.h>
#include<algorithm>
using namespace std;

/*一把过，满分，虽然不知道和hash表有什么关系。。用的排序做的*/
int main(void){
    int coins[100005];
    int n, m;
    int front = 0, rear;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", coins + i);
    }
    sort(coins, coins + n);
    rear = n - 1;
    while(front < rear){
        if(coins[front] + coins[rear] == m){
            break;
        }
        else if(coins[front] + coins[rear] < m){
            front++;
        }
        else{
            rear--;
        }
    }
    if(front == rear){
        printf("No Solution\n");
    }
    else{
        printf("%d %d\n", coins[front], coins[rear]);
    }
    return 0;
}