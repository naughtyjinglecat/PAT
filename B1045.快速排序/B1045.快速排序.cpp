#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;

/*不知道错哪里了，思路是，每次快排之后都会确定一个元素的位置，那么只需要和最终排序结果对比，和最终排序结果相同则该元素可以作为主元，否则，不能作为主元*/

int main(){
    int n;
    int *sequence, *sorted;
    int count = 0;
    bool sign = false;
    scanf("%d", &n);
    sequence = (int*)malloc(sizeof(int)*n);
    sorted = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", sequence + i);
        sorted[i] = sequence[i];
    }
    sort(sorted, sorted + n);
    for(int i = 0; i < n; i++){
        if(sorted[i] == sequence[i]){
            count++;
        }
    }
    printf("%d\n", count);
    for(int i = 0; i < n; i++){
        if(sorted[i] == sequence[i]){
            if(sign == true){
                printf(" ");
            }
            printf("%d", sorted[i]);
            sign = true;
        }
    }
    printf("\n");
    return 0;
}