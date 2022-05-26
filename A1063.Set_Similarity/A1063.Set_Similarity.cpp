#include<cstdio>
#include<set>
using namespace std;

/*全部纯纯的用set会超时，应该在计算相同元素和不同元素个数时使用更简单的算法，set的插入应该时是一件比较费时间的事情
21分，最后一一组超时
*/


/*计算set a，b共有不同元素个数的总数*/
int totalCount(set<int> a, set<int> b);
/*计算set a，b相同元素个数的总数*/
int sameCount(set<int> a, set<int> b);
int main(){
    int n, n2;
    int temp;
    /*待查询的两组数据*/
    int index1, index2;
    /*记录一共有多少不同的元素，多少相同的元素*/
    int t, s;
    set<int> sets[55];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &n2);
        for(int j = 0; j < n2; j++){
            scanf("%d", &temp);
            sets[i].insert(temp);
        }
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &index1, &index2);
        t = totalCount(sets[index1 - 1], sets[index2 - 1]);
        s = sameCount(sets[index1 - 1], sets[index2 - 1]);
        printf("%.1lf%\n", (double)s*100/(double)t);
    }
    return 0;
}

/*计算set a，b共有不同元素个数的总数*/
int totalCount(set<int> a, set<int> b){
    set<int> temp;
    for(set<int>::iterator it = a.begin(); it != a.end(); it++){
        temp.insert(*it);
    }
    for(set<int>::iterator it = b.begin(); it != b.end(); it++){
        temp.insert(*it);
    }
    return temp.size();
}

/*计算set a，b相同元素个数的总数*/
int sameCount(set<int> a, set<int> b){
    set<int> temp;
    for(set<int>::iterator it = a.begin(); it != a.end(); it++){
        temp.insert(*it);
    }
    for(set<int>::iterator it = b.begin(); it != b.end(); it++){
        temp.insert(*it);
    }
    return a.size() + b.size() - temp.size();
}