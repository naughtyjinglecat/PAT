#include<cstdio>

typedef struct inf_inout
{
    char ID_num[16];
    int in_hour;
    int in_min;
    int in_sec;
    int out_hour;
    int out_min;
    int out_sec;
}inf_inout;

/*a比b早到，则输出true，否则输出false*/
bool early(inf_inout a, inf_inout b);
/*a比b晚离开，则输出true，否则输出false*/
bool later(inf_inout a, inf_inout b);

int main(void){
    inf_inout unlock;
    inf_inout lock;
    inf_inout temp;
    int num = 0;
    int i = 0;
    scanf("%d", &num);
    scanf("%s %d:%d:%d %d:%d:%d", &(temp.ID_num[0]), &(temp.in_hour), &(temp.in_min), &(temp.in_sec), &temp.out_hour, &temp.out_min, &temp.out_sec);
    /* 到目前记录为止，开锁的人是这个人，上锁的也是这个人 */
    unlock = temp;
    lock = temp;
    for(i = 0; i < num - 1; i++){
        scanf("%s %d:%d:%d %d:%d:%d", &(temp.ID_num[0]), &(temp.in_hour), &(temp.in_min), &(temp.in_sec), &temp.out_hour, &temp.out_min, &temp.out_sec);
        unlock = (early(unlock, temp)) ? unlock : temp;
        lock = (later(lock, temp)) ? lock : temp;
    }
    printf("%s %s\n", unlock.ID_num, lock.ID_num);
    return 0;
}

bool early(inf_inout a, inf_inout b){
    bool ans = false;
    if(a.in_hour < b.in_hour){
        ans = true;
    }
    else if(a.in_hour == b.in_hour && a.in_min < b.in_min){
        ans = true;
    }
    else if(a.in_hour == b.in_hour && a.in_min == b.in_min && a.in_sec < b.in_sec){
        ans = true;
    }
    return ans;
}

bool later(inf_inout a, inf_inout b){
    bool ans = false;
    if(a.out_hour > b.out_hour){
        ans = true;
    }
    else if(a.out_hour == b.out_hour && a.out_min > b.out_min){
        ans = true;
    }
    else if(a.out_hour == b.out_hour && a.out_min == b.out_min && a.out_sec > b.out_sec){
        ans = true;
    }
    return ans;
}