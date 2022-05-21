#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/*重点是字符串转化为hash值*/

/*将名字字符串转化为数字*/
int transform(char name[]);

int main(void){
    int n, k;
    int index, ni;
    char name[5];
    int num;//记录名字对应的哈希数值
    vector<int> list[26*26*26*10+1];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d", &index, &ni);
        for(int j = 0; j < ni; j++){
            scanf("%s", name);
            num = transform(name);
            list[num].push_back(index);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%s", name);
        num = transform(name);
        sort(list[num].begin(), list[num].end());
        printf("%s %lld", name, list[num].size());
        for(vector<int>::iterator it = list[num].begin(); it != list[num].end(); it++){
            printf(" %d", *it);
        }
        printf("\n");
    }
    return 0;
}

/*将名字字符串转化为数字*/
int transform(char name[]){
    int num = 0;
    for(int i = 0; i < 3; i++){
        num = num*26 + (name[i] - 'A');
    }
    num = num*10 + (name[3] - '0');
    return num;
}