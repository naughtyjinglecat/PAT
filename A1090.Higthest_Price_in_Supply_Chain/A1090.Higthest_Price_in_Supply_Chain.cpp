#include<cstdio>
#include<vector>
using namespace std;



/*不知道错哪里了，但是19分， 阿巴阿巴阿巴*/



/*本题题中给出的是一个逆向二叉树，即从叶子结点指向根节点，
遍历每个节点的价格固然可以求得结果但是时间复杂度为O(n*logn)
的时间量级，先把这颗树的方向反转过来，修改为根节点指向子节点，
再深度优先遍历，
*/




int max_level = 0, max_c = 0;

//深度遍历求取最大价格，及其个数
double max_price(vector<int> *head, int index, double p, double r){
    double ans = p;
    double temp;
    for(int i = 0; i < head[index].size(); i++){
        temp = max_price(head, head[index][i], p, r)*(1+0.01*r);
        if(ans < temp){
            ans = temp;
        }
    }
    return ans;
}

void max_count(vector<int> *head, int index, int level){
    if(level > max_level){
        max_level = level;
        max_c = 1;
    }
    else{
        max_c++;
    }
    for(int i = 0; i < head[index].size(); i++){
        if(head[head[index][i]].size() > 0){
            max_count(head, head[index][i], level+1);
        }
    }
}

int main(void){
    int n;
    double p, r;
    int *node_u;//从记录自下而上的树
    vector<int> *node_d;//node_d，记录自上而下的树
    int head = 0;
    scanf("%d %lf %lf", &n, &p, &r);
    node_u = new int[n];
    node_d = new vector<int>[n];
    for(int i = 0; i < n; i++){
        scanf("%d", node_u + i);
        if(node_u[i] == -1){
            head = i;
        }
        else{
            node_d[node_u[i]].push_back(i);
        }
    }
    max_count(node_d, head, 1);
    printf("%.2lf %d\n", max_price(node_d, head, p, r), max_c);
    return 0;
}