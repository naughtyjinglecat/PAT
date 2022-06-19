#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

//不知道错哪里了，应该是一些边界条件出问题了，26分，满分应该是30分甚至35分


int curSum;//当前遍历求和
int n, k, p;
vector<int> ans_temp;
vector<int> ans;
int factor_final = 0;
vector<int> fac;

//index:扫描到第几个数字 cur_sum当前数字求和 count_taken已经记录的数字数量
void DFS(int index, int cur_sum, int factor_sum);

int main(void){

    int temp;
    scanf("%d %d %d", &n, &k, &p);
    //先准备因数缓存
    for(int i = 0; i <= n; i++){
        temp = (int)pow(i, p);
        if(temp < n){
            fac.push_back(temp);
        }
        else{
            break;
        }
    }
    DFS(fac.size()-1, 0, 0);
    printf("%d = ", n);
    for(int i = 0; i < ans.size(); i++){
        if(i == 0){
            printf("%d^%d", ans[i], p);
        }
        else{
            printf(" + %d^%d", ans[i], p);
        }
    }
    printf("\n");
    return 0;
}
//index表示当前指向的数字，cur_sum表示当前ans_temp中的数字之和，factor_sum表示当前ans_temp中因素的和
//index:扫描到第几个数字 cur_sum当前数字求和
void DFS(int index, int cur_sum, int factor_sum){
    //访问到最后一层了，则选择要不要采取这条路线的方案
    if(ans_temp.size() == k && cur_sum == n){
        if(factor_final < factor_sum){
            factor_final = factor_sum;
            ans = ans_temp;
        }
        return;
    }
    //如果存储的数值超过了目标n，则提前结束计算
    else if(cur_sum > n){
        return;
    }
    //访问不能越界
    if(index >= 1 && ans_temp.size() < k){
        //选了当前数字
        ans_temp.push_back(index);
        DFS(index, cur_sum + fac[index],factor_sum+index);
        //不选当前数字
        ans_temp.pop_back();
        DFS(index-1, cur_sum, factor_sum);
    }
}