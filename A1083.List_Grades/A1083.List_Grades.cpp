/* 拿到满分了，25分，但是写代码加调试用时40分钟有点长了 */

#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct stu{
    char name[11];
    char id[11];
    int grade;
}stu;

bool compare(stu a, stu b){
    return a.grade > b.grade;
}

int main(void){
    int n;
    stu *list = NULL;
    int grade_1, grade_2;
    stu *front = NULL, *rear = NULL;
    scanf("%d", &n);
    list = (stu*)malloc(sizeof(stu)*n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", list[i].name, list[i].id, &list[i].grade);
    }
    scanf("%d %d", &grade_1, &grade_2);
    sort(list, list + n, compare);
    front = list;
    while(front->grade > grade_2 && front != list + n){
        front++;
    }
    rear = front;
    while(rear->grade >= grade_1 && rear != list + n){
        rear++;
    }
    if(front == rear){
        printf("NONE\n");
    }
    else{
        while(front != rear){
            printf("%s %s\n", front->name, front->id);
            front++;
        }
    }
    return 0;
}