#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*一遍过，25分*/


int main(void){
    int n, p;
    int front = 0, rear = 0;
    long long m, M;
    long long *nums = NULL;
    int maxLength = 0;
    scanf("%d %d", &n, &p);
    nums = (long long*)malloc(sizeof(long long)*n);
    for(int i = 0; i < n; i++){
        scanf("%lld", nums + i);
    }
    sort(nums, nums + n);
    while(rear < n){
        M = nums[rear];
        m = nums[front];
        if(M <= m*p){
            maxLength = (rear - front + 1 > maxLength) ? (rear - front + 1) : maxLength;
            rear++;
        }
        else{
            front++;
        }
    }
        printf("%d\n", maxLength);
    return 0;
}