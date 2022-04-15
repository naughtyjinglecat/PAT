#include<cstdio>
#include<string.h>


int main(void){
    int totalscore[1005];
    int n;
    int groupIndex;
    int individualIndex;
    int individualscore;
    int topGroupIndex = 1;
    int topGroupScore = 0;
    memset(totalscore, 0, sizeof(totalscore));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d-%d %d", &groupIndex, &individualIndex, &individualscore);
        totalscore[groupIndex] += individualscore;
    }
    for(int i = 1; i <=1000; i++){
        if(totalscore[i] > topGroupScore){
            topGroupScore = totalscore[i];
            topGroupIndex = i;
        }
    }
    printf("%d %d\n", topGroupIndex, topGroupScore);
    return 0;
}