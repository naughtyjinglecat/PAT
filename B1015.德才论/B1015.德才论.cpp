/*麻了。。。应该是满分。。。*/

#include<cstdio>
#include<algorithm>
using namespace std;

typedef struct inf{
    int IDnum;
    int moral;//德分
    int intel;//才分
    char tag;
}inf;



bool compare(inf a, inf b);
bool compareSametag(inf a, inf b);

int main(void){
    int n, low, high;
    int i = 0, j = 0;;
    inf kaosheng[100005];
    inf temp;
    scanf("%d %d %d", &n, &low, &high);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &temp.IDnum, &temp.moral, &temp.intel);
        if(temp.intel >= high && temp.moral >= high){
            temp.tag = 'A';
        }
        else if(temp.intel >= low && temp.moral >= high){
            temp.tag = 'B';
        }
        else if(temp.intel >= low && temp.moral >= low && temp.moral >= temp.intel){
            temp.tag = 'C';
        }
        else if(temp.intel >= low && temp.moral >= low){
            temp.tag = 'D';
        }
        else{
            temp.tag = 'E';
        }
        if(temp.tag != 'E'){
            kaosheng[j] = temp;
            j++;
        }
    }
    sort(kaosheng, kaosheng + j, compare);
    printf("%d\n", j);
    for(i = 0; i < j; i++){
        printf("%d %d %d\n", kaosheng[i].IDnum, kaosheng[i].moral, kaosheng[i].intel);
    }
    return 0;
}

bool compare(inf a, inf b){
    bool ans = false;
    if(a.tag < b.tag){
        ans = true;
    }
    else if(a.tag == b.tag){
        ans = compareSametag(a, b);
    }
    return ans;
}

bool compareSametag(inf a, inf b){
    bool ans = false;
    if(a.intel + a.moral > b.intel + b.moral){
        ans = true;
    }
    else if(a.intel + a.moral == b.intel + b.moral && a.moral > b.moral){
        ans = true;
    }
    else if (a.intel + a.moral == b.intel + b.moral &&a.moral == b.moral && a.IDnum < b.IDnum){
        ans = true;
    }
    return ans;
}