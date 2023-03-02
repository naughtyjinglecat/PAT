#include<algorithm>
#include<cstdio>
#include<stdlib.h>
using namespace std;
/*想尝试手写完全二叉平衡树。。插入算法。。。。。*/
/*有很多种方式。。。*/

/*将value插入*/


int p = 0;

void MidorderSearch(int *tree, int *temp, int root, int count);

int main(void){
    int *tree = NULL;
    int *temp;
    int count = 0;
    scanf("%d\n", &count);
    tree = (int*)malloc(sizeof(int)*count);
    temp = (int*)malloc(sizeof(int)*count);
    for (int i = 0; i < count; i++){
        scanf("%d", temp+i);
    }
    sort(temp, temp + count);
    MidorderSearch(tree, temp, 0, count);
    for(int i = 0; i < count; i++){
        if(i != count-1){
            printf("%d ", tree[i]);
        }
        else{
            printf("%d\n", tree[i]);
        } 
    }
    free(temp);
    free(tree);
    return 0;
}

void MidorderSearch(int *tree, int *temp, int root, int count){
    if(root <= count-1){
        MidorderSearch(tree, temp, root*2+1, count);
        tree[root] = temp[p];
        p++;
        MidorderSearch(tree, temp, root*2+2, count);
    }
}