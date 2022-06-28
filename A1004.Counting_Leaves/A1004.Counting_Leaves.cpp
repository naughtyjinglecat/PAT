#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<queue>
using namespace std;

/*重点在输入上，每一次的输入都要严格的判定，30分*/



typedef struct kin{
    int k;
    int *children;
    kin(){
        k = 0;
        children = NULL;
    }
}kin;

vector<int> ans;


//根节点的level定义为0,每一次递归，都会把下一代全部入队，同时level加1
void BFS(queue<int> &Q, kin kins[], int level){
    int temp;
    int cur_generation = Q.size();//这一代的数量
    if(!Q.empty()){
        ans.push_back(0);
        for(int i = 0; i < cur_generation; i++){
            temp = Q.front();
            Q.pop();
            //如果这个节点是叶节点，则叶节点数量加1，否则他的下一代节点入队
            if(kins[temp].k == 0){
                ans[level]++;
            }
            else{
                for(int j = 0; j < kins[temp].k; j++){
                    Q.push(kins[temp].children[j]);
                }
            }
        }
        BFS(Q, kins, level+1);
    }
}

int main(void){
    int n, m;
    kin kins[100];
    int index_temp;
    queue<int> Q;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &index_temp);
        scanf("%d", &kins[index_temp].k);
        if(kins[index_temp].k != 0){
            kins[index_temp].children = (int*)malloc(sizeof(int)*kins[index_temp].k);
            for(int j = 0; j < kins[index_temp].k; j++){
                scanf("%d", &kins[index_temp].children[j]);
            }
        }
    }
    Q.push(1);
    BFS(Q, kins, 0);
    for(int i = 0; i < ans.size()-1; i++){
        printf("%d ", ans[i]);
    }
    printf("%d\n", ans[ans.size()-1]);
    return 0;
}