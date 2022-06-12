#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;


/*
简单来说，就是将节点保存在顺序表中，然后利用c++stl库中的排序sort对节点直接排序，

需要注意这次要单独输出地址，并且有序使用了vector存储节点，所以节点下标并不是节点
的实际地址，需要对地址进行存储
*/
/*不晓得错哪里了，因为数组越界，24分*/


typedef struct node{
    int address;
    int data;
    int next;
}node;

//比较两个节点的大小
bool compare(node a, node b){
    return a.data < b.data;
}

int main(void){
    int temp_address;
    int n;//读入数据个数
    int length;//实际链表长度
    vector<node> linkList;//使用变长数组进行排序
    int head;//链表头结点首地址
    int p;
    node nodes[100005];
    //读入数据
    scanf("%d %d", &n, &head);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp_address);
        scanf("%d %d", &nodes[temp_address].data, &nodes[temp_address].next);
        nodes[temp_address].address = temp_address;
    }
    p = head;
    //提取输入数据中有效的节点组成链表
    while(p >= 0){
        linkList.push_back(nodes[p]);
        p = nodes[p].next;
    }
    //对有效节点进行排序
    sort(linkList.begin(), linkList.end(), compare);
    //修改节点的next指向
    for(int i = 0; i < linkList.size()-1; i++){
        linkList[i].next = linkList[i+1].address;
    }
    linkList[linkList.size()-1].next = -1;
    //输出有效节点
    if(linkList.size() >= 1){
        printf("%ld %05d\n", linkList.size(), linkList[0].address);
    }
    else{
        printf("0 -1\n");
    }
    for(int i = 0; i < linkList.size(); i++){
        if(i != linkList.size()-1){
            printf("%05d %d %05d\n", linkList[i].address, linkList[i].data, linkList[i].next);
        }
        else{
            printf("%05d %d %d\n", linkList[i].address, linkList[i].data, linkList[i].next);
        }
    }
    return 0;
}