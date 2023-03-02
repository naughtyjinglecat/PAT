#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>

#define MAXSIZE 1005

using namespace std;

// typedef struct person{
//     int father;
//     vector<int> hobby;
// }person;

/*访问根节点获取这一爱好群体的人数*/
typedef struct hobby{
    int father;
    int numofperson;
    hobby(){
        father = -1;
        numofperson = 0;
    }
}hobby;

void unionn(hobby a, hobby b){
    
}
int findfather(hobby hobbies[], int a){
    while(hobbies[a].father != -1){
        a = hobbies[a].father;
    }
    return a;
}

bool cmp(int a, int b){
    return a > b;
}


int main(void){
    int n, k, h;
    int temp;
    vector<int> count;
    hobby hobbes[MAXSIZE];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d:", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &h);
            if(j == 0){
                temp = h;
            }
            else{
                unionn(hobbes[temp], hobbes[h]);
            }
        }
        hobbes[findfather(hobbes, temp)].numofperson++;
    }
    temp = 0;
    for(int i = 0; i < MAXSIZE; i++){
        if(hobbes[i].father == -1 && hobbes[i].numofperson > 0){
            temp++;
            count.push_back(hobbes[i].numofperson);
        }
    }
    sort(count.begin(), count.end(), cmp);
    printf("%d\n", temp);
    for(int i = 0; i < count.size(); i++)
    {
        if(i != count.size()-1){
            printf("%d ", count[i]);
        }
        else{
            printf("%d\n", count[i]);
        }
    }
    
    return 0;
}