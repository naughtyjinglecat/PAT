#include<cstdio>
#include<vector>
#include<string.h>
#define MAXSIZE 1000
using namespace std;


/*
本题着重考察了后序遍历和中序遍历的特点，在二叉树中，假设左右子树各有m，n个节点，则
后序遍历序列的特点为，前m个输出为左子树，其后n个输出为右子树，最后输出的是根节点，

中序序列中，以根节点的位置划分，前m个为左子树，第m+1个为根节点，最后n个输出为右子树

所以根据后序和中序序列，我们总是可以确定根节点是那个，同时确定左子树和右子树各自的后
序、中序序列，递归的中岛左右子树的根节点直到遍历整个二叉树
*/
/*22分，我也不知道错哪里了。。。*/

int post_order[MAXSIZE];
int in_order[MAXSIZE];
int tree[MAXSIZE];




/*从后序序列，中序序列中挑选出根节点，并指定插入tree的节点序号*/
void DFS(int *post_order, int *in_order, int num, int index){
    //如果根节点存在则根节点插入树中
    int l_num = 0, r_num = 0;
    if(num > 0){
        tree[index] = post_order[num - 1];
        //确定左子树，右子树各有多少个
        for(int i = 0; i < num; i++){
            if(in_order[i] == post_order[num - 1]){
                l_num = i;
                r_num = num - 1 -l_num;
                break;
            }
        }
        DFS(post_order, in_order, l_num, index*2+1);
        DFS(post_order+l_num, in_order+l_num+1, r_num, index*2+2);
    }
}

int main(void){
    int temp;
    int n;
    int count = 0;
    memset(tree, -1, sizeof(tree));
    memset(tree, -1, sizeof(tree));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", post_order+i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", in_order+i);
    }
    DFS(post_order, in_order, n, 0);
    for(int i = 0; i < MAXSIZE && count <= n; i++){
        if(i == 0){
            printf("%d", tree[i]);
            count++;
        }
        else if(tree[i] != -1){
            printf(" %d", tree[i]);
            count++;
        }
    }
    printf("\n");
    
    return 0;
}
