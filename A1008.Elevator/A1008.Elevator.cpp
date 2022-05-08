#include<cstdio>

/*看清题目就好，其实不太难，20分满分*/


int main(void){
    int n;
    /*记录当前楼层和目标楼层*/
    int curFloor = 0;
    int destFloor;
    int totalTime = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        /*现在我要去某某楼层*/
        scanf("%d", &destFloor);
        /*正在前往ing……*/
        if(destFloor > curFloor){
            /*若是向上走，则每层花费六秒，否则花费四秒*/
            totalTime += (destFloor - curFloor)*6;
        }
        else{
            totalTime += (curFloor - destFloor)*4;
        }
        /*到达了目标楼层*/
        curFloor = destFloor;
        /*还要停留五秒*/
        totalTime += 5;
    }
    printf("%d\n", totalTime);
    return 0;
}