#include<cstdio>
#include<algorithm>
using namespace std;


/*总之就是，逻辑太复杂，然后访问越界了，现在是13分，多个函数应该分开来单独测试不然一次性测试五个函数吃不消*/

typedef struct node{
    int data;
    int left;
    int right;
    node(){
        left = -1;
        right = -1;
    }
}node;


int n;
int inde = 0;

//将树镜像
void mirror(node nodes[]);
//将第index号节点插入树中,树的头结点是nodes[i]
void insert(node* nodes, int i, int ind);
//进行先序遍历
void preorder(node* nodes, int index, int temp[]);
//进行后序遍历
void postOrder(node* nodess, int index);
//检查插入的序列和先序序列是否相同
bool check(node nodes[], int size);

int main(void){
    node *nodes = NULL;
    int n;
    bool sign_1 = false, sign_2 = false;
    scanf("%d", &n);
    nodes = new node[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &nodes[i].data);
    }
    for(int i = 1; i < n; i++){
        insert(nodes, 0, i);
    }
    sign_1 = check(nodes, n);
    if(sign_1 == true){
        printf("YES\n");
        postOrder(nodes, 0);
    }
    else{
        mirror(nodes);
        sign_2 = check(nodes, n);
        if(sign_2 == true){
            mirror(nodes);
            printf("YES\n");
            postOrder(nodes, 0);
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

//将树镜像
void mirror(node nodes[]){
    int temp = nodes->left;
    nodes->left = nodes->right;
    nodes->right = temp;
    if(nodes->left != -1){
        mirror(nodes + nodes->left);
    }
    if(nodes->right != -1){
        mirror(nodes + nodes->right);
    }
}

//将第index号节点插入树中
void insert(node* nodes, int i, int index){
    if(nodes[index].data < nodes[i].data){
        if(nodes[i].left == -1){
            nodes[i].left = index;
        }
        else{
            insert(nodes, nodes[i].left, index);
        }
    }
    else{
        if(nodes[i].right == -1){
            nodes[i].right = index;
        }
        else{
            insert(nodes, nodes[i].right, index);
        }
    }
}

//进行后序遍历
void postOrder(node* nodes, int index){
    if(nodes[index].left != -1){
        postOrder(nodes, nodes[index].left);
    }
    if(nodes[index].right != -1){
        postOrder(nodes, nodes[index].right);
    }
    if(index != 0){
        printf("%d ", nodes[index].data);
    }
    else{
        printf("%d\n", nodes[index].data);
    }
}

//检查插入的序列和先序序列是否相同
bool check(node nodes[], int size){
    int* temp = new int[size];
    inde = 0;
    preorder(nodes, 0, temp);
    for(int i = 0; i < size; i++){
        if(nodes[i].data != temp[i]){
            delete(temp);
            return false;
        }
    }
    delete(temp);
    return true;
}

//进行先序遍历
void preorder(node* nodes, int index, int temp[]){
    temp[inde] = nodes[index].data;
    inde++;
    if(nodes[index].left != -1){
        preorder(nodes, nodes[index].left, temp);
    }
    if(nodes[index].right != -1){
        preorder(nodes, nodes[index].right, temp);
    }
}
