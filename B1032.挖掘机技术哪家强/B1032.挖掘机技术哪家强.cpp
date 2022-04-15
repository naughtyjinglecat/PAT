#include<cstdio>
#include<string.h>


int main(void){
    int competitor[100001];
    int sum = 0;
    int num_temp = -1, score_temp = -1;
    int num_max = 0, score_max = 0;
    memset(competitor, -1, sizeof(competitor));
    scanf("%d", &sum);
    for(int i = 0; i < sum; i++){
        scanf("%d %d", &num_temp, &score_temp);
        if(competitor[num_temp] == -1){
            competitor[num_temp] = 0;
        }
        competitor[num_temp] +=score_temp;
    }
    score_max = competitor[0];
    for(int i = 1; i < 100001 && competitor[i] != -1; i++){
        if(competitor[i] > score_max){
            num_max = i;
            score_max = competitor[i];
        }
    }
    printf("%d %d\n", num_max, score_max);
    return 0;
}