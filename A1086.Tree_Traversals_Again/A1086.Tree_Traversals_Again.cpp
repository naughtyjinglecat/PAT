#include<cstdio>
#include<string.h>
#include<malloc.h>
#include<stack>
#define MAXSIZE 10000
#define po false
#define pu true
using namespace std;

/*虽然是25分，但是使用的是数组来模拟二叉树，如果树的层数很多的话这种方法就会失效，下次需要考虑使用节点而不是数组来实现二叉树*/


/*pre记录此节点上一个节点是pu还是po，若是po则代表出栈，pu表示入栈
    此时有四种组合，
    pre-pu, cur-pu,则当前节点为上一个节点的左孩子
    pre-pu, cur-po, 则当前节点为此前节点，且该节点为叶节点
    pre-po， cur-pu，则表示当前节点是上一个节点的右孩子
    pre-po， cur-po，当前节点是上一个节点的祖先

    使用hashtable快速查找当前节点在tree中的位置
    使用后序遍历来进行后序输出
*/



void postOrder(int tree[], int index){
    if(tree[index] != -1){
        postOrder(tree, index*2+1);
        postOrder(tree, index*2+2);
        if(index != 0){
            printf("%d ", tree[index]);
        }
        else{
            printf("%d\n", tree[index]);
        }
    }

}

int main(void){
    int n;
    int tree[MAXSIZE];
    char temp[8];
    int pre_index, cur_index;
    int *hashtable;
    stack<int> S;
    /*pre和cur记录此节点上一个节点与当前节点是pu还是po，po则代表出栈，pu表示入栈
    此时有四种组合，
    pre-pu, cur-pu,则当前节点为上一个节点的左孩子
    pre-pu, cur-po, 则当前节点为此前节点，且该节点为叶节点
    pre-po， cur-pu，则表示当前节点是上一个节点的右孩子
    pre-po， cur-po，当前节点是上一个节点的祖先
    */
    bool pre, cur;
    memset(tree, -1, sizeof(tree));
    scanf("%d", &n);
    hashtable = (int*)malloc(sizeof(int)*(n+1));
    if(n > 0){
        scanf("%s %d", temp, &pre_index);
        tree[0] = pre_index;
        pre = pu;
        hashtable[pre_index] = 0;
        S.push(pre_index);
    }
    for(int i = 0; i < 2*n-1; i++){
        scanf("%s", temp);
        if(strcmp(temp, "Push") == 0){
            scanf("%d", &cur_index);
            cur = pu;
            S.push(cur_index);
        }
        else{
            cur = po;
            cur_index = S.top();
            S.pop();
        }
        if(pre == pu && cur == pu){
            tree[hashtable[pre_index]*2+1] = cur_index;
            hashtable[cur_index] = hashtable[pre_index]*2+1;
        }
        else if(pre == po && cur == pu){
            tree[hashtable[pre_index]*2+2] = cur_index;
            hashtable[cur_index] = hashtable[pre_index]*2+2;
        }
        pre_index = cur_index;
        pre = cur;
    }
    postOrder(tree, 0);
    return 0;
}