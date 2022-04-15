/*运行超时+解答错误， 21分，满分25*/
/*应该采取空间换时间的策略，对每个年龄段前一百名富豪对数组进行预处理，否则不断反复排序，一定会超时*/

#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct billionairy{
    char name[9];
    int age;
    int wealth;
}billionairy;

/*比较两个富豪的年龄大小*/
bool compare_age(billionairy a, billionairy b);
/*比较两个富豪的财富*/
bool compare_wealth(billionairy a, billionairy b);

int main(void){
    int n, k, m, min, max;
    billionairy billionairies[100005];
    billionairy *amin = NULL, *amax = NULL;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", billionairies[i].name, &billionairies[i].age, &billionairies[i].wealth);
    }
    sort(billionairies, billionairies + n, compare_age);
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &m, &min, &max);
        amin = billionairies;
        while(amin->age < min){
            amin++;
        }
        amax = amin;
        while(amax->age <=max){
            amax++;
        }
        if(amin == amax || amin->age > max){
            printf("Case #%d:\nNone\n", i + 1);
        }
        else{
            sort(amin, amax, compare_wealth);
            printf("Case #%d:\n", i + 1);
            for(int x = 0; x < m && (amin + x)->age <= max; x++){
                printf("%s %d %d\n", (amin + x)->name, (amin + x)->age, (amin + x)->wealth);
            }
            sort(amin, amax, compare_age);
        }
    }
    return 0;
}

bool compare_age(billionairy a, billionairy b){
    bool ans = false;
    if(a.age < b.age){
        ans = true;
    }
    else if(a.age == b.age && strcmp(a.name, b.name) < 0){
        ans = true;
    }
    return ans;
}

bool compare_wealth(billionairy a, billionairy b){
    bool ans = false;
    if(a.wealth > b.wealth){
        ans = true;
    }
    else if(a.wealth == b.wealth && a.age < b.age){
        ans = true;
    }
    else if(a.wealth == b.wealth && a.age == b.age && strcmp(a.name, b.name) < 0){
        ans = true;
    }
    return ans;
}