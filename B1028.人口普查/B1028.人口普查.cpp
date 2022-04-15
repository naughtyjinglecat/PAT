/*细节需要处理好，尤其是数据的初始化，一定要是有效数据初始化才能尽可能的避免错误*/

#include<cstdio>

typedef struct resident{
    char name[6];
    int year;
    int month;
    int day;
    resident(int _year, int _month, int _day){
        year = _year;
        month = _month;
        day = _day;
    }
    resident(){
    }
}resident;

bool age_reasonable(resident a);
bool age_older(resident a, resident b);

int main(void){
    resident oldest(2014, 9, 6);
    resident youngest(2014-200, 9, 6);
    resident temp;
    int sum = 0;
    int count = 0;
    int sign = 1;
    scanf("%d", &count);
    sum = count;
    /*下面两行初始化的时候可能导致oldest和youngest中是一个不合理数据导致后续比较出现问题*/
    for(int i = 0; i < count; i++){
        scanf("%s %d/%d/%d", &(temp.name[0]), &(temp.year), &(temp.month), &(temp.day));
        if(!age_reasonable(temp)){
            sum--;
        }
        else{
            if(sign == 1){
                oldest = temp;
                youngest = temp;
                sign = 0;
            }
            oldest = (age_older(oldest, temp)) ? oldest : temp;
            youngest = (age_older(youngest, temp)) ? temp : youngest;
        }
    }
    if(sum == 0){
        printf("0\n");
    }
    else{
        printf("%d %s %s\n", sum, oldest.name, youngest.name);
    }
    return 0;
}
/*输入的这个人的信息是否合法*/
bool age_reasonable(resident a){
    bool ans = true;
    if(a.year > 2014){
        ans = false;
    }
    else if(a.year == 2014 && a.month > 9){
        ans = false;
    }
    else if(a.year == 2014 && a.month == 9 && a.day > 6){
        ans = false;
    }
    else if(a.year < 2014 - 200){
        ans = false;
    }
    else if(a.year == 2014 -200 && a.month < 9){
        ans = false;
    }
    else if(a.year == 2014 -200 && a.month == 9 && a.day < 6){
        ans = false;
    }
    return ans;
}
/*比年龄谁大，a大则true，b大则false*/
bool age_older(resident a, resident b){
    bool ans = true;
    if(a.year > b.year){
        ans = false;
    }
    else if(a.year == b.year && a.month > b.month){
        ans = false;
    }
    else if(a.year == b.year && a.month == b.month && a.day > b.day){
        ans = false;
    }
    return ans;
}