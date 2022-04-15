#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
/*思路应该没问题，跑示例一把过，但是测试结果是答案错误，格式错误都有,18分*/
/*答案建议使用map的数据结构来处理这道题目，以后再订正吧*/

typedef struct record{
    char plate_num[8];
    char time[9];
    char status[4];
    bool iseffective;
    record(){
        iseffective = false;
    }
}record;

typedef struct car{
    char plate_num[8];
    int parkedtime;
}car;



/*对两条记录进行排序*/
bool compare(record a, record b);
int parkedtime(char* time_a, char* time_b);
bool compareCar(car a, car b);
int main(void){
    int n, k;
    int j;
    record records[10005];
    int curParkedTime;
    int maxParkedTime = 0;
    /*记录每一辆车出入之后校内车数*/
    int total[10005];
    /*记录当前校内有多少车辆*/
    int sum = 0;
    char query[80005][9];
    car cars[5002];
    /*还需要记录车的数量*/
    int carAmount = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s %s %s", records[i].plate_num, records[i].time, records[i].status);        
    }
    for(int i = 0; i < k; i++){
        scanf("%s", &query[i][0]);
    }
    /*先把所有记录按时间排好序*/
    sort(records, records + n, compare);
    /*剔除无效数据*/
    for(int i = 0; i < n; i++){
        /*假定当前车辆是有效的*/
        /*查找当前车辆下一次记录在哪里*/
        if(records[i].status[0] == 'i'){
            for(j = i + 1; j < n; j++){
                if(strcmp(records[i].plate_num, records[j].plate_num) == 0){
                    break;
                }
            }
            if(j < n && records[j].status[0] == 'o'){
                records[i].iseffective = true;
                records[j].iseffective = true;
                curParkedTime = parkedtime(records[i].time, records[j].time);
                cars[carAmount].parkedtime = curParkedTime;
                strcpy(cars[carAmount].plate_num, records[i].plate_num);
                carAmount++;
            }
        }
    }
    sort(cars, cars + carAmount, compareCar);
    memset(total, -1, sizeof(total));
    for(int i = 0; i < n; i++){
        if(records[i].iseffective == true){
            if(records[i].status[0] == 'i'){
                sum++;
                total[i] = sum;
            }
            else{
                sum--;
                total[i] = sum;
            }
        }
    }
    j = 0;
    for(int i = 0; i < k; i++){
        for(; j < n; j++){
            if(records[j].iseffective && strcmp(records[j].time, &query[i][0]) > 0){
                break;
            }
        }
        if(j < n){
            if(records[j].status[0] == 'i'){
                printf("%d\n", total[j] - 1);
            }
            else{
                printf("%d\n", total[j] + 1);
            }
        }
        else{
            printf("0\n");
        }
    }
    for(j = 1; j < carAmount; j++){
        if(cars[j].parkedtime != cars[j-1].parkedtime){
            break;
        }
    }
    while(j >= 0){
        printf("%s ", cars[j].plate_num);
        j--;
    }
    printf("%02d:%02d:%02d\n", cars[0].parkedtime/3600, cars[0].parkedtime%3600/60, cars[0].parkedtime%60);
    return 0;
}

bool compare(record a, record b){
    bool ans =false;
    if(strcmp(a.time, b.time) < 0){
        ans = true;
    }
    return ans;
}

int parkedtime(char* time_a, char* time_b){
    return ((time_b[0] - time_a[0])*10 + (time_b[1] - time_a[1]))*3600 + ((time_b[3] - time_a[3])*10 + (time_b[4] - time_a[4]))*60 + ((time_b[6] - time_a[6])*10 + (time_b[7] - time_a[7]));
}

bool compareCar(car a, car b){
    bool ans = false;
    if(a.parkedtime != b.parkedtime){
        ans = a.parkedtime > b.parkedtime;
    }
    else{
        if(strcmp(a.plate_num, b.plate_num) > 0){
            ans = true;
        }
    }
    return ans;
}