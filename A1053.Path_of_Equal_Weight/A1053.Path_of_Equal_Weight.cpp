#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*总之就是谜一般的比较函数compare，30分*/

typedef struct node{
    int k;
    int weight;
    int *id;
    node(){
        k = 0;
        weight = -1;
        id = NULL;
    }
}node;

vector<int> temp;

//nodes:树 head：根节点的编号 ans：输出数组， s 求和目标， sum遍历到当前节点的和
void DFS(node nodes[], int head, vector< vector<int> > &ans, int s, int sum){
    temp.push_back(nodes[head].weight);
    sum += nodes[head].weight;
    //如果当前节点是叶子节点，则和s比较大小。和s相等则加入ans中，如果鄙视叶子节点，则继续递归
    if(nodes[head].k == 0){
        if(sum == s){
            ans.push_back(temp);
        }
    }
    else{
        for(int i = 0; i < nodes[head].k; i++){
            //只有当sum < s的时候才会继续递归
            if(sum < s){
                DFS(nodes, nodes[head].id[i], ans, s, sum);
            }
        }
    }
    temp.pop_back();
}

bool compare(vector<int> a, vector<int> b){
    bool ans = false;
    for(int i = 0; i < a.size() && i < b.size(); i++){
        if(a[i] == b[i]){
            continue;
        }
        else if(a[i] > b[i])
        {
            ans = true;
            break;
        }
        else{
            ans = false;
            break;
        }
    }
    return ans;
}

int main(void){
    int n, m ,s;
    node nodes[100];
    int temp_id;
    vector< vector<int> > ans;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &nodes[i].weight);
    }
    for(int i = 0; i < m; i++){
        scanf("%d", &temp_id);
        scanf("%d", &nodes[temp_id].k);
        nodes[temp_id].id = new int[nodes[temp_id].k];
        for(int j = 0; j < nodes[temp_id].k; j++){
            scanf("%d", &nodes[temp_id].id[j]);
        }
    }
    DFS(nodes, 0, ans, s, 0);
    sort(ans.begin(), ans.end(), compare);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            if(j != ans[i].size()-1){
                printf("%d ", ans[i][j]);
            }
            else{
                printf("%d\n", ans[i][j]);
            }
        }
    }
    return 0;
}