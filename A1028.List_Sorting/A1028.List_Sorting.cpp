/*一次通过。。。奇迹 满分25，得分25*/

#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;


typedef struct record{
    int id;
    char name[9];
    int score;
}record;


bool compare_1(record a, record b);
bool compare_2(record a, record b);
bool compare_3(record a, record b);

int main(void){
    int n;
    char c;
    record list[100005];
    scanf("%d %c", &n, &c);
    for(int i = 0; i < n; i++){
        scanf("%d %s %d", &list[i].id, list[i].name, &list[i].score);
    }
    switch (c){
    case '1':
        sort(list, list + n, compare_1);
        break;
    case '2':
        sort(list, list + n, compare_2);
        break;
    case '3':
        sort(list, list + n, compare_3);
        break;    
    default:
        break;
    }
    for(int i = 0; i < n; i++){
        printf("%06d %s %d\n", list[i].id, list[i].name, list[i].score);
    }
    return 0;
}

bool compare_1(record a, record b){
    return a.id < b.id;
}
bool compare_2(record a, record b){
    bool ans = false;
    int temp = strcmp(a.name, b.name);
    if(temp < 0){
        ans = true;
    }
    else if(temp == 0){
        ans = (a.id < b.id);
    }
    return ans;
}

bool compare_3(record a, record b){
    bool ans = false;
    if(a.score < b.score){
        ans = true;
    }
    else if(a.score == b.score){
        ans = (a.id < b.id);
    }
    return ans;
}