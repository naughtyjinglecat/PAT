#include<cstdio>
#include<map>
#include<cstdio>
using namespace std;

int main(void){
    int m, n, temp;
    int dominant = -1;
    map<int, int> mp;
    mp[-1] = 0;
    scanf("%d %d", &m, &n);
    for(int i= 0; i < m*n; i++){
        scanf("%d", &temp);
        if(mp.find(temp) == mp.end()){
            mp[temp] = 0;
        }
        mp[temp]++;
        dominant = (mp[dominant] > mp[temp]) ? dominant : temp;
    }
    printf("%d\n", dominant);
    return 0;
}