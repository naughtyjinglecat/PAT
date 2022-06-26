#include<cstdio>
#include<stdlib.h>
#include<queue>
using namespace std;

/*总之就是把几个遍历算法都写了一遍，复习了层序遍历，中序遍历，后序遍历， 25分*/

bool sign = false;

typedef struct node{
    int data;
    int left;
    int right;
    node(){
        left = -1;
        right = -1;
    }
}node;

/*交换左右子树*/
void postOrder(node nodes[], int index){
    int temp;
    if(index != -1){
        temp = nodes[index].left;
        nodes[index].left = nodes[index].right;
        nodes[index].right = temp;
        postOrder(nodes, nodes[index].left);
        postOrder(nodes, nodes[index].right);
    }
}

void levelOrder(node nodes[], int head){
    queue<int> Q;
    int temp;
    Q.push(head);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        //如果到了最后一个节点，则打印回车符，否则打印空格
        if(nodes[temp].left != -1){
            Q.push(nodes[temp].left);
        }
        if(nodes[temp].right != -1){
            Q.push(nodes[temp].right);
        }
        if(Q.empty()){
            printf("%d\n", nodes[temp].data);
        }
        else{
            printf("%d ", nodes[temp].data);
        }
    }
    
}

void inOrder(node nodes[], int head){
    if(head != -1){
        inOrder(nodes, nodes[head].left);
        if(sign == false){
            printf("%d", nodes[head]);
            sign = true;
        }
        else{
            printf(" %d", nodes[head]);
        }
        inOrder(nodes, nodes[head].right);
    }
}



int main(void){
    int n;
    node *nodes;
    char temp_1, temp_2;
    int head;
    scanf("%d\n", &n);
    nodes = new node[n];
    //因为所有节点的标号是个从0开始个数为n的等差数列，对所有的标号进行求和再减去所有左右孩子的序号，剩下的数字就是非左右孩子，即头结点的标号
    head = (n-1)*n/2;
    for(int i = 0; i < n; i++){
        nodes[i].data = i;
        scanf("%c %c\n", &temp_1, &temp_2);
        if(temp_1 != '-'){
            nodes[i].left = (int)(temp_1 - '0');
            head -= (int)(temp_1 - '0');
        }
        if(temp_2 != '-'){
            nodes[i].right = (int)(temp_2 - '0');
            head -= (int)(temp_2 - '0');
        }
    }
    postOrder(nodes, head);
    levelOrder(nodes, head);
    inOrder(nodes, head);
    printf("\n");
    return 0;
}