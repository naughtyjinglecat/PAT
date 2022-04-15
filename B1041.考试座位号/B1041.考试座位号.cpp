#include<cstdio>
#include<string.h>
typedef struct inf_stu{
    char zkzh[16];
    int shiji;
    int kaoshi;
}inf_stu;

int main(void){
    inf_stu stu[1000];
    int n = 0;
    int m = 0;
    int chaxun = -1;
    memset(stu, 0, sizeof(stu));
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 16; j++){
            scanf("%c", &(stu[i].zkzh[j]));
        }
        scanf("%d", &(stu[i].shiji));
        scanf("%d", &(stu[i].kaoshi));
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &chaxun);
        for(int j = 0; j < 1000; j++){
            if(stu[j].shiji == chaxun){
                for(int k = 0; k < 16; k++){
                    printf("%c", (stu[j].zkzh[k]));
                }
                printf(" %d\n", stu[j].kaoshi);
                break;
            }
        }
    }
    return 0;
}