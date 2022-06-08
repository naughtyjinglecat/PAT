#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<vector>
using namespace std;

//笑死，根本解不出来，哈哈哈哈

typedef struct mouse{
    int wight;
    int rank;
}mouse;

int main(void){
    int np, ng;
    int temp;
    int k = 0, j = 0;
    int countInGame;
    int maybeCurwinner;
    int numInthisTurn;
    mouse mice[11];
    queue<int> orderInGame;
    scanf("%d %d", &np, &ng);
    // mice = (mouse*)malloc(sizeof(mouse)*np);
    for(int i = 0; i < np; i++){
        scanf("%d", &mice[i].wight);
        mice[i].rank = 1;
    }
    for(int i = 0; i < np; i++){
        scanf("%d", &temp);
        orderInGame.push(temp);
    }
    countInGame = np;
    numInthisTurn = np;
    while(countInGame != 1){
        //每小组比赛假定第一只老鼠可能获胜
        if(k%ng == 0){
            maybeCurwinner = orderInGame.front();
            orderInGame.pop();
            countInGame--;
            // continue;
        }
        //依次比较得出那一组最重的老鼠
        else if(k%ng != ng-1){
            if(mice[maybeCurwinner].wight < mice[orderInGame.front()].wight){
                maybeCurwinner = orderInGame.front();
            }
            orderInGame.pop();
            countInGame--;
        }
        //在比较这一组的最后一个成员的时候，除了要比较之外，还要把这个最重的成员拉回队列中去参与下一轮比较
        else{
            if(mice[maybeCurwinner].wight < mice[orderInGame.front()].wight){
                maybeCurwinner = orderInGame.front();
            }
            orderInGame.pop();
            countInGame--;
            orderInGame.push(maybeCurwinner);
            countInGame++;
        }
        //如果不巧最后一组没有足够数量的成员，那么需要提前处理该组最后一个成员
        if(k == numInthisTurn - 1 && k%ng != ng - 1){
            orderInGame.push(maybeCurwinner);
            countInGame++;
        }
        //下一轮比赛开始之前刷新一些工具参数
        if(k == numInthisTurn - 1){
            //晋级下一轮游戏的全部升级
            for(int j = 0; j < orderInGame.size(); j++){
                temp = orderInGame.front();
                orderInGame.pop();
                mice[temp].rank++;
                orderInGame.push(temp);
            }
            k = 0;
            numInthisTurn = orderInGame.size();
            continue;
        }
        k++;
    }
    for(int i = 0; i < np; i++){
        if(i != np - 1){
            printf("%d ", mice[i].rank);
        }
        else{
            printf("%d\n", mice[i].rank);
        }
    }
    // free(mice);
    return 0;
}