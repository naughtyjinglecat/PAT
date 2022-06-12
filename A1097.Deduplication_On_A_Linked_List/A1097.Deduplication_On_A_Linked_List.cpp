#include<cstdio>
#include<string.h>

//为了搞快点所以代码结构很糟糕，没有封装函数，但是好在一遍过，不过以后得注意结构问题，以后得封装函数

typedef struct node{
    int data;
    int next;
    int ans_next;
    bool removed;
}node;
//返回数据的绝对值
int abs(int num){
    if(num < 0){
        num *= -1;
    }
    return num;
}

int main(void){
    node nodes[100005];
    int head;//首地址
    int n;//输入节点个数
    int temp_address;//缓存当前节点地址
    int p;//指向当前访问节点
    bool is_duplicated[10005];
    int cur_abs;//记录当前节点的数据的绝对值
    int pre;//记录上一个已经/没有被移除的节点地址
    int head_unremoved = -1, head_removed = -1;//未被移除的链表首地址和被移除的链表首地址
    bool sign1 = false, sign2 = false;//是否记录过链表首地址
    memset(is_duplicated, 0, sizeof(is_duplicated));
    //读入数据
    scanf("%d %d", &head, &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp_address);
        scanf("%d %d", &nodes[temp_address].data, &nodes[temp_address].next);
        nodes[temp_address].removed = false;
    }
    p = head;
    while(p != -1){
        cur_abs = abs(nodes[p].data);
        //若是没遇见过这个数值，则标记一下这个数值
        if(is_duplicated[cur_abs] == false){
            is_duplicated[cur_abs] = true;
        }
        //若是已经遇见了这个数值，则修改当前节点为已经移除
        else{
            nodes[p].removed = true;
        }
        p = nodes[p].next;
    }
    //连接未被移除的链表
    p = head;
    pre = -1;
    while(p != -1){
        //若是当前节点为有效节点,则让上一个有效节点指向当前节点，且则记录当前节点为目前访问到的最后一个有效节点
        if(!nodes[p].removed){
            if(sign1 == false){
                head_unremoved = p;
                sign1 = true;
            }
            //上一个有效节点存在,则上一个节点指向当前节点
            if(pre != -1){
                nodes[pre].ans_next = p;
            }
            pre = p;
        }
        p = nodes[p].next;
    }
    nodes[pre].ans_next = -1;

    //连接已被被移除的链表
    p = head;
    pre = -1;
    while(p != -1){
        //若是当前节点为有效节点,则让上一个有效节点指向当前节点，且则记录当前节点为目前访问到的最后一个有效节点
        if(nodes[p].removed){
            if(sign2 == false){
                head_removed = p;
                sign2 = true;
            }
            //上一个有效节点存在,则上一个节点指向当前节点
            if(pre != -1){
                nodes[pre].ans_next = p;
            }
            pre = p;
        }
        p = nodes[p].next;
    }
    nodes[pre].ans_next = -1;
    //接下来打印输出
    p = head_unremoved;
    while(p != -1){
        if(!nodes[p].removed){
            if(nodes[p].ans_next != -1){
                printf("%05d %d %05d\n", p, nodes[p].data, nodes[p].ans_next);
            }
            else{
                printf("%05d %d -1\n", p, nodes[p].data);
            }
        }
        p = nodes[p].ans_next;
    }
    p = head_removed;
    while(p != -1){
        if(nodes[p].removed){
            if(nodes[p].ans_next != -1){
                printf("%05d %d %05d\n", p, nodes[p].data, nodes[p].ans_next);
            }
            else{
                printf("%05d %d -1\n", p, nodes[p].data);
            }
        }
        p = nodes[p].ans_next;
    }
    return 0;
}