/*整理清楚思路就不太难，重点是理解插入排序和归并排序的特征，而不是考察插入排序乃至归并排序本身， 25分，1小时34分钟*/

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

/*检查一个数列书否有序，有序则输出true，否则输出false*/
bool isSorted(int nums[], int length){
    bool ans = true;
    for(int i = 0; i < length - 1; i++){
        if(nums[i] > nums[i+1]){
            ans = false;
            break;
        }
    }
    return ans;
}
/*检查在group分组数量下，该序列是否满足归并排序*/
bool isAdaptToMerge(int nums[], int length, int group){
    bool ans = true;
    int *temp = nums;
    for(int total = length; total > 0; total -= group){
        if(total >= group){
            ans = isSorted(temp, group);
        }
        else{
            ans = isSorted(temp, total);
        }
        if(ans == false){
            break;
        }
        temp += group;
    }
    return ans;
}

int main(void){
    int n;
    /*如果次数列是归并排序，则标记isMerge为true，否则为false*/
    bool isMerge = true;
    /*局部有序则标志为true，否则标志为false*/
    int *sequence, *processing;
    /*入果在该分组数量下，该排序符合归并排序，则标志isfittmerge为true ，否则为false*/
    bool isfitmerge = true;
    int group = 2;
    scanf("%d", &n);
    sequence = (int*)malloc(sizeof(int)*n);
    processing = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", sequence + i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", processing + i);
    }
    isMerge = isAdaptToMerge(processing, n, 2);
    if(isMerge == true){
        printf("Merge Sort\n");
        for(group = 4; group <= n; group*=2){
            isfitmerge = isAdaptToMerge(processing, n, group);
            if(isfitmerge == false){
                int *temp = processing;
                /*total用来记录还剩多少数字没排序*/
                for(int total = n; total > 0; total -= group){
                    if(total >= group){
                        sort(temp, temp + group);
                    }
                    else{
                        sort(temp, temp + total);
                    }
                    temp += group;
                }
                for(int i = 0; i < n; i++){
                    if(i != 0){
                        printf(" ");
                    }
                    printf("%d", processing[i]);
                }
                printf("\n");
                break;
            }
        }
    }
    else{
        /*记录已经有序的元素数量*/
        int count;
        printf("Insertion Sort\n");
        for(int i = 0; i < n - 1; i++){
            if(processing[i] > processing[i + 1]){
                count = i + 1;
                sort(processing, processing + count + 1);
                for(int j = 0; j < n; j++){
                    if(j != 0){
                        printf(" ");
                    }
                    printf("%d", processing[j]);
                }
                printf("\n");
                break;
            }
        }
    }
    free(sequence);
    free(processing);
    return 0;
}