#include<cstdio>
#include<stdlib.h>
#include<math.h>


//答案全对，还有一件事就是要释放空间
/*25分，就是深度遍历一遍就好，可以一遍遍历一遍释放空间*/

typedef struct supplier{
    int k;
    int *receives;
    supplier(){
        k = 0;
        receives = NULL;
    }
}supplier;

int min_level;
int min_level_count = 0;

//深度优先搜索整棵树，
void DFS(supplier suppliers[], int index, int level){
    if(suppliers[index].k == 0){
        if(min_level > level){
            min_level = level;
            min_level_count = 1;
        }
        else if(min_level == level){
            min_level_count++;
        }
    }
    else{
        for(int i = 0; i < suppliers[index].k; i++){
            DFS(suppliers, suppliers[index].receives[i], level+1);
        }
        free(suppliers[index].receives);
    }
}

int main(void){
    int n;
    double p, r;
    supplier *suppliers;
    scanf("%d %lf %lf", &n, &p, &r);
    suppliers = new supplier[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &suppliers[i].k);
        if(suppliers[i].k != 0){
            suppliers[i].receives = (int*)malloc(sizeof(int)*suppliers[i].k);
        }
        for(int j = 0; j < suppliers[i].k; j++){
            scanf("%d", &suppliers[i].receives[j]);
        }
    }
    min_level = n+1;
    DFS(suppliers, 0, 0);
    delete(suppliers);
    printf("%.4lf %d\n", p*pow(1+0.01*r, min_level), min_level_count);
    return 0;
}