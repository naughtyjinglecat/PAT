/*修了三小时bug，我特喵的过了25分*/

#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;


typedef struct user_inf{
    int ID;
    int score[5];
    int total_score;
    int perfect;
    int rank;
    user_inf(){
        /* 初始化为负值，-2代表没有提交过 */
        fill(score, score + 5, -2);
        total_score = 0;
        perfect = 0;
    }
}user_inf;

int max_score[5];

bool compare(user_inf a, user_inf b);

int main(void){
    int N, K, M;
    user_inf list[10005];
    /*暂时缓存一下学号和题号*/
    int ID_temp, index_temp, score_temp;
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 0; i < K; i++){
        scanf("%d", max_score + i);
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &ID_temp, &index_temp, &score_temp);
        list[ID_temp - 1].ID = ID_temp;
        if(score_temp > list[ID_temp - 1].score[index_temp - 1]){
            list[ID_temp - 1].score[index_temp - 1] = score_temp;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            if(list[i].score[j] > 0){
                list[i].total_score += list[i].score[j];
            }
            if(list[i].score[j] == max_score[j]){
                list[i].perfect++;
            }
        }
    }
    sort(list, list + N, compare);
    list[0].rank = 1;
    for(int i = 1; i < N; i++){
        if(list[i].total_score == list[i - 1].total_score){
            list[i].rank = list[i - 1].rank;
        }
        else{
            list[i].rank = i + 1;
        }
    }
    for(int i = 0; i < N; i++){
        if(list[i].score[0] >= 0  || list[i].score[1] >= 0 || list[i].score[2] >= 0 || list[i].score[3] >= 0 || list[i].score[4] >= 0){
            printf("%d %05d %d",list[i].rank, list[i].ID, list[i].total_score);
            for(int j = 0; j < K; j++){
                if(list[i].score[j] == -2){
                    printf(" -");
                }
                else if(list[i].score[j] == -1){
                    printf(" 0");
                }
                else{
                    printf(" %d", list[i].score[j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}


bool compare(user_inf a, user_inf b){
    bool ans = false;
    if(a.total_score != b.total_score){
        ans = a.total_score > b.total_score;
    }
    else if(a.perfect != b.perfect){
        ans = a.perfect > b.perfect;
    }
    else{
        ans = a.ID < b.ID;
    }
    return ans;
}