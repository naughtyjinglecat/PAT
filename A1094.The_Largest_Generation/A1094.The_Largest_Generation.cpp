#include<cstdio>
#include<vector>
#include<string.h>
using namespace std;



/*这道题出现了新的问题，超越了题目本身，我定义了一个包含vector的结构体，然后通过new运算符
申请了内存空间，但是在使用delete释放内存空间时出现了异常，暂时不知道这种情况如何使用delete
释放空间
*/

/*又是不知道什么地方出现新的问题了，23分*/

typedef struct member{
    int count_child;
    vector<int> children;
    member(){
        count_child = 0;
        children.clear();
    }
}member;

void generationCount(member members[], int index, int level, int level_count[]){
    level_count[level] += members[index].children.size();
    for(int i = 0; i < members[index].children.size(); i++){
        generationCount(members, members[index].children[i], level+1, level_count);
    }
    members[index].children.clear();
}

int main(void){
    int n, m;
    member *members = NULL;
    int temp_index, temp;
    int head;
    int level_count[105];
    int max_level = 1;
    memset(level_count, 0, sizeof(level_count));
    scanf("%d %d", &n, &m);
    members = new member[n+1];
    for(int i = 0; i < m; i++){
        scanf("%d", &temp_index);
        scanf("%d", &members[temp_index].count_child);
        for(int j = 0; j < members[temp_index].count_child; j++){
            scanf("%d", &temp);
            members[temp_index].children.push_back(temp);
        }
    }
    generationCount(members, 1, 1, level_count);
    for(int i = 0; i < 105; i++){
        if(level_count[max_level] < level_count[i]){
            max_level = i;
        }
    }
    printf("%d %d\n", level_count[max_level], max_level+1);
    // delete(members);
    return 0;
}