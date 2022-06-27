#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;


/*理解了题意节好做了，是个英语问题。。。25分*/

typedef struct node{
    int k;
    vector<int> id;
    node(){
        id.clear();
    }
}node;


//深度优先遍历，遍历多叉树的每一条路径，p表示基价，人表示中间商赚差价倍率
double DFS(node nodes[],int head, double p, double r){
    double ans = 0;
    if(nodes[head].k == 0){
        ans = p*nodes[head].id[0];
    }
    else{
        for(int i = 0; i < nodes[head].k; i++){
            ans += (1 + r*0.01)*DFS(nodes, nodes[head].id[i], p, r);
        }
    }
    return ans;
}

int main(void){
    int n;
    double p, r;
    node *nodes;
    int temp_k, temp;
    int head;
    int level = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    nodes = new node[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &temp_k);
        nodes[i].k = temp_k;
        if(temp_k == 0){
            temp_k = 1;
        }
        for(int j = 0; j < temp_k; j++){
            scanf("%d", &temp);
            nodes[i].id.push_back(temp);
        }
    }
    //计算出head的总和，然后减去各个非根节点的编号，剩下的就是根节点的编号
    head = (n-1)*n/2;
    for(int i = 0; i < n; i++){
        if(nodes[i].k != 0){
            for(int j = 0; j < nodes[i].id.size(); j++){
                head -= nodes[i].id[j];
            }
        }
    }
    printf("%.1lf\n", DFS(nodes, head, p, r));
    return 0;
}