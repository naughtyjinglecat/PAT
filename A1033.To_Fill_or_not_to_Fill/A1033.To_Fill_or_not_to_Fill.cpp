#include<cstdio>
#include<algorithm>

/*
这题的策略从一开始思路就出问题了，现阶段的我考试遇到了直接g，
本题0分,我是查找当前车子能抵达的油价最低的车站，而题解中选择的
是当车子能抵达的最便宜车站
*/

using namespace std;
typedef struct station{
    double price;
    int distance;
}station;

bool compare(station a, station b){
    return a.distance < b.distance;
}
/*车站列表，车站数量，当前车站，车子能跑的最远距离, 查询不到则返回-1*/
int findCheapest(station stations[], int total, int curStation, double maxdistance);

int main(void){
    int Cmax, d, dvag, n;
    station stations[505];
    int curStation = 0;
    double remain = 0;
    /*最远开车距离*/
    double maxdistance;
    double totalSpend = 0;
    int curLowest;
    scanf("%d %d %d %d", &Cmax, &d, &dvag, &n);
    maxdistance = Cmax*dvag;
    for(int i = 0; i < n; i++){
        scanf("%lf %d", &stations[i].price, &stations[i].distance);
    }
    sort(stations, stations + n, compare);
    /*启动汽车，开始花钱*/
    curStation = 0;
    remain = Cmax;
    totalSpend = (double)Cmax*stations[0].price;
    while(curStation < n - 1){
        /*如果车子现在的油量开不到目的地*/
        if(stations[curStation].distance + maxdistance < d){
            /*查询最近能开到的最便宜的加油站*/
            curLowest = findCheapest(stations, n, curStation, maxdistance);
            if(curLowest == -1){
                break;
            }
            /*开到那个加油站还剩的油量*/
            remain = (double)(stations[curLowest].distance - stations[curStation].distance)/(double)dvag;
            /*掏钱加油*/
            if(stations[curLowest].distance + maxdistance < d){
                /*如果到了最近的加油站之后如果加满油也开不到目的地，则加油加满*/
                totalSpend += ((double)Cmax - remain)*stations[curLowest].price;
            }
            /*如果开得到目的地，则只用加油加到恰好开到目的地为止*/
            else{
                totalSpend += stations[curLowest].price*(d - stations[curLowest].distance)/(double)dvag;
            }
            /*车子开到了最近的那个最便宜的加油站，在这里加油，当前车站更新了*/
            curStation = curLowest;
        }
        else{
            break;
        }
    }
    if(curLowest == -1){
        printf(" maximum travel distance = %.2lf\n", (double)(stations[curStation].distance + maxdistance));
    }
    else{
        printf("%.2lf\n", totalSpend);
    }
    return 0;
}

int findCheapest(station stations[], int total, int curStation, double maxdistance){
    int cheapest = curStation + 1;
    if(curStation + 1 >= total){
        return -1;
    }
    for(int i = curStation + 1; i < total && stations[curStation].distance + maxdistance >= stations[i].distance; i++){
        cheapest = (stations[i].price < stations[cheapest].price) ? i : cheapest;
    }
    return cheapest;
}