#include<cstdio>
#include<vector>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
using namespace std;

/*25分，关键是设置公用的数组去储存名单*/

char **list;

bool compare(int a, int b){
    int i = strcmp(list[a], list[b]);
    return i < 0;
}


int main(void){
    int n,k;
    int count = 0;//记录当前学生的课程数量
    int index;//记录当前课程的索引号
    vector<int> courses[2505];
    
    scanf("%d %d", &n, &k);
    list = (char**)malloc(sizeof(char*)*n);
    for(int i = 0; i < n; i++){
        list[i] = (char*)malloc(sizeof(char)*5);
        scanf("%s %d", list[i], &count);
        for(int j = 0; j < count; j++){
            scanf("%d", &index);
            courses[index].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++){
        printf("%d %lld\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), compare);
        for(int j = 0; (long long unsigned)j < courses[i].size(); j++){
            printf("%s\n", list[courses[i][j]]);
        }
    }
    return 0;
}