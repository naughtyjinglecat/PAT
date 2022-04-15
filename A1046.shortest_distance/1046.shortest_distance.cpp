#include<cstdio>
#include<string.h>

/*我的答案，但是会超时，原因是每次查询两个出口之间的距离的时间复杂度为0(n)的量级，事
实上，可以先保存1号出口到其他出口按顺序的距离是多少，
这样子就可以快速查询任意两个节点之间的距离是多少
比如，查询第i个和第j个节点的距离，只需要取min(高速公路总长度-（dis[j]-dis[i]), dis[j]-dis[i]）
即可，注意需确保i<j,否则会出现负数*/

int main(){
    int count = 0;
    int pair = 0;
    int length = 0;//环形公路总长度
    int distance = 0;
    int dis[100005];
    int small, big;
    int ans;
    scanf("%d", &count);
    int exit_1 = 0, exit_2 = 0;
    for(int i = 0; i < count; i++){
        scanf("%d", dis + i);
        length += dis[i];
    }
    scanf("%d", &pair);
    for(int i = 0; i < pair; i++){
        scanf("%d", &exit_1);
        scanf("%d", &exit_2);
        
        small = ((exit_1 < exit_2) ? exit_1 : exit_2) - 1;
        big = ((exit_1 > exit_2) ? exit_1 : exit_2) - 1;
        for(int j = 0; j < big - small; j++){
            distance += dis[small + j];
        }
        if(distance > length/2){
            ans = length - distance;
        }
        else{
            ans = distance;
        }
        printf("%d\n", ans);
        distance = 0;
    }
    return 0;
}
