#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
//不晓得哪里错了，22分
using namespace std;
int main(void){
    string information;
    string query;
    int temp;
    map<string, vector<int> > mp;
    int n,m;
    int type;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            if(j == 0){
                scanf("%d", &temp);
                getchar();
            }else if(j != 3){
                getline(cin, information);
                mp[information].push_back(temp);
            }
            else{
                do{
                    cin >> information;
                    mp[information].push_back(temp);
                }while(getchar() != '\n');
            }
        }
    }
    for(map<string, vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
        sort((*it).second.begin(), (*it).second.end());
    }
    scanf("%d", &m);
    getchar();
    for(int i = 0; i < m; i++){
        scanf("%d: ", &type);
        getline(cin, query);
        printf("%d: %s\n", type, query.c_str());
        if(mp.find(query) != mp.end()){
            for(int i = 0; i < mp[query].size(); i++){
                printf("%d\n", mp[query][i]);
            }
        }
        else{
            printf("Not Found\n");
        }
    }
    return 0;
}