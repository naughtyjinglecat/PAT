/*有一组测试没有通过，也许是越界，也许是特殊情况没有考虑到，得分22分，满分25*/

#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int rate[24];

typedef struct call_inf{
    char name[21];
    int time[4];
    bool sign;
}call_inf;

typedef struct username{
    char name[21];
}username;

/*比较名字谁先谁后*/
bool nameCompare(username a, username b);
/*比较时间谁先谁后*/
bool timeCompare(call_inf a, call_inf b);
/* 检查名字是否出现在名单中，若有名字不在名单中，则返回true，若出现在名单中，则返回false*/
bool checkname(char name[], username namelist[], int list_length);
/*计算这通电话时间花费*/
int timespend(int a[], int b[]);
/*计算这通电话金钱花费*/
double moneyspend(int a[], int b[]);
int main(void){
    username nameList[1005];
    int list_length = 0;
    int n = 0;
    int i;
    char temp[9];
    double cur_time, cur_fee;
    double sum = 0;
    bool sign = true;
    bool tag = true;
    int *time_a, *time_b;
    call_inf record[1005];
    for(i = 0; i < 24; i++){
        scanf("%d", rate + i);
    }
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %d:%d:%d:%d %s", record[i].name, record[i].time, record[i].time + 1, record[i].time + 2, record[i].time + 3, temp);
        if(temp[1] == 'n'){
            record[i].sign = true;
        }
        else{
            record[i].sign = false;
        }
        if(checkname(record[i].name, nameList, list_length)){
            strcpy(nameList[list_length].name, record[i].name);
            list_length++;
        }
    }
    sort(nameList, nameList + list_length, nameCompare);
    sort(record, record + n, timeCompare);
    for(i = 0; i < list_length; i++){
        /*true查找online，false表示查找offline*/
        /*初始化假装上一次记录的是offline*/
        sign = false;
        for(int j = 0; j < n; j++){
            if(strcmp(nameList[i].name, record[j].name) == 0){
                if(sign == false){
                    if(record[j].sign == true){
                        time_a = record[j].time;
                        sign = true;
                    }

                }
                else{
                    if(record[j].sign == true){
                        time_a = record[j].time;
                        sign = true;
                    }
                    else{
                        time_b = record[j].time;
                        sign = false;
                        cur_time = timespend(time_a, time_b);
                        cur_fee = moneyspend(time_a, time_b);
                        sum += cur_fee;
                        if(tag == true){
                            printf("%s %02d\n", nameList[i].name, record[0].time[0]);
                            tag = false;
                        }
                        printf("%02d:%02d:%02d ", time_a[1], time_a[2], time_a[3]);
                        printf("%02d:%02d:%02d %.0lf $%.2lf\n", time_b[1], time_b[2], time_b[3], cur_time, (double)cur_fee/100);
                    }
                }
            }
        }
        if(tag == false){
            printf("Total amount: $%.2lf\n", sum/100);
        }
        
        sum = 0;
        tag = true;
    }
    return 0;
}

bool checkname(char name[], username namelist[], int list_length){
    bool ans = true;
    int i = 0;
    for(i = 0; i < list_length; i++){
        if(strcmp(name, namelist[i].name) == 0){
            ans = false;
            break;
        }
    }
    return ans;
}
/*比较名字谁先谁后*/
bool nameCompare(username a, username b){
    bool ans = false;
    int i = strcmp(a.name, b.name);
    if(i < 0){
        ans = true;
    }
    return ans;
}

/*比较时间谁先谁后*/
bool timeCompare(call_inf a, call_inf b){
    bool ans = false;
    if(a.time[1] < b.time[1]){
        ans = true;
    }
    else if(a.time[1] == b.time[1] && a.time[2] < b.time[2]){
        ans = true;
    }
    else if(a.time[1] == b.time[1] && a.time[2] == b.time[2] && a.time[3] < b.time[3]){
        ans = true;
    }
    return ans;
}

/*计算这通电话时间花费*/
int timespend(int a[], int b[]){
    int day = b[1] - a[1], hour = b[2] - a[2], min = b[3] - a[3];
    return min + hour*60 + day*60*24;
}

/*计算这通电话金钱花费*/
double moneyspend(int a[], int b[]){
    double sum = 0;
    double temp = 0;
    if(a[1] == b[1]){
        sum = (60 - a[3])*rate[a[2]] + b[3]*rate[b[2]];
        for(int i = a[2]+1; i <= b[2] - 1; i++){
            sum += rate[i]*60;
        }
    }
    else{
        for(int i = 0; i < 24; i++){
            temp += 60*rate[i];
        }
        for(int i = a[2]+1; i < 24; i++){
            sum += rate[i]*60;
        }
        sum += (60 - a[3])*rate[a[2]] + b[3]*rate[b[2]];
        for(int i = 0; i < b[2]; i++){
            sum += rate[i]*60;
        }
        sum += (b[1] - a[1] - 1)*temp;
    }
    return sum;
}