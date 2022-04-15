/*完美运行*/

#include<cstdio>
#include<string.h>

typedef struct grade_inf
{
    char name[11];
    char sex;
    char ID[11];
    int grade;
    grade_inf(){
        sex = 'Q';
    }
}grade_inf;


int main(void){
    int n = 0;
    grade_inf highest_girl;
    grade_inf lowest_boy;
    grade_inf temp;
    highest_girl.grade = 0;
    lowest_boy.grade = 100;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %c %s %d", temp.name, &temp.sex, temp.ID, &temp.grade);
        if(temp.sex == 'F'){
            highest_girl = (highest_girl.grade > temp.grade) ? highest_girl : temp;
        }
        else{
            lowest_boy = (lowest_boy.grade < temp.grade) ? lowest_boy : temp;
        }
    }
    if(highest_girl.sex == 'Q'){
        printf("Absent\n");
    }
    else{
        printf("%s %s\n", highest_girl.name, highest_girl.ID);
    }
    if(lowest_boy.sex == 'Q'){
        printf("Absent\n");
    }
    else{
        printf("%s %s\n", lowest_boy.name, lowest_boy.ID);
    }
    if(highest_girl.sex == 'Q' || lowest_boy.sex == 'Q'){
        printf("NA\n");
    }
    else{
        printf("%d\n", highest_girl.grade - lowest_boy.grade);
    }
    return 0;
}