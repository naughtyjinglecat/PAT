#include<cstdio>
#include<string.h>
/*直接满分*/
int main(){
    int occuranceTime[10005];
    int n;
    int bet[100005];
    int winner = -1;
    scanf("%d", &n);
    memset(occuranceTime, 0, sizeof(occuranceTime));
    memset(bet, -1, sizeof(bet));
    for(int i = 0; i < n; i++){
        scanf("%d", bet + i);
        occuranceTime[bet[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(occuranceTime[bet[i]] == 1){
            winner = bet[i];
            break;
        }
    }
    if(winner != -1){
        printf("%d\n", winner);
    }
    else{
        printf("None\n");
    }
    return 0;
}