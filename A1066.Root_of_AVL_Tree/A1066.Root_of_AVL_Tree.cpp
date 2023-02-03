#include<cstdio>

/*总之就是非常离谱。。。测试了很多测试用例才满分*/

typedef struct node{
    int data;
    node *lchild;
    node *rchild;
    node(){
        lchild = NULL;
        rchild = NULL;
        data = 0;
    }
    node(int _data){
        lchild = NULL;
        rchild = NULL;
        data = _data;
    }
}node, *tree;

//将数据data插入树root中
void insert(tree &root, int data);
//得到树的高度
int getHeighten(tree &root);
/*LL型，LR型，RL型，RR型旋转*/
void adjustLL(tree &root);
void adjustLR(tree &root);
void adjustRL(tree &root);
void adjustRR(tree &root);
int max(int a, int b){
    return (a > b) ? a : b;
}
int abs(int a){
    if(a >0){
        return a;
    }
    else{
        return -a;
    }
}

int main(void){
    int n;
    tree root = NULL;
    int temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        insert(root, temp);
    }
    printf("%d", root->data);
    return 0;
}

void insert(tree &root, int data){
    int lsubtreeHeight = 0, rsubtreeHeight = 0;
    if(root == NULL){
        root = new node(data);
    }
    else{
        if(data < root->data){
        insert(root->lchild, data);
        }
        else{
        insert(root->rchild, data);
        }
    }
    lsubtreeHeight = getHeighten(root->lchild);
    rsubtreeHeight = getHeighten(root->rchild);
    /*如果需要调整*/
    if(abs(lsubtreeHeight - rsubtreeHeight) > 1){
        /*L型*/
        if(lsubtreeHeight > rsubtreeHeight){
            /*LL型*/
            if(getHeighten(root->lchild->lchild) >= getHeighten(root->lchild->rchild)){
                adjustLL(root);
            }
            /*LR型*/
            else{
                adjustLR(root);
            }
        }
        /*R型*/
        else{
            /*RR型*/
            if(getHeighten(root->rchild->rchild) > getHeighten(root->rchild->lchild)){
                adjustRR(root);
            }
            /*RL型*/
            else{
                adjustRL(root);
            }
        }
    }
}

void adjustLL(tree &root){
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    root = temp;
}
void adjustLR(tree &root){
    adjustRR(root->lchild);
    adjustLL(root);
}
void adjustRL(tree &root){
    adjustLL(root->rchild);
    adjustRR(root);
}
void adjustRR(tree &root){
    node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    root = temp;
}

int getHeighten(tree &root){
    int lheighten = 0, rheighten = 0;
    if(root == NULL){
        return 0;
    }
    else{
        lheighten = getHeighten(root->lchild);
        rheighten = getHeighten(root->rchild);
        return max(lheighten, rheighten) + 1;
    }
}