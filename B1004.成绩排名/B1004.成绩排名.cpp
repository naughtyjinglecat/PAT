#include<stdio.h>

typedef struct stu_inf{
    char name[11];
    char ID_num[11];
    int score;
}stu_inf;

int main(void){
    int n = -1;
    stu_inf temp, first, last;
    scanf("%d", &n);
    scanf("%s%s%d", &(temp.name[0]), &(temp.ID_num[0]), &(temp.score));
    first = temp;
    last = temp;
    for(int i = 0; i < n - 1; i++){
        scanf("%s%s%d", &(temp.name[0]), &(temp.ID_num[0]), &(temp.score));
        if(temp.score > first.score){
            first = temp;
        }
        else if(temp.score < last.score){
            last = temp;
        }
    }
    printf("%s %s\n%s %s\n", first.name, first.ID_num, last.name, last.ID_num);
    return 0;
}