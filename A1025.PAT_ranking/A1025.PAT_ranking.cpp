/*满分通关，25分*/

#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct ccase{
    char reg_num[14];
    int score;
    int local_num;
    int final_rank;
    int local_rank;
}ccase;

bool campare(ccase a, ccase b){
    bool ans = false;
    if(a.score > b.score){
        ans = true;
    }
    else if(a.score == b.score && strcmp(a.reg_num, b.reg_num) < 0){
        ans = true;
    }
    return ans;
}
/*在[start, end)之间填入他们的局部排名*/
void rank_local(ccase *start, ccase *end);

/*在[start, end)之间填入他们的最终排名*/
void rank_final(ccase *start, ccase *end);

int main(void){
    int k;
    int n;
    int j = 0;
    int count = 0;//已经录入了多少个
    ccase test[30005];
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &n);
        for(j = count; j < count + n; j++){
            scanf("%s %d", test[j].reg_num, &test[j].score);
            test[j].local_num = i + 1;
        }
        sort(test + j - n, test + j, campare);
        rank_local(test + j - n, test + j);
        count += n;
    }
    sort(test, test + count, campare);
    rank_final(test, test + count);
    printf("%d\n",count);
    for(int i = 0; i < count; i++){
        printf("%s %d %d %d\n", test[i].reg_num, test[i].final_rank, test[i].local_num, test[i].local_rank);
    }
    return 0;
}

void rank_local(ccase *start, ccase *end){
    int i = 1;
    ccase *p = start, *pre =NULL;
    p->local_rank = 1;
    pre = p;
    p++;
    while(p != end){
        i++;
        if(p->score == pre->score){
            p->local_rank = pre->local_rank;
        }
        else{
            p->local_rank = i;
        }
        pre = p;
        p++;
    }
}

void rank_final(ccase *start, ccase *end){
    int i = 1;
    ccase *p = start, *pre =NULL;
    p->final_rank = 1;
    pre = p;
    p++;
    while(p != end){
        i++;
        if(p->score == pre->score){
            p->final_rank = pre->final_rank;
        }
        else{
            p->final_rank = i;
        }
        pre = p;
        p++;
    }
}