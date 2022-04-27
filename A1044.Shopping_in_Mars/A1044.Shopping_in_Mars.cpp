/*虽然最后提交完美解答，但是花了两个小时，关键是对二分查找要捻熟于心。25分*/

#include<stdio.h>
#include<stdlib.h>


/*返回恰好可以付款的最后一节钻石标号*/
int binarySearch(int diamond[], int front, int n, int m);
/*返回当前钻石段的价值*/
int segmentValue(int diamond[], int front, int back);


int main(void){
    /*第一次输出记为false，之后从第二次输出开始记为true*/
    bool sign = false;
    int n, m;
    int *diamonds;
    scanf("%d %d", &n, &m);
    int front = 0, back = 0;
    /*最小花费截断的范围*/
    int minFront = 0, minBack = 0;
    /*最少花费的钱数*/
    int minSpend = 0;
    /*从front开始查找，恰好可以满足付款要求的钻石价值*/
    int value = 0;
    diamonds = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", diamonds + i);
        if(i != 0){
            diamonds[i] += diamonds[i-1];
        }
    }
    minSpend = diamonds[n - 1];
    value = diamonds[0];
    if(value == m){
        printf("0-0");
    }
    while(front < n && segmentValue(diamonds, front, n-1) >= m){
        back = binarySearch(diamonds, front, n, m);
        value = segmentValue(diamonds, front, back);
        if(minSpend > value){
            minSpend = value;
            minFront = front;
            minBack = back;
        }
        if(value == m){
            if(sign == true){
                printf("\n");
            }
            printf("%d-%d", front + 1, back + 1);
            sign = true;
        }
        front++;
    }
    front = 0, back = 0;
    if(sign == false){
        while(front < n && segmentValue(diamonds, front, n-1) >= minSpend){
            back = binarySearch(diamonds, front, n, minSpend);
            value = segmentValue(diamonds, front, back);
            if(minSpend > value){
                minSpend = value;
                minFront = front;
                minBack = back;
            }
            if(value == minSpend){
                if(sign == true){
                    printf("\n");
                }
                printf("%d-%d", front + 1, back + 1);
                sign = true;
            }
            front++;
        }
    }
    free(diamonds);
    return 0;
}

int binarySearch(int diamonds[], int front, int n, int m){
    int start= front;
    int back = n - 1;
    int ans = n - 1;
    int mid = front + (back - front)/2;
    while(front <= back){
        mid = front + (back - front)/2;
        if(segmentValue(diamonds, start, mid) >= m){
            ans = mid;
            back = mid - 1;
        }
        else{
            front = mid + 1;
        }
    }
    return ans;
}

int segmentValue(int diamond[], int front, int back){
    if(front == 0){
        return diamond[back];
    }
    else{
        return diamond[back] - diamond[front -1];
    }
}