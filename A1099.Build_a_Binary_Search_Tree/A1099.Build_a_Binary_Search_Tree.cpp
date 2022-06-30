#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

/*中序序列是递增的，所以按照中序序列填入二叉树即可，30分*/

typedef struct node{
    int data;
    int left;
    int right;
}node;

int *temp;
int ind = 0;

void inOrder(node nodes[], int index){

    if(nodes[index].left != -1){
        inOrder(nodes, nodes[index].left);
    }
    nodes[index].data = temp[ind];
    ind++;
    if(nodes[index].right != -1){
        inOrder(nodes, nodes[index].right);
    }
}

void levelOrder(node nodes[], int index){
    queue<int> Q;
    int temp;
    bool sign = false;
    Q.push(index);
    while(!Q.empty()){
        temp = Q.front();
        Q.pop();
        if(sign == false){
            printf("%d", nodes[temp].data);
            sign = true;
        }
        else{
            printf(" %d", nodes[temp].data);
        }
        if(nodes[temp].left != -1){
            Q.push(nodes[temp].left);
        }
        if(nodes[temp].right != -1){
            Q.push(nodes[temp].right);
        }
    }
    printf("\n");
}

int main(void){
    int n;
    node *nodes;
    scanf("%d", &n);
    nodes = new node[n];
    temp = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &nodes[i].left, &nodes[i].right);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", temp + i);
    }
    sort(temp, temp + n);
    inOrder(nodes, 0);
    levelOrder(nodes, 0);
    delete(nodes);
    delete(temp);
    return 0;
}