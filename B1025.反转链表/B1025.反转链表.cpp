#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;

//由于无效节点没有剔除，所以21分。。。


typedef struct node{
    int data;
    int next;
}node;



int main(void){
    node nodes[100000];
    int temp_adress;
    int head, n, k;
    int *addresses;//记录节点的地址顺序
    int p;//指向当前节点
    scanf("%d %d %d", &head, &n, &k);
    addresses = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp_adress);
        scanf("%d %d", &nodes[temp_adress].data, &nodes[temp_adress].next);
    }
    p = head;
    for(int i = 0; i < n; i++){
        addresses[i] = p;
        p = nodes[p].next;
    }
    //修改访问顺序
    for(int i = 0; i < n; i += k){
        if(i+k-1 <= n){
            reverse(addresses + i, addresses + i + k);
        }
    }
    //修改指针朝向
    for(int i = 0; i < n; i++){
        if(i != n - 1){
            nodes[addresses[i]].next = addresses[i + 1];
        }
        else{
            nodes[addresses[i]].next = -1;
        }
    }
    p = head;
    for(int i = 0; i < n; i++){
        if(nodes[addresses[i]].next != -1){
            printf("%05d %d %05d\n", addresses[i], nodes[addresses[i]].data, nodes[addresses[i]].next);
        }
        else{
            printf("%05d %d %d\n", addresses[i], nodes[addresses[i]].data, nodes[addresses[i]].next);
        }
    }
    return 0;
}