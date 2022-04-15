/*感天动地，25分，数组范围不能定义太大，不然无法运行程序*/

#include<cstdio>
#include<algorithm>
#include<stdlib.h>
using namespace std;

typedef struct student{
    int ID;
    int GE;
    int G1;
    int prefer[5];
    int rank;
    int total;
}student;

typedef struct college{
    /*打算录取人数*/
    int quota;
    /*实际录取人数*/
    int rolled;
    int admision[40005];
    int lastRank;
    college(){
        rolled = 0;
    }
}college;

bool compare(student a, student b);
int compareID(int a, int b){
    return a < b;
}

int main(void){
    int n, m, k;
    college *list = NULL;
    student applicants[40005];
    int cur_apply;//当前试图申请的学校编号
    scanf("%d %d %d", &n, &m, &k);
    list = (college*)malloc(sizeof(college)*m);
    for(int i = 0; i < m; i++){
        scanf("%d", &list[i].quota);
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &applicants[i].GE, &applicants[i].G1);
        applicants[i].total = applicants[i].GE + applicants[i].G1;
        applicants[i].ID = i;
        for(int j = 0; j < k; j++){
            scanf("%d", &applicants[i].prefer[j]);
        }
    }
    sort(applicants, applicants + n, compare);
    applicants[0].rank = 1;
    for(int i = 1; i < n; i++){
        if(applicants[i].total == applicants[i - 1].total && applicants[i].GE == applicants[i - 1].GE){
            applicants[i].rank = applicants[i - 1].rank;
        }
        else{
            applicants[i].rank = i + 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cur_apply = applicants[i].prefer[j];
            if(list[cur_apply].rolled < list[cur_apply].quota){
                list[cur_apply].admision[list[cur_apply].rolled] = applicants[i].ID;
                list[cur_apply].rolled++;
                list[cur_apply].lastRank = applicants[i].rank;
                break;
            }
            else if(list[cur_apply].rolled != 0 && list[cur_apply].lastRank == applicants[i].rank){
                list[cur_apply].admision[list[cur_apply].rolled] = applicants[i].ID;
                list[cur_apply].rolled++;
                list[cur_apply].lastRank = applicants[i].rank;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        sort(list[i].admision, list[i].admision + list[i].rolled, compareID);
        for(int j = 0; j < list[i].rolled; j++){
            printf("%d", list[i].admision[j]);
            if(j != list[i].rolled - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

bool compare(student a, student b){
    bool ans = false;
    if(a.total != b.total){
        ans = a.total > b.total;
    }
    else if(a.GE != b.GE){
        ans = a.GE > b.GE;
    }
    return ans;
}