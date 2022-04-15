#include<cstdio>
#include<algorithm>
using namespace std;
/*这个做法，直接用数组下标作为排名，会导致排名相同的名次不能正常输出，应该单独记录排名，或者查找正确的排名*/


typedef struct stu_inf{
    int id_num;//学号
    int credit;//分数
}stu_inf;

bool compare(stu_inf a, stu_inf b);
int consult(stu_inf[], int n, int id);//返回改学号的排名
int min(int a, int b);


int main(void){
    stu_inf c[2000];
    stu_inf m[2000];
    stu_inf e[2000];
    stu_inf a[2000];
    int i = 0, j = 0;
    int n, M;
    int temp_id;
    int highest = 2005;//排名最高的名次
    char hignest_sub;//排名最高的科目
    scanf("%d %d", &n, &M);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &a[i].id_num, &c[i].credit, &m[i].credit, &e[i].credit);
        c[i].id_num = a[i].id_num;
        m[i].id_num = a[i].id_num;
        e[i].id_num = a[i].id_num;
        a[i].credit = c[i].credit + m[i].credit + e[i].credit;
    }
    sort(c, c + n, compare);
    sort(a, a + n, compare);
    sort(e, e + n, compare);
    sort(m, m + n, compare);
    for(i = 0; i < M; i++){
        scanf("%d", &temp_id);
        for(j = 0; j < n; j++){
            if(a[j].id_num == temp_id){
                highest = j + 1;
                hignest_sub = 'A';
                break;
            }
        }
        if(j == n){
            printf("N/A\n");
            continue;
        }
        for(j = 0; j < n; j++){
            if(c[j].id_num == temp_id){
                if(highest > j + 1){
                    highest = j + 1;
                    hignest_sub = 'C';
                    break;
                }
            }
        }
        for(j = 0; j < n; j++){
            if(m[j].id_num == temp_id){
                if(highest > j + 1){
                    highest = j + 1;
                    hignest_sub = 'M';
                    break;
                }
            }
        }
        for(j = 0; j < n; j++){
            if(e[j].id_num == temp_id){
                if(highest > j + 1){
                    highest = j + 1;
                    hignest_sub = 'E';
                    break;
                }
            }
        }
        printf("%d %c\n", highest, hignest_sub);
    }
    return 0;
}
bool compare(stu_inf a, stu_inf b){
    return a.credit > b.credit;
}